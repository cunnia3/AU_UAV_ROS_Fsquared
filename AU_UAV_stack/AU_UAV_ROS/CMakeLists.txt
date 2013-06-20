cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
rosbuild_genmsg()
#uncomment if you have defined services
rosbuild_gensrv()

SET(
  CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake
)
include(cmake/FindGLIB2.cmake)
include(cmake/FindGTHREAD2.cmake)

FIND_PACKAGE(GLIB2  REQUIRED)
FIND_PACKAGE(GTHREAD2  REQUIRED)

INCLUDE_DIRECTORIES(
  ${MAVLINK_INCLUDE_DIR}
  ${GLIB2_MAIN_INCLUDE_DIR}
  ${GLIB2_INTERNAL_INCLUDE_DIR}
  ${GTHREAD2_MAIN_INCLUDE_DIR}
  ../include/
)

#add_jar_dir(/usr/share/java)
#add_runtime_classpath(${PROJECT_SOURCE_DIR}/bin)
#add_java_source_dir(${PROJECT_SOURCE_DIR}/src/JAVA)

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

#this is for unit-testing
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#rosbuild_add_gtest(test/PlaneCoordinatorTest test/PlaneCoordinatorTest.cpp)
rosbuild_add_gtest(test/standardDefsTest test/StandardDefsTest.cpp)
rosbuild_add_gtest(test/XbeeIOTest test/XbeeIOTest.cpp)


#C++ executables
rosbuild_add_executable(simulator src/simulator.cpp src/AU_UAV_ROS/SimulatedPlane.cpp src/AU_UAV_ROS/standardDefs.cpp src/planeObject.cpp src/standardFuncs.cpp src/ripna.cpp src/vmath.cpp)
#target_link_libraries(simulator Geographic noise)
rosbuild_add_executable(distSimulator src/distSimulator.cpp src/AU_UAV_ROS/SimulatedPlane.cpp src/AU_UAV_ROS/standardDefs.cpp src/standardFuncs.cpp src/planeObject.cpp src/ripna.cpp src/vmath.cpp)
#add our fsquared for plane
target_link_libraries(distSimulator fsquared)
target_link_libraries(simulator fsquared)
rosbuild_add_executable(collisionAvoidance src/collisionAvoidance.cpp src/AU_UAV_ROS/standardDefs.cpp src/standardFuncs.cpp src/planeObject.cpp src/ripna.cpp src/vmath.cpp)
#adding our fsquared for plane object
target_link_libraries(collisionAvoidance fsquared)

rosbuild_add_executable(coordinator src/coordinator.cpp src/AU_UAV_ROS/PlaneCoordinator.cpp src/AU_UAV_ROS/standardDefs.cpp)
rosbuild_add_executable(ControlMenu src/ControlMenu.cpp src/AU_UAV_ROS/standardDefs.cpp)
rosbuild_add_executable(KMLCreator src/KMLCreator.cpp)
rosbuild_add_executable(visualization src/visualization.cpp)
rosbuild_add_executable(evaluator src/evaluator.cpp src/AU_UAV_ROS/standardDefs.cpp)
rosbuild_add_executable(XbeeIO src/XbeeIO.cpp)
#New - JC
#There is an easier way to do this if we want to change it. We can just glob all the .cpp files.
rosbuild_add_executable(guiInterfacer src/guiInterfacer.cpp src/AU_UAV_ROS/standardDefs.cpp)
target_link_libraries(XbeeIO
  ${GLIB2_LIBRARY}
  ${GTHREAD2_LIBRARY}
)

#FSQUARED 2013
#------------
#FSQUARED Library
#Attempt at making life easier, and only compiling our f^2 library.
#rosbuild_add_library(fsquared src/ForceField.cpp src/Fsquared.cpp src/vmath.cpp src/planeObject.cpp src/standardFuncs.cpp)
rosbuild_add_library(fsquared src/ForceField.cpp src/Fsquared.cpp src/vmath.cpp src/planeObject.cpp src/standardFuncs.cpp src/ForceField.cpp)

#Testing and stuff
rosbuild_add_gtest(test/Fsquared_test test/FSquared_test.cpp)
target_link_libraries(test/Fsquared_test fsquared)
rosbuild_add_gtest(test/ForceShape_test test/ForceShape_test.cpp)
target_link_libraries(test/ForceShape_test fsquared)
rosbuild_add_gtest(test/andrew_Fsquared_test test/andrew_Fsquared_test.cpp)
target_link_libraries(test/andrew_Fsquared_test fsquared)
