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
include src/MiniClient/CMakeFiles/MiniClient.dir/depend.make

# Include the progress variables for this target.
include src/MiniClient/CMakeFiles/MiniClient.dir/progress.make

# Include the compile flags for this target's objects.
include src/MiniClient/CMakeFiles/MiniClient.dir/flags.make

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o: src/MiniClient/CMakeFiles/MiniClient.dir/flags.make
src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o: ../src/MiniClient/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o"
	cd /home/keith/dev/MServer/cmake/src/MiniClient && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniClient.dir/main.cpp.o -c /home/keith/dev/MServer/src/MiniClient/main.cpp

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniClient.dir/main.cpp.i"
	cd /home/keith/dev/MServer/cmake/src/MiniClient && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keith/dev/MServer/src/MiniClient/main.cpp > CMakeFiles/MiniClient.dir/main.cpp.i

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniClient.dir/main.cpp.s"
	cd /home/keith/dev/MServer/cmake/src/MiniClient && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keith/dev/MServer/src/MiniClient/main.cpp -o CMakeFiles/MiniClient.dir/main.cpp.s

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.requires:

.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.requires

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.provides: src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.requires
	$(MAKE) -f src/MiniClient/CMakeFiles/MiniClient.dir/build.make src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.provides.build
.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.provides

src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.provides.build: src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o


# Object files for target MiniClient
MiniClient_OBJECTS = \
"CMakeFiles/MiniClient.dir/main.cpp.o"

# External object files for target MiniClient
MiniClient_EXTERNAL_OBJECTS =

src/MiniClient/MiniClient: src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o
src/MiniClient/MiniClient: src/MiniClient/CMakeFiles/MiniClient.dir/build.make
src/MiniClient/MiniClient: src/NetWork/libNetWork.a
src/MiniClient/MiniClient: src/ServerBase/libServerBase.a
src/MiniClient/MiniClient: src/MiniClient/CMakeFiles/MiniClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MiniClient"
	cd /home/keith/dev/MServer/cmake/src/MiniClient && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiniClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/MiniClient/CMakeFiles/MiniClient.dir/build: src/MiniClient/MiniClient

.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/build

src/MiniClient/CMakeFiles/MiniClient.dir/requires: src/MiniClient/CMakeFiles/MiniClient.dir/main.cpp.o.requires

.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/requires

src/MiniClient/CMakeFiles/MiniClient.dir/clean:
	cd /home/keith/dev/MServer/cmake/src/MiniClient && $(CMAKE_COMMAND) -P CMakeFiles/MiniClient.dir/cmake_clean.cmake
.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/clean

src/MiniClient/CMakeFiles/MiniClient.dir/depend:
	cd /home/keith/dev/MServer/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keith/dev/MServer /home/keith/dev/MServer/src/MiniClient /home/keith/dev/MServer/cmake /home/keith/dev/MServer/cmake/src/MiniClient /home/keith/dev/MServer/cmake/src/MiniClient/CMakeFiles/MiniClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/MiniClient/CMakeFiles/MiniClient.dir/depend
