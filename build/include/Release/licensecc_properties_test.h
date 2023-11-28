#ifndef BUILD_PROPERTIES_TEST_H_
#define BUILD_PROPERTIES_TEST_H_

//Build locations and parameters for tests
#define PROJECT_BINARY_DIR "D:/SourceCode/HDS/licensecc/build"
#define PROJECT_SRC_DIR "D:/SourceCode/HDS/licensecc/test/../src"
#define PROJECT_BASE_DIR "D:/SourceCode/HDS/licensecc"
//this file is customized in test folder
#define PROJECT_TEST_SRC_DIR "D:/SourceCode/HDS/licensecc/test"
#define PROJECT_TEST_TEMP_DIR "D:/SourceCode/HDS/licensecc/build/Testing/Temporary"
#define BUILD_TYPE ""
#define LCC_EXE "D:/SourceCode/HDS/licensecc/build/extern/license-generator/src/license_generator/Release/lccgen.exe"

#define LCC_TEST_LICENSES_PROJECT "D:/SourceCode/HDS/licensecc/build/Testing/Temporary/DEFAULT"
#define LCC_LICENSES_BASE LCC_TEST_LICENSES_PROJECT "/licenses"
#define LCC_PROJECTS_BASE_DIR "D:/SourceCode/HDS/licensecc/projects"
#define LCC_PROJECT_PRIVATE_KEY "D:/SourceCode/HDS/licensecc/projects/DEFAULT/private_key.rsa"

/*
 * command line parameters 
 */
#define PARAM_BASE64 "base64"
#define PARAM_LICENSE_OUTPUT "output-file-name"
#define PARAM_PRODUCT_NAME "product-name"
#define PARAM_PROJECT_FOLDER "project-folder"
#define PARAM_PRIMARY_KEY "primary-key"

#endif
