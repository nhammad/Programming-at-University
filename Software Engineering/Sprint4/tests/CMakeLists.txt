#
# /test/CMakeLists.txt --
#

# Making sure that the version of cmake we are using is correct
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Including the main build directory
include_directories(${CMAKE_SOURCE_DIR})

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find the QtTest library
find_package(Qt5 COMPONENTS Widgets Network Charts WebEngineWidgets Sql CONFIG REQUIRED)
qt5_add_resources(RESOURCES ../src/frontend/resource.qrc)

# Populate two CMake variables with the sources
set(test_SRCS tests.cpp)

set(project_SRCS 
    ../src/backend/game.cpp
    ../src/backend/instructor.cpp
    ../src/backend/order.cpp
    ../src/backend/player.cpp
    ../src/backend/playerevent.cpp
    ../src/backend/shipment.cpp
    ../src/frontend/playerdialog.cpp
    ../src/frontend/mainwindow.cpp
    ../src/frontend/instructordialog.cpp
    ../src/frontend/resource.qrc
    )

add_executable(beergame-tests ${test_SRCS} ${project_SRCS} ${RESOURCES})

# set_target_properties(beergame-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

target_link_libraries(beergame-tests Qt5::Widgets Qt5::Charts Qt5::WebEngineWidgets Qt5::Sql ${GTEST_LIBRARIES} pthread)

set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
