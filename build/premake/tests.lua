--------------------------------------------------------
-- Test applications
--------------------------------------------------------

-- test dafif library functionality
project "testDafif"
   kind "ConsoleApp"
   targetname "testDafif"
   targetdir "../../testDafif"
   debugdir "../../testDafif"
   files {
      "../../testDafif/**.h*",
      "../../testDafif/**.cpp",
      "../../testDafif/**.cxx",
      "../../testDafif/**.epp",
      "../../testDafif/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "mixr_simulation", "mixr_terrain", "mixr_dafif", "mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "mixr_simulation_d", "mixr_terrain_d", "mixr_dafif_d", "mixr_base_d"}
      links {LibWindows}

-- testEvents: test of event passing
project "testEvents"
   kind "WindowedApp"
   targetname "testEvents"
   targetdir "../../testEvents"
   debugdir "../../testEvents"
   files {
      "../../testEvents/**.h*",
      "../../testEvents/**.cpp",
      "../../testEvents/**.epp",
      "../../testEvents/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_gui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_gui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testGraphics : test of basic graphics
project "testGraphics"
   kind "WindowedApp"
   targetname "testGraphics"
   targetdir "../../testGraphics"
   debugdir "../../testGraphics"
   files {
      "../../testGraphics/**.h*",
      "../../testGraphics/**.cpp",
      "../../testGraphics/**.epp",
      "../../testGraphics/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_gui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_gui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testInfrared: IR test
project "testInfrared"
   kind "ConsoleApp"
   targetname "testInfrared"
   targetdir "../../testInfrared"
   debugdir "../../testInfrared"
   files {
      "../../testInfrared/**.h*",
      "../../testInfrared/**.cpp",
      "../../testInfrared/**.epp",
      "../../testInfrared/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "JSBSim"}
      links {"mixr_otw", LibCigi}
      links {"mixr_interop_dis", "mixr_interop" }
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_gui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "JSBSim_d"}
      links {"mixr_otw_d", LibCigi_d}
      links {"mixr_interop_dis_d", "mixr_interop_d" }
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_gui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testIoHandler: I/O handler test
project "testIoHandler"
   kind "WindowedApp"
   targetname "testIoHandler"
   targetdir "../../testIoHandler"
   debugdir "../../testIoHandler"
   files {
      "../../testIoHandler/**.h*",
      "../../testIoHandler/**.cpp",
      "../../testIoHandler/**.epp",
      "../../testIoHandler/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_iodevice", "mixr_gui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_iodevice_d", "mixr_gui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testLinearSys: test of linear system components
project "testLinearSys"
   targetname "testLinearSys"
   targetdir "../../testLinearSys"
   debugdir "../../testLinearSys"
   files {
      "../../testLinearSys/**.h*",
      "../../testLinearSys/**.cpp",
      "../../testLinearSys/**.epp",
      "../../testLinearSys/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_linearsystem", "mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_linearsystem_d", "mixr_base_d"}
      links {LibWindows}

-- testMatrix
project "testMatrix"
   targetname "testMatrix"
   targetdir "../../testMatrix"
   debugdir "../../testMatrix"
   files {
      "../../testMatrix/**.h*",
      "../../testMatrix/**.cpp",
      "../../testMatrix/**.epp",
      "../../testMatrix/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testMetaObject
project "testMetaObject"
   targetname "testMetaObject"
   targetdir "../../testMetaObject"
   debugdir "../../testMetaObject"
   files {
      "../../testMetaObject/**.h*",
      "../../testMetaObject/**.cpp",
      "../../testMetaObject/**.epp",
      "../../testMetaObject/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- test navigation utility functions
project "testNavUtils"
   targetname "testNavUtils"
   targetdir "../../testNavUtils"
   debugdir "../../testNavUtils"
   files {
      "../../testNavUtils/**.h*",
      "../../testNavUtils/**.cpp",
      "../../testNavUtils/**.epp",
      "../../testNavUtils/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testNetHandler
project "testNetHandler"
   targetname "testNetHandler"
   targetdir "../../testNetHandler"
   debugdir "../../testNetHandler"
   files {
      "../../testNetHandler/**.h*",
      "../../testNetHandler/**.cpp",
      "../../testNetHandler/**.epp",
      "../../testNetHandler/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base", "libzmq" }
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d", "libzmq_d" }
      links {LibWindows}

-- testRadar
project "testRadar"
   targetname "testRadar"
   targetdir "../../testRadar"
   debugdir "../../testRadar"
   files {
      "../../testRadar/**.h*",
      "../../testRadar/**.cpp",
      "../../testRadar/**.epp",
      "../../testRadar/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "JSBSim"}
      links {"mixr_otw", LibCigi}
      links {"mixr_interop_dis", "mixr_interop", "mixr_iodevice"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_gui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "JSBSim_d"}
      links {"mixr_otw_d", LibCigi_d}
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_iodevice_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_gui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testRecordData
project "testRecordData"
   targetname "testRecordData"
   targetdir "../../testRecordData"
   debugdir "../../testRecordData"
   files {
      "../../testRecordData/**.h*",
      "../../testRecordData/**.cpp",
      "../../testRecordData/**.epp",
      "../../testRecordData/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder", "libxpanel" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "JSBSim" }
      links {"mixr_otw", LibCigi }
      links {"mixr_interop_dis", "mixr_interop", "mixr_recorder", "mixr_iodevice" }
      links {"mixr_simulation", "mixr_terrain" }
      links {"mixr_gui_glut", "mixr_instruments", "mixr_graphics", "mixr_base" }
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {"libprotobuf" }
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "JSBSim_d" }
      links {"mixr_otw_d",  LibCigi_d }
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_recorder_d", "mixr_iodevice_d" }
      links {"mixr_simulation_d", "mixr_terrain_d" }
      links {"mixr_gui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d" }
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {"libprotobuf_d" }
      links {LibWindows}

-- testRecorderRead
project "testRecorderRead"
   targetname "testRecorderRead"
   targetdir "../../testRecorderRead"
   debugdir "../../testRecorderRead"
   files {
      "../../testRecorderRead/**.h*",
      "../../testRecorderRead/**.cpp",
      "../../testRecorderRead/**.epp",
      "../../testRecorderRead/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "JSBSim" }
      links {"mixr_recorder", "mixr_simulation", "mixr_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "JSBSim_d" }
      links {"mixr_recorder_d", "mixr_simulation_d", "mixr_base_d", "libprotobuf_d" }
      links {LibWindows}

-- testRecorderWrite
project "testRecorderWrite"
   targetname "testRecorderWrite"
   targetdir "../../testRecorderWrite"
   debugdir "../../testRecorderWrite"
   files {
      "../../testRecorderWrite/**.h*",
      "../../testRecorderWrite/**.cpp",
      "../../testRecorderWrite/**.epp",
      "../../testRecorderWrite/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_models", "JSBSim" }
      links {"mixr_recorder", "mixr_simulation", "mixr_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_models_d", "JSBSim_d" }
      links {"mixr_recorder_d", "mixr_simulation_d", "mixr_base_d", "libprotobuf_d" }
      links {LibWindows}

-- testRng
project "testRng"
   targetname "testRng"
   targetdir "../../testRng"
   debugdir "../../testRng"
   files {
      "../../testRng/**.h*",
      "../../testRng/**.cpp",
      "../../testRng/**.epp",
      "../../testRng/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testStateMach
project "testStateMach"
   targetname "testStateMach"
   targetdir "../../testStateMach"
   debugdir "../../testStateMach"
   files {
      "../../testStateMach/**.h*",
      "../../testStateMach/**.cpp",
      "../../testStateMach/**.epp",
      "../../testStateMach/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTables
project "testTables"
   targetname "testTables"
   targetdir "../../testTables"
   debugdir "../../testTables"
   files {
      "../../testTables/**.h*",
      "../../testTables/**.cpp",
      "../../testTables/**.epp",
      "../../testTables/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTemplates
project "testTemplates"
   targetname "testTemplates"
   targetdir "../../testTemplates"
   debugdir "../../testTemplates"
   files {
      "../../testTemplates/**.h*",
      "../../testTemplates/**.cpp",
      "../../testTemplates/**.epp",
      "../../testTemplates/**.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTimer
project "testTimer"
   targetname "testTimer"
   targetdir "../../testTimer"
   debugdir "../../testTimer"
   files {
      "../../testTimer/*.h*",
      "../../testTimer/*.cpp",
      "../../testTimer/*.edl"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mixr_base_d"}
      links {LibWindows}

