# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hammad/OS/HW4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hammad/OS/HW4

# Include any dependencies generated for this target.
include CMakeFiles/rot13.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rot13.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rot13.dir/flags.make

CMakeFiles/rot13.dir/rot13.c.o: CMakeFiles/rot13.dir/flags.make
CMakeFiles/rot13.dir/rot13.c.o: rot13.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hammad/OS/HW4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rot13.dir/rot13.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rot13.dir/rot13.c.o   -c /home/hammad/OS/HW4/rot13.c

CMakeFiles/rot13.dir/rot13.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rot13.dir/rot13.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hammad/OS/HW4/rot13.c > CMakeFiles/rot13.dir/rot13.c.i

CMakeFiles/rot13.dir/rot13.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rot13.dir/rot13.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hammad/OS/HW4/rot13.c -o CMakeFiles/rot13.dir/rot13.c.s

CMakeFiles/rot13.dir/rot13.c.o.requires:

.PHONY : CMakeFiles/rot13.dir/rot13.c.o.requires

CMakeFiles/rot13.dir/rot13.c.o.provides: CMakeFiles/rot13.dir/rot13.c.o.requires
	$(MAKE) -f CMakeFiles/rot13.dir/build.make CMakeFiles/rot13.dir/rot13.c.o.provides.build
.PHONY : CMakeFiles/rot13.dir/rot13.c.o.provides

CMakeFiles/rot13.dir/rot13.c.o.provides.build: CMakeFiles/rot13.dir/rot13.c.o


# Object files for target rot13
rot13_OBJECTS = \
"CMakeFiles/rot13.dir/rot13.c.o"

# External object files for target rot13
rot13_EXTERNAL_OBJECTS =

librot13.so: CMakeFiles/rot13.dir/rot13.c.o
librot13.so: CMakeFiles/rot13.dir/build.make
librot13.so: CMakeFiles/rot13.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hammad/OS/HW4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library librot13.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rot13.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rot13.dir/build: librot13.so

.PHONY : CMakeFiles/rot13.dir/build

CMakeFiles/rot13.dir/requires: CMakeFiles/rot13.dir/rot13.c.o.requires

.PHONY : CMakeFiles/rot13.dir/requires

CMakeFiles/rot13.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rot13.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rot13.dir/clean

CMakeFiles/rot13.dir/depend:
	cd /home/hammad/OS/HW4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hammad/OS/HW4 /home/hammad/OS/HW4 /home/hammad/OS/HW4 /home/hammad/OS/HW4 /home/hammad/OS/HW4/CMakeFiles/rot13.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rot13.dir/depend

