#include "Encryption.h"

/**
 * @brief Encrypt an integer using a simple encryption algorithm.
 * @param number The integer to be encrypted.
 * @return The encrypted integer.
 *
 * This function adds 7 to each digit of the input number, takes the modulo 10 of the result,
 * and swaps the positions of the first and third digits, as well as the second and fourth digits.
 */
int Encryption::encrypt(int number) {
    int encrypted = 0;
    int factor = 1;

    for (int i = 0; i < 4; ++i) {
        int digit = (number % 10 + 7) % 10;
        encrypted += digit * factor;
        factor *= 10;
        number /= 10;
    }

    // Swap the digits
    return swapDigits(encrypted);
}

/**
 * @brief Decrypt an integer that was encrypted using a simple encryption algorithm.
 * @param number The encrypted integer to be decrypted.
 * @return The decrypted integer.
 *
 * This function first swaps the positions of the first and third digits, as well as the second and fourth digits,
 * and then subtracts 7 from each digit of the input number, taking the modulo 10 of the result.
 */
int Encryption::decrypt(int number) {
    // Swap the digits back to their original positions
    number = swapDigits(number);

    int decrypted = 0;
    int factor = 1;

    for (int i = 0; i < 4; ++i) {
        int digit = (number % 10 - 7 + 10) % 10;
        decrypted += digit * factor;
        factor *= 10;
        number /= 10;
    }

    return decrypted;
}

/**
 * @brief Swap the positions of the first and third digits, as well as the second and fourth digits.
 * @param number The integer in which the digits will be swapped.
 * @return The integer with swapped digits.
 */
int Encryption::swapDigits(int number) {
    int first = number / 1000;
    int second = (number / 100) % 10;
    int third = (number / 10) % 10;
    int fourth = number % 10;

    return third * 1000 + fourth * 100 + first * 10 + second;
}
