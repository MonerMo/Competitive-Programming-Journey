# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Clion Projects\Competitive Programming\2Pointers"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CF.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CF.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CF.dir/flags.make

CMakeFiles/CF.dir/1006-C.cpp.obj: CMakeFiles/CF.dir/flags.make
CMakeFiles/CF.dir/1006-C.cpp.obj: D:/Clion\ Projects/Competitive\ Programming/2Pointers/1006-C.cpp
CMakeFiles/CF.dir/1006-C.cpp.obj: CMakeFiles/CF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CF.dir/1006-C.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CF.dir/1006-C.cpp.obj -MF CMakeFiles\CF.dir\1006-C.cpp.obj.d -o CMakeFiles\CF.dir\1006-C.cpp.obj -c "D:\Clion Projects\Competitive Programming\2Pointers\1006-C.cpp"

CMakeFiles/CF.dir/1006-C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CF.dir/1006-C.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Clion Projects\Competitive Programming\2Pointers\1006-C.cpp" > CMakeFiles\CF.dir\1006-C.cpp.i

CMakeFiles/CF.dir/1006-C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CF.dir/1006-C.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Clion Projects\Competitive Programming\2Pointers\1006-C.cpp" -o CMakeFiles\CF.dir\1006-C.cpp.s

# Object files for target CF
CF_OBJECTS = \
"CMakeFiles/CF.dir/1006-C.cpp.obj"

# External object files for target CF
CF_EXTERNAL_OBJECTS =

CF.exe: CMakeFiles/CF.dir/1006-C.cpp.obj
CF.exe: CMakeFiles/CF.dir/build.make
CF.exe: CMakeFiles/CF.dir/linklibs.rsp
CF.exe: CMakeFiles/CF.dir/objects1.rsp
CF.exe: CMakeFiles/CF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CF.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CF.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CF.dir/build: CF.exe
.PHONY : CMakeFiles/CF.dir/build

CMakeFiles/CF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CF.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CF.dir/clean

CMakeFiles/CF.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Clion Projects\Competitive Programming\2Pointers" "D:\Clion Projects\Competitive Programming\2Pointers" "D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug" "D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug" "D:\Clion Projects\Competitive Programming\2Pointers\cmake-build-debug\CMakeFiles\CF.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CF.dir/depend

