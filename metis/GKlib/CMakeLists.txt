cmake_minimum_required(VERSION 2.8)
project(GKlib)

get_filename_component(abs "." ABSOLUTE)
set(GKLIB_PATH ${abs})
unset(abs)
include(GKlibSystem.cmake)

include_directories(".")
add_library(GKlib ${GKlib_sources})
if(UNIX)
  target_link_libraries(GKlib m)
elseif(MSVC)
  include(GenerateExportHeader)
  generate_export_header(GKlib)
endif()

include_directories("test")
add_subdirectory("test")

install(TARGETS GKlib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib)
install(FILES ${GKlib_includes} DESTINATION include)
