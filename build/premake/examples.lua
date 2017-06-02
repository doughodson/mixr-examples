--------------------------------------------------------
-- Example applications
--------------------------------------------------------

-- Simple cockpit
project "mainCockpit"
   kind "ConsoleApp"
   targetname "mainCockpit"
   targetdir "../../mainCockpit"
   debugdir "../../mainCockpit"
   files {
      "../../mainCockpit/**.h*",
      "../../mainCockpit/**.cpp",
      "../../mainCockpit/**.epp",
      "../../mainCockpit/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath, MXRP_ExamplesIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath, MXRP_ExamplesLibPath }
   links       { "libxPanel" }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim", "libzmq"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_interop_dis", "mxrp_interop", "mxrp_recorder", "mxrp_iodevice"}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {"libprotobuf"}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d", "libzmq_d"}
      links {"mxrp_otw_d",  LibCigi_d}
      links {"mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_recorder_d", "mxrp_iodevice_d"}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {"libprotobuf_d" }
      links {LibWindows}

-- Ground Mapping Radar example
project "mainGndMapRdr"
   kind "ConsoleApp"
   targetname "mainGndMapRdr"
   targetdir "../../mainGndMapRdr"
   debugdir "../../mainGndMapRdr"
   files {
      "../../mainGndMapRdr/**.h*",
      "../../mainGndMapRdr/**.cpp",
      "../../mainGndMapRdr/**.epp",
      "../../mainGndMapRdr/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "mxrp_simulation", "JSBSim", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "mxrp_simulation_d", "JSBSim_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- mainLaero example
project "mainLaero"
   kind "ConsoleApp"
   targetname "mainLaero"
   targetdir "../../mainLaero"
   debugdir "../../mainLaero"
   files {
      "../../mainLaero/**.h*",
      "../../mainLaero/**.cpp",
      "../../mainLaero/**.epp",
      "../../mainLaero/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim", "libzmq" }
      links {"mxrp_interop_dis", "mxrp_interop", "mxrp_iodevice"}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d", "libzmq_d" }
      links {"mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_iodevice_d"}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Non-RealTime 1 example
project "mainNonRT1"
   kind "ConsoleApp"
   targetname "mainNonRT1"
   targetdir "../../mainNonRT1"
   debugdir "../../mainNonRT1"
   files {
      "../../mainNonRT1/**.h*",
      "../../mainNonRT1/**.cpp",
      "../../mainNonRT1/**.epp",
      "../../mainNonRT1/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d"}
      links {"mxrp_otw_d", LibCigi_d}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Puzzle 1 example
project "mainPuzzle1"
   targetname "mainPuzzle1"
   targetdir "../../mainPuzzle1"
   debugdir "../../mainPuzzle1"
   files {
      "../../mainPuzzle1/**.h*",
      "../../mainPuzzle1/**.cpp",
      "../../mainPuzzle1/**.epp",
      "../../mainPuzzle1/**.edl"
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

-- Puzzle 2 example
project "mainPuzzle2"
   targetname "mainPuzzle2"
   targetdir "../../mainPuzzle2"
   debugdir "../../mainPuzzle2"
   files {
      "../../mainPuzzle2/**.h*",
      "../../mainPuzzle2/**.cpp",
      "../../mainPuzzle2/**.epp",
      "../../mainPuzzle2/**.edl"
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

 -- simple Simulation 1 example
project "mainSim1"
   targetname "mainSim1"
   targetdir "../../mainSim1"
   debugdir "../../mainSim1"
   files {
      "../../mainSim1/**.h*",
      "../../mainSim1/**.cpp",
      "../../mainSim1/**.epp",
      "../../mainSim1/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim", "libzmq"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_interop_dis", "mxrp_interop"}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d", "libzmq_d"}
      links {"mxrp_otw_d", LibCigi_d}
      links {"mxrp_interop_dis_d", "mxrp_interop_d"}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- simple Simulation 2 example
project "mainSim2"
   targetname "mainSim2"
   targetdir "../../mainSim2"
   debugdir "../../mainSim2"
   files {
      "../../mainSim2/**.h*",
      "../../mainSim2/**.cpp",
      "../../mainSim2/**.epp",
      "../../mainSim2/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_models", "JSBSim", "libzmq"}
      links {"mxrp_otw", LibCigi}
      links {"mxrp_interop_dis", "mxrp_interop", "mxrp_iodevice"}
      links {"mxrp_simulation", "mxrp_terrain"}
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_models_d", "JSBSim_d", "libzmq_d"}
      links {"mxrp_otw_d", LibCigi_d}
      links {"mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_iodevice_d"}
      links {"mxrp_simulation_d", "mxrp_terrain_d"}
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- simple Simulation 3 example
project "mainSim3"
   targetname "mainSim3"
   targetdir "../../mainSim3"
   debugdir "../../mainSim3"
   files {
      "../../mainSim3/**.h*",
      "../../mainSim3/**.cpp",
      "../../mainSim3/**.epp",
      "../../mainSim3/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   -- zeromq nethandlers
   defines { "ZMQ_STATIC" }
   links { "libxzmq" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links { "mxrp_models", "JSBSim", "libzmq" }
      links { "mxrp_otw", LibCigi }
      links { "mxrp_interop_dis", "mxrp_interop", LibCigi }
      links { "mxrp_simulation", "mxrp_terrain" }
      links { "mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base" }
      links { LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL }
      links { LibWindows }
   filter "configurations:Debug*"
      links { "mxrp_models_d", "JSBSim_d", "libzmq_d" }
      links { "mxrp_otw_d", LibCigi_d }
      links { "mxrp_interop_dis_d", "mxrp_interop_d" }
      links { "mxrp_simulation_d", "mxrp_terrain_d" }
      links { "mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d" }
      links { LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL }
      links { LibWindows }

-- Terrain loading example
project "mainTerrain"
   targetname "mainTerrain"
   targetdir "../../mainTerrain"
   debugdir "../../mainTerrain"
   files {
      "../../mainTerrain/**.h*",
      "../../mainTerrain/**.cpp",
      "../../mainTerrain/**.epp",
      "../../mainTerrain/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_terrain", "mxrp_simulation"}
      links {"mxrp_gui_glut", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_terrain_d", "mxrp_simulation_d"}
      links {"mxrp_gui_glut_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- mainUbf1
project "mainUbf1"
   targetname "mainUbf1"
   targetdir "../../mainUbf1"
   debugdir "../../mainUbf1"
   files {
      "../../mainUbf1/**.h*",
      "../../mainUbf1/**.cpp",
      "../../mainUbf1/**.epp",
      "../../mainUbf1/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath, MXRP_ExamplesIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath, MXRP_ExamplesLibPath }
   links { "libxbehaviors",  "libxpanel" }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links { "mxrp_models", "JSBSim" }
      links { "mxrp_otw", LibCigi }
      links { "mxrp_interop_dis", "mxrp_interop", "mxrp_iodevice" }
      links { "mxrp_simulation", "mxrp_terrain" }
      links { "mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base" }
      links { LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL }
      links { LibWindows }
   filter "configurations:Debug*"
      links { "mxrp_models_d", "JSBSim_d" }
      links { "mxrp_otw_d", LibCigi_d }
      links { "mxrp_interop_dis_d", "mxrp_interop_d", "mxrp_iodevice_d" }
      links { "mxrp_simulation_d", "mxrp_terrain_d" }
      links { "mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d" }
      links { LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL }
      links { LibWindows }
