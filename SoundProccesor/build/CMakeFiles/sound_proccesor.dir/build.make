# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/babrakadabra/second_course/CPP_tasks/SoundProccesor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build

# Include any dependencies generated for this target.
include CMakeFiles/sound_proccesor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sound_proccesor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sound_proccesor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sound_proccesor.dir/flags.make

CMakeFiles/sound_proccesor.dir/main.cpp.o: CMakeFiles/sound_proccesor.dir/flags.make
CMakeFiles/sound_proccesor.dir/main.cpp.o: /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/main.cpp
CMakeFiles/sound_proccesor.dir/main.cpp.o: CMakeFiles/sound_proccesor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sound_proccesor.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sound_proccesor.dir/main.cpp.o -MF CMakeFiles/sound_proccesor.dir/main.cpp.o.d -o CMakeFiles/sound_proccesor.dir/main.cpp.o -c /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/main.cpp

CMakeFiles/sound_proccesor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sound_proccesor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/main.cpp > CMakeFiles/sound_proccesor.dir/main.cpp.i

CMakeFiles/sound_proccesor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sound_proccesor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/main.cpp -o CMakeFiles/sound_proccesor.dir/main.cpp.s

# Object files for target sound_proccesor
sound_proccesor_OBJECTS = \
"CMakeFiles/sound_proccesor.dir/main.cpp.o"

# External object files for target sound_proccesor
sound_proccesor_EXTERNAL_OBJECTS =

sound_proccesor: CMakeFiles/sound_proccesor.dir/main.cpp.o
sound_proccesor: CMakeFiles/sound_proccesor.dir/build.make
sound_proccesor: lib/libsound_proccesor_lib.a
sound_proccesor: CMakeFiles/sound_proccesor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sound_proccesor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sound_proccesor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sound_proccesor.dir/build: sound_proccesor
.PHONY : CMakeFiles/sound_proccesor.dir/build

CMakeFiles/sound_proccesor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sound_proccesor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sound_proccesor.dir/clean

CMakeFiles/sound_proccesor.dir/depend:
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/babrakadabra/second_course/CPP_tasks/SoundProccesor /home/babrakadabra/second_course/CPP_tasks/SoundProccesor /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles/sound_proccesor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sound_proccesor.dir/depend

