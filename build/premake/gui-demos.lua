--------------------------------------------------------
-- GUI examples
--------------------------------------------------------

-- GLUT-based GUI example
project "mainGlut"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "mainGlut"
   targetdir "../../mainGlut"
   debugdir "../../mainGlut"
   files {
      "../../mainGlut/**.h*",
      "../../mainGlut/**.cpp",
      "../../mainGlut/**.epp",
      "../../mainGlut/**.edl"
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

