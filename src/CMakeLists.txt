cmake_minimum_required (VERSION 2.6)

project (algorithm-cpp)

set (PRO_VERSION_MAJOR 1)
set (PRO_VERSION_MINOR 0)

set(CXX_FLAGS
  -g
  -Wall
  -std=c++11)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_library(PTHREAD_LIB pthread)
if(NOT PTHREAD_LIB)
  message(FATAL_ERROR "not found pthread")
endif()

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory (container)
add_subdirectory (algo)
# add_subdirectory (test)
# add_subdirectory (algorithm)

add_executable (main main.cc)
target_link_libraries(main container algo)
