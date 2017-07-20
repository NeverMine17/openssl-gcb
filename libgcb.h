#ifndef OPENSSL_GCB_FILE_ENCRYPTING_LIBGCB_H
#define OPENSSL_GCB_FILE_ENCRYPTING_LIBGCB_H

#include <iostream>
#include <cstring>
#include <utility>
#include <ctime>
#include "gcm.h"
#include "base64.h"

class gcb {
public:
    gcb(std::string str, std::string password);

    std::string encrypt_m();

    std::string decrypt_m();

    std::string string_ret() {
        return string_enc;
    }

    std::string password_ret() {
        return password_enc;
    }

    std::string ciphertext_ret() {
        return ciphertext_enc;
    }

    unsigned char aad[1024]{};
    unsigned char iv[16]{};
    unsigned char ciphertext[1024]{};
    unsigned char tag[1024]{};
private:
    std::string string_enc;
    std::string password_enc;
    std::string ciphertext_enc;
};


#endif //OPENSSL_GCB_FILE_ENCRYPTING_LIBGCB_H
