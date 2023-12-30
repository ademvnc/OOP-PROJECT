#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "NaoRobotAPI.h"

/**
 * @brief The Encryption class provides methods for encrypting and decrypting numbers.
 */
class Encryption {
public:
    /**
     * @brief Encrypts a number by swapping its digits.
     * @param number The number to be encrypted.
     * @return The encrypted number.
     */
    static int encrypt(int number);

    /**
     * @brief Decrypts an encrypted number by swapping its digits back.
     * @param number The encrypted number to be decrypted.
     * @return The decrypted number.
     */
    static int decrypt(int number);

private:
    /**
     * @brief Swaps the digits of a number.
     * @param number The number whose digits will be swapped.
     * @return The number with its digits swapped.
     */
    static int swapDigits(int number);
};

#endif // ENCRYPTION_H
