cmake_minimum_required(VERSION 3.5)

project(beerGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.14.1/")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(../include)

SET(UI_RESOURCES
    ./src/beerGame/res.qrc
)

#googletest part 


configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


#Qt5 part

QT5_ADD_RESOURCES(UI_RESOURCES_RCC ${UI_RESOURCES})


add_executable(beergame
        ./src/beerGame/main.cpp
        ./src/beerGame/playerScreen.ui
        ./src/beerGame/playerScreen.cpp
        ./src/beerGame/playerScreen.h
        ./src/Player.cpp
        ./src/Instructor.cpp
        ./src/PlayerEvent.cpp
        ./src/Order.cpp
        ./src/Shipment.cpp
        ./src/Game.cpp
        ./src/beerGame/instructorscreen.cpp
        ./src/beerGame/instructorscreen.h
        ./src/beerGame/instructorscreen.ui
        ./src/beerGame/instructorwelcome.ui
        ./src/beerGame/instructorwelcome.cpp
        ./src/beerGame/instructorwelcome.h
        ./src/beerGame/instructorLogin.ui
        ./src/beerGame/instructorLogin.cpp
        ./src/beerGame/instructorLogin.h
        ./src/beerGame/loginscreen.ui
        ./src/beerGame/loginscreen.cpp
        ./src/beerGame/loginscreen.h
        ./src/beerGame/playerlogin.ui
        ./src/beerGame/playerlogin.cpp
        ./src/beerGame/playerlogin.h
  ${UI_RESOURCES_RCC}
)

add_executable(beergame-tests
        ./src/tests.cpp
        ./src/Player.cpp
        ./src/Instructor.cpp
        ./src/PlayerEvent.cpp
        ./src/Order.cpp
        ./src/Shipment.cpp
        ./src/Game.cpp
)


target_link_libraries(beergame Qt5::Widgets)
target_link_libraries(beergame-tests gtest_main)


#Doxygen part
# check if Doxygen is installed
find_package(Doxygen)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(
        doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/build/doc/html/index.html
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Automatic Documentation with Doxygen"
        VERBATIM)

else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
