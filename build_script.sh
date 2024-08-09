# Build script file for Mac/Linux systems
mkdir build
cd build
cmake ../
cmake --build .
cd ..
rm -rf "website/build"
mv build website
