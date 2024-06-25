cmake_minimum_required(VERSION 3.22)
project(scc-modules)

# Set minimum C++ version (need 23 for "nodiscard" lambdas)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -march=native -flto")

# Add source directory
add_subdirectory(src)

# Add testing directory
enable_testing()
add_subdirectory(test)
