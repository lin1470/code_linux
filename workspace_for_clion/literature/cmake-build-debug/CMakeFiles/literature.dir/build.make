# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/bruce/Downloads/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bruce/Downloads/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bruce/workspace_all/workspace_for_clion/literature

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/literature.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/literature.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/literature.dir/flags.make

CMakeFiles/literature.dir/main.cpp.o: CMakeFiles/literature.dir/flags.make
CMakeFiles/literature.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/literature.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/literature.dir/main.cpp.o -c /home/bruce/workspace_all/workspace_for_clion/literature/main.cpp

CMakeFiles/literature.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/literature.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/literature/main.cpp > CMakeFiles/literature.dir/main.cpp.i

CMakeFiles/literature.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/literature.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/literature/main.cpp -o CMakeFiles/literature.dir/main.cpp.s

CMakeFiles/literature.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/literature.dir/main.cpp.o.requires

CMakeFiles/literature.dir/main.cpp.o.provides: CMakeFiles/literature.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/literature.dir/build.make CMakeFiles/literature.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/literature.dir/main.cpp.o.provides

CMakeFiles/literature.dir/main.cpp.o.provides.build: CMakeFiles/literature.dir/main.cpp.o


# Object files for target literature
literature_OBJECTS = \
"CMakeFiles/literature.dir/main.cpp.o"

# External object files for target literature
literature_EXTERNAL_OBJECTS =

literature: CMakeFiles/literature.dir/main.cpp.o
literature: CMakeFiles/literature.dir/build.make
literature: CMakeFiles/literature.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable literature"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/literature.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/literature.dir/build: literature

.PHONY : CMakeFiles/literature.dir/build

CMakeFiles/literature.dir/requires: CMakeFiles/literature.dir/main.cpp.o.requires

.PHONY : CMakeFiles/literature.dir/requires

CMakeFiles/literature.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/literature.dir/cmake_clean.cmake
.PHONY : CMakeFiles/literature.dir/clean

CMakeFiles/literature.dir/depend:
	cd /home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/workspace_all/workspace_for_clion/literature /home/bruce/workspace_all/workspace_for_clion/literature /home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/literature/cmake-build-debug/CMakeFiles/literature.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/literature.dir/depend

