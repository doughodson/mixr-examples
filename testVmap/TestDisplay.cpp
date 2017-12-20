
#include "TestDisplay.hpp"

#include "mixr/base/Pair.hpp"

#include "mixr/graphics/MapPage.hpp"
#include "mixr/graphics/SymbolLoader.hpp"

#include "mixr/map/vpf/VMap0MainDirectory.hpp"
#include "mixr/map/vpf/VMap0ReferenceDirectory.hpp"
#include "mixr/map/vpf/VMap0RefCoverageDirectory.hpp"

#include <iostream>

#include <GL/glut.h>

IMPLEMENT_SUBCLASS(TestDisplay, "TestDisplay")
EMPTY_COPYDATA(TestDisplay)
EMPTY_DELETEDATA(TestDisplay)

BEGIN_SLOTTABLE(TestDisplay)
    "vpfdirectory",          // 1) set our VMap0MainDirectory object
END_SLOTTABLE(TestDisplay)

BEGIN_SLOT_MAP(TestDisplay)
    ON_SLOT(1, setSlotVMapDir, mixr::vpf::VMap0MainDirectory)
END_SLOT_MAP()

using namespace mixr;

TestDisplay::TestDisplay()
{
    STANDARD_CONSTRUCTOR()
    for (int i = 0; i < 500; i++) {
        verts[i].set(0,0,0);
        *placenames[i] = 0;
    }
}

bool TestDisplay::setSlotVMapDir(mixr::vpf::VMap0MainDirectory* vDir)
{
    if (vpf != nullptr) vpf->unref();
    vpf = nullptr;
    if (vDir != nullptr) {
        vpf = vDir;
        vpf->ref();
    }
    return true;
}

void TestDisplay::drawIt()
{
    BaseClass::drawIt();
    //clear();
    //draw();
    //swapBuffers();
}

void TestDisplay::updateData(const double dt)
{
    BaseClass::updateData(dt);

#if 0
    if (start) {
        if (vpf != 0) {
            // get our reference directory
            Vpf::VMAP0ReferenceDirectory* ref{vpf->getReferenceDir()};
            if (ref != 0) {
//                bool ok = true;
                numVerts = 0;
#if 1
                Vpf::VMAP0RefCoverageDirectory* rDir{ref->getCoverage(Vpf::VMAP0ReferenceDirectory::CVG_PLACENAM)};
                if (rDir != 0) {
                    //numVerts = rDir->getPlacenameCoordsByRange(20, 20, 39.9276f, -75.2182f, verts, 500);  
                    //updatePoints();

                    //ok = true;
                    //numVerts = 0;
                    //numRecords = 0;
                    //// now get our placenames
                    //for (int i = 0; i < 
                    //    rDir->getPlacenameByRecord(numRecords+1, placenames[numPlaces]);
                    //    //std::cout << "PLACENAME #" <<  numPlaces +1 << " = " << placenames[numPlaces] << std::endl;
                    //    numPlaces++;
                    //    numRecords++;
                    //}
                    //// if we never reached a bad record, back up one
                    //updatePlaceNames();


                    //ok = true;
                    //numVerts = 0;
                    //numRecords = 0;
                    ////// now get our placenames
                    //while (numRecords < 250 && numVerts < 500){
                    //    // let's just get our coordinates first (by record)
                    //    int count = rDir->getPlacenameCoordsByRecord(numRecords+1, verts, numVerts, 500);
                    //    //std::cout << "PLACENAME #" << numVerts+1 << " = " << placenames[numVerts] << std::endl;
                    //    numVerts += count;
                    //    numRecords++;
                    //}
                    //// if we never reached a bad record, back up one
                    //updatePoints();
    #else
                    // we are going to query our components by a lat long and range
                    VMAP0RefCoverageDirectory* rDir{ref->getCoverage(VMAP0ReferenceDirectory::CVG_POLBND)};
                    // ok, our placenam coverage directory contains points and their associated names, so let's query them by record first
                    while (numVerts < 500) {
                        float maxLat{90}, maxLon{180};
                        float minLat{-90}, minLon{-180};
                        int x{rDir->getPolBndCoordsByLatLon(maxLat, maxLon, minLat, minLon, numVerts, verts)};
                        numVerts += x;
                    }
                    //while (ok && numVerts < 500) {
                        // let's just get our coordinates first (by record)
                        //int x = rDir->getPolBndCoordsByRecord(numRecords+1, verts, numVerts);  
                        
                        // add the number of vertices we recorded
                        //numVerts += x;
                        //numRecords++;
                    //}
                    updatePoints();
    #if 0
                    ok = true;
                    numVerts = 0;
                    // now get our placenames
                    while (ok && numVerts < 300) {
                        // let's just get our coordinates first (by record)
                        ok = rDir->getPlacenameByRecord(numVerts+1, placenames[numVerts]);
                        //std::cout << "PLACENAME #" << numVerts+1 << " = " << placenames[numVerts] << std::endl;
                        //if (numVerts > 0) std::cout << "PLACENAME - 1 #" << numVerts << " = " << placenames[numVerts-1] << std::endl;
                        numVerts++;
                    }
                    // if we never reached a bad record, back up one
                    if (!ok) numVerts--;
                    updatePlaceNames();
    #endif
    #endif
                }
            }
        }
        start = false;
    }
#endif
}

void TestDisplay::updatePlaceNames() 
{
    base::Pair* pair{subpage()->findByName("places")};
    if (pair != nullptr) {
        pair->ref();
        graphics::SymbolLoader* myLoader{dynamic_cast<graphics::SymbolLoader*>(pair->object())};
        if (myLoader != nullptr) {
            myLoader->clearLoader();
            for (int i = 0; i < numPlaces; i++) {
                int idx{myLoader->addSymbol(1, placenames[i])};
                myLoader->updateSymbolPositionLL(idx, verts[i].x(), verts[i].y());
                myLoader->updateSymbolText(idx, "name", placenames[i]);
                std::cout << "PUT PLACENAME " << placenames[i] << " into position " << verts[i].x() << ", " << verts[i].y() << std::endl;
            }
        }
        pair->unref();
    }        
}

void TestDisplay::updatePoints() 
{
    base::Pair* pair{subpage()->findByName("points")};
    if (pair != nullptr) {
        pair->ref();
        graphics::SymbolLoader* myLoader{dynamic_cast<graphics::SymbolLoader*>(pair->object())};
        if (myLoader != nullptr) {
            myLoader->clearLoader();
            for (int i = 0; i < numVerts; i++) {
                if (verts[i].y() != 0 && verts[i].x() != 0 && verts[i].z() != 0) {
                    int idx{myLoader->addSymbol(1, placenames[i])};
                    myLoader->updateSymbolPositionLL(idx, verts[i].x(), verts[i].y());
                    std::cout << "COORDINATE = " << verts[i].x() << ", " << verts[i].y() << std::endl;
                }
            }
        }
        pair->unref();
    }
}


//SLS - last update 3/18/08 
//Now I can query the reference directory for the placenam coverage, and get placenames and coordinates based on a ref lat lon and range
//The next step would be to start querying political boundaries (polbnd) using the indexes they have setup.

// mouseEvent() -- Handle mouse inputs
void TestDisplay::mouseEvent(const int button, const int state, const int x, const int y)
{
    setMouse(x,y);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // we just did a pick, let's do a spatial query on it, based on our lat and lon
        graphics::MapPage* page{static_cast<graphics::MapPage*>(subpage())};
        if (page != nullptr) {
            double refLat{page->getReferenceLatDeg()};
            double refLon{page->getReferenceLonDeg()};
            double mapRange{page->getRange()};
            // now get our directory and query our index
            if (vpf != nullptr) {
                // get our reference directory
                vpf::VMap0ReferenceDirectory* ref{vpf->getReferenceDir()};
                if (ref != nullptr) {
//                    bool ok = true;
                    numVerts = 0;
                    vpf::VMap0RefCoverageDirectory* rDir{ref->getCoverage(vpf::VMap0ReferenceDirectory::CVG_PLACENAM)};
                    if (rDir != nullptr) {
                        // query our place name by reference latitutde
                        numVerts = rDir->getPlacenameCoordsByRange(static_cast<float>(mapRange), static_cast<float>(mapRange),
                                                                   static_cast<float>(refLat), static_cast<float>(refLon), verts, 0, 500);
                        // update points
                        updatePoints();
                        // now get our placenames
                        numPlaces = 0;
                        for (int i = 0; i < numVerts; i++) {
                            int primId{rDir->getSpatialQueryPlacenamePrimID(i+1)};
                            rDir->getPlacenameByRecord(primId, placenames[numPlaces++]);
                        }
                        updatePlaceNames();
                    }
                }
            }
        }
    }
}

