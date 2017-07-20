#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../libgcb.h"
#include "../gcm.h"

class MyGCBTestSuite : public CxxTest::TestSuite {
public:
    void testEncryptionDecryption(void) {
        std::cout << std::endl << "Starting Encryption&Decryption test";
        gcb a("Testing","Password");
        a.encrypt_m();
        a.decrypt_m();
        std::cout << std::endl << "Plaintext == " << a.string_ret() << std::endl;
        TS_ASSERT(a.string_ret() == "Testing");
    }
};