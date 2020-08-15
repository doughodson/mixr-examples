--------------------------------------------------------------------------------
-- creating the example libraries
--------------------------------------------------------------------------------

--  eXample UBF behaviors library
project "libxbehaviors"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   kind "StaticLib"
   targetname "xbehaviors"
   targetdir (MIXR_ExamplesLibPath)
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   files {
      "../../shared/include/shared/xbehaviors/*.h*",
      "../../shared/src/xbehaviors/*.cpp",
   }
   defines { "_LIB" }

--  eXample library that extends the data recorder
project "libxrecorder"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   kind "StaticLib"
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   targetname "xrecorder"
   targetdir (MIXR_ExamplesLibPath)
   files {
      "../../shared/include/shared/xrecorder/**.h*",
      "../../shared/src/xrecorder/**.cpp",
      "../../shared/src/xrecorder/**.cc",
      "../../shared/src/xrecorder/**.proto",
   }
   defines { "_LIB" }
   defines { "_SCL_SECURE_NO_WARNINGS" } -- suppress protocol buffer warning

--  eXample Panel library -- common instrument panel code for several examples
project "libxpanel"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   kind "StaticLib"
   targetname "xpanel"
   targetdir (MIXR_ExamplesLibPath)
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   files {
      "../../shared/include/shared/xpanel/*.h*",
      "../../shared/include/shared/xpanel/**.epp",
      "../../shared/src/xpanel/*.cpp",
   }
   defines { "_LIB" }

--  eXample ZeroMQ network handlers
project "libxzmq"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   kind "StaticLib"
   targetname "xzmq"
   targetdir (MIXR_ExamplesLibPath)
   includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
   defines { "ZMQ_STATIC" }
   files {
      "../../shared/include/shared/xzmq/*.h*",
      "../../shared/include/shared/xzmq/**.epp",
      "../../shared/src/xzmq/*.cpp",
   }
   defines { "_LIB" }
