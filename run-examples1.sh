
source setenv.sh
cd demoEfis; make run; cd ..
cd demoFlightDisplays1; make run; cd ..
cd demoFlightDisplays2; make run; cd ..
cd ../demoSubDisplays
echo "demoSubDisplays -f test.edl"
./demoSubDisplays -f test.edl
cd ../mainCockpit
echo "mainCockpit -f test1.edl"
./mainCockpit -f test1.edl
cd ../mainGlut
echo "mainGlut -f alignmentPattern.edl"
./mainGlut -f alignmentPattern.edl
echo "mainGlut -f textDisplay.edl"
./mainGlut -f textDisplay.edl
cd ../mainGndMapRdr
echo "mainGndMapRdr -f test.edl"
./mainGndMapRdr -f test.edl
cd ../mainIgViewer
echo "mainIgViewer -f test.edl"
./mainIgViewer -f test.edl
cd ../mainLaero
echo "mainLaero -f test.edl"
./mainLaero -f test.edl
cd ../mainNonRT1
echo "mainNonRT1 -f test1.edl"
./mainNonRT1 -f test1.edl
echo "mainNonRT1 -f test2.edl"
./mainNonRT1 -f test2.edl
cd ../mainPuzzle1
echo "mainPuzzle1 -f puzzle.edl"
./mainPuzzle1 -f puzzle.edl
cd ../mainPuzzle2
echo "mainPuzzle2 -f puzzle.edl"
./mainPuzzle2 -f puzzle.edl
cd ../mainSim1
echo "mainSim1 -f test0.edl"
./mainSim1 -f test0.edl
echo "mainSim1 -f test1.edl"
./mainSim1 -f test1.edl
echo "mainSim1 -f test2.edl"
./mainSim1 -f test2.edl
echo "mainSim1 -f test3.edl"
./mainSim1 -f test3.edl
echo "mainSim1 -f test4.edl"
./mainSim1 -f test4.edl
cd ../mainSim2
echo "mainSim2 -f test0.edl"
./mainSim2 -f test0.edl
cd ../mainSim3
echo "mainSim3 -f test.edl"
./mainSim3 -f test.edl

