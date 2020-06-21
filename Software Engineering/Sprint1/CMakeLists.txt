cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(beergame-tests tests.cpp src/Instructor.cpp src/Instructor.h src/Player.cpp src/Player.h src/Factory.cpp src/Factory.h src/Order.cpp src/Order.h src/Game.cpp src/Game.h)
target_link_libraries(beergame-tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)