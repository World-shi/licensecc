#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "license_generator::lccgen" for configuration "Debug"
set_property(TARGET license_generator::lccgen APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(license_generator::lccgen PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/lccgen.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS license_generator::lccgen )
list(APPEND _IMPORT_CHECK_FILES_FOR_license_generator::lccgen "${_IMPORT_PREFIX}/bin/lccgen.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
