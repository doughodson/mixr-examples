
source setenv.sh
echo "demoEfis"
cd demoEfis
./demoEfis -f glutdisplay.edl
echo "demoFlightDisplay1"
cd ../demoFlightDisplays1
./demoFlightDisplays1 -f test.edl
echo "demoFlightDisplay2"
cd ../demoFlightDisplays2
./demoFlightDisplays2 -f test.edl
echo "demoInstruments"
cd ../demoInstruments
./demoInstruments -f testinstruments.edl
echo "demoSubDisplays"
cd ../demoSubDisplays
./demoSubDisplays -f test.edl
echo "mainCockpit"
cd ../mainCockpit
echo "mainCockpit -f test1.edl"
./mainCockpit -f test1.edl
echo "mainGlut"
cd ../mainGlut
./mainGlut -f alignmentPattern.edl
./mainGlut -f textDisplay.edl
echo "mainGndMapRdr"
cd ../mainGndMapRdr
./mainGndMapRdr -f test.edl
echo "mainIgViewer"
cd ../mainIgViewer
./mainIgViewer -f test.edl
echo "mainLaero"
cd ../mainLaero
./mainLaero -f test.edl
echo "mainNonRT1"
cd ../mainNonRT1
echo "mainNonRT1 -f test1.edl"
./mainNonRT1 -f test1.edl
echo "mainNonRT1 -f test2.edl"
./mainNonRT1 -f test2.edl
echo "mainPuzzle1"
cd ../mainPuzzle1
./mainPuzzle1 -f puzzle.edl
echo "mainPuzzle2"
cd ../mainPuzzle2
./mainPuzzle2 -f puzzle.edl

