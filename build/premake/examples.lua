--------------------------------------------------------
-- Example applications
--------------------------------------------------------

-- Simple cockpit
project "mainCockpit"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainCockpit"
   targetdir "../../mainCockpit"
   debugdir "../../mainCockpit"
   files {
      "../../mainCockpit/**.h*",
      "../../mainCockpit/**.cpp",
      "../../mainCockpit/**.epp",
      "../../mainCockpit/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links       { "libxPanel" }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release"
      links {"mixr_models", "JSBSim", "libzmq"}
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear", "mixr_ighost_pov" }
      links {"mixr_interop_dis", "mixr_interop", "mixr_recorder", "mixr_linkage"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {"libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "JSBSim_d", "libzmq_d"}
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d", "mixr_ighost_pov_d"}
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_recorder_d", "mixr_linkage_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {"libprotobuf_d" }
      links {LibWindows}

-- Ground Mapping Radar example
project "mainGndMapRdr"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainGndMapRdr"
   targetdir "../../mainGndMapRdr"
   debugdir "../../mainGndMapRdr"
   files {
      "../../mainGndMapRdr/**.h*",
      "../../mainGndMapRdr/**.cpp",
      "../../mainGndMapRdr/**.epp",
      "../../mainGndMapRdr/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_models", "mixr_simulation", "JSBSim", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "mixr_simulation_d", "JSBSim_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Image generator viewer (understands flightgear compatible packets)
project "mainIgViewer"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainIgViewer"
   targetdir "../../mainIgViewer"
   debugdir "../../mainIgViewer"
   defines { "OSG_LIBRARY_STATIC" }
   files {
      "../../mainIgViewer/**.h*",
      "../../mainIgViewer/**.cpp",
      "../../mainIgViewer/**.epp",
      "../../mainIgViewer/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_3rdPartyLibPath.."/osgPlugins-3.6.5" }
   filter "configurations:Release"
      links {"mixr_models", "mixr_simulation", "JSBSim", "mixr_terrain"}
      links {"mixr_ighost_pov"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibOsg, LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "mixr_simulation_d", "JSBSim_d", "mixr_terrain_d"}
      links {"mixr_ighost_pov_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibOsg_d, LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- mainLaero example
project "mainLaero"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainLaero"
   targetdir "../../mainLaero"
   debugdir "../../mainLaero"
   files {
      "../../mainLaero/**.h*",
      "../../mainLaero/**.cpp",
      "../../mainLaero/**.epp",
      "../../mainLaero/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   filter "configurations:Release"
      links {"mixr_models", "JSBSim", "libzmq" }
      links {"mixr_interop_dis", "mixr_interop", "mixr_ighost_flightgear", "mixr_ighost_pov"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "JSBSim_d", "libzmq_d" }
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_ighost_flightgear_d", "mixr_ighost_pov_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Non-RealTime 1 example
project "mainNonRT1"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainNonRT1"
   targetdir "../../mainNonRT1"
   debugdir "../../mainNonRT1"
   files {
      "../../mainNonRT1/**.h*",
      "../../mainNonRT1/**.cpp",
      "../../mainNonRT1/**.epp",
      "../../mainNonRT1/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_models", "JSBSim"}
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "JSBSim_d"}
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Puzzle 1 example
project "mainPuzzle1"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainPuzzle1"
   targetdir "../../mainPuzzle1"
   debugdir "../../mainPuzzle1"
   files {
      "../../mainPuzzle1/**.h*",
      "../../mainPuzzle1/**.cpp",
      "../../mainPuzzle1/**.epp",
      "../../mainPuzzle1/**.edl"
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

-- Puzzle 2 example
project "mainPuzzle2"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainPuzzle2"
   targetdir "../../mainPuzzle2"
   debugdir "../../mainPuzzle2"
   files {
      "../../mainPuzzle2/**.h*",
      "../../mainPuzzle2/**.cpp",
      "../../mainPuzzle2/**.epp",
      "../../mainPuzzle2/**.edl"
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

 -- simple Simulation 1 example
project "mainSim1"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainSim1"
   targetdir "../../mainSim1"
   debugdir "../../mainSim1"
   files {
      "../../mainSim1/**.h*",
      "../../mainSim1/**.cpp",
      "../../mainSim1/**.epp",
      "../../mainSim1/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   filter "configurations:Release"
      links {"mixr_models", "JSBSim", "libzmq"}
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear"}
      links {"mixr_interop_dis", "mixr_interop"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "JSBSim_d", "libzmq_d"}
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d"}
      links {"mixr_interop_dis_d", "mixr_interop_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- simple Simulation 2 example
project "mainSim2"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainSim2"
   targetdir "../../mainSim2"
   debugdir "../../mainSim2"
   files {
      "../../mainSim2/**.h*",
      "../../mainSim2/**.cpp",
      "../../mainSim2/**.epp",
      "../../mainSim2/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   filter "configurations:Release"
      links {"mixr_models", "JSBSim", "libzmq"}
      links {"mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear"}
      links {"mixr_interop_dis", "mixr_interop", "mixr_linkage"}
      links {"mixr_simulation", "mixr_terrain"}
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_models_d", "JSBSim_d", "libzmq_d"}
      links {"mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d"}
      links {"mixr_interop_dis_d", "mixr_interop_d", "mixr_linkage_d"}
      links {"mixr_simulation_d", "mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- simple Simulation 3 example
project "mainSim3"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainSim3"
   targetdir "../../mainSim3"
   debugdir "../../mainSim3"
   files {
      "../../mainSim3/**.h*",
      "../../mainSim3/**.cpp",
      "../../mainSim3/**.epp",
      "../../mainSim3/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   filter "configurations:Release"
      links { "mixr_models", "JSBSim", "libzmq"}
      links { "mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear"}
      links { "mixr_interop_dis", "mixr_interop", LibCigi}
      links { "mixr_simulation", "mixr_terrain"}
      links { "mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links { LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links { LibWindows }
   filter "configurations:Debug"
      links { "mixr_models_d", "JSBSim_d", "libzmq_d"}
      links { "mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d"}
      links { "mixr_interop_dis_d", "mixr_interop_d"}
      links { "mixr_simulation_d", "mixr_terrain_d"}
      links { "mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links { LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links { LibWindows }

-- Terrain loading example
project "mainTerrain"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainTerrain"
   targetdir "../../mainTerrain"
   debugdir "../../mainTerrain"
   files {
      "../../mainTerrain/**.h*",
      "../../mainTerrain/**.cpp",
      "../../mainTerrain/**.epp",
      "../../mainTerrain/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_terrain"}
      links {"mixr_ui_glut", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_terrain_d"}
      links {"mixr_ui_glut_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- mainUbf1
project "mainUbf1"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainUbf1"
   targetdir "../../mainUbf1"
   debugdir "../../mainUbf1"
   files {
      "../../mainUbf1/**.h*",
      "../../mainUbf1/**.cpp",
      "../../mainUbf1/**.epp",
      "../../mainUbf1/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath, MIXR_ExamplesLibPath }
   links { "libxbehaviors",  "libxpanel" }
   filter "configurations:Release"
      links { "mixr_models", "JSBSim" }
      links { "mixr_ighost_cigi", LibCigi, "mixr_ighost_flightgear" }
      links { "mixr_interop_dis", "mixr_interop" }
      links { "mixr_simulation", "mixr_terrain" }
      links { "mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base" }
      links { LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL }
      links { LibWindows }
   filter "configurations:Debug"
      links { "mixr_models_d", "JSBSim_d" }
      links { "mixr_ighost_cigi_d", LibCigi_d, "mixr_ighost_flightgear_d" }
      links { "mixr_interop_dis_d", "mixr_interop_d" }
      links { "mixr_simulation_d", "mixr_terrain_d" }
      links { "mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d" }
      links { LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL }
      links { LibWindows }
