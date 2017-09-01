--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2013     (Visual Studio 2013)
--     vs2015     (Visual Studio 2015)
--     vs2017     (Visual Studio 2017)
--

-- we must have an ide/compiler specified
if (_ACTION == nil) then
  return
end

--
-- directory locations for framework and 3rd party dependencies
--
MIXR_ROOT           = "../../../mixr"
MIXR_3RD_PARTY_ROOT = "../../../mixr-3rdparty"

--
-- set include and library paths
--
MIXR_IncPath         = MIXR_ROOT.."/include"
MIXR_LibPath         = MIXR_ROOT.."/lib/"
MIXR_3rdPartyIncPath = MIXR_3RD_PARTY_ROOT.."/include"
MIXR_3rdPartyLibPath = MIXR_3RD_PARTY_ROOT.."/lib/".._ACTION.."-32"
MIXR_ExamplesIncPath = "../../shared"
MIXR_ExamplesLibPath = "../../lib/"
print ("MIXR Paths:")
print ("  Include   : "..MIXR_IncPath)
print ("  Libraries : "..MIXR_LibPath)
print ("MIXR 3rdParty Paths:")
print ("  Include   :"..MIXR_3rdPartyIncPath)
print ("  Libraries :"..MIXR_3rdPartyLibPath)
print ("MIXR Examples Paths:")
print ("  Include   :"..MIXR_ExamplesIncPath)
print ("  Libraries :"..MIXR_ExamplesLibPath)

--
-- directory location for HLA include and library paths
--
HLA_ROOT = "../../../openrti"
HLAIncPath = HLA_ROOT.."/include"
HLALibPath = HLA_ROOT.."/lib"
print ("HLA Paths:")
print ("  Include   : "..HLALibPath)
--print ("  Libraries : "..MIXR_LibPath)

--
-- 3rd party library names
--
LibCigi       = "ccl_lib"
LibFtgl       = "ftgl"
LibFreetype   = "freetype2"
LibGlut       = "freeglut"

LibCigi_d     = LibCigi.."_d"
LibFtgl_d     = LibFtgl.."_d"
LibFreetype_d = LibFreetype.."_d"
LibGlut_d     = LibGlut.."_d"

LibGLU        = "glu32"
LibGL         = "opengl32"

LibWindows    = {"Ws2_32", "Winmm", "comctl32", "gdi32", "iphlpapi"}

workspace "examples"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

   -- create console application by default
   kind "ConsoleApp"

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Application linked to Multi-threaded DLL)
   --     Debug          (Application linked to Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   -- visual studio options and warnings
   -- /wd4351 (C4351 warning) - disable warning associated with array brace initialization
   -- /wd4996 (C4996 warning) - disable deprecated declarations
   -- /wd4005 (C4005 warning) - disable macro redefinition
   -- /wd4100 (C4100 warning) - disable unreferenced formal parameter
   -- /Oi - generate intrinsic functions
   buildoptions( { "/wd4351", "/wd4996", "/wd4005", "/wd4100", "/Oi" } )

   -- common release configuration flags, symbols and libraries
   filter { "Release" }
		optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags, symbols and libraries
   filter { "Debug" }
      symbols "On"
      targetsuffix "_d"
      defines { "WIN32", "_DEBUG" }

   -- libraries
   dofile "libs.lua"

   -- demos
   dofile "demos.lua"

   -- examples
   dofile "examples.lua"

   -- tests
   dofile "tests.lua"

   -- tutorial
   dofile "tutorials.lua"

   -- gui examples
   dofile "guidemos.lua"

