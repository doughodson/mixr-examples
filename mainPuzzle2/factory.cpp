
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "Blocks.hpp"
#include "PuzzleBoard.hpp"
#include "Controller.hpp"
#include "State.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj {};

    // Main board
    if ( name == PuzzleBoard::getFactoryName() ) {
        obj = new PuzzleBoard;
    }

    // Puzzle controller
    else if ( name == Controller::getFactoryName() ) {
        obj = new Controller();
    }

    // Puzzle state
    else if ( name == State::getFactoryName() ) {
        obj = new State();
    }

    // Puzzle blocks
    else if ( name == Block1::getFactoryName() ) {
        obj = new Block1();
    }
    else if ( name == Block2::getFactoryName() ) {
        obj = new Block2();
    }
    else if ( name == Block3::getFactoryName() ) {
        obj = new Block3();
    }
    else if ( name == Block4::getFactoryName() ) {
        obj = new Block4();
    }
    else if ( name == Block5::getFactoryName() ) {
        obj = new Block5();
    }
    else if ( name == Block6::getFactoryName() ) {
        obj = new Block6();
    }
    else if ( name == Block7::getFactoryName() ) {
        obj = new Block7();
    }
    else if ( name == Block8::getFactoryName() ) {
        obj = new Block8();
    }
    else if ( name == Block9::getFactoryName() ) {
        obj = new Block9();
    }
    else if ( name == Block10::getFactoryName() ) {
        obj = new Block10();
    }
    else if ( name == Block11::getFactoryName() ) {
        obj = new Block11();
    }
    else if ( name == Block12::getFactoryName() ) {
        obj = new Block12();
    }
    else if ( name == Block13::getFactoryName() ) {
        obj = new Block13();
    }
    else if ( name == Block14::getFactoryName() ) {
        obj = new Block14();
    }
    else if ( name == Block15::getFactoryName() ) {
        obj = new Block15();
    }

    else {
       if (obj == nullptr) obj = mixr::graphics::factory(name);
       if (obj == nullptr) obj = mixr::glut::factory(name);
       if (obj == nullptr) obj = mixr::base::factory(name);
    }

    return obj;
}
