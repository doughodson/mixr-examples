
include makedefs

# demos
APPLICATIONS = demoEfis
APPLICATIONS += demoFlightDisplays1
APPLICATIONS += demoFlightDisplays2
APPLICATIONS += demoInstruments
APPLICATIONS += demoSubDisplays

# graphic oriented examples
APPLICATIONS += testGraphics

# GUI examples
APPLICATIONS += mainGlut
#APPLICATIONS += mainQt1

# non-real-time simulation
APPLICATIONS += mainNonRT1

# terrain database loader
APPLICATIONS += mainTerrain

# AI development examples
APPLICATIONS += mainPuzzle1 mainPuzzle2

# simple simulation examples
APPLICATIONS += mainSim1 mainSim2 mainSim3

# ground mapping radar example
APPLICATIONS += mainGndMapRdr

# ubf example
APPLICATIONS += mainUbf1

# example of Laero model and autopilot functionality
APPLICATIONS += mainLaero

# simple cockpit
APPLICATIONS += mainCockpit

# simple image generator viewer
APPLICATIONS += mainIgViewer

# test table, state machines, events and timer
APPLICATIONS += testDafif
APPLICATIONS += testEvents
APPLICATIONS += testMetaObject
APPLICATIONS += testTables
APPLICATIONS += testSlots
APPLICATIONS += testStateMach
APPLICATIONS += testTemplates
APPLICATIONS += testTimer

# infrared and radar test programs
APPLICATIONS += testRadar
APPLICATIONS += testInfrared

# linkage test program
APPLICATIONS += testLinkage

# matrix test program
APPLICATIONS += testMatrix

# navigation tests
APPLICATIONS += testNavUtils

# network handler testing
APPLICATIONS += testNetHandler

# linear systems package
APPLICATIONS += testLinearSys

# data recorder read/write tests
APPLICATIONS += testRecordData
APPLICATIONS += testRecorderRead
APPLICATIONS += testRecorderWrite

# test VMAP0 loader library
APPLICATIONS += testVmap

# test unit classes and a few other things
APPLICATIONS += testUnits

# tutorial examples
APPLICATIONS += tutorial01
APPLICATIONS += tutorial02
APPLICATIONS += tutorial03
APPLICATIONS += tutorial04
APPLICATIONS += tutorial05
APPLICATIONS += tutorial06
APPLICATIONS += tutorial07
APPLICATIONS += tutorial08

PROJECTS = shared $(APPLICATIONS)

.PHONY: all clean $(PROJECTS) $(APPLICATIONS) edl

all: $(PROJECTS)

$(PROJECTS):
	$(MAKE) -C $@

$(APPLICATIONS): shared

edl:
	-for d in $(PROJECTS); do (cd $$d; $(MAKE) edl ); done

clean:
	-for d in $(PROJECTS); do (cd $$d; $(MAKE) clean ); done
