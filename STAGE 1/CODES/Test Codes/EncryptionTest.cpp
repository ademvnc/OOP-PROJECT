#include "Encryption.h"
#include <iostream>

void testEncryption() {
    int originalNumber = 1234;
    int encryptedNumber = Encryption::encrypt(originalNumber);
    int decryptedNumber = Encryption::decrypt(encryptedNumber);

    std::cout << "Orijinal Numara: " << originalNumber << std::endl;
    std::cout << "Sifrelenmis Numara: " << encryptedNumber << std::endl;
    std::cout << "Sifresi Cozulmus Numara: " << decryptedNumber << std::endl;
}

int main() {
    testEncryption();
    return 0;
}
