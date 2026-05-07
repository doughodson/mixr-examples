source setenv.sh
cd testRecordData
echo "testRecordData -f test.edl"
./testRecordData -f test.edl
cd ../testRecorderRead
echo "testRecorderRead -f test.edl"
./testRecordRead -f test.edl
cd ../testRecorderWrite
echo "testRecorderWrite -f test.edl"
./testRecorderWrite -f test.edl

