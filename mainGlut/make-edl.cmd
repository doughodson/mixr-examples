::
call ..\makedefs.cmd
%mcpp% configs/alignmentPattern.epp > alignmentPattern.edl %EPPFLAGS%
%mcpp% configs/textDisplay.epp > textDisplay.edl %EPPFLAGS%
