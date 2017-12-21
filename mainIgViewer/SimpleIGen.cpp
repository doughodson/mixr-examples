
#include "SimpleIGen.hpp"

#include "events.hpp"

#include "mixr/base/units/Distances.hpp"
#include "mixr/base/units/distance_utils.hpp"

#include "mixr/base/network/NetHandler.hpp"

#include <iostream>

#define SYNC2HOST

using namespace mixr;

IMPLEMENT_SUBCLASS(SimpleIGen, "SimpleIGen")
EMPTY_COPYDATA(SimpleIGen)
EMPTY_DELETEDATA(SimpleIGen)

BEGIN_EVENT_HANDLER(SimpleIGen)
   ON_EVENT(USER_EVENT_ON_ENTRY, onEntry)
END_EVENT_HANDLER()

BEGIN_SLOTTABLE(SimpleIGen)
   "databasePath",     // 1) Path to database files
   "netInput",         // 2) Network input handler
END_SLOTTABLE(SimpleIGen)

BEGIN_SLOT_MAP(SimpleIGen)
  ON_SLOT(1, setSlotDatabasePath, base::String)
  ON_SLOT(2, setSlotNetInput,     base::NetHandler)
END_SLOT_MAP()

SimpleIGen::SimpleIGen()
{
   STANDARD_CONSTRUCTOR()
   x = -20.0f * base::distance::KM2M;
   y = -20.0f * base::distance::KM2M;
   viewer = new osgViewer::Viewer;
}

// set database path
bool SimpleIGen::setSlotDatabasePath(base::String* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      databasePath = msg->getString();
      ok = true;
   }
   return ok;
}

// Set Network Input Handler
bool SimpleIGen::setSlotNetInput(base::NetHandler* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      netInput = msg;
      ok = true;
   }
   return ok;
}

// initialize network input handler
bool SimpleIGen::initNetwork()
{
   // Already done?
   if (netOk)
      return true;

#ifdef SYNC2HOST
   if (netInput->initNetwork(true)) {
      netOk = true;
      std::cout << "netInput Init OK" << std::endl;
      return netOk;
   }
#else
   if (netInput->initNetwork(false)) {
      netOk = true;
      return netOk;
   }
#endif
   return netOk;
}

int SimpleIGen::recv(char* buffer)
{
   int recvCnt{};
   if (netOk)
      recvCnt = netInput->recvData(buffer, 1472);
   return recvCnt;
}

void SimpleIGen::updateData(const double dt)
{
   BaseClass::updateData(dt);
}

void SimpleIGen::draw()
{
   if (viewer->isRealized()) {
      
      int n{recv((char*)&entityState)};
      if (n > 0) {
         // update position
         x = entityState.pilot_eye_y * base::distance::FT2M;
         y = entityState.pilot_eye_x * base::distance::FT2M;
         z = entityState.pilot_eye_z * base::distance::FT2M;
         // update orientation
         yaw = -entityState.psi;     // OSE heading is -(A/C heading)
         pitch = entityState.theta;
         roll = entityState.phi;
      }

      viewMatrix.set(
         1, 0, 0, 0,
         0, 0, -1, 0,
         0, 1, 0, 0,
         0, 0, 0, 1);

      rotate = osg::Matrix::rotate(osg::DegreesToRadians(roll), osg::Y_AXIS, osg::DegreesToRadians(pitch),
                                   osg::X_AXIS, osg::DegreesToRadians(yaw), osg::Z_AXIS);
      translate = osg::Matrix::translate(x, y, z);
      
      // Setup Rotation and Position Matrix
      viewRotAndPosMatrix = rotate * translate;
      // Invert Model View Matrix
      viewRotAndPosMatrix.invert(viewRotAndPosMatrix);
      // Create New Eye Matrix
      eyeMatrix = viewRotAndPosMatrix * viewMatrix;
      // Setup Eye Matrix
      viewer->getCamera()->setViewMatrix(eyeMatrix);
      viewer->frame();
   }
}

bool SimpleIGen::onEntry()
{
   if (!initNetwork())
      return false;
   // our terrain
   terrain = osgDB::readNodeFile(databasePath + "/archive.txp");
   if (!terrain)
      return false;

   // our light
   light = new osg::Light;
   light->setLightNum(1);
   lightSource = new osg::LightSource;
   lightSource->setLight(light.get());

   rootnode = new osg::Group;
   rootnode->addChild(terrain.get());
   rootnode->getOrCreateStateSet()->setMode(GL_LIGHT1, osg::StateAttribute::ON);
   rootnode->addChild(lightSource.get());

   GLint x {}, y {};
   GLsizei vpWidth {}, vpHeight {};
   getViewport(&x, &y, &vpWidth, &vpHeight);
   window = viewer->setUpViewerAsEmbeddedInWindow(x, y, vpWidth, vpHeight);
   viewer->setSceneData(rootnode.get());
   viewer->setLightingMode(::osg::View::SKY_LIGHT);

   // open viewer
   viewer->realize();
   return true;
}

void SimpleIGen::reshapeIt(int w, int h)
{
   if (window.valid()) {
      window->resized(window->getTraits()->x, window->getTraits()->y, w, h);
      window->getEventQueue()->windowResize(window->getTraits()->x, window->getTraits()->y, w, h);
   }
   BaseClass::reshapeIt(w, h);
}
