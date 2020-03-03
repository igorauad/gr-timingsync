INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TIMINGSYNC timingsync)

FIND_PATH(
    TIMINGSYNC_INCLUDE_DIRS
    NAMES timingsync/api.h
    HINTS $ENV{TIMINGSYNC_DIR}/include
        ${PC_TIMINGSYNC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TIMINGSYNC_LIBRARIES
    NAMES gnuradio-timingsync
    HINTS $ENV{TIMINGSYNC_DIR}/lib
        ${PC_TIMINGSYNC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/timingsyncTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TIMINGSYNC DEFAULT_MSG TIMINGSYNC_LIBRARIES TIMINGSYNC_INCLUDE_DIRS)
MARK_AS_ADVANCED(TIMINGSYNC_LIBRARIES TIMINGSYNC_INCLUDE_DIRS)
