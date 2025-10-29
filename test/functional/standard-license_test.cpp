
#define BOOST_TEST_MODULE test_standard_license

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <licensecc/licensecc.h>
#include <licensecc_properties_test.h>
#include <licensecc_properties.h>

#include "../../src/library/ini/SimpleIni.h"
#include "generate-license.h"
#include "../../src/library/base/file_utils.hpp"
#define PRODUCT_NAME HDNLRP
unsigned char g_public_key[] = {
	48,	 129, 137, 2,	129, 129, 0,   175, 97,	 222, 57,  228, 187, 186, 6,   247, 52,	 170, 127, 92,
	19,	 72,  63,  117, 129, 142, 239, 112, 77,	 55,  215, 174, 1,	 195, 243, 184, 158, 143, 78,  38,
	106, 200, 219, 156, 144, 233, 135, 164, 91,	 68,  144, 118, 96,	 46,  163, 95,	27,	 244, 43,  133,
	19,	 11,  199, 219, 93,	 196, 234, 49,	64,	 184, 25,  21,	40,	 141, 143, 227, 100, 245, 85,  51,
	198, 130, 213, 231, 166, 3,	  192, 166, 109, 184, 184, 203, 245, 53,  81,  2,	33,	 240, 246, 183,
	94,	 135, 123, 23,	106, 128, 122, 152, 91,	 122, 40,  36,	97,	 51,  40,  250, 119, 21,  15,  118,
	34,	 19,  108, 157, 127, 180, 76,  211, 219, 61,  232, 213, 83,	 16,  121, 2,	3,	 1,	  0,   1};
using namespace std;
namespace fs = boost::filesystem;

namespace license {
namespace test {

/**
 * Test a generic license with no expiry neither client id. The license is read from file
 */
BOOST_AUTO_TEST_CASE(test_generic_license_read_file) {
	const vector<string> extraArgs;
	const string licLocation = generate_license("standard_license", extraArgs);
	/* */
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PATH};
	std::copy(licLocation.begin(), licLocation.end(), location.licenseData);
	const LCC_EVENT_TYPE result = acquire_license(nullptr, &location, &license);
	BOOST_CHECK_EQUAL(result, LICENSE_OK);
	BOOST_CHECK_EQUAL(license.has_expiry, false);
	BOOST_CHECK_EQUAL(license.linked_to_pc, false);
}

/**
 * Test a generic license with no expiry neither client id. The license is passed in trhough the licenseData structure.
 */
BOOST_AUTO_TEST_CASE(test_read_license_data) {
	const vector<string> extraArgs;
	const fs::path licLocation = fs::path(generate_license("standard_license1", extraArgs));
	const string licLocationStr = licLocation.string();
	string license_data = get_file_contents(licLocationStr.c_str(), 65536);
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PLAIN_DATA};
	std::copy(license_data.begin(), license_data.end(), location.licenseData);
	const LCC_EVENT_TYPE result = acquire_license(nullptr, &location, &license);
	BOOST_CHECK_EQUAL(result, LICENSE_OK);
	BOOST_CHECK_EQUAL(license.has_expiry, false);
	BOOST_CHECK_EQUAL(license.linked_to_pc, false);
}

/**
 * Pass the license data to the application.
 */
/* lccgen bug #10 parameter -b is ignored.
BOOST_AUTO_TEST_CASE(base64_encoded) {
	const string licLocation("standard_b64.lic");
	vector<string> extraArgs;
	extraArgs.push_back("-b");
	const string lic_location = generate_license(licLocation, extraArgs);
	const string license_data(license::get_file_contents(lic_location.c_str(), 65536));
	LicenseInfo license;
	LicenseLocation licenseLocation;
	licenseLocation.license_data_type = LICENSE_ENCODED;
	std::copy(license_data.begin(), license_data.end(), licenseLocation.licenseData);
	const LCC_EVENT_TYPE result = acquire_license(nullptr, &licenseLocation, &license);
	BOOST_CHECK_EQUAL(result, LCC_EVENT_TYPE::LICENSE_OK);
	BOOST_CHECK_EQUAL(license.has_expiry, false);
	BOOST_CHECK_EQUAL(license.linked_to_pc, false);
}
*/

// old boost version can't parse the comma separated list.. only centos 7 and Ubuntu 16.04
#if (BOOST_VERSION > 106500)
BOOST_AUTO_TEST_CASE(multiple_features) {
	vector<string> extraArgs;
	extraArgs.push_back("-f");
	extraArgs.push_back(LCC_PROJECT_NAME ",feature1,feature2");
	const fs::path licLocation = fs::path(generate_license("multi_feature", extraArgs));
	const string licLocationStr = licLocation.string();
	string license_data = get_file_contents(licLocationStr.c_str(), 65536);
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PLAIN_DATA};
	std::copy(license_data.begin(), license_data.end(), location.licenseData);
	CallerInformations callInfo;
	strcpy(callInfo.feature_name, "feature1");
	callInfo.magic = 0;
	callInfo.version[0] = '\0';
	LCC_EVENT_TYPE result = acquire_license(&callInfo, &location, &license);
	BOOST_CHECK_EQUAL(result, LCC_EVENT_TYPE::LICENSE_OK);
	strcpy(callInfo.feature_name, "feature2");
	result = acquire_license(&callInfo, &location, &license);
	BOOST_CHECK_EQUAL(result, LCC_EVENT_TYPE::LICENSE_OK);
	strcpy(callInfo.feature_name, "feature3");
	result = acquire_license(&callInfo, &location, &license);
	BOOST_CHECK_EQUAL(result, LCC_EVENT_TYPE::PRODUCT_NOT_LICENSED);
}
#endif

//
// BOOST_AUTO_TEST_CASE( hw_identifier ) {
//	const string licLocation(PROJECT_TEST_TEMP_DIR "/hw_identifier.lic");
//	const vector<string> extraArgs = { "-s", "Jaaa-aaaa-MG9F-ZhB1" };
//	generate_license(licLocation, extraArgs);
//
//	LicenseInfo license;
//	LicenseLocation licenseLocation;
//	licenseLocation.licenseFileLocation = licLocation.c_str();
//	licenseLocation.licenseData = "";
//	const EVENT_TYPE result = acquire_license("TEST", &licenseLocation,
//			&license);
//	BOOST_CHECK_EQUAL(result, IDENTIFIERS_MISMATCH);
//	BOOST_CHECK_EQUAL(license.has_expiry, false);
//	BOOST_CHECK_EQUAL(license.linked_to_pc, true);
//}
}  // namespace test
}  // namespace license
