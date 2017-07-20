#include "libgcb.h"

gcb::gcb(std::string str, std::string password) {
    string_enc = std::move(str);
    password_enc = std::move(password);
}

std::string gcb::decrypt_m() {
    std::string temp = string_enc;
    decrypt((unsigned char *) ciphertext_enc.c_str(), (int) strlen((char *) ciphertext),
            aad, (int) (strlen((char *) aad)),
            tag, (unsigned char *) password_enc.c_str(), iv, (unsigned char *) temp.c_str()
    );
    return temp;
}

std::string gcb::encrypt_m() {
    encrypt((unsigned char *) string_enc.c_str(), static_cast<int>(strlen((char *) string_enc.c_str())),
            aad, 0,
            (unsigned char *) password_enc.c_str(), iv, (unsigned char *) ciphertext_enc.c_str(), tag
    );

    /*decrypt(ciphertext, (int) (strlen((char *) ciphertext) + 1),
            aad, (int) (strlen((char *) aad) + 1), tag, key, iv, plaintext);*/

    // base64_encode(ciphertext, (unsigned int) (strlen((char*)plaintext) + 1))
    return ciphertext_enc;
}
