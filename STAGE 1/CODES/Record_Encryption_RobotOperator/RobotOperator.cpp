/**
 * @file
 * @brief This file contains the implementation of the RobotOperator class.
 */

#include "RobotOperator.h"
#include <iostream>

 /**
  * @brief Constructor for the RobotOperator class.
  * @param name The name of the robot operator.
  * @param accessCode The encrypted access code for the operator.
  */
RobotOperator::RobotOperator(const std::string& name, int accessCode)
    : name(name), accessCode(encryptCode(accessCode)) {}

/**
 * @brief Encrypts an access code using a simple shift cipher.
 * @param code The access code to be encrypted.
 * @return The encrypted access code.
 */
int RobotOperator::encryptCode(int code) {
    // Shift each digit by a certain amount for encryption
    int encryptedCode = 0;
    int factor = 1;
    while (code > 0) {
        int digit = (code % 10 + SHIFT) % 10;
        encryptedCode += digit * factor;
        factor *= 10;
        code /= 10;
    }
    return encryptedCode;
}

/**
 * @brief Decrypts an access code that was encrypted using the same shift cipher.
 * @param code The encrypted access code to be decrypted.
 * @return The decrypted access code.
 */
int RobotOperator::decryptCode(int code) {
    // Reverse the shift for each digit to decrypt the code
    int decryptedCode = 0;
    int factor = 1;
    while (code > 0) {
        int digit = (code % 10 - SHIFT + 10) % 10;
        decryptedCode += digit * factor;
        factor *= 10;
        code /= 10;
    }
    return decryptedCode;
}

/**
 * @brief Checks if the provided access code matches the operator's access code.
 * @param code The access code to be checked.
 * @return True if the access code is correct, false otherwise.
 */
bool RobotOperator::checkAccessCode(int code) {
    return decryptCode(accessCode) == code;
}

/**
 * @brief Prints operator information, including their name and access status.
 */
void RobotOperator::print() {
    std::cout << "Operator: " << name << "\nAccess Status: "
        << (checkAccessCode(accessCode) ? "Authorized" : "Unauthorized") << std::endl;
}
