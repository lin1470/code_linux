# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bruce/workspace_all/workspace_for_clion/offer/subarray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/subarray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/subarray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subarray.dir/flags.make

CMakeFiles/subarray.dir/main.cpp.o: CMakeFiles/subarray.dir/flags.make
CMakeFiles/subarray.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/subarray.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/subarray.dir/main.cpp.o -c /home/bruce/workspace_all/workspace_for_clion/offer/subarray/main.cpp

CMakeFiles/subarray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/subarray.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/offer/subarray/main.cpp > CMakeFiles/subarray.dir/main.cpp.i

CMakeFiles/subarray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/subarray.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/offer/subarray/main.cpp -o CMakeFiles/subarray.dir/main.cpp.s

CMakeFiles/subarray.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/subarray.dir/main.cpp.o.requires

CMakeFiles/subarray.dir/main.cpp.o.provides: CMakeFiles/subarray.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/subarray.dir/build.make CMakeFiles/subarray.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/subarray.dir/main.cpp.o.provides

CMakeFiles/subarray.dir/main.cpp.o.provides.build: CMakeFiles/subarray.dir/main.cpp.o


# Object files for target subarray
subarray_OBJECTS = \
"CMakeFiles/subarray.dir/main.cpp.o"

# External object files for target subarray
subarray_EXTERNAL_OBJECTS =

subarray: CMakeFiles/subarray.dir/main.cpp.o
subarray: CMakeFiles/subarray.dir/build.make
subarray: CMakeFiles/subarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable subarray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subarray.dir/build: subarray

.PHONY : CMakeFiles/subarray.dir/build

CMakeFiles/subarray.dir/requires: CMakeFiles/subarray.dir/main.cpp.o.requires

.PHONY : CMakeFiles/subarray.dir/requires

CMakeFiles/subarray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subarray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subarray.dir/clean

CMakeFiles/subarray.dir/depend:
	cd /home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/workspace_all/workspace_for_clion/offer/subarray /home/bruce/workspace_all/workspace_for_clion/offer/subarray /home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/offer/subarray/cmake-build-debug/CMakeFiles/subarray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subarray.dir/depend

