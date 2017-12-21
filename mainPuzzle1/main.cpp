
#include "PuzzleBoard.hpp"
#include "factory.hpp"

#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/util/system_utils.hpp"

#include <iostream>
#include <GL/glut.h>

#include <string>
#include <cstdlib>

const int frameRate{20};
PuzzleBoard* board{};

void timerCB(int)
{
   const double dt0{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt0 * 1000)};
   glutTimerFunc(millis, timerCB, 1);

   // current time
   const double time{mixr::base::getComputerTime()};

   // N-1 Time
   static double time0{time};

   // compute delta time
   const double dt{time - time0};
   time0 = time;

   mixr::base::Timer::updateTimers(static_cast<double>(dt));
   mixr::graphics::Graphic::flashTimer(static_cast<double>(dt));
   board->tcFrame(static_cast<double>(dt));
}

// board builder
PuzzleBoard* builder(const std::string& filename)
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
   const auto board = dynamic_cast<PuzzleBoard*>(obj);
   if (board == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return board;
}

int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "puzzle.edl";

   board = builder(configFilename);

   // create a display window
   board->createWindow();

   // set timer
   const double dt{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerCB, 1);

   glutMainLoop();

   return 0;
}
