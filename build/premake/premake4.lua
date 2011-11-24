--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2008     (Visual Studio 2008)
--     vs2010     (Visual Studio 2010)
--     codeblocks (Code::Blocks)
--     codelite   (CodeLite)
--

if (_ACTION == nil) then
  return
end

--
-- set library paths based on compiler
--
if (_ACTION == "vs2008") or (_ACTION == "vs2010") then
  OELibPath         = "../../../OpenEaagles/lib/".._ACTION
  OE3rdPartyLibPath = "../../../OpenEaagles3rdParty/lib/".._ACTION.."-32"
end
if (_ACTION == "codelite") or (_ACTION == "codeblocks") then
  OELibPath         = "../../../OpenEaagles/lib/mingw"
  OE3rdPartyLibPath = "../../../OpenEaagles3rdParty/lib/mingw-32"
end
print ("OpenEaagles library path: "..OELibPath)
print ("OpenEaagles 3rd party library path:"..OE3rdPartyLibPath)

solution "examples"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

   -- creating console application
   kind "ConsoleApp"

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Application linked to Multi-threaded DLL)
   --     Debug          (Application linked to Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   -- common release configuration flags and symbols
   configuration { "Release" }
      flags { "Optimize" }
      if (_ACTION == "vs2008") or (_ACTION == "vs2010") then
         -- enable compilier intrinsics and favor speed over size
         buildoptions { "/Oi", "/Ot" }
         defines { "WIN32", "_LIB", "NDEBUG" }
      end

   -- common debug configuration flags and symbols
   configuration { "Debug" }
      flags { "Symbols" }
      if (_ACTION == "vs2008") or (_ACTION == "vs2010") then
         -- enable compilier intrinsics
         buildoptions { "/Oi" }
         defines { "WIN32", "_LIB", "_DEBUG" }
      end

   -- examples
   dofile "examples.lua"
   -- tests
   dofile "tests.lua"
   -- tutorial
   dofile "tutorials.lua"
   -- gui demos
   dofile "guidemos.lua"
