set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.14.1/gcc_64)
# find_package(Qt5 COMPONENTS Core Gui Widgets Network REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts WebEngineWidgets Sql)

include_directories(backend)
include_directories(frontend)

set(BINARY "beergame")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ui *.qrc)

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

set(BACKEND ${CMAKE_CURRENT_SOURCE_DIR}/backend)
set(FRONTEND ${CMAKE_CURRENT_SOURCE_DIR}/frontend)
add_library(${BINARY}_lib ${BACKEND} ${FRONTEND})

target_link_libraries(${BINARY} PRIVATE Qt5::Widgets Qt5::Charts Qt5::WebEngineWidgets Qt5::Sql)
