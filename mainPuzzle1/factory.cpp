
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "Blocks.hpp"
#include "Board.hpp"
#include "Puzzle.hpp"
#include "State.hpp"

#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    // Main board
    if ( name == Board::getFactoryName() ) {
        obj = new Board;
    }

    // Puzzle controller
    else if ( name == Puzzle::getFactoryName() ) {
        obj = new Puzzle();
    }

    // Puzzle state
    else if ( name == State::getFactoryName() ) {
        obj = new State();
    }

    // Puzzle blocks
    else if ( name == Block1x1::getFactoryName() ) {
        obj = new Block1x1();
    }
    else if ( name == Block1x2::getFactoryName() ) {
        obj = new Block1x2();
    }
    else if ( name == Block2x1::getFactoryName() ) {
        obj = new Block2x1();
    }
    else if ( name == Block2x2::getFactoryName() ) {
        obj = new Block2x2();
    }

    else {
       if (obj == nullptr) obj = mxrp::graphics::factory(name);
       if (obj == nullptr) obj = mxrp::glut::factory(name);
       if (obj == nullptr) obj = mxrp::base::factory(name);
    }

    return obj;
}
