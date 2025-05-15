
/*
 * LicenseVerifier_test.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: GC
 */
#define BOOST_TEST_MODULE test_signature_verifier

#include <boost/test/unit_test.hpp>
#include <licensecc_properties_test.h>
#include <licensecc_properties.h>

#include "../../src/library/os/signature_verifier.hpp"
#include "generate-license.h"
//#define PUBLIC_KEY_LEN 140
#define PRODUCT_NAME HDNLRP
unsigned char g_public_key[] = {
	48,	 129, 137, 2,	129, 129, 0,   175, 97,	 222, 57,  228, 187, 186, 6,   247, 52,	 170, 127, 92,
	19,	 72,  63,  117, 129, 142, 239, 112, 77,	 55,  215, 174, 1,	 195, 243, 184, 158, 143, 78,  38,
	106, 200, 219, 156, 144, 233, 135, 164, 91,	 68,  144, 118, 96,	 46,  163, 95,	27,	 244, 43,  133,
	19,	 11,  199, 219, 93,	 196, 234, 49,	64,	 184, 25,  21,	40,	 141, 143, 227, 100, 245, 85,  51,
	198, 130, 213, 231, 166, 3,	  192, 166, 109, 184, 184, 203, 245, 53,  81,  2,	33,	 240, 246, 183,
	94,	 135, 123, 23,	106, 128, 122, 152, 91,	 122, 40,  36,	97,	 51,  40,  250, 119, 21,  15,  118,
	34,	 19,  108, 157, 127, 180, 76,  211, 219, 61,  232, 213, 83,	 16,  121, 2,	3,	 1,	  0,   1};
namespace license {
namespace test {
using namespace std;

BOOST_AUTO_TEST_CASE(verify_signature_ok) {
	const string test_data("HDPDFISclient-signatureAEjP-GMIA-AAA=lic_ver200valid-to2033-11-31");
	const string signature = sign_data(test_data, string("verify_signature"));

	FUNCTION_RETURN result = license::os::verify_signature(test_data, signature);
	BOOST_CHECK_MESSAGE(result == FUNC_RET_OK, "signature verified");
}

BOOST_AUTO_TEST_CASE(verify_signature_data_mismatch) {
	const string test_data("test_data");
	const string signature = sign_data(test_data, string("verify_signature"));

	FUNCTION_RETURN result = license::os::verify_signature(string("other data"), signature);
	BOOST_CHECK_MESSAGE(result == FUNC_RET_ERROR, "signature NOT verified");
}

BOOST_AUTO_TEST_CASE(verify_signature_modified) {
	const string test_data("test_data");
	string signature = sign_data(test_data, string("verify_signature"));
	signature[2] = signature[2] + 1;
	FUNCTION_RETURN result = license::os::verify_signature(test_data, signature);
	BOOST_CHECK_MESSAGE(result == FUNC_RET_ERROR, "signature NOT verified");
}

}  // namespace test

} /* namespace license */
