# src/CMakeLists.txt

# Add include
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Add executable
add_executable(smodule ${SOURCES} main.cpp)