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
CMAKE_COMMAND = "D:\Programs\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ProgramData\CLion\agh\improc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ProgramData\CLion\agh\improc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/image_processor__test.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/image_processor__test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_processor__test.dir/flags.make

CMakeFiles/image_processor__test.dir/src/bitmap.c.obj: CMakeFiles/image_processor__test.dir/flags.make
CMakeFiles/image_processor__test.dir/src/bitmap.c.obj: CMakeFiles/image_processor__test.dir/includes_C.rsp
CMakeFiles/image_processor__test.dir/src/bitmap.c.obj: ../src/bitmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/image_processor__test.dir/src/bitmap.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\image_processor__test.dir\src\bitmap.c.obj -c D:\ProgramData\CLion\agh\improc\src\bitmap.c

CMakeFiles/image_processor__test.dir/src/bitmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/image_processor__test.dir/src/bitmap.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ProgramData\CLion\agh\improc\src\bitmap.c > CMakeFiles\image_processor__test.dir\src\bitmap.c.i

CMakeFiles/image_processor__test.dir/src/bitmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/image_processor__test.dir/src/bitmap.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ProgramData\CLion\agh\improc\src\bitmap.c -o CMakeFiles\image_processor__test.dir\src\bitmap.c.s

CMakeFiles/image_processor__test.dir/src/improc.cpp.obj: CMakeFiles/image_processor__test.dir/flags.make
CMakeFiles/image_processor__test.dir/src/improc.cpp.obj: CMakeFiles/image_processor__test.dir/includes_CXX.rsp
CMakeFiles/image_processor__test.dir/src/improc.cpp.obj: ../src/improc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_processor__test.dir/src/improc.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\image_processor__test.dir\src\improc.cpp.obj -c D:\ProgramData\CLion\agh\improc\src\improc.cpp

CMakeFiles/image_processor__test.dir/src/improc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor__test.dir/src/improc.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProgramData\CLion\agh\improc\src\improc.cpp > CMakeFiles\image_processor__test.dir\src\improc.cpp.i

CMakeFiles/image_processor__test.dir/src/improc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor__test.dir/src/improc.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProgramData\CLion\agh\improc\src\improc.cpp -o CMakeFiles\image_processor__test.dir\src\improc.cpp.s

CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj: CMakeFiles/image_processor__test.dir/flags.make
CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj: CMakeFiles/image_processor__test.dir/includes_CXX.rsp
CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj: ../src/imqueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\image_processor__test.dir\src\imqueue.cpp.obj -c D:\ProgramData\CLion\agh\improc\src\imqueue.cpp

CMakeFiles/image_processor__test.dir/src/imqueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor__test.dir/src/imqueue.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProgramData\CLion\agh\improc\src\imqueue.cpp > CMakeFiles\image_processor__test.dir\src\imqueue.cpp.i

CMakeFiles/image_processor__test.dir/src/imqueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor__test.dir/src/imqueue.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProgramData\CLion\agh\improc\src\imqueue.cpp -o CMakeFiles\image_processor__test.dir\src\imqueue.cpp.s

CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj: CMakeFiles/image_processor__test.dir/flags.make
CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj: CMakeFiles/image_processor__test.dir/includes_CXX.rsp
CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj: ../test/main_gtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\image_processor__test.dir\test\main_gtest.cpp.obj -c D:\ProgramData\CLion\agh\improc\test\main_gtest.cpp

CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProgramData\CLion\agh\improc\test\main_gtest.cpp > CMakeFiles\image_processor__test.dir\test\main_gtest.cpp.i

CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProgramData\CLion\agh\improc\test\main_gtest.cpp -o CMakeFiles\image_processor__test.dir\test\main_gtest.cpp.s

# Object files for target image_processor__test
image_processor__test_OBJECTS = \
"CMakeFiles/image_processor__test.dir/src/bitmap.c.obj" \
"CMakeFiles/image_processor__test.dir/src/improc.cpp.obj" \
"CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj" \
"CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj"

# External object files for target image_processor__test
image_processor__test_EXTERNAL_OBJECTS =

image_processor__test.exe: CMakeFiles/image_processor__test.dir/src/bitmap.c.obj
image_processor__test.exe: CMakeFiles/image_processor__test.dir/src/improc.cpp.obj
image_processor__test.exe: CMakeFiles/image_processor__test.dir/src/imqueue.cpp.obj
image_processor__test.exe: CMakeFiles/image_processor__test.dir/test/main_gtest.cpp.obj
image_processor__test.exe: CMakeFiles/image_processor__test.dir/build.make
image_processor__test.exe: CMakeFiles/image_processor__test.dir/linklibs.rsp
image_processor__test.exe: CMakeFiles/image_processor__test.dir/objects1.rsp
image_processor__test.exe: CMakeFiles/image_processor__test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable image_processor__test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\image_processor__test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_processor__test.dir/build: image_processor__test.exe
.PHONY : CMakeFiles/image_processor__test.dir/build

CMakeFiles/image_processor__test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\image_processor__test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/image_processor__test.dir/clean

CMakeFiles/image_processor__test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ProgramData\CLion\agh\improc D:\ProgramData\CLion\agh\improc D:\ProgramData\CLion\agh\improc\cmake-build-debug D:\ProgramData\CLion\agh\improc\cmake-build-debug D:\ProgramData\CLion\agh\improc\cmake-build-debug\CMakeFiles\image_processor__test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_processor__test.dir/depend

