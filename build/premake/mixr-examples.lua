--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2019     (Visual Studio 2019)
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
MIXR_3rdPartyLibPath = MIXR_3RD_PARTY_ROOT.."/lib/msvc_v142_x64"

MIXR_ExamplesIncPath = "../../shared/include"
MIXR_ExamplesLibPath = "../../shared/lib"

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
LibCigi       = "cigicl"
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

LibOsg        = {"osgdb_txp",
                 "osg161-osg", "osg161-osgAnimation", "osg161-osgDB", "osg161-osgFX", "osg161-osgGA",
                 "osg161-osgManipulator", "osg161-osgParticle", "osg161-osgPresentation",
                 "osg161-osgShadow", "osg161-osgSim", "osg161-osgTerrain", "osg161-osgText",
                 "osg161-osgUI", "osg161-osgUtil", "osg161-osgViewer", "osg161-osgVolume", "osg161-osgWidget",
                 "ot21-OpenThreads"}

LibOsg_d      = {"osgdb_txpd",
                 "osg161-osgd", "osg161-osgAnimationd", "osg161-osgDBd", "osg161-osgFXd", "osg161-osgGAd",
                 "osg161-osgManipulatord", "osg161-osgParticled", "osg161-osgPresentationd",
                 "osg161-osgShadowd", "osg161-osgSimd", "osg161-osgTerraind", "osg161-osgTextd",
                 "osg161-osgUId", "osg161-osgUtild", "osg161-osgViewerd", "osg161-osgVolumed", "osg161-osgWidgetd",
                 "ot21-OpenThreadsd"}

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
   platforms { "x64" }

   -- visual studio options and warnings
   -- /wd4351 (C4351 warning) - disable warning associated with array brace initialization
   -- /wd4996 (C4996 warning) - disable deprecated declarations
   -- /wd4005 (C4005 warning) - disable macro redefinition
   -- /wd4100 (C4100 warning) - disable unreferenced formal parameter
   -- /Oi - generate intrinsic functions
   disablewarnings { "4351",  "4996", "4005", "4100" }
   buildoptions { "/Oi" }

   -- common release configuration flags, symbols and libraries
   filter { "configurations:Release" }
      symbols "Off"
      optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   filter {}

   -- common debug configuration flags, symbols and libraries
   filter { "configurations:Debug" }
      symbols "On"
      targetsuffix "_d"
      defines { "WIN32", "_DEBUG" }

   filter { "platforms:x64" }
      system "Windows"
      architecture "x86_64"

   filter {}

   -- libraries shared between examples
   dofile "shared-libs.lua"

   -- demos
   dofile "demos.lua"

   -- examples
   dofile "examples.lua"

   -- tests
   dofile "tests.lua"

   -- tutorial
   dofile "tutorials.lua"

   -- gui examples
   dofile "gui-demos.lua"

