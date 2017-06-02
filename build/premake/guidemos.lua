--------------------------------------------------------
-- GUI examples
--------------------------------------------------------

-- GLUT-based GUI example
project "mainGlut"
   kind "ConsoleApp"
   targetname "mainGlut"
   targetdir "../../mainGlut"
   debugdir "../../mainGlut"
   files {
      "../../mainGlut/**.h*",
      "../../mainGlut/**.cpp",
      "../../mainGlut/**.epp",
      "../../mainGlut/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {LibFtgl, LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {LibFtgl_d, LibFreetype_d, LibGlut_d, LibGLU, LibGL}
      links {LibWindows}

