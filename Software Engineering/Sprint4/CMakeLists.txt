cmake_minimum_required(VERSION 3.5)
project(se-03-team-08 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

if(EXISTS $ENV{HOME}/Qt/5.14.2/gcc_64)
  set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.14.2/gcc_64)
endif()

if(EXISTS $ENV{HOME}/Qt/5.14.1/gcc_64)
  set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.14.1/gcc_64)
endif()

include_directories(src)
add_subdirectory(src)
add_subdirectory(tests)

set(directory db)
add_custom_target(build-time-make-directory ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${directory})


# Doxygen documentation:

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
        # COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/build/doc/html/index.html
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
 message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

