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
CMAKE_SOURCE_DIR = /home/bruce/workspace_all/workspace_for_clion/linux/network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/network.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/network.dir/flags.make

CMakeFiles/network.dir/main.cpp.o: CMakeFiles/network.dir/flags.make
CMakeFiles/network.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/network.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/main.cpp.o -c /home/bruce/workspace_all/workspace_for_clion/linux/network/main.cpp

CMakeFiles/network.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/linux/network/main.cpp > CMakeFiles/network.dir/main.cpp.i

CMakeFiles/network.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/linux/network/main.cpp -o CMakeFiles/network.dir/main.cpp.s

CMakeFiles/network.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/network.dir/main.cpp.o.requires

CMakeFiles/network.dir/main.cpp.o.provides: CMakeFiles/network.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/network.dir/build.make CMakeFiles/network.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/network.dir/main.cpp.o.provides

CMakeFiles/network.dir/main.cpp.o.provides.build: CMakeFiles/network.dir/main.cpp.o


CMakeFiles/network.dir/socket/server.c.o: CMakeFiles/network.dir/flags.make
CMakeFiles/network.dir/socket/server.c.o: ../socket/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/network.dir/socket/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/network.dir/socket/server.c.o   -c /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/server.c

CMakeFiles/network.dir/socket/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/network.dir/socket/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/server.c > CMakeFiles/network.dir/socket/server.c.i

CMakeFiles/network.dir/socket/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/network.dir/socket/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/server.c -o CMakeFiles/network.dir/socket/server.c.s

CMakeFiles/network.dir/socket/server.c.o.requires:

.PHONY : CMakeFiles/network.dir/socket/server.c.o.requires

CMakeFiles/network.dir/socket/server.c.o.provides: CMakeFiles/network.dir/socket/server.c.o.requires
	$(MAKE) -f CMakeFiles/network.dir/build.make CMakeFiles/network.dir/socket/server.c.o.provides.build
.PHONY : CMakeFiles/network.dir/socket/server.c.o.provides

CMakeFiles/network.dir/socket/server.c.o.provides.build: CMakeFiles/network.dir/socket/server.c.o


CMakeFiles/network.dir/socket/client.c.o: CMakeFiles/network.dir/flags.make
CMakeFiles/network.dir/socket/client.c.o: ../socket/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/network.dir/socket/client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/network.dir/socket/client.c.o   -c /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/client.c

CMakeFiles/network.dir/socket/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/network.dir/socket/client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/client.c > CMakeFiles/network.dir/socket/client.c.i

CMakeFiles/network.dir/socket/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/network.dir/socket/client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bruce/workspace_all/workspace_for_clion/linux/network/socket/client.c -o CMakeFiles/network.dir/socket/client.c.s

CMakeFiles/network.dir/socket/client.c.o.requires:

.PHONY : CMakeFiles/network.dir/socket/client.c.o.requires

CMakeFiles/network.dir/socket/client.c.o.provides: CMakeFiles/network.dir/socket/client.c.o.requires
	$(MAKE) -f CMakeFiles/network.dir/build.make CMakeFiles/network.dir/socket/client.c.o.provides.build
.PHONY : CMakeFiles/network.dir/socket/client.c.o.provides

CMakeFiles/network.dir/socket/client.c.o.provides.build: CMakeFiles/network.dir/socket/client.c.o


# Object files for target network
network_OBJECTS = \
"CMakeFiles/network.dir/main.cpp.o" \
"CMakeFiles/network.dir/socket/server.c.o" \
"CMakeFiles/network.dir/socket/client.c.o"

# External object files for target network
network_EXTERNAL_OBJECTS =

network: CMakeFiles/network.dir/main.cpp.o
network: CMakeFiles/network.dir/socket/server.c.o
network: CMakeFiles/network.dir/socket/client.c.o
network: CMakeFiles/network.dir/build.make
network: CMakeFiles/network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/network.dir/build: network

.PHONY : CMakeFiles/network.dir/build

CMakeFiles/network.dir/requires: CMakeFiles/network.dir/main.cpp.o.requires
CMakeFiles/network.dir/requires: CMakeFiles/network.dir/socket/server.c.o.requires
CMakeFiles/network.dir/requires: CMakeFiles/network.dir/socket/client.c.o.requires

.PHONY : CMakeFiles/network.dir/requires

CMakeFiles/network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/network.dir/clean

CMakeFiles/network.dir/depend:
	cd /home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/workspace_all/workspace_for_clion/linux/network /home/bruce/workspace_all/workspace_for_clion/linux/network /home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug /home/bruce/workspace_all/workspace_for_clion/linux/network/cmake-build-debug/CMakeFiles/network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/network.dir/depend
