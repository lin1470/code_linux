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
CMAKE_SOURCE_DIR = /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nacklace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nacklace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nacklace.dir/flags.make

CMakeFiles/nacklace.dir/main.cpp.o: CMakeFiles/nacklace.dir/flags.make
CMakeFiles/nacklace.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nacklace.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nacklace.dir/main.cpp.o -c /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/main.cpp

CMakeFiles/nacklace.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nacklace.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/main.cpp > CMakeFiles/nacklace.dir/main.cpp.i

CMakeFiles/nacklace.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nacklace.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/main.cpp -o CMakeFiles/nacklace.dir/main.cpp.s

CMakeFiles/nacklace.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/nacklace.dir/main.cpp.o.requires

CMakeFiles/nacklace.dir/main.cpp.o.provides: CMakeFiles/nacklace.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/nacklace.dir/build.make CMakeFiles/nacklace.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/nacklace.dir/main.cpp.o.provides

CMakeFiles/nacklace.dir/main.cpp.o.provides.build: CMakeFiles/nacklace.dir/main.cpp.o


# Object files for target nacklace
nacklace_OBJECTS = \
"CMakeFiles/nacklace.dir/main.cpp.o"

# External object files for target nacklace
nacklace_EXTERNAL_OBJECTS =

nacklace: CMakeFiles/nacklace.dir/main.cpp.o
nacklace: CMakeFiles/nacklace.dir/build.make
nacklace: CMakeFiles/nacklace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nacklace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nacklace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nacklace.dir/build: nacklace

.PHONY : CMakeFiles/nacklace.dir/build

CMakeFiles/nacklace.dir/requires: CMakeFiles/nacklace.dir/main.cpp.o.requires

.PHONY : CMakeFiles/nacklace.dir/requires

CMakeFiles/nacklace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nacklace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nacklace.dir/clean

CMakeFiles/nacklace.dir/depend:
	cd /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/ACM/exercise5/nacklace/cmake-build-debug/CMakeFiles/nacklace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nacklace.dir/depend

