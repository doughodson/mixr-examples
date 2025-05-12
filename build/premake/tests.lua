--------------------------------------------------------
-- Test applications
--------------------------------------------------------

-- test dafif library functionality
project "testDafif"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testDafif"
   targetdir "../../testDafif"
   debugdir "../../testDafif"
   files {
      "../../testDafif/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "mixr_simulation", "mixr_terrain", "mixr_dafif", "mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "mixr_simulation_d", "mixr_terrain_d", "mixr_dafif_d", "mixr_base_d"}
      links {LibWindows}

-- testEvents: test of event passing
project "testEvents"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testEvents"
   targetdir "../../testEvents"
   debugdir "../../testEvents"
   files {
      "../../testEvents/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testGraphics : test of basic graphics
project "testGraphics"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testGraphics"
   targetdir "../../testGraphics"
   debugdir "../../testGraphics"
   files {
      "../../testGraphics/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testInfrared: IR test
project "testInfrared"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testInfrared"
   targetdir "../../testInfrared"
   debugdir "../../testInfrared"
   files {
      "../../testInfrared/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "JSBSim"}
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear"}
      links {"mixr_interop_dis", "mixr_interop" }
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "JSBSim_d"}
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d"}
      links {"mixr_interop_dis_d", "mixr_interop_d" }
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testLinearSys: test of linear system components
project "testLinearSys"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testLinearSys"
   targetdir "../../testLinearSys"
   debugdir "../../testLinearSys"
   files {
      "../../testLinearSys/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testLinkage: linkage test
project "testLinkage"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testLinkage"
   targetdir "../../testLinkage"
   debugdir "../../testLinkage"
   files {
      "../../testLinkage/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_linkage", "mixr_ui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_linkage_d", "mixr_ui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testMatrix
project "testMatrix"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testMatrix"
   targetdir "../../testMatrix"
   debugdir "../../testMatrix"
   files {
      "../../testMatrix/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testMetaObject
project "testMetaObject"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testMetaObject"
   targetdir "../../testMetaObject"
   debugdir "../../testMetaObject"
   files {
      "../../testMetaObject/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- test navigation utility functions
project "testNavUtils"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testNavUtils"
   targetdir "../../testNavUtils"
   debugdir "../../testNavUtils"
   files {
      "../../testNavUtils/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testNetHandler
project "testNetHandler"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testNetHandler"
   targetdir "../../testNetHandler"
   debugdir "../../testNetHandler"
   files {
      "../../testNetHandler/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   filter "configurations:Release"
      links {"mixr_base", "libzmq" }
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d", "libzmq_d" }
      links {LibWindows}

-- testRadar
project "testRadar"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testRadar"
   targetdir "../../testRadar"
   debugdir "../../testRadar"
   files {
      "../../testRadar/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "JSBSim"}
      links {"mixr_interop_dis", "mixr_interop", "mixr_linkage"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "JSBSim_d"}
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_linkage_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- testRecordData
project "testRecordData"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testRecordData"
   targetdir "../../testRecordData"
   debugdir "../../testRecordData"
   files {
      "../../testRecordData/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder", "libxpanel" }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "JSBSim" }
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear" }
      links {"mixr_interop_dis", "mixr_interop", "mixr_recorder", "mixr_linkage" }
      links {"mixr_simulation", "mixr_terrain" }
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base" }
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {"libprotobuf" }
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "JSBSim_d" }
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d" }
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_recorder_d", "mixr_linkage_d" }
      links {"mixr_simulation_d", "mixr_terrain_d" }
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d" }
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {"libprotobuf_d" }
      links {LibWindows}

-- testRecorderRead
project "testRecorderRead"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testRecorderRead"
   targetdir "../../testRecorderRead"
   debugdir "../../testRecorderRead"
   files {
      "../../testRecorderRead/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder" }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "JSBSim" }
      links {"mixr_recorder", "mixr_simulation", "mixr_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "JSBSim_d" }
      links {"mixr_recorder_d", "mixr_simulation_d", "mixr_base_d", "libprotobuf_d" }
      links {LibWindows}

-- testRecorderWrite
project "testRecorderWrite"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testRecorderWrite"
   targetdir "../../testRecorderWrite"
   debugdir "../../testRecorderWrite"
   files {
      "../../testRecorderWrite/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxrecorder" }
   filter "configurations:Release"
      links {"mixr_models_jsbsim", "mixr_models", "JSBSim" }
      links {"mixr_recorder", "mixr_simulation", "mixr_base", "libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_jsbsim_d", "mixr_models_d", "JSBSim_d" }
      links {"mixr_recorder_d", "mixr_simulation_d", "mixr_base_d", "libprotobuf_d" }
      links {LibWindows}

-- testSlots
project "testSlots"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testSlots"
   targetdir "../../testSlots"
   debugdir "../../testSlots"
   files {
      "../../testSlots/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testStateMach
project "testStateMach"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testStateMach"
   targetdir "../../testStateMach"
   debugdir "../../testStateMach"
   files {
      "../../testStateMach/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTables
project "testTables"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testTables"
   targetdir "../../testTables"
   debugdir "../../testTables"
   files {
      "../../testTables/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTemplates
project "testTemplates"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testTemplates"
   targetdir "../../testTemplates"
   debugdir "../../testTemplates"
   files {
      "../../testTemplates/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- testTimer
project "testTimer"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testTimer"
   targetdir "../../testTimer"
   debugdir "../../testTimer"
   files {
      "../../testTimer/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- test: general test of several base and graphics functionalities
project "test"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "test"
   targetdir "../../test"
   debugdir "../../test"
   files {
      "../../test/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_base", "mixr_graphics"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d", "mixr_graphics_d"}
      links {LibWindows}

-- testVmap - test VMAP0 loader library
project "testVmap"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "testVmap"
   targetdir "../../testVmap"
   debugdir "../../testVmap"
   files {
      "../../testVmap/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_map_vpf", "mixr_instruments", "mixr_ui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_map_vpf_d", "mixr_instruments_d", "mixr_ui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}
