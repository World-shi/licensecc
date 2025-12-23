#define BOOST_TEST_MODULE integration_test_hw_identifier

#include <boost/test/unit_test.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <boost/filesystem.hpp>
#include <licensecc_properties.h>
#include <licensecc_properties_test.h>

#include <licensecc/licensecc.h>
#include "../../src/library/ini/SimpleIni.h"
#include "../../src/library/hw_identifier/hw_identifier_facade.hpp"
#include "../../src/library/os/os.h"
#include "../../src/library/os/network.hpp"
#include "generate-license.h"
#define PRODUCT_NAME HDNLRP
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
namespace fs = boost::filesystem;
using namespace std;
using namespace hw_identifier;

/**
 * If the current pc has at least one disk generate a hardware identifier using disk, generate a license, verify the license
 * is OK
 */

static void generate_and_verify_license(LCC_API_HW_IDENTIFICATION_STRATEGY strategy, const string& lic_fname) {
	BOOST_TEST_CHECKPOINT("Before generate");
	const string identifier_out = HwIdentifierFacade::generate_user_pc_signature(strategy);
	BOOST_TEST_CHECKPOINT("After generate signature");
	cout << "Identifier:" << identifier_out << endl;
	vector<string> extraArgs;
	extraArgs.push_back("-s");
	extraArgs.push_back(identifier_out);
	BOOST_TEST_CHECKPOINT("Before generate license");
	const string licLocation = generate_license(lic_fname, extraArgs);
	LicenseInfo license;
	LicenseLocation location = {LICENSE_PATH};
	std::copy(licLocation.begin(), licLocation.end(), location.licenseData);
	const LCC_EVENT_TYPE result = acquire_license(nullptr, &location, &license);
	BOOST_CHECK_EQUAL(result, LICENSE_OK);
	BOOST_CHECK_EQUAL(license.has_expiry, false);
	BOOST_CHECK_EQUAL(license.linked_to_pc, true);
}

BOOST_AUTO_TEST_CASE(volid_lic_file) {
	HwIdentifier identifier_out;
	vector<DiskInfo> diskInfos;
	FUNCTION_RETURN result_diskinfos = getDiskInfos(diskInfos);
	if ((result_diskinfos == FUNC_RET_BUFFER_TOO_SMALL || result_diskinfos == FUNC_RET_OK) && diskInfos.size() > 0) {
		generate_and_verify_license(LCC_API_HW_IDENTIFICATION_STRATEGY::STRATEGY_DISK, "volid_lic_file");
	} else {
		BOOST_TEST_MESSAGE("No disk found skipping testing disk hardware identifier");
	}
}

BOOST_AUTO_TEST_CASE(strategy_mac_address) {
	vector<os::OsAdapterInfo> adapters;
	FUNCTION_RETURN result_adapterInfos = os::getAdapterInfos(adapters);
	if ((result_adapterInfos == FUNC_RET_BUFFER_TOO_SMALL || result_adapterInfos == FUNC_RET_OK) &&
		adapters.size() > 0) {
		generate_and_verify_license(LCC_API_HW_IDENTIFICATION_STRATEGY::STRATEGY_ETHERNET, "strategy_mac_address");
	} else {
		BOOST_TEST_MESSAGE("No ethernet adapter found skipping testing mac address hardware identifier");
	}
}

BOOST_AUTO_TEST_CASE(strategy_ip_address) {
	vector<os::OsAdapterInfo> adapters;
	FUNCTION_RETURN result_adapterInfos = os::getAdapterInfos(adapters);
	if ((result_adapterInfos == FUNC_RET_BUFFER_TOO_SMALL || result_adapterInfos == FUNC_RET_OK) &&
		adapters.size() > 0) {
		generate_and_verify_license(LCC_API_HW_IDENTIFICATION_STRATEGY::STRATEGY_IP_ADDRESS, "strategy_ip_address");
	} else {
		BOOST_TEST_MESSAGE("No ethernet adapter found skipping testing ip hardware identifier");
	}
}

}  // namespace test
}  // namespace license
