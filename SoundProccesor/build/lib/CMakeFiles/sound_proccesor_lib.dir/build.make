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
include lib/CMakeFiles/sound_proccesor_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/sound_proccesor_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/sound_proccesor_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/sound_proccesor_lib.dir/flags.make

lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/flags.make
lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o: /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/reader.cpp
lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o -MF CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o.d -o CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o -c /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/reader.cpp

lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sound_proccesor_lib.dir/reader.cpp.i"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/reader.cpp > CMakeFiles/sound_proccesor_lib.dir/reader.cpp.i

lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sound_proccesor_lib.dir/reader.cpp.s"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/reader.cpp -o CMakeFiles/sound_proccesor_lib.dir/reader.cpp.s

lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/flags.make
lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o: /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/sound.cpp
lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o -MF CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o.d -o CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o -c /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/sound.cpp

lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sound_proccesor_lib.dir/sound.cpp.i"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/sound.cpp > CMakeFiles/sound_proccesor_lib.dir/sound.cpp.i

lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sound_proccesor_lib.dir/sound.cpp.s"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/sound.cpp -o CMakeFiles/sound_proccesor_lib.dir/sound.cpp.s

lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/flags.make
lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o: /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/Pars.cpp
lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o: lib/CMakeFiles/sound_proccesor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o -MF CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o.d -o CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o -c /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/Pars.cpp

lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.i"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/Pars.cpp > CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.i

lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.s"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib/Pars.cpp -o CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.s

# Object files for target sound_proccesor_lib
sound_proccesor_lib_OBJECTS = \
"CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o" \
"CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o" \
"CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o"

# External object files for target sound_proccesor_lib
sound_proccesor_lib_EXTERNAL_OBJECTS =

lib/libsound_proccesor_lib.a: lib/CMakeFiles/sound_proccesor_lib.dir/reader.cpp.o
lib/libsound_proccesor_lib.a: lib/CMakeFiles/sound_proccesor_lib.dir/sound.cpp.o
lib/libsound_proccesor_lib.a: lib/CMakeFiles/sound_proccesor_lib.dir/Pars.cpp.o
lib/libsound_proccesor_lib.a: lib/CMakeFiles/sound_proccesor_lib.dir/build.make
lib/libsound_proccesor_lib.a: lib/CMakeFiles/sound_proccesor_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsound_proccesor_lib.a"
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/sound_proccesor_lib.dir/cmake_clean_target.cmake
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sound_proccesor_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/sound_proccesor_lib.dir/build: lib/libsound_proccesor_lib.a
.PHONY : lib/CMakeFiles/sound_proccesor_lib.dir/build

lib/CMakeFiles/sound_proccesor_lib.dir/clean:
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/sound_proccesor_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/sound_proccesor_lib.dir/clean

lib/CMakeFiles/sound_proccesor_lib.dir/depend:
	cd /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/babrakadabra/second_course/CPP_tasks/SoundProccesor /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/lib /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib /home/babrakadabra/second_course/CPP_tasks/SoundProccesor/build/lib/CMakeFiles/sound_proccesor_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/CMakeFiles/sound_proccesor_lib.dir/depend

