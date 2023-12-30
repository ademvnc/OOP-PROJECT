#include "ForceSensor.h"
#include<iostream>

/**
 * @brief Constructor for the ForceSensor class.
 * @param robotAPI Pointer to the NaoRobotAPI object.
 */
ForceSensor::ForceSensor(NaoRobotAPI* robotAPI) : robotAPI{ robotAPI } {}

/**
 * @brief Update the force sensor reading.
 */
void ForceSensor::updateSensor()
{
    /**
     * @todo Implement a function to update the force sensor reading using data from the NaoRobotAPI object.
     */
    std::cout << "Force sensor values are updated" << std::endl;
    force = robotAPI->getFootForce();
}

/**
 * @brief Get the current force sensor reading.
 * @return The current force sensor reading.
 */
double ForceSensor::getForceValue()
{
    /**
     * @todo Implement a function to retrieve the current force sensor reading.
     * @return The current force sensor reading.
     */
    return force;
}

/**
 * @brief Get the current force sensor reading.
 */
void ForceSensor::getForce()
{
    /**
     * @deprecated This function is deprecated and should not be used. Use getForceValue() instead.
     */
    std::cout << "Force value is retrieved" << std::endl;
    robotAPI->getFootForce();
}

/**
 * @brief Check if the robot has fallen based on the force sensor reading.
 * @return True if the robot has fallen, false otherwise.
 */
bool ForceSensor::checkFall()
{
    /**
     * @todo Implement a function to check if the robot has fallen based on the force sensor reading.
     * @return True if the robot has fallen, false otherwise.
     */
    std::cout << "Checking for fall" << std::endl;
    if (force == 0)
        return true;
    return false;
}
