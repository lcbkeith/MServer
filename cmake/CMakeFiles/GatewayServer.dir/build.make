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
include CMakeFiles/GatewayServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GatewayServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GatewayServer.dir/flags.make

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o: CMakeFiles/GatewayServer.dir/flags.make
CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o: ../src/GatewayServer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o -c /home/keith/dev/MServer/src/GatewayServer/main.cpp

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keith/dev/MServer/src/GatewayServer/main.cpp > CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.i

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keith/dev/MServer/src/GatewayServer/main.cpp -o CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.s

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.requires:

.PHONY : CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.requires

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.provides: CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GatewayServer.dir/build.make CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.provides.build
.PHONY : CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.provides

CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.provides.build: CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o


# Object files for target GatewayServer
GatewayServer_OBJECTS = \
"CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o"

# External object files for target GatewayServer
GatewayServer_EXTERNAL_OBJECTS =

bin/GatewayServer: CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o
bin/GatewayServer: CMakeFiles/GatewayServer.dir/build.make
bin/GatewayServer: src/NetWork/libNetWork.a
bin/GatewayServer: src/ServerBase/libServerBase.a
bin/GatewayServer: CMakeFiles/GatewayServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keith/dev/MServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/GatewayServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GatewayServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GatewayServer.dir/build: bin/GatewayServer

.PHONY : CMakeFiles/GatewayServer.dir/build

CMakeFiles/GatewayServer.dir/requires: CMakeFiles/GatewayServer.dir/src/GatewayServer/main.cpp.o.requires

.PHONY : CMakeFiles/GatewayServer.dir/requires

CMakeFiles/GatewayServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GatewayServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GatewayServer.dir/clean

CMakeFiles/GatewayServer.dir/depend:
	cd /home/keith/dev/MServer/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keith/dev/MServer /home/keith/dev/MServer /home/keith/dev/MServer/cmake /home/keith/dev/MServer/cmake /home/keith/dev/MServer/cmake/CMakeFiles/GatewayServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GatewayServer.dir/depend
