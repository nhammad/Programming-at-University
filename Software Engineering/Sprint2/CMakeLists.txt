cmake_minimum_required(VERSION 3.10 FATAL_ERROR)


set(CMAKE_C_COMPILER gcc)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${MAKE_CXX_FLAGS} -std=c++0x")

project(beergame C CXX)


set(SOURCES
  src/player.cpp
  src/game.cpp
  src/playerEvent.cpp
  src/main.cpp
  src/instructor.cpp
  src/shipment.cpp
  src/order.cpp
)

set(HEADERS
  src/player.h
  src/game.h
  src/playerEvent.h
  src/instructor.h
  src/order.h
  src/shipment.h
)

set(TESTSOURCES
  test/tests-mainfunctionality-v2.cpp
  src/game.cpp
  src/instructor.cpp
  src/playerEvent.cpp
  src/player.cpp
  src/shipment.cpp
  src/order.cpp
)

add_executable(
  beergame-cli
  ${SOURCES}
)


set(GUIFILE
src/gui/create_game.cpp
src/gui/create_game.h
src/gui/create_game.ui
src/gui/game.cpp
src/gui/game.h
src/gui/game.ui
src/gui/info_sharing.h
src/gui/info_sharing.cpp
src/gui/info_sharing.ui
src/gui/instructor.cpp
src/gui/instructor.h
src/gui/instructor.ui
src/gui/instructors_dashboard.cpp
src/gui/instructors_dashboard.h
src/gui/instructors_dashboard.ui
src/gui/main.cpp
src/gui/mainwindow.cpp
src/gui/mainwindow.h
src/gui/mainwindow.ui
src/gui/order.cpp
src/gui/order.h
src/gui/player_password.cpp
src/gui/player_password.h
src/gui/player_password.ui
src/gui/player.cpp
src/gui/player.ui
src/gui/players_playing.cpp
src/gui/players_playing.h
src/gui/players_playing.ui
src/gui/print_passwords.cpp
src/gui/print_passwords.h
src/gui/print_passwords.ui
src/gui/resource.qrc
src/gui/img/new.jpg
)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(CURL REQUIRED)
qt5_add_resources(resource.qrc)
add_executable(beergame ${GUIFILE})
target_link_libraries(beergame PRIVATE Qt5::Widgets)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#if(CMAKE_COMPILER_IS_GNUCC)
#    add_definitions(-Wall -Werror -lcurl)
#endif(CMAKE_COMPILER_IS_GNUCC)

add_executable(beergame-tests ${TESTSOURCES} ${HEADERS} )
target_link_libraries(beergame-tests curl Qt5::Widgets ${GTEST_LIBRARIES} pthread)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(CURL REQUIRED)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.doxygen)

    # request to configure the file
   configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
       COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/build/doc/html/index.html
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
 message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
