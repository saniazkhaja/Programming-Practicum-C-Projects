# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/szkhaja1/cmake-3.20.0/bin/cmake

# The command to remove a file.
RM = /home/szkhaja1/cmake-3.20.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Program3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Program3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program3.dir/flags.make

CMakeFiles/Program3.dir/bpgame.c.o: CMakeFiles/Program3.dir/flags.make
CMakeFiles/Program3.dir/bpgame.c.o: ../bpgame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Program3.dir/bpgame.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Program3.dir/bpgame.c.o -c "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/bpgame.c"

CMakeFiles/Program3.dir/bpgame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Program3.dir/bpgame.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/bpgame.c" > CMakeFiles/Program3.dir/bpgame.c.i

CMakeFiles/Program3.dir/bpgame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Program3.dir/bpgame.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/bpgame.c" -o CMakeFiles/Program3.dir/bpgame.c.s

CMakeFiles/Program3.dir/simpleio.c.o: CMakeFiles/Program3.dir/flags.make
CMakeFiles/Program3.dir/simpleio.c.o: ../simpleio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Program3.dir/simpleio.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Program3.dir/simpleio.c.o -c "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/simpleio.c"

CMakeFiles/Program3.dir/simpleio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Program3.dir/simpleio.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/simpleio.c" > CMakeFiles/Program3.dir/simpleio.c.i

CMakeFiles/Program3.dir/simpleio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Program3.dir/simpleio.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/simpleio.c" -o CMakeFiles/Program3.dir/simpleio.c.s

# Object files for target Program3
Program3_OBJECTS = \
"CMakeFiles/Program3.dir/bpgame.c.o" \
"CMakeFiles/Program3.dir/simpleio.c.o"

# External object files for target Program3
Program3_EXTERNAL_OBJECTS =

Program3: CMakeFiles/Program3.dir/bpgame.c.o
Program3: CMakeFiles/Program3.dir/simpleio.c.o
Program3: CMakeFiles/Program3.dir/build.make
Program3: CMakeFiles/Program3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Program3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Program3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program3.dir/build: Program3
.PHONY : CMakeFiles/Program3.dir/build

CMakeFiles/Program3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Program3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Program3.dir/clean

CMakeFiles/Program3.dir/depend:
	cd "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program3/cmake-build-debug/CMakeFiles/Program3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Program3.dir/depend

