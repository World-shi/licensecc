# CMake generated Testfile for 
# Source directory: D:/SourceCode/HDS/licensecc/test/library/os
# Build directory: D:/SourceCode/HDS/licensecc/build/test/library/os
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_network "D:/SourceCode/HDS/licensecc/build/test/library/os/Debug/test_network.exe")
  set_tests_properties(test_network PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;12;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_network "D:/SourceCode/HDS/licensecc/build/test/library/os/Release/test_network.exe")
  set_tests_properties(test_network PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;12;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_network "D:/SourceCode/HDS/licensecc/build/test/library/os/MinSizeRel/test_network.exe")
  set_tests_properties(test_network PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;12;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_network "D:/SourceCode/HDS/licensecc/build/test/library/os/RelWithDebInfo/test_network.exe")
  set_tests_properties(test_network PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;12;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
else()
  add_test(test_network NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_dmi_info "D:/SourceCode/HDS/licensecc/build/test/library/os/Debug/test_dmi_info.exe")
  set_tests_properties(test_dmi_info PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;22;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_dmi_info "D:/SourceCode/HDS/licensecc/build/test/library/os/Release/test_dmi_info.exe")
  set_tests_properties(test_dmi_info PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;22;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_dmi_info "D:/SourceCode/HDS/licensecc/build/test/library/os/MinSizeRel/test_dmi_info.exe")
  set_tests_properties(test_dmi_info PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;22;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_dmi_info "D:/SourceCode/HDS/licensecc/build/test/library/os/RelWithDebInfo/test_dmi_info.exe")
  set_tests_properties(test_dmi_info PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;22;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
else()
  add_test(test_dmi_info NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_execution_environment "D:/SourceCode/HDS/licensecc/build/test/library/os/Debug/test_execution_environment.exe")
  set_tests_properties(test_execution_environment PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;36;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_execution_environment "D:/SourceCode/HDS/licensecc/build/test/library/os/Release/test_execution_environment.exe")
  set_tests_properties(test_execution_environment PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;36;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_execution_environment "D:/SourceCode/HDS/licensecc/build/test/library/os/MinSizeRel/test_execution_environment.exe")
  set_tests_properties(test_execution_environment PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;36;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_execution_environment "D:/SourceCode/HDS/licensecc/build/test/library/os/RelWithDebInfo/test_execution_environment.exe")
  set_tests_properties(test_execution_environment PROPERTIES  _BACKTRACE_TRIPLES "D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;36;ADD_TEST;D:/SourceCode/HDS/licensecc/test/library/os/CMakeLists.txt;0;")
else()
  add_test(test_execution_environment NOT_AVAILABLE)
endif()
