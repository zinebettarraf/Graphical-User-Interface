# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /user/4/boukhrin/Documents/Version_Finale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lines.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lines.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lines.dir/flags.make

CMakeFiles/lines.dir/tests/lines.c.o: CMakeFiles/lines.dir/flags.make
CMakeFiles/lines.dir/tests/lines.c.o: ../tests/lines.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lines.dir/tests/lines.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lines.dir/tests/lines.c.o   -c /user/4/boukhrin/Documents/Version_Finale/tests/lines.c

CMakeFiles/lines.dir/tests/lines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lines.dir/tests/lines.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/tests/lines.c > CMakeFiles/lines.dir/tests/lines.c.i

CMakeFiles/lines.dir/tests/lines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lines.dir/tests/lines.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/tests/lines.c -o CMakeFiles/lines.dir/tests/lines.c.s

# Object files for target lines
lines_OBJECTS = \
"CMakeFiles/lines.dir/tests/lines.c.o"

# External object files for target lines
lines_EXTERNAL_OBJECTS =

lines: CMakeFiles/lines.dir/tests/lines.c.o
lines: CMakeFiles/lines.dir/build.make
lines: libei.a
lines: ../_x11/libeibase64.a
lines: CMakeFiles/lines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lines"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lines.dir/build: lines

.PHONY : CMakeFiles/lines.dir/build

CMakeFiles/lines.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lines.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lines.dir/clean

CMakeFiles/lines.dir/depend:
	cd /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/4/boukhrin/Documents/Version_Finale /user/4/boukhrin/Documents/Version_Finale /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles/lines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lines.dir/depend

