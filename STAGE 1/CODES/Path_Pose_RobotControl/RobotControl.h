#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "NaoRobotAPI.h"
#include "Pose.h"

/**
 * @brief The RobotControl class provides control functions for a robot's movement.
 */
class RobotControl {
public:
    /**
     * @brief Constructor for the RobotControl class.
     */
    RobotControl();

    /**
     * @brief Destructor for the RobotControl class.
     */
    ~RobotControl();

    /**
     * @brief Turn the robot to the left.
     */
    void turnLeft();

    /**
     * @brief Turn the robot to the right.
     */
    void turnRight();

    /**
     * @brief Move the robot forward.
     */
    void forward();

    /**
     * @brief Move the robot backward.
     */
    void backward();

    /**
     * @brief Move the robot to the left.
     */
    void moveLeft();

    /**
     * @brief Move the robot to the right.
     */
    void moveRight();

    /**
     * @brief Get the current pose (position and orientation) of the robot.
     * @param x Reference to store the x-coordinate of the pose.
     * @param y Reference to store the y-coordinate of the pose.
     * @param th Reference to store the orientation (theta) of the pose.
     * @return A pointer to the Pose object representing the robot's pose.
     */
    Pose* getPose(double& x, double& y, double& th);

    /**
     * @brief Stop the robot's movement.
     */
    void stop();

    /**
     * @brief Print the current state of the robot.
     */
    void print();

private:
    NaoRobotAPI* robotAPI; ///< Pointer to the NaoRobotAPI object.
    Pose* position; ///< Pointer to the current position of the robot.
    int state; ///< Current state of the robot.
    double distance; ///< Distance for movement actions (e.g., forward, backward).
};

#endif // ROBOTCONTROL_H
