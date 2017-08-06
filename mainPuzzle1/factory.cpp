
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "Blocks.hpp"
#include "Board.hpp"
#include "Puzzle.hpp"
#include "State.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj = nullptr;

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
       if (obj == nullptr) obj = mixr::graphics::factory(name);
       if (obj == nullptr) obj = mixr::glut::factory(name);
       if (obj == nullptr) obj = mixr::base::factory(name);
    }

    return obj;
}
