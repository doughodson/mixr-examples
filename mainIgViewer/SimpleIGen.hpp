
#ifndef __SimpleIGen_HPP__
#define __SimpleIGen_HPP__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include "mixr/ighost/pov/Pov.hpp"

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>

namespace mixr {
namespace base { class INetHandler; class String; }
}

class SimpleIGen final: public ::mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(SimpleIGen, ::mixr::glut::GlutDisplay)

public:
   SimpleIGen();

   // base::Component interface
   void updateData(const double dt = 0) final;

   // graphics::Page interface
   void draw() final;

   // graphics::Display interface
   void reshapeIt(int w, int h) final;

   // base::Component interface
   bool event(const int event, ::mixr::base::IObject* const obj = nullptr) final;

   // SimpleIGen interface
   bool onEntry() final;

   // initialize the network
   bool initNetwork();
   // receive a buffer from the network
   int recv(char* buffer);

private:
   ::osg::ref_ptr<osgViewer::Viewer> viewer;
   ::osg::ref_ptr<::osg::Group> rootnode;
   ::osg::ref_ptr<::osg::Node> terrain;
   ::osg::ref_ptr<::osg::Light> light;
   ::osg::ref_ptr<::osg::LightSource> lightSource;
   ::osg::observer_ptr<osgViewer::GraphicsWindow> window;
   // data from simulation
   ::mixr::ighost::pov::Pov pov;
   // coord System Shift (Z Up)
   ::osg::Matrix viewMatrix;
   ::osg::Matrix viewRotAndPosMatrix;
   ::osg::Matrix eyeMatrix;
   ::osg::Matrix translate;
   ::osg::Matrix rotate;
   std::string databasePath;                                    // database path
   ::mixr::base::safe_ptr<::mixr::base::INetHandler> netInput;  // Input network handler
   bool netOk {};

private:
   // slot table helper methods
   bool setSlotDatabasePath(::mixr::base::String* const);
   bool setSlotNetInput(::mixr::base::INetHandler* const);
};

#endif

