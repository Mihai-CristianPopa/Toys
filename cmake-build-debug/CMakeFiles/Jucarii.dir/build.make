# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Mihai facultate\CLion\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Mihai facultate\CLion\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Drontek\CLionProjects\Jucarii

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Jucarii.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Jucarii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Jucarii.dir/flags.make

CMakeFiles/Jucarii.dir/main.cpp.obj: CMakeFiles/Jucarii.dir/flags.make
CMakeFiles/Jucarii.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Jucarii.dir/main.cpp.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Jucarii.dir\main.cpp.obj -c C:\Users\Drontek\CLionProjects\Jucarii\main.cpp

CMakeFiles/Jucarii.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jucarii.dir/main.cpp.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Drontek\CLionProjects\Jucarii\main.cpp > CMakeFiles\Jucarii.dir\main.cpp.i

CMakeFiles/Jucarii.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jucarii.dir/main.cpp.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Drontek\CLionProjects\Jucarii\main.cpp -o CMakeFiles\Jucarii.dir\main.cpp.s

# Object files for target Jucarii
Jucarii_OBJECTS = \
"CMakeFiles/Jucarii.dir/main.cpp.obj"

# External object files for target Jucarii
Jucarii_EXTERNAL_OBJECTS =

Jucarii.exe: CMakeFiles/Jucarii.dir/main.cpp.obj
Jucarii.exe: CMakeFiles/Jucarii.dir/build.make
Jucarii.exe: CMakeFiles/Jucarii.dir/linklibs.rsp
Jucarii.exe: CMakeFiles/Jucarii.dir/objects1.rsp
Jucarii.exe: CMakeFiles/Jucarii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Jucarii.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Jucarii.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Jucarii.dir/build: Jucarii.exe
.PHONY : CMakeFiles/Jucarii.dir/build

CMakeFiles/Jucarii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Jucarii.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Jucarii.dir/clean

CMakeFiles/Jucarii.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Drontek\CLionProjects\Jucarii C:\Users\Drontek\CLionProjects\Jucarii C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug C:\Users\Drontek\CLionProjects\Jucarii\cmake-build-debug\CMakeFiles\Jucarii.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Jucarii.dir/depend

