#define BOOST_TEST_MODULE test_date

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <licensecc_properties.h>
#include <licensecc_properties_test.h>

#include <licensecc/licensecc.h>
#include "../../src/library/ini/SimpleIni.h"
#include "generate-license.h"

namespace fs = boost::filesystem;
using namespace license;
using namespace std;
unsigned char g_public_key[] = {
	48,	 129, 137, 2,	129, 129, 0,   207, 116, 173, 52,  34,	169, 218, 129, 123, 8,	 251, 172, 121,
	66,	 222, 73,  145, 83,	 2,	  18,  158, 187, 59,  106, 76,	179, 120, 105, 98,	200, 244, 187, 113,
	35,	 52,  159, 2,	88,	 71,  139, 103, 236, 84,  141, 94,	44,	 227, 215, 105, 130, 231, 66,  56,
	37,	 214, 14,  211, 153, 234, 218, 75,	7,	 109, 180, 55,	181, 165, 9,   100, 162, 238, 126, 37,
	45,	 116, 6,   223, 176, 196, 234, 149, 199, 207, 5,   218, 172, 246, 107, 166, 188, 77,  148, 105,
	29,	 117, 194, 48,	77,	 158, 254, 251, 231, 124, 8,   183, 126, 51,  227, 164, 202, 116, 250, 151,
	162, 226, 82,  13,	57,	 188, 245, 113, 117, 151, 64,  4,	250, 214, 135, 2,	3,	 1,	  0,   1};
namespace license {
namespace test {

BOOST_AUTO_TEST_CASE(license_not_expired) {
	vector<string> extraArgs;
	extraArgs.push_back("-e");
	extraArgs.push_back("2050-10-10");
	const string licLocation = generate_license("not_expired.lic", extraArgs);
	/* */
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PATH};
	std::copy(licLocation.begin(), licLocation.end(), location.licenseData);

	const LCC_EVENT_TYPE result = acquire_license(nullptr, &location, &license);
	BOOST_CHECK_EQUAL(result, LICENSE_OK);
	BOOST_CHECK_EQUAL(license.has_expiry, true);
	BOOST_CHECK_EQUAL(license.linked_to_pc, false);
	BOOST_CHECK_GT(license.days_left, (unsigned int)0);
}

BOOST_AUTO_TEST_CASE(license_expired) {
	vector<string> extraArgs;
	extraArgs.push_back("-e");
	extraArgs.push_back("2013-10-10");
	const string licLocation = generate_license("expired", extraArgs);
	/* */
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PATH};
	std::copy(licLocation.begin(), licLocation.end(), location.licenseData);
	BOOST_TEST_MESSAGE("before acquire license");
	const LCC_EVENT_TYPE result = acquire_license(nullptr, &location, &license);
	BOOST_CHECK_EQUAL(result, PRODUCT_EXPIRED);
	BOOST_CHECK_EQUAL(license.has_expiry, true);
	BOOST_CHECK_EQUAL(license.linked_to_pc, false);
	BOOST_CHECK_EQUAL(license.days_left, 0);
}

}  // namespace test
}  // namespace license
