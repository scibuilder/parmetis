cmake_minimum_required(VERSION 2.8)
project(METIS)

set(GKLIB_PATH "GKlib" CACHE PATH "path to GKlib")

include(${GKLIB_PATH}/GKlibSystem.cmake)
# Add include directories.
include_directories(${GKLIB_PATH})
include_directories(include)
# Recursively look for CMakeLists.txt in subdirs.
add_subdirectory("include")
add_subdirectory("libmetis")
#add_subdirectory("programs")
