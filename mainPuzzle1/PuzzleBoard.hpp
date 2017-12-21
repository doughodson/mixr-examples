
#ifndef __PuzzleBoard_H__
#define __PuzzleBoard_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include <array>

namespace mixr {
   namespace base { class PairStream; }
   namespace graphics { class Graphic; }
}

class Controller;
class State;

//------------------------------------------------------------------------------
// Class: PuzzleBoard
// Description: Puzzle board
//------------------------------------------------------------------------------
class PuzzleBoard final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(PuzzleBoard, mixr::glut::GlutDisplay)

public:
   PuzzleBoard();

   Controller* getController()              { return controller; }  // Returns the puzzle controller
   const Controller* getController() const  { return controller; }  // Returns the puzzle controller (const version)

   const State* getFinalState() const       { return finalState; }  // Returns the final state

   void drawFunc() final;
   void updateData(const double dt = 0.0) final;

protected:
   virtual int setupBlockGraphics();                         // Setup the list of graphics::Graphic objects for the initial blocks
   virtual void clearGraphics();                             // Clears the list of graphics::Graphic objects for the blocks
   virtual void updateSolutionPath(const double dt);         // Updates the solution path graphics
   virtual void resetSolutionPath();                         // Resets the solution path graphics
   virtual void updateBlockDeltaPositions();                 // Updates the blocks' delta positions

private:
   const mixr::base::PairStream* templates {};   // Graphical templates for the blocks
   Controller* controller{};                     // puzzle controller
   double startupTimer{};                        // Movement timer

   static const int MAX_STATES{1000};            // Max states in solution path (i.e., moves)
   std::array<const State*, MAX_STATES> path{};  // Solution path
   const State* finalState{};                    // Final state (puzzle solved if not equal zero)
   int nstates{};                                // number of states in solution path

   int curPathState{};                           // Current state in the solution path
   double moveTimer{};                           // Movement timer
   bool movingFlg{};                             // Block is moving

   static const int MAX_BLOCKS{30};
   std::array<mixr::graphics::Graphic*, MAX_BLOCKS> blocks{}; // Graphics for each block
   std::array<unsigned int, MAX_BLOCKS> blockId{};            // Block reference IDs
   std::array<double, MAX_BLOCKS> xp{};                       // Block X positions
   std::array<double, MAX_BLOCKS> yp{};                       // Block Y positions
   std::array<double, MAX_BLOCKS> xd{};                       // Block delta X positions
   std::array<double, MAX_BLOCKS> yd{};                       // Block delta Y positions
   int nblocks{};                                             // number of blocks

private:
   // slot table helper methods
   bool setSlotController(Controller* const);                    // Sets the puzzle controller
   bool setSlotTemplates(const mixr::base::PairStream* const);   // Sets a list of the graphical templates for the blocks
};

#endif
