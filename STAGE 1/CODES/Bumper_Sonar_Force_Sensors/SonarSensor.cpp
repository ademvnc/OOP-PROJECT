/**
 * @file
 * @brief This file contains the implementation of the SonarSensor class.
 */

#include "SonarSensor.h"
#include <iostream>

 /**
  * @brief Constructor for the SonarSensor class.
  * @param robotAPI Pointer to the NaoRobotAPI object.
  */
SonarSensor::SonarSensor(NaoRobotAPI* robotAPI) : robotAPI{ robotAPI } {}

/**
 * @brief Get the range of the sonar sensor at the given index.
 * @param index The index of the sonar sensor.
 * @return The range of the sonar sensor at the given index.
 */
double SonarSensor::getRange(int index)
{
    return *ranges[index];
}

/**
 * @brief Get the maximum range of the sonar sensors.
 * @return The maximum range of the sonar sensors.
 */
double SonarSensor::getMax()
{
    if (sonarLeft <= sonarRight)
        return sonarRight;
    return sonarLeft;
}

/**
 * @brief Get the minimum range of the sonar sensors.
 * @return The minimum range of the sonar sensors.
 */
double SonarSensor::getMin()
{
    if (sonarLeft >= sonarRight)
        return sonarRight;
    return sonarLeft;
}

/**
 * @brief Overload the [] operator to get the range of the sonar sensor at the given index.
 * @param index The index of the sonar sensor.
 * @return The range of the sonar sensor at the given index.
 */
double SonarSensor::operator[](const int& index)
{
    return *ranges[index];
}

/**
 * @brief Update the range of the sonar sensors.
 * @details This function retrieves the latest sonar range data from the robot's API.
 *          It should be called periodically to keep the sensor data up to date.
 */
void SonarSensor::updateSensor()
{
    std::cout << "SonarSensor is updating" << std::endl;
    robotAPI->getSonarRange(sonarLeft, sonarRight);
}
