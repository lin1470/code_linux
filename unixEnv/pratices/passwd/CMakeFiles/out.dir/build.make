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
CMAKE_SOURCE_DIR = /home/bruce/code/code_linux-master/unixEnv/pratices/passwd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/code/code_linux-master/unixEnv/pratices/passwd

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/sigmask.c.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/sigmask.c.o: sigmask.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruce/code/code_linux-master/unixEnv/pratices/passwd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/out.dir/sigmask.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/out.dir/sigmask.c.o   -c /home/bruce/code/code_linux-master/unixEnv/pratices/passwd/sigmask.c

CMakeFiles/out.dir/sigmask.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/out.dir/sigmask.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bruce/code/code_linux-master/unixEnv/pratices/passwd/sigmask.c > CMakeFiles/out.dir/sigmask.c.i

CMakeFiles/out.dir/sigmask.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/out.dir/sigmask.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bruce/code/code_linux-master/unixEnv/pratices/passwd/sigmask.c -o CMakeFiles/out.dir/sigmask.c.s

CMakeFiles/out.dir/sigmask.c.o.requires:

.PHONY : CMakeFiles/out.dir/sigmask.c.o.requires

CMakeFiles/out.dir/sigmask.c.o.provides: CMakeFiles/out.dir/sigmask.c.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/sigmask.c.o.provides.build
.PHONY : CMakeFiles/out.dir/sigmask.c.o.provides

CMakeFiles/out.dir/sigmask.c.o.provides.build: CMakeFiles/out.dir/sigmask.c.o


# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/sigmask.c.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

out: CMakeFiles/out.dir/sigmask.c.o
out: CMakeFiles/out.dir/build.make
out: cassdk.out/libapue.a
out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruce/code/code_linux-master/unixEnv/pratices/passwd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/requires: CMakeFiles/out.dir/sigmask.c.o.requires

.PHONY : CMakeFiles/out.dir/requires

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	cd /home/bruce/code/code_linux-master/unixEnv/pratices/passwd && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/code/code_linux-master/unixEnv/pratices/passwd /home/bruce/code/code_linux-master/unixEnv/pratices/passwd /home/bruce/code/code_linux-master/unixEnv/pratices/passwd /home/bruce/code/code_linux-master/unixEnv/pratices/passwd /home/bruce/code/code_linux-master/unixEnv/pratices/passwd/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

