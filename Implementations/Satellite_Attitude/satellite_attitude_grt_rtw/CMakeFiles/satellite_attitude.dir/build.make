# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /home/sebastian/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/sebastian/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw

# Include any dependencies generated for this target.
include CMakeFiles/satellite_attitude.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/satellite_attitude.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/satellite_attitude.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/satellite_attitude.dir/flags.make

CMakeFiles/satellite_attitude.dir/main.cpp.o: CMakeFiles/satellite_attitude.dir/flags.make
CMakeFiles/satellite_attitude.dir/main.cpp.o: main.cpp
CMakeFiles/satellite_attitude.dir/main.cpp.o: CMakeFiles/satellite_attitude.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/satellite_attitude.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/satellite_attitude.dir/main.cpp.o -MF CMakeFiles/satellite_attitude.dir/main.cpp.o.d -o CMakeFiles/satellite_attitude.dir/main.cpp.o -c /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/main.cpp

CMakeFiles/satellite_attitude.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/satellite_attitude.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/main.cpp > CMakeFiles/satellite_attitude.dir/main.cpp.i

CMakeFiles/satellite_attitude.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/satellite_attitude.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/main.cpp -o CMakeFiles/satellite_attitude.dir/main.cpp.s

# Object files for target satellite_attitude
satellite_attitude_OBJECTS = \
"CMakeFiles/satellite_attitude.dir/main.cpp.o"

# External object files for target satellite_attitude
satellite_attitude_EXTERNAL_OBJECTS = \
"/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/mnt/c/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.o" \
"/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/rt_nonfinite.cpp.o" \
"/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/satellite_attitude.cpp.o" \
"/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/Observer.cpp.o" \
"/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/ConcreteObserverStates.cpp.o"

satellite_attitude: CMakeFiles/satellite_attitude.dir/main.cpp.o
satellite_attitude: CMakeFiles/satellite_attitude_objects.dir/mnt/c/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.o
satellite_attitude: CMakeFiles/satellite_attitude_objects.dir/rt_nonfinite.cpp.o
satellite_attitude: CMakeFiles/satellite_attitude_objects.dir/satellite_attitude.cpp.o
satellite_attitude: CMakeFiles/satellite_attitude_objects.dir/Observer.cpp.o
satellite_attitude: CMakeFiles/satellite_attitude_objects.dir/ConcreteObserverStates.cpp.o
satellite_attitude: CMakeFiles/satellite_attitude.dir/build.make
satellite_attitude: CMakeFiles/satellite_attitude.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable satellite_attitude"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/satellite_attitude.dir/link.txt --verbose=$(VERBOSE)
	/home/sebastian/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E cmake_echo_color --cyan \#\#\#\ Created\ executable:\ /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/satellite_attitude

# Rule to build all files generated by this target.
CMakeFiles/satellite_attitude.dir/build: satellite_attitude
.PHONY : CMakeFiles/satellite_attitude.dir/build

CMakeFiles/satellite_attitude.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/satellite_attitude.dir/cmake_clean.cmake
.PHONY : CMakeFiles/satellite_attitude.dir/clean

CMakeFiles/satellite_attitude.dir/depend:
	cd /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/satellite_attitude.dir/depend

