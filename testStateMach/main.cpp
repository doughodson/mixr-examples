
#include "factory.hpp"

#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/StateMachine.hpp"
#include "mixr/base/Timers.hpp"

#include <string>
#include <cstdlib>

// state machine builder
mixr::base::StateMachine* builder(const std::string& filename)
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
   const auto stateMachine = dynamic_cast<mixr::base::StateMachine*>(obj);
   if (stateMachine == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return stateMachine;
}

// main test loop
void theTest(mixr::base::StateMachine* stateMachine)
{
   const double dt{0.05};  // Fake delta time

   while (stateMachine->getState() != 99) {
      mixr::base::Timer::updateTimers(static_cast<double>(dt));
      stateMachine->updateTC(dt);
      stateMachine->updateData(dt);
   }
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "test1.edl";

   // parse arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // ---
   // Read in the description files
   // ---
   mixr::base::StateMachine* stateMachine{builder(configFilename)};

   //stateMachine->serialize(std::cout);

   // reset the system
   stateMachine->event(mixr::base::Component::RESET_EVENT);

   // run the test
   theTest(stateMachine);

   return 0;
}
