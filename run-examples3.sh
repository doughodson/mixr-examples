source setenv.sh
cd testEvents
echo "testEvents -f testEvents.edl"
./testEvents -f testEvents.edl
cd ../testGraphics
echo "testGraphics -f test1.edl"
./testGraphics -f test1.edl
echo "testGraphics -f test2.edl"
./testGraphics -f test2.edl
cd ../testInfrared
echo "testInfrared -f test1.edl"
./testInfrared -f test1.edl
cd ../testLinearSys
echo "testLinearSys"
./testLinearSys
cd ../testLinkage
echo "testLinkage -f test1.edl"
./testLinkage -f test1.edl

