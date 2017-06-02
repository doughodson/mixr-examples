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
MXRP_ROOT           = "../../../mxrp"
MXRP_3RD_PARTY_ROOT = "../../../mxrp-3rdparty"

--
-- set include and library paths
--
MXRP_IncPath         = MXRP_ROOT.."/include"
MXRP_LibPath         = MXRP_ROOT.."/lib/"
MXRP_3rdPartyIncPath = MXRP_3RD_PARTY_ROOT.."/include"
MXRP_3rdPartyLibPath = MXRP_3RD_PARTY_ROOT.."/lib/".._ACTION.."-32"
MXRP_ExamplesIncPath = "../../shared"
MXRP_ExamplesLibPath = "../../lib/"
print ("MXRP Paths:")
print ("  Include   : "..MXRP_IncPath)
print ("  Libraries : "..MXRP_LibPath)
print ("MXRP 3rdParty Paths:")
print ("  Include   :"..MXRP_3rdPartyIncPath)
print ("  Libraries :"..MXRP_3rdPartyLibPath)
print ("MXRP Examples Paths:")
print ("  Include   :"..MXRP_ExamplesIncPath)
print ("  Libraries :"..MXRP_ExamplesLibPath)


--
-- directory location for HLA include and library paths
--
HLA_ROOT = "../../../openrti"
HLAIncPath = HLA_ROOT.."/include"
HLALibPath = HLA_ROOT.."/lib"
print ("HLA Paths:")
print ("  Include   : "..HLALibPath)
--print ("  Libraries : "..MXRP_LibPath)

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
      flags { "Optimize" }
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

