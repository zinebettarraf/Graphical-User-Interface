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
include CMakeFiles/ei.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ei.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ei.dir/flags.make

CMakeFiles/ei.dir/src/ei_draw.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_draw.c.o: ../src/ei_draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ei.dir/src/ei_draw.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_draw.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_draw.c

CMakeFiles/ei.dir/src/ei_draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_draw.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_draw.c > CMakeFiles/ei.dir/src/ei_draw.c.i

CMakeFiles/ei.dir/src/ei_draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_draw.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_draw.c -o CMakeFiles/ei.dir/src/ei_draw.c.s

CMakeFiles/ei.dir/src/ei_draw_suite.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_draw_suite.c.o: ../src/ei_draw_suite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ei.dir/src/ei_draw_suite.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_draw_suite.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_draw_suite.c

CMakeFiles/ei.dir/src/ei_draw_suite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_draw_suite.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_draw_suite.c > CMakeFiles/ei.dir/src/ei_draw_suite.c.i

CMakeFiles/ei.dir/src/ei_draw_suite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_draw_suite.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_draw_suite.c -o CMakeFiles/ei.dir/src/ei_draw_suite.c.s

CMakeFiles/ei.dir/src/ei_drawpolygon.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_drawpolygon.c.o: ../src/ei_drawpolygon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ei.dir/src/ei_drawpolygon.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_drawpolygon.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_drawpolygon.c

CMakeFiles/ei.dir/src/ei_drawpolygon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_drawpolygon.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_drawpolygon.c > CMakeFiles/ei.dir/src/ei_drawpolygon.c.i

CMakeFiles/ei.dir/src/ei_drawpolygon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_drawpolygon.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_drawpolygon.c -o CMakeFiles/ei.dir/src/ei_drawpolygon.c.s

CMakeFiles/ei.dir/src/ei_application.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_application.c.o: ../src/ei_application.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ei.dir/src/ei_application.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_application.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_application.c

CMakeFiles/ei.dir/src/ei_application.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_application.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_application.c > CMakeFiles/ei.dir/src/ei_application.c.i

CMakeFiles/ei.dir/src/ei_application.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_application.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_application.c -o CMakeFiles/ei.dir/src/ei_application.c.s

CMakeFiles/ei.dir/src/ei_widgetclass.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_widgetclass.c.o: ../src/ei_widgetclass.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ei.dir/src/ei_widgetclass.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_widgetclass.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_widgetclass.c

CMakeFiles/ei.dir/src/ei_widgetclass.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_widgetclass.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_widgetclass.c > CMakeFiles/ei.dir/src/ei_widgetclass.c.i

CMakeFiles/ei.dir/src/ei_widgetclass.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_widgetclass.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_widgetclass.c -o CMakeFiles/ei.dir/src/ei_widgetclass.c.s

CMakeFiles/ei.dir/src/ei_widget.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_widget.c.o: ../src/ei_widget.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ei.dir/src/ei_widget.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_widget.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_widget.c

CMakeFiles/ei.dir/src/ei_widget.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_widget.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_widget.c > CMakeFiles/ei.dir/src/ei_widget.c.i

CMakeFiles/ei.dir/src/ei_widget.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_widget.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_widget.c -o CMakeFiles/ei.dir/src/ei_widget.c.s

CMakeFiles/ei.dir/src/ei_histo_conf.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_histo_conf.c.o: ../src/ei_histo_conf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ei.dir/src/ei_histo_conf.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_histo_conf.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_histo_conf.c

CMakeFiles/ei.dir/src/ei_histo_conf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_histo_conf.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_histo_conf.c > CMakeFiles/ei.dir/src/ei_histo_conf.c.i

CMakeFiles/ei.dir/src/ei_histo_conf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_histo_conf.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_histo_conf.c -o CMakeFiles/ei.dir/src/ei_histo_conf.c.s

CMakeFiles/ei.dir/src/ei_event.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_event.c.o: ../src/ei_event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ei.dir/src/ei_event.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_event.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_event.c

CMakeFiles/ei.dir/src/ei_event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_event.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_event.c > CMakeFiles/ei.dir/src/ei_event.c.i

CMakeFiles/ei.dir/src/ei_event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_event.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_event.c -o CMakeFiles/ei.dir/src/ei_event.c.s

CMakeFiles/ei.dir/src/ei_frame.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_frame.c.o: ../src/ei_frame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ei.dir/src/ei_frame.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_frame.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_frame.c

CMakeFiles/ei.dir/src/ei_frame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_frame.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_frame.c > CMakeFiles/ei.dir/src/ei_frame.c.i

CMakeFiles/ei.dir/src/ei_frame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_frame.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_frame.c -o CMakeFiles/ei.dir/src/ei_frame.c.s

CMakeFiles/ei.dir/src/ei_placer.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_placer.c.o: ../src/ei_placer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/ei.dir/src/ei_placer.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_placer.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_placer.c

CMakeFiles/ei.dir/src/ei_placer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_placer.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_placer.c > CMakeFiles/ei.dir/src/ei_placer.c.i

CMakeFiles/ei.dir/src/ei_placer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_placer.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_placer.c -o CMakeFiles/ei.dir/src/ei_placer.c.s

CMakeFiles/ei.dir/src/ei_button.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_button.c.o: ../src/ei_button.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/ei.dir/src/ei_button.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_button.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_button.c

CMakeFiles/ei.dir/src/ei_button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_button.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_button.c > CMakeFiles/ei.dir/src/ei_button.c.i

CMakeFiles/ei.dir/src/ei_button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_button.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_button.c -o CMakeFiles/ei.dir/src/ei_button.c.s

CMakeFiles/ei.dir/src/ei_drawbutton.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_drawbutton.c.o: ../src/ei_drawbutton.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/ei.dir/src/ei_drawbutton.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_drawbutton.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_drawbutton.c

CMakeFiles/ei.dir/src/ei_drawbutton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_drawbutton.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_drawbutton.c > CMakeFiles/ei.dir/src/ei_drawbutton.c.i

CMakeFiles/ei.dir/src/ei_drawbutton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_drawbutton.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_drawbutton.c -o CMakeFiles/ei.dir/src/ei_drawbutton.c.s

CMakeFiles/ei.dir/src/ei_toplevel.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_toplevel.c.o: ../src/ei_toplevel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/ei.dir/src/ei_toplevel.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_toplevel.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_toplevel.c

CMakeFiles/ei.dir/src/ei_toplevel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_toplevel.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_toplevel.c > CMakeFiles/ei.dir/src/ei_toplevel.c.i

CMakeFiles/ei.dir/src/ei_toplevel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_toplevel.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_toplevel.c -o CMakeFiles/ei.dir/src/ei_toplevel.c.s

CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o: ../src/ei_drawtoplevel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_drawtoplevel.c

CMakeFiles/ei.dir/src/ei_drawtoplevel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_drawtoplevel.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_drawtoplevel.c > CMakeFiles/ei.dir/src/ei_drawtoplevel.c.i

CMakeFiles/ei.dir/src/ei_drawtoplevel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_drawtoplevel.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_drawtoplevel.c -o CMakeFiles/ei.dir/src/ei_drawtoplevel.c.s

CMakeFiles/ei.dir/src/ei_globals.c.o: CMakeFiles/ei.dir/flags.make
CMakeFiles/ei.dir/src/ei_globals.c.o: ../src/ei_globals.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/ei.dir/src/ei_globals.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ei.dir/src/ei_globals.c.o   -c /user/4/boukhrin/Documents/Version_Finale/src/ei_globals.c

CMakeFiles/ei.dir/src/ei_globals.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ei.dir/src/ei_globals.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /user/4/boukhrin/Documents/Version_Finale/src/ei_globals.c > CMakeFiles/ei.dir/src/ei_globals.c.i

CMakeFiles/ei.dir/src/ei_globals.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ei.dir/src/ei_globals.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /user/4/boukhrin/Documents/Version_Finale/src/ei_globals.c -o CMakeFiles/ei.dir/src/ei_globals.c.s

# Object files for target ei
ei_OBJECTS = \
"CMakeFiles/ei.dir/src/ei_draw.c.o" \
"CMakeFiles/ei.dir/src/ei_draw_suite.c.o" \
"CMakeFiles/ei.dir/src/ei_drawpolygon.c.o" \
"CMakeFiles/ei.dir/src/ei_application.c.o" \
"CMakeFiles/ei.dir/src/ei_widgetclass.c.o" \
"CMakeFiles/ei.dir/src/ei_widget.c.o" \
"CMakeFiles/ei.dir/src/ei_histo_conf.c.o" \
"CMakeFiles/ei.dir/src/ei_event.c.o" \
"CMakeFiles/ei.dir/src/ei_frame.c.o" \
"CMakeFiles/ei.dir/src/ei_placer.c.o" \
"CMakeFiles/ei.dir/src/ei_button.c.o" \
"CMakeFiles/ei.dir/src/ei_drawbutton.c.o" \
"CMakeFiles/ei.dir/src/ei_toplevel.c.o" \
"CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o" \
"CMakeFiles/ei.dir/src/ei_globals.c.o"

# External object files for target ei
ei_EXTERNAL_OBJECTS =

libei.a: CMakeFiles/ei.dir/src/ei_draw.c.o
libei.a: CMakeFiles/ei.dir/src/ei_draw_suite.c.o
libei.a: CMakeFiles/ei.dir/src/ei_drawpolygon.c.o
libei.a: CMakeFiles/ei.dir/src/ei_application.c.o
libei.a: CMakeFiles/ei.dir/src/ei_widgetclass.c.o
libei.a: CMakeFiles/ei.dir/src/ei_widget.c.o
libei.a: CMakeFiles/ei.dir/src/ei_histo_conf.c.o
libei.a: CMakeFiles/ei.dir/src/ei_event.c.o
libei.a: CMakeFiles/ei.dir/src/ei_frame.c.o
libei.a: CMakeFiles/ei.dir/src/ei_placer.c.o
libei.a: CMakeFiles/ei.dir/src/ei_button.c.o
libei.a: CMakeFiles/ei.dir/src/ei_drawbutton.c.o
libei.a: CMakeFiles/ei.dir/src/ei_toplevel.c.o
libei.a: CMakeFiles/ei.dir/src/ei_drawtoplevel.c.o
libei.a: CMakeFiles/ei.dir/src/ei_globals.c.o
libei.a: CMakeFiles/ei.dir/build.make
libei.a: CMakeFiles/ei.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking C static library libei.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ei.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ei.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ei.dir/build: libei.a

.PHONY : CMakeFiles/ei.dir/build

CMakeFiles/ei.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ei.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ei.dir/clean

CMakeFiles/ei.dir/depend:
	cd /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/4/boukhrin/Documents/Version_Finale /user/4/boukhrin/Documents/Version_Finale /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug /user/4/boukhrin/Documents/Version_Finale/cmake-build-debug/CMakeFiles/ei.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ei.dir/depend
