
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include "mixr/base/osg/Vec3d"

#include "mixr/map/vpf/VpfTable.hpp"

namespace mixr {
namespace base { class Vec3d; }
namespace graphics { class Graphic; }
namespace vpf { class VpfTable; class VMap0MainDirectory; }
}

class TestDisplay final: public mixr::glut::GlutDisplay
{
    DECLARE_SUBCLASS(TestDisplay, mixr::glut::GlutDisplay)

public:
    TestDisplay();
    
    void drawIt() final;
    void mouseEvent(const int button, const int state, const int x, const int y) final;
    void updateData(const double dt = 0.0) final;

    void updatePlaceNames();
    void updatePoints();

private:
    // Select/Pick test
    mixr::graphics::Graphic* selected{};
    //packet test for vector product format level 0
    mixr::vpf::VpfTable tables[2];
    bool start{true};
    int numVerts{};
    int numRecords{4};
    int numPlaces{};
    mixr::base::Vec3d verts[5000];
    mixr::vpf::VMap0MainDirectory* vpf{};
    char placenames[500][100]{};

private:
    // slot table helper methods
    bool setSlotVMapDir(mixr::vpf::VMap0MainDirectory*);
};

#endif
