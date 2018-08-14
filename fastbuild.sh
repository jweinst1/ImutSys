# For running in one command
mkdir -p build
cd build
cmake ..
make
./CopperTests
cd ..
rm -rf build
