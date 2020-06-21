cmake_minimum_required (VERSION 3.1)

project (eyden-tracer)

configure_file(${PROJECT_SOURCE_DIR}/cmake/types.h.in ${PROJECT_SOURCE_DIR}/include/types.h)

file(GLOB INCLUDE "include/*.h")
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

source_group("Include" FILES ${INCLUDE})
source_group("" FILES ${INCLUDE} ${SOURCES} ${HEADERS}) 
source_group("Source Files" FILES "src/main.cpp") 
source_group("Source Files\\camera" FILES "src/ICamera.h" "src/CameraPerspective.h")
source_group("Source Files\\lights" FILES "src/ILight.h" "src/LightPoint.h" "src/LightArea.h")
source_group("Source Files\\primitives" FILES "src/Prim.h" "src/PrimSphere.h" "src/PrimPlane.h" "src/PrimTriangle.h")
source_group("Source Files\\shaders" FILES "src/IShader.h" "src/ShaderFlat.h" "src/ShaderEyelight.h" "src/ShaderPhong.h")
source_group("Source Files\\scene" FILES "src/Scene.h" "src/Scene.cpp")
source_group("Source Files\\utilities" FILES "src/ray.h" "src/random.h" "src/timer.h")
source_group("Source Files\\utilities\\BSP Tree" FILES "src/BSPNode.h" "src/BSPTree.h" "src/BoundingBox.h")

# OpenCV package
find_package(OpenCV 4.0 REQUIRED core highgui imgproc imgcodecs PATHS "$ENV{OPENCVDIR}/build")

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Sets
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 17)
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /wd5040") 
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS} /DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF")
endif(MSVC)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 
#set(IB_API_INCLUDE_DIR "" CACHE PATH "Path to the IP API")

# Properties -> C/C++ -> General -> Additional Include Directories
include_directories(${PROJECT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

# Definitions
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)

# Options
include(CMakeDependentOption)
option(ENABLE_BSP "Use Binary Space Partitioning (BSP) Tree for optimized ray traversal" ON)

add_executable(eyden-tracer ${INCLUDE} ${SOURCES} ${HEADERS})

# Properties -> Linker -> Input -> Additional Dependencies
target_link_libraries(eyden-tracer ${OpenCV_LIBS})
