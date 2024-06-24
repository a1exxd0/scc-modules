# test/CMakeLists.txt

# Include the main source directory to access headers
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Find the testing framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(fake_test ${SOURCES} fake_test.cpp )
target_link_libraries(fake_test ${GTEST_LIBRARIES} pthread)
add_test(NAME fake_test COMMAND fake_test)