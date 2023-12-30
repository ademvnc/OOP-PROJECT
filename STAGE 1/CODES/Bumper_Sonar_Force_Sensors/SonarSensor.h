#pragma once
#include "NaoRobotAPI.h"

/**
 * @brief The SonarSensor class represents a sensor for measuring distances using sonar technology.
 */
class SonarSensor
{
private:
    NaoRobotAPI* robotAPI; ///< Pointer to the NaoRobotAPI object.
    double sonarRight = 0; ///< Reading from the right sonar sensor.
    double sonarLeft = 0; ///< Reading from the left sonar sensor.
    double* ranges[2] = { &sonarLeft, &sonarRight }; ///< Array of pointers to the sonar sensor readings.

public:
    /**
     * @brief Constructor for the SonarSensor class.
     * @param robotAPI Pointer to the NaoRobotAPI object.
     */
    SonarSensor(NaoRobotAPI* robotAPI);

    /**
     * @brief Get the range reading of the sonar sensor at the given index.
     * @param index The index of the sonar sensor (0 for left, 1 for right).
     * @return The range reading of the sonar sensor at the given index.
     */
    double getRange(int index);

    /**
     * @brief Get the maximum range of the sonar sensors.
     * @return The maximum range of the sonar sensors.
     */
    double getMax();

    /**
     * @brief Get the minimum range of the sonar sensors.
     * @return The minimum range of the sonar sensors.
     */
    double getMin();

    /**
     * @brief Overload the [] operator to get the range reading of the sonar sensor at the given index.
     * @param index The index of the sonar sensor (0 for left, 1 for right).
     * @return The range reading of the sonar sensor at the given index.
     */
    double operator[](const int& index);

    /**
     * @brief Update the range readings of the sonar sensors.
     */
    void updateSensor();
};
