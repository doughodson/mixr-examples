
# platform path
MIXR_ROOT = $$(MIXR_ROOT)
isEmpty(MIXR_ROOT) MIXR_ROOT = $$PWD/../../mixr
message(MIXR_ROOT = $${MIXR_ROOT})

# version of Visual Studio, if applicable
MS_VER = vs2013-32
#MS_VER = vs2015-32

# path to 3rd party libraries
MIXR_3RD_PARTY_ROOT = $$(MIXR_3RD_PARTY_ROOT)
isEmpty(MIXR_3RD_PARTY_ROOT) MIXR_3RD_PARTY_ROOT = $$PWD/../../mixr-3rdparty
message(MIXR_3RD_PARTY_ROOT = $${MIXR_3RD_PARTY_ROOT})

QT += core widgets

MAKEFILE = qtMakefile

TARGET = mainQt1
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

# file types to include in project
SOURCES += *.cpp
FORMS += *.ui
HEADERS += *.hpp
OTHER_FILES += configs/*.epp

# include paths
INCLUDEPATH += \
   $${MIXR_ROOT}/include

# default location for intermediate files
UI_DIR = ./tmp/ui
OBJECTS_DIR = ./tmp/obj
MOC_DIR = ./tmp/moc
RCC_DIR = ./tmp/rcc

# libraries
# Windows release libraries
win32:CONFIG(release, debug|release): LIBS +=        \
    # mixr
    -L$${MIXR_ROOT}/lib/                             \
    -L$${MIXR_3RD_PARTY_ROOT}/lib/$${MS_VER}         \
    -lmixr_interop_dis                               \
    -lmixr_interop                                   \
    -lmixr_simulation                                \
    -lmixr_models                                    \
    -lmixr_terrain                                   \
    -lmixr_base                                      \
    -ljsbsim                                         \
    # system
    -lwinmm                                          \
    -lws2_32

# Windows debug libraries
else:win32:CONFIG(debug, debug|release): LIBS +=        \
    # mixr
    -L$${MIXR_ROOT}/lib/                                \
    -L$${MIXR_3RD_PARTY_ROOT}/lib/$${MS_VER}            \
    -lmixr_interop_dis_d                                \
    -lmixr_interop_d                                    \
    -lmixr_simulation_d                                 \
    -lmixr_models_d                                     \
    -lmixr_terrain_d                                    \
    -lmixr_base_d                                       \
    -ljsbsim_d                                          \
    # system
    -lwinmm                                             \
    -lws2_32

# Linux libraries
else:unix:!macx:!symbian: LIBS +=       \
    # mixr
    -L$${MIXR_ROOT}/lib/                \
    -L$${MIXR_3RD_PARTY_ROOT}/lib/      \
    -lmixr_interop_dis                  \
    -lmixr_interop                      \
    -lmixr_simulation                   \
    -lmixr_models                       \
    -lmixr_terrain                      \
    -lmixr_base                         \
    -lJSBSim                            \
    # system
    -lX11 -lpthread -lrt

RESOURCES += \
    configs/data/icons.qrc
