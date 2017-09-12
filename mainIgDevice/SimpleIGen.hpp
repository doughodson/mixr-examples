
#ifndef __SimpleIGen_H__
#define __SimpleIGen_H__

#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/network/NetHandler.hpp"
#include "mixr/graphics/Graphic.hpp"
#include "mixr/ui/glut/GlutDisplay.hpp"

#include "mixr/ig/viewpoint/EntityState.hpp"

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>

#include <GL/glut.h>

namespace mixr {
namespace base { class NetHandler; class String; }
}

class SimpleIGen : public ::mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(SimpleIGen, ::mixr::glut::GlutDisplay)

public:
   SimpleIGen();

   // base::Component interface
   virtual void updateData(const double dt = 0) override;

   // graphics::Page interface
    virtual void draw() override;

   // graphics::Display interface
   virtual void reshapeIt(int w, int h);

   // base::Component interface
   virtual bool event(const int event, ::mixr::base::Object* const obj = nullptr) override;

   // SimpleIGen interface
   bool onEntry();
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
   // Attitude
   float yaw {}, pitch {}, roll {};
   // Position
   float x {}, y {}, z {6000.0};
   // Data from simulation
   ::mixr::viewpoint::EntityState entityState;
   // Coord System Shift (Z Up)
   ::osg::Matrix viewMatrix;
   ::osg::Matrix viewRotAndPosMatrix;
   ::osg::Matrix eyeMatrix;
   ::osg::Matrix translate;
   ::osg::Matrix rotate;
   std::string databasePath;                                    // database path
   ::mixr::base::safe_ptr<::mixr::base::NetHandler> netInput;   // Input network handler
   bool netOk {};

private:
   // slot table helper methods
   bool setSlotDatabasePath(::mixr::base::String* const);
   bool setSlotNetInput(::mixr::base::NetHandler* const);
};

#endif

