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
CMAKE_SOURCE_DIR = /home/babrakadabra/second_course/CPP_tasks/1a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/babrakadabra/second_course/CPP_tasks/1a/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/BA_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/BA_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/BA_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/BA_test.dir/flags.make

tests/CMakeFiles/BA_test.dir/test.cpp.o: tests/CMakeFiles/BA_test.dir/flags.make
tests/CMakeFiles/BA_test.dir/test.cpp.o: /home/babrakadabra/second_course/CPP_tasks/1a/tests/test.cpp
tests/CMakeFiles/BA_test.dir/test.cpp.o: tests/CMakeFiles/BA_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/babrakadabra/second_course/CPP_tasks/1a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/BA_test.dir/test.cpp.o"
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/BA_test.dir/test.cpp.o -MF CMakeFiles/BA_test.dir/test.cpp.o.d -o CMakeFiles/BA_test.dir/test.cpp.o -c /home/babrakadabra/second_course/CPP_tasks/1a/tests/test.cpp

tests/CMakeFiles/BA_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BA_test.dir/test.cpp.i"
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/babrakadabra/second_course/CPP_tasks/1a/tests/test.cpp > CMakeFiles/BA_test.dir/test.cpp.i

tests/CMakeFiles/BA_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BA_test.dir/test.cpp.s"
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/babrakadabra/second_course/CPP_tasks/1a/tests/test.cpp -o CMakeFiles/BA_test.dir/test.cpp.s

# Object files for target BA_test
BA_test_OBJECTS = \
"CMakeFiles/BA_test.dir/test.cpp.o"

# External object files for target BA_test
BA_test_EXTERNAL_OBJECTS =

tests/BA_test: tests/CMakeFiles/BA_test.dir/test.cpp.o
tests/BA_test: tests/CMakeFiles/BA_test.dir/build.make
tests/BA_test: lib/libgtest_main.a
tests/BA_test: lib/libbitArray.a
tests/BA_test: lib/libgtest.a
tests/BA_test: tests/CMakeFiles/BA_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/babrakadabra/second_course/CPP_tasks/1a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BA_test"
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BA_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && /usr/bin/cmake -D TEST_TARGET=BA_test -D TEST_EXECUTABLE=/home/babrakadabra/second_course/CPP_tasks/1a/build/tests/BA_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/babrakadabra/second_course/CPP_tasks/1a/build/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=BA_test_TESTS -D CTEST_FILE=/home/babrakadabra/second_course/CPP_tasks/1a/build/tests/BA_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.28/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/BA_test.dir/build: tests/BA_test
.PHONY : tests/CMakeFiles/BA_test.dir/build

tests/CMakeFiles/BA_test.dir/clean:
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/BA_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/BA_test.dir/clean

tests/CMakeFiles/BA_test.dir/depend:
	cd /home/babrakadabra/second_course/CPP_tasks/1a/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/babrakadabra/second_course/CPP_tasks/1a /home/babrakadabra/second_course/CPP_tasks/1a/tests /home/babrakadabra/second_course/CPP_tasks/1a/build /home/babrakadabra/second_course/CPP_tasks/1a/build/tests /home/babrakadabra/second_course/CPP_tasks/1a/build/tests/CMakeFiles/BA_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/BA_test.dir/depend

