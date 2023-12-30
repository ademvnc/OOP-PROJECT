#pragma once

#ifndef ROBOT_OPERATOR_H
#define ROBOT_OPERATOR_H

#include "NaoRobotAPI.h"
#include <string>

/**
 * @brief The RobotOperator class represents an operator with access to control the robot.
 */
class RobotOperator {
private:
    int accessCode; ///< Access code for the operator.
    std::string name; ///< Name of the operator.

public:
    /**
     * @brief Constructor for the RobotOperator class.
     * @param name The name of the operator.
     * @param accessCode The access code for the operator.
     */
    RobotOperator(const std::string& name, int accessCode);

    /**
     * @brief Encrypt an access code.
     * @param code The access code to be encrypted.
     * @return The encrypted access code.
     */
    int encryptCode(int code);

    /**
     * @brief Decrypt an encrypted access code.
     * @param code The encrypted access code to be decrypted.
     * @return The decrypted access code.
     */
    int decryptCode(int code);

    /**
     * @brief Check if a provided access code matches the operator's access code.
     * @param code The access code to be checked.
     * @return True if the provided code matches the operator's access code, false otherwise.
     */
    bool checkAccessCode(int code);

    /**
     * @brief Print information about the operator.
     */
    void print();
};

#endif // ROBOT_OPERATOR_H
