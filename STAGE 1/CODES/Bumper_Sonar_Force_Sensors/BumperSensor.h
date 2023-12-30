#pragma once
#include "NaoRobotAPI.h"

/**
 * @brief The BumperSensor class represents a class for managing bumper sensors on a robot.
 */
class BumperSensor
{
private:
    bool lFoot_left = false; ///< Left foot left bumper sensor state.
    bool lFoot_right = false; ///< Left foot right bumper sensor state.
    bool rFoot_left = false; ///< Right foot left bumper sensor state.
    bool rFoot_right = false; ///< Right foot right bumper sensor state.
    bool* states[4] = { &lFoot_left, &lFoot_right, &rFoot_left, &rFoot_right }; ///< Array of pointers to the bumper sensor states.
    NaoRobotAPI* robotAPI; ///< Pointer to the NaoRobotAPI object.

public:
    /**
     * @brief Constructor for the BumperSensor class.
     * @param robotAPI Pointer to the NaoRobotAPI object.
     */
    BumperSensor(NaoRobotAPI* robotAPI);

    /**
     * @brief Get the state of the left foot left bumper sensor.
     * @return The state of the left foot left bumper sensor.
     */
    bool get_lFoot_left() const { return lFoot_left; }

    /**
     * @brief Get the state of the left foot right bumper sensor.
     * @return The state of the left foot right bumper sensor.
     */
    bool get_lFoot_right() const { return lFoot_right; }

    /**
     * @brief Get the state of the right foot left bumper sensor.
     * @return The state of the right foot left bumper sensor.
     */
    bool get_rFoot_left() const { return rFoot_left; }

    /**
     * @brief Get the state of the right foot right bumper sensor.
     * @return The state of the right foot right bumper sensor.
     */
    bool get_rFoot_right() const { return rFoot_right; }

    /**
     * @brief Get the state of the bumper sensor at the given index.
     * @param index The index of the bumper sensor (0 for left foot left, 1 for left foot right, 2 for right foot left, 3 for right foot right).
     * @return The state of the bumper sensor at the given index.
     */
    bool getState(const int& index) const;

    /**
     * @brief Check if any of the bumper sensors have been touched.
     * @return True if any bumper sensor has been touched, false otherwise.
     */
    bool checkTouch() const;

    /**
     * @brief Update the state of the bumper sensors.
     */
    void updateSensor();
};
