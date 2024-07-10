mkdir build
cd build
cmake ../
cmake --build .
cd ..
rmdir /S/Q "website/build"
move /Y build website