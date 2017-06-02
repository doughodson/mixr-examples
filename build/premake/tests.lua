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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "mxrp_simulation", "mxrp_terrain", "mxrp_dafif", "mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "mxrp_simulation_d", "mxrp_terrain_d", "mxrp_dafif_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_gui_glut", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_gui_glut_d", "mxrp_graphics_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_gui_glut", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_gui_glut_d", "mxrp_graphics_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_interop_dis", "mxrp_interop" }
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d"}
      links {"mxrp_otw_d", LibCigi_d}
      links {"mxrp_interop_dis_d", "mxrp_interop_d" }
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_iodevice", "mxrp_gui_glut", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_iodevice_d", "mxrp_gui_glut_d", "mxrp_graphics_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_linearsystem", "mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_linearsystem_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base", "libzmq" }
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d", "libzmq_d" }
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_interop_dis", "mxrp_interop", "mxrp_iodevice"}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d"}
      links {"mxrp_otw_d", LibCigi_d}
      links {"mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_iodevice_d"}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath, MXRP_ExamplesIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath, MXRP_ExamplesLibPath }
   links       { "libxrecorder", "libxpanel" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim" }
      links {"mxrp_otw", LibCigi }
      links {"mxrp_interop_dis", "mxrp_interop", "mxrp_recorder", "mxrp_iodevice" }
      links {"mxrp_simulation", "mxrp_terrain" }
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base" }
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {"libprotobuf" }
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d" }
      links {"mxrp_otw_d",  LibCigi_d }
      links {"mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_recorder_d", "mxrp_iodevice_d" }
      links {"mxrp_simulation_d", "mxrp_terrain_d" }
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d" }
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath, MXRP_ExamplesIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath, MXRP_ExamplesLibPath }
   links       { "libxrecorder" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim" }
      links {"mxrp_recorder", "mxrp_simulation", "mxrp_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d" }
      links {"mxrp_recorder_d", "mxrp_simulation_d", "mxrp_base_d", "libprotobuf_d" }
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
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath, MXRP_ExamplesIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath, MXRP_ExamplesLibPath }
   links       { "libxrecorder" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim" }
      links {"mxrp_recorder", "mxrp_simulation", "mxrp_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d" }
      links {"mxrp_recorder_d", "mxrp_simulation_d", "mxrp_base_d", "libprotobuf_d" }
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
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
   includedirs { MXRP_IncPath }
   libdirs     { MXRP_LibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_base"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_base_d"}
      links {LibWindows}

