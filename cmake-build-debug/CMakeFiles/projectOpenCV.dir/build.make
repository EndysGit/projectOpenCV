# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/Users/Gleb/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/Gleb/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Gleb/CLionProjects/projectOpenCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projectOpenCV.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projectOpenCV.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectOpenCV.dir/flags.make

CMakeFiles/projectOpenCV.dir/main.cpp.o: CMakeFiles/projectOpenCV.dir/flags.make
CMakeFiles/projectOpenCV.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projectOpenCV.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projectOpenCV.dir/main.cpp.o -c /Users/Gleb/CLionProjects/projectOpenCV/main.cpp

CMakeFiles/projectOpenCV.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projectOpenCV.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gleb/CLionProjects/projectOpenCV/main.cpp > CMakeFiles/projectOpenCV.dir/main.cpp.i

CMakeFiles/projectOpenCV.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projectOpenCV.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gleb/CLionProjects/projectOpenCV/main.cpp -o CMakeFiles/projectOpenCV.dir/main.cpp.s

CMakeFiles/projectOpenCV.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/projectOpenCV.dir/main.cpp.o.requires

CMakeFiles/projectOpenCV.dir/main.cpp.o.provides: CMakeFiles/projectOpenCV.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/projectOpenCV.dir/build.make CMakeFiles/projectOpenCV.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/projectOpenCV.dir/main.cpp.o.provides

CMakeFiles/projectOpenCV.dir/main.cpp.o.provides.build: CMakeFiles/projectOpenCV.dir/main.cpp.o


# Object files for target projectOpenCV
projectOpenCV_OBJECTS = \
"CMakeFiles/projectOpenCV.dir/main.cpp.o"

# External object files for target projectOpenCV
projectOpenCV_EXTERNAL_OBJECTS =

projectOpenCV: CMakeFiles/projectOpenCV.dir/main.cpp.o
projectOpenCV: CMakeFiles/projectOpenCV.dir/build.make
projectOpenCV: /usr/local/lib/libopencv_shape.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_stitching.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_superres.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_videostab.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_adas.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_bgsegm.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_bioinspired.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_ccalib.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_datasets.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_face.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_latentsvm.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_line_descriptor.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_reg.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_rgbd.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_saliency.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_surface_matching.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_text.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_tracking.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_ximgproc.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_xobjdetect.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_xphoto.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_objdetect.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_calib3d.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_features2d.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_ml.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_flann.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_video.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_highgui.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_photo.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_videoio.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_imgcodecs.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_imgproc.3.2.0.dylib
projectOpenCV: /usr/local/lib/libopencv_core.3.2.0.dylib
projectOpenCV: CMakeFiles/projectOpenCV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projectOpenCV"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectOpenCV.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projectOpenCV.dir/build: projectOpenCV

.PHONY : CMakeFiles/projectOpenCV.dir/build

CMakeFiles/projectOpenCV.dir/requires: CMakeFiles/projectOpenCV.dir/main.cpp.o.requires

.PHONY : CMakeFiles/projectOpenCV.dir/requires

CMakeFiles/projectOpenCV.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectOpenCV.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectOpenCV.dir/clean

CMakeFiles/projectOpenCV.dir/depend:
	cd /Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Gleb/CLionProjects/projectOpenCV /Users/Gleb/CLionProjects/projectOpenCV /Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug /Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug /Users/Gleb/CLionProjects/projectOpenCV/cmake-build-debug/CMakeFiles/projectOpenCV.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projectOpenCV.dir/depend

