--------------------------------------------------------
-- Tutorial applications
--------------------------------------------------------

-- tutorial01
project "tutorial01"
   targetname "tutorial01"
   targetdir "../../tutorial01"
   debugdir "../../tutorial01"
   files {
      "../../tutorial01/**.h*",
      "../../tutorial01/**.cpp",
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

-- tutorial02
project "tutorial02"
   targetname "tutorial02"
   targetdir "../../tutorial02"
   debugdir "../../tutorial02"
   files {
      "../../tutorial02/**.h*",
      "../../tutorial02/**.cpp",
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

-- tutorial03
project "tutorial03"
   targetname "tutorial03"
   targetdir "../../tutorial03"
   debugdir "../../tutorial03"
   files {
      "../../tutorial03/**.h*",
      "../../tutorial03/**.cpp",
      "../../tutorial03/**.epp",
      "../../tutorial03/**.edl"
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

-- tutorial04
project "tutorial04"
   targetname "tutorial04"
   targetdir "../../tutorial04"
   debugdir "../../tutorial04"
   files {
      "../../tutorial04/**.h*",
      "../../tutorial04/**.cpp",
      "../../tutorial04/**.epp",
      "../../tutorial04/**.edl"
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

-- tutorial05
project "tutorial05"
   targetname "tutorial05"
   targetdir "../../tutorial05"
   debugdir "../../tutorial05"
   files {
      "../../tutorial05/**.h*",
      "../../tutorial05/**.cpp",
      "../../tutorial05/**.epp",
      "../../tutorial05/**.edl"
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

-- tutorial06
project "tutorial06"
   targetname "tutorial06"
   targetdir "../../tutorial06"
   debugdir "../../tutorial06"
   files {
      "../../tutorial06/**.h*",
      "../../tutorial06/**.cpp",
      "../../tutorial06/**.epp",
      "../../tutorial06/**.edl"
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

-- tutorial07
project "tutorial07"
   targetname "tutorial07"
   targetdir "../../tutorial07"
   debugdir "../../tutorial07"
   files {
      "../../tutorial07/**.h*",
      "../../tutorial07/**.cpp",
      "../../tutorial07/**.epp",
      "../../tutorial07/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {"ftgl", LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {"ftgl_d", "freetype2_d", "freeglut_d"}
      links {"glu32", "opengl32"}
      links {LibWindows}

-- tutorial08
project "tutorial08"
   targetname "tutorial08"
   targetdir "../../tutorial08"
   debugdir "../../tutorial08"
   files {
      "../../tutorial08/**.h*",
      "../../tutorial08/**.cpp",
      "../../tutorial08/**.epp",
      "../../tutorial08/**.edl"
   }
   includedirs { MXRP_IncPath, MXRP_3rdPartyIncPath }
   libdirs     { MXRP_LibPath, MXRP_3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "configurations:Release*"
      links {"mxrp_gui_glut", "mxrp_instruments", "mxrp_graphics", "mxrp_base"}
      links {"ftgl", LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug*"
      links {"mxrp_gui_glut_d", "mxrp_instruments_d", "mxrp_graphics_d", "mxrp_base_d"}
      links {"ftgl_d", "freetype2_d", "freeglut_d"}
      links {"glu32", "opengl32"}
      links {LibWindows}

