--------------------------------------------------------
-- Demo applications
--------------------------------------------------------

-- demoEfis: demo of EFIS
project "demoEfis"
   targetname "demoEfis"
   targetdir "../../demoEfis"
   debugdir "../../demoEfis"
   files {
      "../../demoEfis/**.h*",
      "../../demoEfis/**.cpp",
      "../../demoEfis/**.epp",
      "../../demoEfis/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Flight Display 1 demo
project "demoFlightDisplays1"
   targetname "demoFlightDisplays1"
   targetdir "../../demoFlightDisplays1"
   debugdir "../../demoFlightDisplays1"
   files {
      "../../demoFlightDisplays1/**.h*",
      "../../demoFlightDisplays1/**.cpp",
      "../../demoFlightDisplays1/**.epp",
      "../../demoFlightDisplays1/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- Flight Display 2 demo
project "demoFlightDisplays2"
   targetname "demoFlightDisplays2"
   targetdir "../../demoFlightDisplays2"
   debugdir "../../demoFlightDisplays2"
   files {
      "../../demoFlightDisplays2/**.h*",
      "../../demoFlightDisplays2/**.cpp",
      "../../demoFlightDisplays2/**.epp",
      "../../demoFlightDisplays2/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- demoInstruments
project "demoInstruments"
   targetname "demoInstruments"
   targetdir "../../demoInstruments"
   debugdir "../../demoInstruments"
   files {
      "../../demoInstruments/**.h*",
      "../../demoInstruments/**.cpp",
      "../../demoInstruments/**.epp",
      "../../demoInstruments/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

-- demoSubDisplays
project "demoSubDisplays"
   targetname "demoSubDisplays"
   targetdir "../../demoSubDisplays"
   debugdir "../../demoSubDisplays"
   files {
      "../../demoSubDisplays/**.h*",
      "../../demoSubDisplays/**.cpp",
      "../../demoSubDisplays/**.epp",
      "../../demoSubDisplays/**.edl"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

