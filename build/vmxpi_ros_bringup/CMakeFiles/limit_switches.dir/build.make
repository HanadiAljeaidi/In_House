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
CMAKE_SOURCE_DIR = /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/catkin_ws/build/vmxpi_ros_bringup

# Include any dependencies generated for this target.
include CMakeFiles/limit_switches.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/limit_switches.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/limit_switches.dir/flags.make

CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o: CMakeFiles/limit_switches.dir/flags.make
CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/src/limit_switches.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/catkin_ws/build/vmxpi_ros_bringup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o -c /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/src/limit_switches.cpp

CMakeFiles/limit_switches.dir/src/limit_switches.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/limit_switches.dir/src/limit_switches.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/src/limit_switches.cpp > CMakeFiles/limit_switches.dir/src/limit_switches.cpp.i

CMakeFiles/limit_switches.dir/src/limit_switches.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/limit_switches.dir/src/limit_switches.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/src/limit_switches.cpp -o CMakeFiles/limit_switches.dir/src/limit_switches.cpp.s

# Object files for target limit_switches
limit_switches_OBJECTS = \
"CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o"

# External object files for target limit_switches
limit_switches_EXTERNAL_OBJECTS =

/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: CMakeFiles/limit_switches.dir/src/limit_switches.cpp.o
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: CMakeFiles/limit_switches.dir/build.make
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/local/lib/vmxpi/libvmxpi_hal_cpp.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libnavx_ros_wrapper.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libtitandriver_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libtitandriver_ros_wrapper.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libcobra_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libsharp_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libservo_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libultrasonic_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libiowd_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libdigitalin_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup/../../../devel/lib/libdigitalout_ros.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/libroscpp.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/librosconsole.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/libdynamic_reconfigure_config_init_mutex.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/librostime.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /opt/ros/noetic/lib/libcpp_common.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so.0.4
/home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches: CMakeFiles/limit_switches.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/catkin_ws/build/vmxpi_ros_bringup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/limit_switches.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/limit_switches.dir/build: /home/pi/catkin_ws/devel/.private/vmxpi_ros_bringup/lib/vmxpi_ros_bringup/limit_switches

.PHONY : CMakeFiles/limit_switches.dir/build

CMakeFiles/limit_switches.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/limit_switches.dir/cmake_clean.cmake
.PHONY : CMakeFiles/limit_switches.dir/clean

CMakeFiles/limit_switches.dir/depend:
	cd /home/pi/catkin_ws/build/vmxpi_ros_bringup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup /home/pi/catkin_ws/src/vmxpi_ros/vmxpi_ros_bringup /home/pi/catkin_ws/build/vmxpi_ros_bringup /home/pi/catkin_ws/build/vmxpi_ros_bringup /home/pi/catkin_ws/build/vmxpi_ros_bringup/CMakeFiles/limit_switches.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/limit_switches.dir/depend

