@REM Build script file for Windows
mkdir build
cd build
cmake ../
cmake --build .
cd ..
rmdir /S/Q "website/build"
move /Y build website
type NUL > website/build/__init__.py