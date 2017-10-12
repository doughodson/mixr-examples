echo off
::
:: set path for c-preprocessor
::
set mcpp=..\..\mixr-3rdparty\bin\mcpp.exe
::
:: define c-preprocessor parameters
::
set MIXR_ROOT=../../mixr
set MIXR_DATA_ROOT=../../mixr-data

set EPPFLAGS=^
    -I %MIXR_DATA_ROOT% ^
    -I %MIXR_ROOT%/../mixr-examples/shared ^
    -I %MIXR_ROOT%/include ^
    -DMIXR_DATA_PATH=\"%MIXR_DATA_ROOT%\" ^
    -DMIXR_DATA_FONT_PATH=\"%MIXR_DATA_ROOT%/fonts/\" ^
    -DMIXR_DATA_FONT_11_19_PATH=\"%MIXR_DATA_ROOT%/fonts/11x19/normal/\" ^
    -DMIXR_DATA_TEXTURES_PATH=\"%MIXR_DATA_ROOT%/textures/\" ^
    -DMIXR_DATA_JSBSIM_PATH=\"%MIXR_DATA_ROOT%/JSBSim/\" ^
    -DMIXR_DATA_VMAP0_PATH=\"%MIXR_DATA_ROOT%/vmap0/v0noa_5/vmaplv0/\" ^
    -DMIXR_DATA_VISUALDB_PATH=\"%MIXR_DATA_ROOT%/visualdb/portland/\" ^
    -DMIXR_DATA_RECORDER_FILE=\"%MIXR_DATA_ROOT%/recorder/zFileWriter.ebd\"
echo on
