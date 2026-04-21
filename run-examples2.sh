source setenv.sh
cd mainSim2
echo "mainSim2 -f test0.edl"
./mainSim2 -f test0.edl
cd ../mainSim3
echo "mainSim3 -f test.edl"
./mainSim3 -f test.edl
cd ../mainTerrain
echo "mainTerrain -f test.edl"
./mainTerrain -f test.edl
cd ../mainUbf1
echo "mainUbf1 -f test00.edl"
./mainUbf1 -f test00.edl
cd ../testDafif
echo "testDafif"
./testDafif

