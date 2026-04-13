
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


