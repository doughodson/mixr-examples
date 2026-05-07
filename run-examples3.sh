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
cd ../testMatrix
echo "testMatrix"
./testMatrix
cd ../testMetaObject
echo "testMetaObject"
./testMetaObject
cd ../testNavUtils
echo "testNavUtils"
./testNavUtils
#cd ../testNetHandler
#echo "testNetHandler"
./testNetHandler
cd ../testRadar
echo "testRadar -f test1.edl"
./testRadar -f test1.edl
echo "testRadar -f test2a.edl"
./testRadar -f test2a.edl
echo "testRadar -f test2b.edl"
./testRadar -f test2b.edl
echo "testRadar -f test2c.edl"
./testRadar -f test2c.edl
echo "testRadar -f test3a.edl"
./testRadar -f test3a.edl
echo "testRadar -f test3b.edl"
./testRadar -f test3b.edl
echo "testRadar -f test4a.edl"
./testRadar -f test4a.edl
echo "testRadar -f test4b.edl"
./testRadar -f test4b.edl
echo "testRadar -f test4c.edl"
./testRadar -f test4c.edl

