::
call ..\makedefs.cmd
%mcpp% configs/alignmentPattern.epp > alignmentPattern.edl %EPPFLAGS%
%mcpp% configs/testDisplay.epp > testDisplay.edl %EPPFLAGS%
