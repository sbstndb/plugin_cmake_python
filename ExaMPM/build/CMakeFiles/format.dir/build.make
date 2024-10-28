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
CMAKE_SOURCE_DIR = /home/sbstndbs/3/plugin_cmake_python/ExaMPM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sbstndbs/3/plugin_cmake_python/ExaMPM/build

# Utility rule file for format.

# Include any custom commands dependencies for this target.
include CMakeFiles/format.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/format.dir/progress.make

CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/dam_break.cpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/dam_break.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/free_fall.cpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/main.cpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_BoundaryConditions.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_DenseLinearAlgebra.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Mesh.cpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Mesh.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_ParticleInit.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_ProblemManager.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Solver.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_TimeIntegrator.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_TimeStepControl.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Types.hpp
CMakeFiles/format: /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_VelocityInterpolation.hpp
	/home/sbstndbs/.local/bin/clang-format -i -style=file /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/dam_break.cpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/dam_break.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/free_fall.cpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/examples/main.cpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_BoundaryConditions.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_DenseLinearAlgebra.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Mesh.cpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Mesh.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_ParticleInit.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_ProblemManager.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Solver.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_TimeIntegrator.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_TimeStepControl.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_Types.hpp /home/sbstndbs/3/plugin_cmake_python/ExaMPM/src/ExaMPM_VelocityInterpolation.hpp

format: CMakeFiles/format
format: CMakeFiles/format.dir/build.make
.PHONY : format

# Rule to build all files generated by this target.
CMakeFiles/format.dir/build: format
.PHONY : CMakeFiles/format.dir/build

CMakeFiles/format.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/format.dir/cmake_clean.cmake
.PHONY : CMakeFiles/format.dir/clean

CMakeFiles/format.dir/depend:
	cd /home/sbstndbs/3/plugin_cmake_python/ExaMPM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sbstndbs/3/plugin_cmake_python/ExaMPM /home/sbstndbs/3/plugin_cmake_python/ExaMPM /home/sbstndbs/3/plugin_cmake_python/ExaMPM/build /home/sbstndbs/3/plugin_cmake_python/ExaMPM/build /home/sbstndbs/3/plugin_cmake_python/ExaMPM/build/CMakeFiles/format.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/format.dir/depend
