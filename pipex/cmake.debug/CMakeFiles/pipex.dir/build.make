# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Users/rmander/.brew/Cellar/cmake/3.20.1/bin/cmake

# The command to remove a file.
RM = /Users/rmander/.brew/Cellar/cmake/3.20.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rmander/Dev/42/pipex/pipex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rmander/Dev/42/pipex/pipex/cmake.debug

# Include any dependencies generated for this target.
include CMakeFiles/pipex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipex.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipex.dir/flags.make

CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o: ../src/utils/ft_strlen_until.c
CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o -MF CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o.d -o CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strlen_until.c

CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strlen_until.c > CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.i

CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strlen_until.c -o CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.s

CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o: ../src/utils/ft_strdup_until.c
CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o -MF CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o.d -o CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strdup_until.c

CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strdup_until.c > CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.i

CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_strdup_until.c -o CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.s

CMakeFiles/pipex.dir/src/utils/ft_split.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/utils/ft_split.c.o: ../src/utils/ft_split.c
CMakeFiles/pipex.dir/src/utils/ft_split.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pipex.dir/src/utils/ft_split.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/utils/ft_split.c.o -MF CMakeFiles/pipex.dir/src/utils/ft_split.c.o.d -o CMakeFiles/pipex.dir/src/utils/ft_split.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_split.c

CMakeFiles/pipex.dir/src/utils/ft_split.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/utils/ft_split.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_split.c > CMakeFiles/pipex.dir/src/utils/ft_split.c.i

CMakeFiles/pipex.dir/src/utils/ft_split.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/utils/ft_split.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/utils/ft_split.c -o CMakeFiles/pipex.dir/src/utils/ft_split.c.s

CMakeFiles/pipex.dir/src/pipex.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/pipex.c.o: ../src/pipex.c
CMakeFiles/pipex.dir/src/pipex.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pipex.dir/src/pipex.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/pipex.c.o -MF CMakeFiles/pipex.dir/src/pipex.c.o.d -o CMakeFiles/pipex.dir/src/pipex.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/pipex.c

CMakeFiles/pipex.dir/src/pipex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/pipex.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/pipex.c > CMakeFiles/pipex.dir/src/pipex.c.i

CMakeFiles/pipex.dir/src/pipex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/pipex.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/pipex.c -o CMakeFiles/pipex.dir/src/pipex.c.s

CMakeFiles/pipex.dir/src/error.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/error.c.o: ../src/error.c
CMakeFiles/pipex.dir/src/error.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/pipex.dir/src/error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/error.c.o -MF CMakeFiles/pipex.dir/src/error.c.o.d -o CMakeFiles/pipex.dir/src/error.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/error.c

CMakeFiles/pipex.dir/src/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/error.c > CMakeFiles/pipex.dir/src/error.c.i

CMakeFiles/pipex.dir/src/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/error.c -o CMakeFiles/pipex.dir/src/error.c.s

CMakeFiles/pipex.dir/src/parse.c.o: CMakeFiles/pipex.dir/flags.make
CMakeFiles/pipex.dir/src/parse.c.o: ../src/parse.c
CMakeFiles/pipex.dir/src/parse.c.o: CMakeFiles/pipex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/pipex.dir/src/parse.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipex.dir/src/parse.c.o -MF CMakeFiles/pipex.dir/src/parse.c.o.d -o CMakeFiles/pipex.dir/src/parse.c.o -c /Users/rmander/Dev/42/pipex/pipex/src/parse.c

CMakeFiles/pipex.dir/src/parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipex.dir/src/parse.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmander/Dev/42/pipex/pipex/src/parse.c > CMakeFiles/pipex.dir/src/parse.c.i

CMakeFiles/pipex.dir/src/parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipex.dir/src/parse.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmander/Dev/42/pipex/pipex/src/parse.c -o CMakeFiles/pipex.dir/src/parse.c.s

# Object files for target pipex
pipex_OBJECTS = \
"CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o" \
"CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o" \
"CMakeFiles/pipex.dir/src/utils/ft_split.c.o" \
"CMakeFiles/pipex.dir/src/pipex.c.o" \
"CMakeFiles/pipex.dir/src/error.c.o" \
"CMakeFiles/pipex.dir/src/parse.c.o"

# External object files for target pipex
pipex_EXTERNAL_OBJECTS =

pipex: CMakeFiles/pipex.dir/src/utils/ft_strlen_until.c.o
pipex: CMakeFiles/pipex.dir/src/utils/ft_strdup_until.c.o
pipex: CMakeFiles/pipex.dir/src/utils/ft_split.c.o
pipex: CMakeFiles/pipex.dir/src/pipex.c.o
pipex: CMakeFiles/pipex.dir/src/error.c.o
pipex: CMakeFiles/pipex.dir/src/parse.c.o
pipex: CMakeFiles/pipex.dir/build.make
pipex: CMakeFiles/pipex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable pipex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipex.dir/build: pipex
.PHONY : CMakeFiles/pipex.dir/build

CMakeFiles/pipex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipex.dir/clean

CMakeFiles/pipex.dir/depend:
	cd /Users/rmander/Dev/42/pipex/pipex/cmake.debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rmander/Dev/42/pipex/pipex /Users/rmander/Dev/42/pipex/pipex /Users/rmander/Dev/42/pipex/pipex/cmake.debug /Users/rmander/Dev/42/pipex/pipex/cmake.debug /Users/rmander/Dev/42/pipex/pipex/cmake.debug/CMakeFiles/pipex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipex.dir/depend

