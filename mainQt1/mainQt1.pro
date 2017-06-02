
# path to framework
MXRP_ROOT = $$(MXRP_ROOT)
isEmpty(MXRP_ROOT) MXRP_ROOT = $$PWD/../../mxrp
message(MXRP_ROOT = $${MXRP_ROOT})

# version of Visual Studio, if applicable
MS_VER = vs2013-32
#MS_VER = vs2015-32

# path to 3rd party libraries
MXRP_3RD_PARTY_ROOT = $$(MXRP_3RD_PARTY_ROOT)
isEmpty(MXRP_3RD_PARTY_ROOT) MXRP_3RD_PARTY_ROOT = $$PWD/../../mxrp-3rdparty
message(MXRP_3RD_PARTY_ROOT = $${MXRP_3RD_PARTY_ROOT})

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
   $${MXRP_ROOT}/include

# default location for intermediate files
UI_DIR = ./tmp/ui
OBJECTS_DIR = ./tmp/obj
MOC_DIR = ./tmp/moc
RCC_DIR = ./tmp/rcc

# libraries
# Windows release libraries
win32:CONFIG(release, debug|release): LIBS +=        \
    # mxrp
    -L$${MXRP_ROOT}/lib/                             \
    -L$${MXRP_3RD_PARTY_ROOT}/lib/$${MS_VER}         \
    -lmxrp_interop_dis                               \
    -lmxrp_interop                                   \
    -lmxrp_simulation                                \
    -lmxrp_models                                    \
    -lmxrp_terrain                                   \
    -lmxrp_otw                                       \
    -lmxrp_base                                      \
    -lccl_lib                                        \
    -ljsbsim                                         \
    # system
    -lwinmm                                          \
    -lws2_32

# Windows debug libraries
else:win32:CONFIG(debug, debug|release): LIBS +=        \
    # mxrp
    -L$${MXRP_ROOT}/lib/                                \
    -L$${MXRP_3RD_PARTY_ROOT}/lib/$${MS_VER}            \
    -lmxrp_interop_dis_d                                \
    -lmxrp_interop_d                                    \
    -lmxrp_simulation_d                                 \
    -lmxrp_models_d                                     \
    -lmxrp_terrain_d                                    \
    -lmxrp_otw_d                                        \
    -lmxrp_base_d                                       \
    -lccl_lib_d                                         \
    -ljsbsim_d                                          \
    # system
    -lwinmm                                             \
    -lws2_32

# Linux libraries
else:unix:!macx:!symbian: LIBS +=       \
    # mxrp
    -L$${MXRP_ROOT}/lib/                \
    -L$${MXRP_3RD_PARTY_ROOT}/lib/      \
    -lmxrp_interop_dis                  \
    -lmxrp_interop                      \
    -lmxrp_otw                          \
    -lmxrp_simulation                   \
    -lmxrp_models                       \
    -lmxrp_terrain                      \
    -lmxrp_base                         \
    -lcigicl                            \
    -lJSBSim                            \
    # system
    -lX11 -lpthread -lrt


RESOURCES += \
    configs/data/icons.qrc
