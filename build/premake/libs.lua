--------------------------------------------------------------------------------
-- creating the example libraries
--------------------------------------------------------------------------------

    --  eXample UBF behaviors library
    project "libxbehaviors"
      kind "StaticLib"
      targetname "xbehaviors"
      targetdir (MIXR_ExamplesLibPath)
      includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
      files {
         "../../shared/xbehaviors/*.h*",
         "../../shared/xbehaviors/*.cpp",
      }
      defines { "_LIB" }

    --  eXample library that extends the data recorder
    project "libxrecorder"
      kind "StaticLib"
      includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
      targetname "xrecorder"
      targetdir (MIXR_ExamplesLibPath)
      files {
         "../../shared/xrecorder/**.h*",
         "../../shared/xrecorder/**.cpp",
         "../../shared/xrecorder/**.cc",
         "../../shared/xrecorder/**.proto",
      }
      defines { "_LIB" }
      defines { "_SCL_SECURE_NO_WARNINGS" } -- suppress protocol buffer warning

    --  eXample Panel library -- common instrument panel code for several examples
    project "libxpanel"
      kind "StaticLib"
      targetname "xpanel"
      targetdir (MIXR_ExamplesLibPath)
      includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
      files {
         "../../shared/xpanel/*.h*",
         "../../shared/xpanel/*.cpp",
         "../../shared/xpanel/**.epp",
      }
      defines { "_LIB" }

    --  eXample ZeroMQ network handlers
    project "libxzmq"
      kind "StaticLib"
      targetname "xzmq"
      targetdir (MIXR_ExamplesLibPath)
      includedirs { MIXR_IncPath, MIXR_3rdPartyIncPath, MIXR_ExamplesIncPath }
      defines { "ZMQ_STATIC" }
      files {
         "../../shared/xzmq/*.h*",
         "../../shared/xzmq/*.cpp",
         "../../shared/xzmq/**.epp",
      }
      defines { "_LIB" }
