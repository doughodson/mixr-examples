
#include "TestStation.hpp"
#include "factory.hpp"

#include "mixr/terrain/ded/DedFile.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/util/system_utils.hpp"

#include "mixr/graphics/Graphic.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"
#include <GL/glut.h>

#include <string>
#include <cstdlib>

// background rate
const int bgRate{20};
TestStation* testStation{};

// updateDataCB() -- Station's background tasks
void updateDataCB(int)
{
   const double dt0{1.0 / static_cast<double>(bgRate)};
   const int millis{static_cast<int>(dt0 * 1000)};
   glutTimerFunc(millis, updateDataCB, 1);

   // current time
   const double time{mixr::base::getComputerTime()};

   // N-1 Time
   static double time0{time};

   // compute delta time
   const double dt{time - time0};
   time0 = time;

   mixr::base::Timer::updateTimers(dt);
   mixr::graphics::Graphic::flashTimer(dt);
   testStation->updateData(dt);
}

// test station builder
TestStation* builder(const std::string& filename)
{
   // read configuration file
   int num_errors{};
   mixr::base::Object* obj{mixr::base::edl_parser(filename, factory, &num_errors)};
   if (num_errors > 0) {
      std::cerr << "File: " << filename << ", number of errors: " << num_errors << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // test to see if an object was created
   if (obj == nullptr) {
      std::cerr << "Invalid configuration file, no objects defined!" << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // do we have a base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mixr::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto testStation = dynamic_cast<TestStation*>(obj);
   if (testStation == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return testStation;
}

//
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   // build a test station
   testStation = builder(configFilename);

   // resetting the system will load the data files

   std::cout << "starting loading files --" << std::endl;
   const double start {mixr::base::getComputerTime()};

   testStation->reset();

   const double end{mixr::base::getComputerTime()};
   const double dtime{end - start};
   std::cout << "finished loading files: time(s) = " << dtime << std::endl;

   // set timer for background tasks
   const double dt{1.0 / static_cast<double>(bgRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, updateDataCB, 1);

   testStation->createTimeCriticalProcess();

   glutMainLoop();
   return 0;
}
