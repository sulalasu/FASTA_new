# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug

# Include any dependencies generated for this target.
include CMakeFiles/fasta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fasta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fasta.dir/flags.make

CMakeFiles/fasta.dir/src/main.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fasta.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/src/main.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/src/main.cpp

CMakeFiles/fasta.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/src/main.cpp > CMakeFiles/fasta.dir/src/main.cpp.i

CMakeFiles/fasta.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/src/main.cpp -o CMakeFiles/fasta.dir/src/main.cpp.s

CMakeFiles/fasta.dir/lib/Fasta.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/lib/Fasta.cpp.o: ../lib/Fasta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fasta.dir/lib/Fasta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/lib/Fasta.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Fasta.cpp

CMakeFiles/fasta.dir/lib/Fasta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/lib/Fasta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Fasta.cpp > CMakeFiles/fasta.dir/lib/Fasta.cpp.i

CMakeFiles/fasta.dir/lib/Fasta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/lib/Fasta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Fasta.cpp -o CMakeFiles/fasta.dir/lib/Fasta.cpp.s

CMakeFiles/fasta.dir/lib/FastaFile.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/lib/FastaFile.cpp.o: ../lib/FastaFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fasta.dir/lib/FastaFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/lib/FastaFile.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/FastaFile.cpp

CMakeFiles/fasta.dir/lib/FastaFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/lib/FastaFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/FastaFile.cpp > CMakeFiles/fasta.dir/lib/FastaFile.cpp.i

CMakeFiles/fasta.dir/lib/FastaFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/lib/FastaFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/FastaFile.cpp -o CMakeFiles/fasta.dir/lib/FastaFile.cpp.s

CMakeFiles/fasta.dir/lib/Header.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/lib/Header.cpp.o: ../lib/Header.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fasta.dir/lib/Header.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/lib/Header.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Header.cpp

CMakeFiles/fasta.dir/lib/Header.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/lib/Header.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Header.cpp > CMakeFiles/fasta.dir/lib/Header.cpp.i

CMakeFiles/fasta.dir/lib/Header.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/lib/Header.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Header.cpp -o CMakeFiles/fasta.dir/lib/Header.cpp.s

CMakeFiles/fasta.dir/lib/Helper.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/lib/Helper.cpp.o: ../lib/Helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fasta.dir/lib/Helper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/lib/Helper.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Helper.cpp

CMakeFiles/fasta.dir/lib/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/lib/Helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Helper.cpp > CMakeFiles/fasta.dir/lib/Helper.cpp.i

CMakeFiles/fasta.dir/lib/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/lib/Helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Helper.cpp -o CMakeFiles/fasta.dir/lib/Helper.cpp.s

CMakeFiles/fasta.dir/lib/Sequence.cpp.o: CMakeFiles/fasta.dir/flags.make
CMakeFiles/fasta.dir/lib/Sequence.cpp.o: ../lib/Sequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fasta.dir/lib/Sequence.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fasta.dir/lib/Sequence.cpp.o -c /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Sequence.cpp

CMakeFiles/fasta.dir/lib/Sequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fasta.dir/lib/Sequence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Sequence.cpp > CMakeFiles/fasta.dir/lib/Sequence.cpp.i

CMakeFiles/fasta.dir/lib/Sequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fasta.dir/lib/Sequence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/lib/Sequence.cpp -o CMakeFiles/fasta.dir/lib/Sequence.cpp.s

# Object files for target fasta
fasta_OBJECTS = \
"CMakeFiles/fasta.dir/src/main.cpp.o" \
"CMakeFiles/fasta.dir/lib/Fasta.cpp.o" \
"CMakeFiles/fasta.dir/lib/FastaFile.cpp.o" \
"CMakeFiles/fasta.dir/lib/Header.cpp.o" \
"CMakeFiles/fasta.dir/lib/Helper.cpp.o" \
"CMakeFiles/fasta.dir/lib/Sequence.cpp.o"

# External object files for target fasta
fasta_EXTERNAL_OBJECTS =

fasta: CMakeFiles/fasta.dir/src/main.cpp.o
fasta: CMakeFiles/fasta.dir/lib/Fasta.cpp.o
fasta: CMakeFiles/fasta.dir/lib/FastaFile.cpp.o
fasta: CMakeFiles/fasta.dir/lib/Header.cpp.o
fasta: CMakeFiles/fasta.dir/lib/Helper.cpp.o
fasta: CMakeFiles/fasta.dir/lib/Sequence.cpp.o
fasta: CMakeFiles/fasta.dir/build.make
fasta: CMakeFiles/fasta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable fasta"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fasta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fasta.dir/build: fasta

.PHONY : CMakeFiles/fasta.dir/build

CMakeFiles/fasta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fasta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fasta.dir/clean

CMakeFiles/fasta.dir/depend:
	cd /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug /home/lukasu/Desktop/24-SS-Softwareentwicklung_Projekt_FASTA_NEU/FASTA_new/Debug/CMakeFiles/fasta.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fasta.dir/depend
