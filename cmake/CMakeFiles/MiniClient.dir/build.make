# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/keith/dev/MServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keith/dev/MServer/cmake

# Include any dependencies generated for this target.
include CMakeFiles/MiniClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MiniClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiniClient.dir/flags.make

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o: CMakeFiles/MiniClient.dir/flags.make
CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o: ../src/MiniClient/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o -c /home/keith/dev/MServer/src/MiniClient/main.cpp

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keith/dev/MServer/src/MiniClient/main.cpp > CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.i

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keith/dev/MServer/src/MiniClient/main.cpp -o CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.s

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.requires:

.PHONY : CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.requires

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.provides: CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MiniClient.dir/build.make CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.provides.build
.PHONY : CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.provides

CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.provides.build: CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o


# Object files for target MiniClient
MiniClient_OBJECTS = \
"CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o"

# External object files for target MiniClient
MiniClient_EXTERNAL_OBJECTS =

bin/MiniClient: CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o
bin/MiniClient: CMakeFiles/MiniClient.dir/build.make
bin/MiniClient: src/NetWork/libNetWork.a
bin/MiniClient: src/ServerBase/libServerBase.a
bin/MiniClient: CMakeFiles/MiniClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/MiniClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiniClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiniClient.dir/build: bin/MiniClient

.PHONY : CMakeFiles/MiniClient.dir/build

CMakeFiles/MiniClient.dir/requires: CMakeFiles/MiniClient.dir/src/MiniClient/main.cpp.o.requires

.PHONY : CMakeFiles/MiniClient.dir/requires

CMakeFiles/MiniClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiniClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiniClient.dir/clean

CMakeFiles/MiniClient.dir/depend:
	cd /home/keith/dev/MServer/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keith/dev/MServer /home/keith/dev/MServer /home/keith/dev/MServer/cmake /home/keith/dev/MServer/cmake /home/keith/dev/MServer/cmake/CMakeFiles/MiniClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiniClient.dir/depend

