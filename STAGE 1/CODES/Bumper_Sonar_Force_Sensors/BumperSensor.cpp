#include "BumperSensor.h"
#include<iostream>

/**
 * @brief Constructor for the BumperSensor class.
 * @param robotAPI Pointer to the NaoRobotAPI object.
 */
BumperSensor::BumperSensor(NaoRobotAPI* robotAPI) : robotAPI{ robotAPI } {}

/**
 * @brief Get the state of the bumper sensor at the given index.
 * @param index The index of the bumper sensor.
 * @return The state of the bumper sensor at the given index.
 */
bool BumperSensor::getState(const int& index) const
{
    /**
     * @todo Implement a function to retrieve the state of the bumper sensor at the specified index.
     * @param index The index of the bumper sensor (0 for left foot left, 1 for left foot right, 2 for right foot left, 3 for right foot right).
     * @return The state of the bumper sensor at the given index (true if touched, false otherwise).
     */
    std::cout << "Getting the state of the given index" << std::endl;
    return *states[index];
}

/**
 * @brief Check if any of the bumper sensors have been touched.
 * @return True if any bumper sensor has been touched, false otherwise.
 */
bool BumperSensor::checkTouch() const
{
    /**
     * @todo Implement a function to check if any of the bumper sensors have been touched.
     * @return True if any of the bumper sensors have been touched, false otherwise.
     */
    std::cout << "Checking for touch" << std::endl;
    return lFoot_left || lFoot_right || rFoot_left || rFoot_right;
}

/**
 * @brief Update the state of the bumper sensors.
 */
void BumperSensor::updateSensor()
{
    /**
     * @todo Implement a function to update the state of the bumper sensors using data from the NaoRobotAPI object.
     */
    std::cout << "Bumper values are updated" << std::endl;
    robotAPI->getFootBumpers(lFoot_left, lFoot_right, rFoot_left, rFoot_right);
}
