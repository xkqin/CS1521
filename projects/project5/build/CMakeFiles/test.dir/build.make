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
CMAKE_SOURCE_DIR = /home/csugrads/qinxx215/CS1521/projects/project5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csugrads/qinxx215/CS1521/projects/project5/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/Disc.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Disc.cpp.o: ../Disc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/Disc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Disc.cpp.o -c /home/csugrads/qinxx215/CS1521/projects/project5/Disc.cpp

CMakeFiles/test.dir/Disc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Disc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csugrads/qinxx215/CS1521/projects/project5/Disc.cpp > CMakeFiles/test.dir/Disc.cpp.i

CMakeFiles/test.dir/Disc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Disc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csugrads/qinxx215/CS1521/projects/project5/Disc.cpp -o CMakeFiles/test.dir/Disc.cpp.s

CMakeFiles/test.dir/Disc.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/Disc.cpp.o.requires

CMakeFiles/test.dir/Disc.cpp.o.provides: CMakeFiles/test.dir/Disc.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/Disc.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/Disc.cpp.o.provides

CMakeFiles/test.dir/Disc.cpp.o.provides.build: CMakeFiles/test.dir/Disc.cpp.o


CMakeFiles/test.dir/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/main.cpp.o -c /home/csugrads/qinxx215/CS1521/projects/project5/main.cpp

CMakeFiles/test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csugrads/qinxx215/CS1521/projects/project5/main.cpp > CMakeFiles/test.dir/main.cpp.i

CMakeFiles/test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csugrads/qinxx215/CS1521/projects/project5/main.cpp -o CMakeFiles/test.dir/main.cpp.s

CMakeFiles/test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/main.cpp.o.requires

CMakeFiles/test.dir/main.cpp.o.provides: CMakeFiles/test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/main.cpp.o.provides

CMakeFiles/test.dir/main.cpp.o.provides.build: CMakeFiles/test.dir/main.cpp.o


CMakeFiles/test.dir/DiscList.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/DiscList.cpp.o: ../DiscList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/DiscList.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/DiscList.cpp.o -c /home/csugrads/qinxx215/CS1521/projects/project5/DiscList.cpp

CMakeFiles/test.dir/DiscList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/DiscList.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csugrads/qinxx215/CS1521/projects/project5/DiscList.cpp > CMakeFiles/test.dir/DiscList.cpp.i

CMakeFiles/test.dir/DiscList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/DiscList.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csugrads/qinxx215/CS1521/projects/project5/DiscList.cpp -o CMakeFiles/test.dir/DiscList.cpp.s

CMakeFiles/test.dir/DiscList.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/DiscList.cpp.o.requires

CMakeFiles/test.dir/DiscList.cpp.o.provides: CMakeFiles/test.dir/DiscList.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/DiscList.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/DiscList.cpp.o.provides

CMakeFiles/test.dir/DiscList.cpp.o.provides.build: CMakeFiles/test.dir/DiscList.cpp.o


CMakeFiles/test.dir/Track.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Track.cpp.o: ../Track.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/Track.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Track.cpp.o -c /home/csugrads/qinxx215/CS1521/projects/project5/Track.cpp

CMakeFiles/test.dir/Track.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Track.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csugrads/qinxx215/CS1521/projects/project5/Track.cpp > CMakeFiles/test.dir/Track.cpp.i

CMakeFiles/test.dir/Track.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Track.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csugrads/qinxx215/CS1521/projects/project5/Track.cpp -o CMakeFiles/test.dir/Track.cpp.s

CMakeFiles/test.dir/Track.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/Track.cpp.o.requires

CMakeFiles/test.dir/Track.cpp.o.provides: CMakeFiles/test.dir/Track.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/Track.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/Track.cpp.o.provides

CMakeFiles/test.dir/Track.cpp.o.provides.build: CMakeFiles/test.dir/Track.cpp.o


CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o: ../PrecondViolatedExcep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o -c /home/csugrads/qinxx215/CS1521/projects/project5/PrecondViolatedExcep.cpp

CMakeFiles/test.dir/PrecondViolatedExcep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/PrecondViolatedExcep.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csugrads/qinxx215/CS1521/projects/project5/PrecondViolatedExcep.cpp > CMakeFiles/test.dir/PrecondViolatedExcep.cpp.i

CMakeFiles/test.dir/PrecondViolatedExcep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/PrecondViolatedExcep.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csugrads/qinxx215/CS1521/projects/project5/PrecondViolatedExcep.cpp -o CMakeFiles/test.dir/PrecondViolatedExcep.cpp.s

CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.requires:

.PHONY : CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.requires

CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.provides: CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.provides

CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.provides.build: CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o


# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/Disc.cpp.o" \
"CMakeFiles/test.dir/main.cpp.o" \
"CMakeFiles/test.dir/DiscList.cpp.o" \
"CMakeFiles/test.dir/Track.cpp.o" \
"CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/Disc.cpp.o
test: CMakeFiles/test.dir/main.cpp.o
test: CMakeFiles/test.dir/DiscList.cpp.o
test: CMakeFiles/test.dir/Track.cpp.o
test: CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/Disc.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/main.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/DiscList.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/Track.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/PrecondViolatedExcep.cpp.o.requires

.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/csugrads/qinxx215/CS1521/projects/project5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csugrads/qinxx215/CS1521/projects/project5 /home/csugrads/qinxx215/CS1521/projects/project5 /home/csugrads/qinxx215/CS1521/projects/project5/build /home/csugrads/qinxx215/CS1521/projects/project5/build /home/csugrads/qinxx215/CS1521/projects/project5/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

