# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build

# Include any dependencies generated for this target.
include CMakeFiles/Dijkstra.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Dijkstra.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Dijkstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dijkstra.dir/flags.make

CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj: ../src/Dijkstra.cpp
CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj: CMakeFiles/Dijkstra.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj -MF CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj.d -o CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj -c D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Dijkstra.cpp

CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Dijkstra.cpp > CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.i

CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Dijkstra.cpp -o CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.s

CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj: ../src/Graph.cpp
CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj: CMakeFiles/Dijkstra.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj -MF CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj.d -o CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj -c D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Graph.cpp

CMakeFiles/Dijkstra.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/src/Graph.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Graph.cpp > CMakeFiles/Dijkstra.dir/src/Graph.cpp.i

CMakeFiles/Dijkstra.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/src/Graph.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/src/Graph.cpp -o CMakeFiles/Dijkstra.dir/src/Graph.cpp.s

# Object files for target Dijkstra
Dijkstra_OBJECTS = \
"CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj" \
"CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj"

# External object files for target Dijkstra
Dijkstra_EXTERNAL_OBJECTS =

Dijkstra.exe: CMakeFiles/Dijkstra.dir/src/Dijkstra.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/src/Graph.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/build.make
Dijkstra.exe: CMakeFiles/Dijkstra.dir/linklibs.rsp
Dijkstra.exe: CMakeFiles/Dijkstra.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Dijkstra.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Dijkstra.dir/objects.a
	C:/MinGW/bin/ar.exe qc CMakeFiles/Dijkstra.dir/objects.a @CMakeFiles/Dijkstra.dir/objects1.rsp
	C:/MinGW/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/Dijkstra.dir/objects.a -Wl,--no-whole-archive -o Dijkstra.exe -Wl,--out-implib,libDijkstra.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Dijkstra.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Dijkstra.dir/build: Dijkstra.exe
.PHONY : CMakeFiles/Dijkstra.dir/build

CMakeFiles/Dijkstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dijkstra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dijkstra.dir/clean

CMakeFiles/Dijkstra.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9 D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9 D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build D:/cfla/Documents/Workspace/CC++/DataStructure/Chapter-9/build/CMakeFiles/Dijkstra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dijkstra.dir/depend
