# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing "

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/3_2__Parallel_processing_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3_2__Parallel_processing_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3_2__Parallel_processing_.dir/flags.make

CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o: CMakeFiles/3_2__Parallel_processing_.dir/flags.make
CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o -c "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /main.cpp"

CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /main.cpp" > CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.i

CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /main.cpp" -o CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.s

# Object files for target 3_2__Parallel_processing_
3_2__Parallel_processing__OBJECTS = \
"CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o"

# External object files for target 3_2__Parallel_processing_
3_2__Parallel_processing__EXTERNAL_OBJECTS =

3_2__Parallel_processing_: CMakeFiles/3_2__Parallel_processing_.dir/main.cpp.o
3_2__Parallel_processing_: CMakeFiles/3_2__Parallel_processing_.dir/build.make
3_2__Parallel_processing_: CMakeFiles/3_2__Parallel_processing_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3_2__Parallel_processing_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3_2__Parallel_processing_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3_2__Parallel_processing_.dir/build: 3_2__Parallel_processing_

.PHONY : CMakeFiles/3_2__Parallel_processing_.dir/build

CMakeFiles/3_2__Parallel_processing_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3_2__Parallel_processing_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3_2__Parallel_processing_.dir/clean

CMakeFiles/3_2__Parallel_processing_.dir/depend:
	cd "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing " "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing " "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug" "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug" "/home/ilya/CLionProjects/stepic_algo/3.2. Parallel_processing /cmake-build-debug/CMakeFiles/3_2__Parallel_processing_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/3_2__Parallel_processing_.dir/depend

