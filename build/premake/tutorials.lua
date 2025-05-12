--------------------------------------------------------
-- Tutorial applications
--------------------------------------------------------

-- tutorial01
project "tutorial01"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial01"
   targetdir "../../tutorial01"
   debugdir "../../tutorial01"
   files {
      "../../tutorial01/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial02
project "tutorial02"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial02"
   targetdir "../../tutorial02"
   debugdir "../../tutorial02"
   files {
      "../../tutorial02/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial03
project "tutorial03"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial03"
   targetdir "../../tutorial03"
   debugdir "../../tutorial03"
   files {
      "../../tutorial03/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial04
project "tutorial04"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial04"
   targetdir "../../tutorial04"
   debugdir "../../tutorial04"
   files {
      "../../tutorial04/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial05
project "tutorial05"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial05"
   targetdir "../../tutorial05"
   debugdir "../../tutorial05"
   files {
      "../../tutorial05/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial06
project "tutorial06"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial06"
   targetdir "../../tutorial06"
   debugdir "../../tutorial06"
   files {
      "../../tutorial06/**"
   }
   includedirs { MIXR_IncPath }
   libdirs     { MIXR_LibPath }
   filter "configurations:Release"
      links {"mixr_base"}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_base_d"}
      links {LibWindows}

-- tutorial07
project "tutorial07"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial07"
   targetdir "../../tutorial07"
   debugdir "../../tutorial07"
   files {
      "../../tutorial07/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {"ftgl", LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {"ftgl_d", "freetype2_d", "freeglut_d"}
      links {"glu32", "opengl32"}
      links {LibWindows}

-- tutorial08
project "tutorial08"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "tutorial08"
   targetdir "../../tutorial08"
   debugdir "../../tutorial08"
   files {
      "../../tutorial08/**"
   }
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath }
   libdirs     { MIXR_LibPath, MIXR_3rdPartyLibPath }
   filter "configurations:Release"
      links {"mixr_ui_glut", "mixr_instruments", "mixr_graphics", "mixr_base"}
      links {"ftgl", LibFreetype, LibGlut, LibGLU, LibGL}
      links {LibWindows}
   filter "configurations:Debug"
      links {"mixr_ui_glut_d", "mixr_instruments_d", "mixr_graphics_d", "mixr_base_d"}
      links {"ftgl_d", "freetype2_d", "freeglut_d"}
      links {"glu32", "opengl32"}
      links {LibWindows}
