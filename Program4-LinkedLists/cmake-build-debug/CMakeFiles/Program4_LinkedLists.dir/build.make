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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Program4_LinkedLists.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Program4_LinkedLists.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program4_LinkedLists.dir/flags.make

CMakeFiles/Program4_LinkedLists.dir/llist.c.o: CMakeFiles/Program4_LinkedLists.dir/flags.make
CMakeFiles/Program4_LinkedLists.dir/llist.c.o: ../llist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Program4_LinkedLists.dir/llist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Program4_LinkedLists.dir/llist.c.o -c "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/llist.c"

CMakeFiles/Program4_LinkedLists.dir/llist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Program4_LinkedLists.dir/llist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/llist.c" > CMakeFiles/Program4_LinkedLists.dir/llist.c.i

CMakeFiles/Program4_LinkedLists.dir/llist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Program4_LinkedLists.dir/llist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/llist.c" -o CMakeFiles/Program4_LinkedLists.dir/llist.c.s

# Object files for target Program4_LinkedLists
Program4_LinkedLists_OBJECTS = \
"CMakeFiles/Program4_LinkedLists.dir/llist.c.o"

# External object files for target Program4_LinkedLists
Program4_LinkedLists_EXTERNAL_OBJECTS =

Program4_LinkedLists: CMakeFiles/Program4_LinkedLists.dir/llist.c.o
Program4_LinkedLists: CMakeFiles/Program4_LinkedLists.dir/build.make
Program4_LinkedLists: CMakeFiles/Program4_LinkedLists.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Program4_LinkedLists"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Program4_LinkedLists.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program4_LinkedLists.dir/build: Program4_LinkedLists
.PHONY : CMakeFiles/Program4_LinkedLists.dir/build

CMakeFiles/Program4_LinkedLists.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Program4_LinkedLists.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Program4_LinkedLists.dir/clean

CMakeFiles/Program4_LinkedLists.dir/depend:
	cd "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug" "/mnt/c/Users/Sania Khaja/ClionProjects/CS211/Program4-LinkedLists/cmake-build-debug/CMakeFiles/Program4_LinkedLists.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Program4_LinkedLists.dir/depend
