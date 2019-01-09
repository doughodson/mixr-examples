--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
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

LibOsg        = {"osgdb_txp",
                 "osg131-osg", "osg131-osgAnimation", "osg131-osgDB", "osg131-osgFX", "osg131-osgGA",
                 "osg131-osgManipulator", "osg131-osgParticle", "osg131-osgPresentation",
                 "osg131-osgShadow", "osg131-osgSim", "osg131-osgTerrain", "osg131-osgText",
                 "osg131-osgUI", "osg131-osgUtil", "osg131-osgViewer", "osg131-osgVolume", "osg131-osgWidget",
                 "ot20-OpenThreads"}

LibOsg_d      = {"osgdb_txpd",
                 "osg131-osgd", "osg131-osgAnimationd", "osg131-osgDBd", "osg131-osgFXd", "osg131-osgGAd",
                 "osg131-osgManipulatord", "osg131-osgParticled", "osg131-osgPresentationd",
                 "osg131-osgShadowd", "osg131-osgSimd", "osg131-osgTerraind", "osg131-osgTextd",
                 "osg131-osgUId", "osg131-osgUtild", "osg131-osgViewerd", "osg131-osgVolumed", "osg131-osgWidgetd",
                 "ot20-OpenThreadsd"}

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
   disablewarnings { "4351",  "4996", "4005", "4100" }
   buildoptions { "/Oi" }

   -- common release configuration flags, symbols and libraries
   filter { "configurations:Release" }
      optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags, symbols and libraries
   filter { "configurations:Debug" }
      symbols "On"
      targetsuffix "_d"
      defines { "WIN32", "_DEBUG" }

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
   dofile "guidemos.lua"

