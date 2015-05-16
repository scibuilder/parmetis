# Helper modules.
include(CheckFunctionExists)
include(CheckIncludeFile)

# Setup options.
option(GDB "enable use of GDB" OFF)
option(ASSERT "turn asserts on" OFF)
option(ASSERT2 "additional assertions" OFF)
option(DEBUG "add debugging support" OFF)
option(GPROF "add gprof support" OFF)
option(OPENMP "enable OpenMP support" OFF)
option(PCRE "enable PCRE support" OFF)
if(MSVC OR MINGW)
  option(GKREGEX "enable GKREGEX support" ON)
else()
  option(GKREGEX "enable GKREGEX support" OFF)
endif()
option(GKRAND "enable GKRAND support" OFF)

# Add compiler flags.
if(MSVC)
  set(GKlib_COPTS "/Ox")
  add_definitions(-DWIN32 -DMSC -D_CRT_SECURE_NO_DEPRECATE)
elseif(NOT MINGW)
  set(GKlib_COPTS "-O3")
  add_definitions(-DLINUX -D_FILE_OFFSET_BITS=64)
endif()
if(CYGWIN)
  add_definitions(-DCYGWIN)
endif(CYGWIN)
if(CMAKE_COMPILER_IS_GNUCC)
# GCC opts.
  set(GKlib_COPTIONS "${GKlib_COPTIONS} -std=c99 -fno-strict-aliasing")
  if(NOT MINGW)
      set(GKlib_COPTIONS "${GKlib_COPTIONS} -fPIC")
  endif(NOT MINGW)
# GCC warnings.
  set(GKlib_COPTIONS "${GKlib_COPTIONS} -Wall -pedantic -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unknown-pragmas")
elseif(${CMAKE_C_COMPILER_ID} MATCHES "Sun")
# Sun insists on -xc99.
  set(GKlib_COPTIONS "${GKlib_COPTIONS} -xc99")
endif(CMAKE_COMPILER_IS_GNUCC)

# Find OpenMP if it is requested.
if(OPENMP)
  include(FindOpenMP)
  if(OPENMP_FOUND)
    add_definitions(-D__OPENMP__)
    set(GKlib_COPTIONS "${GKlib_COPTIONS} ${OpenMP_C_FLAGS}")
  else()
    message(WARNING "OpenMP was requested but support was not found")
  endif(OPENMP_FOUND)
endif(OPENMP)


# Add various definitions.
if(GDB)
  set(GKlib_COPTS "${GKlib_COPTS} -g")
  set(GKlib_COPTIONS "${GKlib_COPTIONS} -Werror")
endif(GDB)

if(DEBUG)
  add_definitions(-DDEBUG)
  set(GKlib_COPTS "-g")
endif(DEBUG)

if(GPROF)
  set(GKlib_COPTS "-pg")
endif(GPROF)

if(NOT ASSERT)
  add_definitions(-DNDEBUG)
endif(NOT ASSERT)

if(NOT ASSERT2)
  add_definitions(-DNDEBUG2)
endif(NOT ASSERT2)

if(PCRE)
  add_definitions(-D__WITHPCRE__)
endif(PCRE)

if(GKREGEX)
  add_definitions(-DUSE_GKREGEX)
endif(GKREGEX)

if(GKRAND)
  add_definitions(-DUSE_GKRAND)
endif(GKRAND)

# Check for features.
check_include_file(execinfo.h HAVE_EXECINFO_H)
if(HAVE_EXECINFO_H)
  add_definitions(-DHAVE_EXECINFO_H)
endif(HAVE_EXECINFO_H)

check_function_exists(getline HAVE_GETLINE)
if(HAVE_GETLINE)
  add_definitions(-DHAVE_GETLINE)
endif(HAVE_GETLINE)


# Custom check for TLS.
if(MSVC)
  add_definitions(-D__thread=__declspec(thread))
else()
  # This if checks if that value is cached or not.
  if("${HAVE_THREADLOCALSTORAGE}" MATCHES "^${HAVE_THREADLOCALSTORAGE}$")
    try_compile(HAVE_THREADLOCALSTORAGE
      ${CMAKE_BINARY_DIR}
      ${GKLIB_PATH}/conf/check_thread_storage.c)
    if(HAVE_THREADLOCALSTORAGE)
      message(STATUS "checking for thread-local storage - found")
    else()
      message(STATUS "checking for thread-local storage - not found")
    endif()
  endif()
  if(NOT HAVE_THREADLOCALSTORAGE)
    add_definitions(-D__thread=)
  endif()
endif()

# Finally set the official C flags.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GKlib_COPTIONS} ${GKlib_COPTS}")

# Find GKlib sources.
file(GLOB GKlib_sources ${GKLIB_PATH}/*.c)
file(GLOB GKlib_includes ${GKLIB_PATH}/*.h)
