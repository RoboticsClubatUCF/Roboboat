# Find module for the UCF Utilities libraries.
#
# If the library is in a specific path, set UCFUTILITIES_ROOT to that directory in your CMakeLists.txt before
# calling find_package(UCFUtilities)
#
# Sets the following variables
# - UCFUtilities_FOUND        : Whether the utilities library was found.
# - UCFUTILITIES_INCLUDE_DIRS : Path to the include directories.
# - UCFUTILITIES_LIBS         : Path to the libraries.

set(FIND_UCFUTILITIES_PATHS
    ${UCFUTILITIES_ROOT}
    /usr/local
    /usr/local/include)

find_path(UCFUTILITIES_INCLUDE_DIRS
          NAMES byte_buffer.h
          PATHS ${FIND_UCFUTILITIES_PATHS}
          PATH_SUFFIXES ucf_utilities)

if(NOT UCFUTILITIES_INCLUDE_DIRS)
    message("Could not find UCFUtilities includes in ${FIND_UCFUTILITIES_PATHS}")
endif()
          
find_library(UCFUTILITIES_LIBS
             NAMES ucfutilities libucfutilities
             PATHS ${FIND_UCFUTILITIES_PATHS}
             PATH_SUFFIXES lib)

if(NOT UCFUTILITIES_LIBS)
    message("Could not find UCFUtilities libs in ${FIND_UCFUTILITIES_PATHS}")
endif()