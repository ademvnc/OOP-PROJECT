#pragma once
#include "NaoRobotAPI.h"

/**
 * @brief The ForceSensor class represents a sensor for measuring force on a robot.
 */
class ForceSensor
{
private:
    double force = 0; ///< Current force sensor reading.
    NaoRobotAPI* robotAPI; ///< Pointer to the NaoRobotAPI object.

public:
    /**
     * @brief Constructor for the ForceSensor class.
     * @param robotAPI Pointer to the NaoRobotAPI object.
     */
    ForceSensor(NaoRobotAPI* robotAPI);

    /**
     * @brief Update the force sensor reading.
     */
    void updateSensor();

    /**
     * @brief Get the current force sensor reading.
     * @return The current force sensor reading.
     */
    double getForceValue();

    /**
     * @brief Get the current force sensor reading and store it in the 'force' member variable.
     */
    void getForce();

    /**
     * @brief Check if the robot has fallen based on the force sensor reading.
     * @return True if the robot has fallen, false otherwise.
     */
    bool checkFall();
};
