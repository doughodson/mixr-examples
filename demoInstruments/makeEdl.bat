rem
call ..\makedefs.bat
rem
%mcpp% configs/testinstruments.epp > testinstruments.edl ^
 -I ..\..\mxrp\include ^
 -I ..\shared\data ^
 -DFONT_PATH="\"../shared/data/fonts/\"
