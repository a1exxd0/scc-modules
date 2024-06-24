# SCC Module System
An alternative to the standard modulecmd, using C++, with no TCL.

# Why?
We needed flavours to work, but it was buggy and written in TCL and Perl.
It didn't seem too complicated to do so why not?

# Dependencies
CTest requires you to have the Google Test framework installed. If you haven't already,
run to install it:
```sh
sudo apt-get update
sudo apt-get install libgtest-dev
```

# Quick build
Navigate into the project root directory, and run:
```sh
mkdir build
cd build && cmake ..
cmake --build . --config release

# Verify installation
ctest
```
The final executable will be:
```sh
${PROJECT_SOURCE_DIR}/src/smodule
```