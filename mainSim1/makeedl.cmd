::
call ..\makedefs.cmd
%mcpp% configs/test0.epp > test0.edl %EPPFLAGS%
%mcpp% configs/test1.epp > test1.edl %EPPFLAGS%
%mcpp% configs/test2.epp > test2.edl %EPPFLAGS%
::%mcpp% configs/test3.epp > test3.edl %EPPFLAGS%
%mcpp% configs/test4.epp > test4.edl %EPPFLAGS%

