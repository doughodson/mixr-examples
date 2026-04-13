
source setenv.sh
echo "demoEfis"
cd demoEfis
./demoEfis glutdisplay.edl
echo "demoFlightDisplay1"
cd ../demoFlightDisplays1
./demoFlightDisplays1 test.edl
echo "demoFlightDisplay2"
cd ../demoFlightDisplays2
./demoFlightDisplays2 test.edl
echo "demoInstruments"
cd ../demoInstruments
./demoInstruments testinstruments.edl
echo "demoSubDisplays"
cd ../demoSubDisplays
./demoSubDisplays test.edl
echo "mainCockpit"
cd ../mainCockpit
./mainCockpit test1.edl


