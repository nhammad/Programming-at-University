# 
# cat++/CMakeLists.txt --
#

cmake_minimum_required(VERSION 2.6)
project(CATPP C) 
add_executable(cat++ cat++.c)
add_library(rot13 SHARED rot13.c)
add_library(upper SHARED upper.c)
add_library(lower SHARED lower.c)
find_library(DL dl)
target_link_libraries(cat++ ${DL})
if(CMAKE_COMPILER_IS_GNUCC)
  add_definitions(--std=c99 -Wall -rdynamic)
endif()

