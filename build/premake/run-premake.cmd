rem
rem delete old solution/workspace files
rem
rmdir /S /Q ..\gmake
rmdir /S /Q ..\vs2019
rmdir /S /Q ..\obj
rem
rem delete old shared example libraries
rem
rem rmdir /S /Q ..\..\shared\lib
rem
rem delete old compiled libraries
rem
del ..\..\lib\*.lib
rem
rem create solution/workspace files
rem
premake5-alpha16.exe --os=windows --file=mixr-examples.lua vs2019
