# CMake generated Testfile for 
# Source directory: D:/SourceCode/HDS/licensecc/test/library/hw_identifier
# Build directory: D:/SourceCode/HDS/licensecc/build/test/library/hw_identifier
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_hw_identifier "D:/SourceCode/HDS/licensecc/build/test/library/hw_identifier/Debug/test_hw_identifier.exe")
  set_tests_properties(test_hw_identifier PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;16;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_hw_identifier "D:/SourceCode/HDS/licensecc/build/test/library/hw_identifier/Release/test_hw_identifier.exe")
  set_tests_properties(test_hw_identifier PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;16;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_hw_identifier "D:/SourceCode/HDS/licensecc/build/test/library/hw_identifier/MinSizeRel/test_hw_identifier.exe")
  set_tests_properties(test_hw_identifier PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;16;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_hw_identifier "D:/SourceCode/HDS/licensecc/build/test/library/hw_identifier/RelWithDebInfo/test_hw_identifier.exe")
  set_tests_properties(test_hw_identifier PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;16;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/hw_identifier/CMakeLists.txt;0;")
else()
  add_test(test_hw_identifier NOT_AVAILABLE)
endif()
