# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/petros/QtDice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/petros/QtDice/build

# Include any dependencies generated for this target.
include CMakeFiles/QtDice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QtDice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtDice.dir/flags.make

CMakeFiles/QtDice.dir/src/main.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QtDice.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/main.cpp.o -c /Users/petros/QtDice/src/main.cpp

CMakeFiles/QtDice.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/main.cpp > CMakeFiles/QtDice.dir/src/main.cpp.i

CMakeFiles/QtDice.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/main.cpp -o CMakeFiles/QtDice.dir/src/main.cpp.s

CMakeFiles/QtDice.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/main.cpp.o.requires

CMakeFiles/QtDice.dir/src/main.cpp.o.provides: CMakeFiles/QtDice.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/main.cpp.o.provides

CMakeFiles/QtDice.dir/src/main.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/main.cpp.o


CMakeFiles/QtDice.dir/src/qtdice.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/qtdice.cpp.o: ../src/qtdice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QtDice.dir/src/qtdice.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/qtdice.cpp.o -c /Users/petros/QtDice/src/qtdice.cpp

CMakeFiles/QtDice.dir/src/qtdice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/qtdice.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/qtdice.cpp > CMakeFiles/QtDice.dir/src/qtdice.cpp.i

CMakeFiles/QtDice.dir/src/qtdice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/qtdice.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/qtdice.cpp -o CMakeFiles/QtDice.dir/src/qtdice.cpp.s

CMakeFiles/QtDice.dir/src/qtdice.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/qtdice.cpp.o.requires

CMakeFiles/QtDice.dir/src/qtdice.cpp.o.provides: CMakeFiles/QtDice.dir/src/qtdice.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/qtdice.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/qtdice.cpp.o.provides

CMakeFiles/QtDice.dir/src/qtdice.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/qtdice.cpp.o


CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o: ../src/Dice/dice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o -c /Users/petros/QtDice/src/Dice/dice.cpp

CMakeFiles/QtDice.dir/src/Dice/dice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/Dice/dice.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/Dice/dice.cpp > CMakeFiles/QtDice.dir/src/Dice/dice.cpp.i

CMakeFiles/QtDice.dir/src/Dice/dice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/Dice/dice.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/Dice/dice.cpp -o CMakeFiles/QtDice.dir/src/Dice/dice.cpp.s

CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.requires

CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.provides: CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.provides

CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o


CMakeFiles/QtDice.dir/src/About/about.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/About/about.cpp.o: ../src/About/about.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QtDice.dir/src/About/about.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/About/about.cpp.o -c /Users/petros/QtDice/src/About/about.cpp

CMakeFiles/QtDice.dir/src/About/about.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/About/about.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/About/about.cpp > CMakeFiles/QtDice.dir/src/About/about.cpp.i

CMakeFiles/QtDice.dir/src/About/about.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/About/about.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/About/about.cpp -o CMakeFiles/QtDice.dir/src/About/about.cpp.s

CMakeFiles/QtDice.dir/src/About/about.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/About/about.cpp.o.requires

CMakeFiles/QtDice.dir/src/About/about.cpp.o.provides: CMakeFiles/QtDice.dir/src/About/about.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/About/about.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/About/about.cpp.o.provides

CMakeFiles/QtDice.dir/src/About/about.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/About/about.cpp.o


CMakeFiles/QtDice.dir/src/About/infotab.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/About/infotab.cpp.o: ../src/About/infotab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QtDice.dir/src/About/infotab.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/About/infotab.cpp.o -c /Users/petros/QtDice/src/About/infotab.cpp

CMakeFiles/QtDice.dir/src/About/infotab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/About/infotab.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/About/infotab.cpp > CMakeFiles/QtDice.dir/src/About/infotab.cpp.i

CMakeFiles/QtDice.dir/src/About/infotab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/About/infotab.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/About/infotab.cpp -o CMakeFiles/QtDice.dir/src/About/infotab.cpp.s

CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.requires

CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.provides: CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.provides

CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/About/infotab.cpp.o


CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o: ../src/Settings/configure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o -c /Users/petros/QtDice/src/Settings/configure.cpp

CMakeFiles/QtDice.dir/src/Settings/configure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/src/Settings/configure.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/src/Settings/configure.cpp > CMakeFiles/QtDice.dir/src/Settings/configure.cpp.i

CMakeFiles/QtDice.dir/src/Settings/configure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/src/Settings/configure.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/src/Settings/configure.cpp -o CMakeFiles/QtDice.dir/src/Settings/configure.cpp.s

CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.requires

CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.provides: CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.provides

CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.provides.build: CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o


CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o: QtDice_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o -c /Users/petros/QtDice/build/QtDice_autogen/mocs_compilation.cpp

CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/build/QtDice_autogen/mocs_compilation.cpp > CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.i

CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/build/QtDice_autogen/mocs_compilation.cpp -o CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.s

CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o


CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o: CMakeFiles/QtDice.dir/flags.make
CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o: QtDice_autogen/3333JJZB4S/qrc_dice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o -c /Users/petros/QtDice/build/QtDice_autogen/3333JJZB4S/qrc_dice.cpp

CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petros/QtDice/build/QtDice_autogen/3333JJZB4S/qrc_dice.cpp > CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.i

CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petros/QtDice/build/QtDice_autogen/3333JJZB4S/qrc_dice.cpp -o CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.s

CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.requires:

.PHONY : CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.requires

CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.provides: CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtDice.dir/build.make CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.provides.build
.PHONY : CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.provides

CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.provides.build: CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o


# Object files for target QtDice
QtDice_OBJECTS = \
"CMakeFiles/QtDice.dir/src/main.cpp.o" \
"CMakeFiles/QtDice.dir/src/qtdice.cpp.o" \
"CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o" \
"CMakeFiles/QtDice.dir/src/About/about.cpp.o" \
"CMakeFiles/QtDice.dir/src/About/infotab.cpp.o" \
"CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o" \
"CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o"

# External object files for target QtDice
QtDice_EXTERNAL_OBJECTS =

QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/main.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/qtdice.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/About/about.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/About/infotab.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/build.make
QtDice.app/Contents/MacOS/QtDice: CMakeFiles/QtDice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/petros/QtDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable QtDice.app/Contents/MacOS/QtDice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtDice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtDice.dir/build: QtDice.app/Contents/MacOS/QtDice

.PHONY : CMakeFiles/QtDice.dir/build

CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/main.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/qtdice.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/Dice/dice.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/About/about.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/About/infotab.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/src/Settings/configure.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/QtDice_autogen/mocs_compilation.cpp.o.requires
CMakeFiles/QtDice.dir/requires: CMakeFiles/QtDice.dir/QtDice_autogen/3333JJZB4S/qrc_dice.cpp.o.requires

.PHONY : CMakeFiles/QtDice.dir/requires

CMakeFiles/QtDice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtDice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtDice.dir/clean

CMakeFiles/QtDice.dir/depend:
	cd /Users/petros/QtDice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/petros/QtDice /Users/petros/QtDice /Users/petros/QtDice/build /Users/petros/QtDice/build /Users/petros/QtDice/build/CMakeFiles/QtDice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtDice.dir/depend
