# Install script for directory: D:/SourceCode/HDS/licensecc/src/library

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/licensecc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT" TYPE STATIC_LIBRARY FILES "D:/SourceCode/HDS/licensecc/build/src/library/Debug/licensecc_static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT" TYPE STATIC_LIBRARY FILES "D:/SourceCode/HDS/licensecc/build/src/library/Release/licensecc_static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT" TYPE STATIC_LIBRARY FILES "D:/SourceCode/HDS/licensecc/build/src/library/MinSizeRel/licensecc_static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT" TYPE STATIC_LIBRARY FILES "D:/SourceCode/HDS/licensecc/build/src/library/RelWithDebInfo/licensecc_static.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake/licensecc.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake/licensecc.cmake"
         "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake/licensecc-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake/licensecc.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake" TYPE FILE FILES "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake" TYPE FILE FILES "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake" TYPE FILE FILES "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake" TYPE FILE FILES "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licensecc/DEFAULT/cmake" TYPE FILE FILES "D:/SourceCode/HDS/licensecc/build/src/library/CMakeFiles/Export/licensecc/DEFAULT/cmake/licensecc-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/SourceCode/HDS/licensecc/build/src/library/base/cmake_install.cmake")
  include("D:/SourceCode/HDS/licensecc/build/src/library/os/cmake_install.cmake")
  include("D:/SourceCode/HDS/licensecc/build/src/library/locate/cmake_install.cmake")
  include("D:/SourceCode/HDS/licensecc/build/src/library/hw_identifier/cmake_install.cmake")

endif()

