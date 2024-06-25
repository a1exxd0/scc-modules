# SCC Module System
An alternative to the standard modulecmd, using C++, with no TCL. It ties in together
a "module load" type system from modulecmd, with flavours. What does this mean for you?

Upon doing a "module avail", you may be presented with 100s of modules, but with a flavours
system, it will only show relevant modules to ones you have already loaded, reducing 100s to
a clear few of the specific modules you require.

This is tested for `ubuntu-latest` and `macos-latest`.
# Why?
We needed flavours to work, but it was buggy and written in TCL and Perl.
It didn't seem too complicated to do so why not?

# Dependencies
CTest requires you to have the Google Test framework installed. If you haven't already,
run to install it for:

**Ubuntu**:
```sh
sudo apt-get update
sudo apt-get install libgtest-dev
```
**RHEL/Rocky**:
```sh
sudo dnf -y update
sudo dnf -y install cmake gtest-devel
```
**MACOS**:
```sh
brew update
brew install cmake
brew install googletest
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
${PROJECT_SOURCE_DIR}/build/src/smodule
```
