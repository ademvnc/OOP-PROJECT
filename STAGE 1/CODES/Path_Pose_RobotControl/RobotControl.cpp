/**
 * @file
 * @brief This file contains the implementation of the RobotControl class.
 */

#include "RobotControl.h"
#include <iostream>
#include <thread>
#include <chrono>

 /**
  * @brief Constructor for the RobotControl class.
  * Initializes the NaoRobotAPI and connects to the robot.
  */
RobotControl::RobotControl() : robotAPI(new NaoRobotAPI()), position(new Pose()), state(0) {
    // Connect to the Nao robot and perform any necessary initializations
    robotAPI->connect();
}

/**
 * @brief Destructor for the RobotControl class.
 * Disconnects from the Nao robot and cleans up allocated memory.
 */
RobotControl::~RobotControl() {
    // Disconnect from the Nao robot
    robotAPI->disconnect();

    // Clean up allocated memory
    delete robotAPI;
    delete position;
}

/**
 * @brief Turn the robot to the left.
 */
void RobotControl::turnLeft() {
    // Perform left turn operations on the robot
    double newTh = position->getTh() - 45.0; // Example turn angle
    position->setTh(newTh);
    robotAPI->turnRobot(LEFT);
}

/**
 * @brief Turn the robot to the right.
 */
void RobotControl::turnRight() {
    // Perform right turn operations on the robot
    double newTh = position->getTh() + 45.0; // Example turn angle
    position->setTh(newTh);
    robotAPI->turnRobot(RIGHT);
}

/**
 * @brief Move the robot forward.
 */
void RobotControl::forward() {
    if (state == 1) {
        // Perform forward movement operations on the robot
        double distance = 0.1; // Example distance
        double currentTh = position->getTh();
        Pose newPos = *position + Pose(distance * std::cos(currentTh), distance * std::sin(currentTh), 0.0);
        position->setPose(newPos.getX(), newPos.getY(), newPos.getTh());
        robotAPI->moveRobot(FORWARD);
    }
}

/**
 * @brief Move the robot backward.
 */
void RobotControl::backward() {
    if (state == 1) {
        // Perform backward movement operations on the robot
        double distance = 0.1; // Example distance
        double currentTh = position->getTh();
        Pose newPos = *position - Pose(distance * std::cos(currentTh), distance * std::sin(currentTh), 0.0);
        position->setPose(newPos.getX(), newPos.getY(), newPos.getTh());
        robotAPI->moveRobot(BACKWARD);
    }
}

/**
 * @brief Move the robot to the left.
 */
void RobotControl::moveLeft() {
    if (state == 1) {
        // Perform continuous left movement operations on the robot
        double distancePerStep = 0.5; // Example step distance
        double currentTh = position->getTh();
        Pose newPos = *position + Pose(-distancePerStep * std::sin(currentTh), distancePerStep * std::cos(currentTh), 0.0);
        position->setPose(newPos.getX(), newPos.getY(), newPos.getTh());
        robotAPI->moveRobot(LEFT);
    }
}

/**
 * @brief Move the robot to the right.
 */
void RobotControl::moveRight() {
    if (state == 1) {
        // Perform continuous right movement operations on the robot
        double distancePerStep = 0.1; // Example step distance
        double currentTh = position->getTh();
        Pose newPos = *position + Pose(distancePerStep * std::sin(currentTh), -distancePerStep * std::cos(currentTh), 0.0);
        position->setPose(newPos.getX(), newPos.getY(), newPos.getTh());
        robotAPI->moveRobot(RIGHT);
    }
}

/**
 * @brief Get the current pose of the robot.
 * @param x Reference to store the x-coordinate of the robot's position.
 * @param y Reference to store the y-coordinate of the robot's position.
 * @param th Reference to store the orientation angle of the robot.
 * @return Pointer to the current Pose object representing the robot's pose.
 */
Pose* RobotControl::getPose(double& x, double& y, double& th) {
    // Extract position information
    x = position->getX();
    y = position->getY();
    th = position->getTh();
    return position;
}

/**
 * @brief Stop the robot's movement.
 */
void RobotControl::stop() {
    state = 0;
    // Perform robot stop operations
    // The implementation of this function will depend on the robot API being used.
    // For example, in NaoRobotAPI, a stop function could be called.
    std::cout << "State: " << state << std::endl;
    robotAPI->stopRobot();
}

/**
 * @brief Print the current state and position of the robot.
 */
void RobotControl::print() {
    state = 1;
    // Print the movement state and current position to the console
    std::cout << "State: " << state << std::endl;
    double x, y, th;
    getPose(x, y, th);
    std::cout << "Current Position: (" << x << ", " << y << ", " << th << " degrees)" << std::endl;
}
