#pragma once

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "BumperSensor.h"
#include "Encryption.h"
#include "ForceSensor.h"
#include "NaoRobotApI.h"
#include "Path.h"
#include "Pose.h"
#include "Record.h"
#include "RobotControl.h"
#include "RobotOperator.h"
#include "SonarSensor.h"
#include <thread>
#include <chrono>

/**
 * @brief The Menu class provides a menu interface for interacting with a robot.
 */
class Menu {
public:
    /**
     * @brief Display the main menu.
     */
    void displayMenu();

    /**
     * @brief Handle the robot connection.
     */
    void handleConnection();

    /**
     * @brief Handle robot motion control.
     */
    void handleMotion();

    /**
     * @brief Handle robot sensor readings.
     */
    void handleSensors();

    /**
     * @brief Display the Bumper Sensor menu.
     */
    void BumperSensorMenu();

    /**
     * @brief Display the Sonar Sensor menu.
     */
    void SonarSensorMenu();

    /**
     * @brief Display the Force Sensor menu.
     */
    void ForceSensorMenu();

    /**
     * @brief Constructor for the Menu class.
     * @param robot Pointer to the NaoRobotAPI object.
     */
    Menu(NaoRobotAPI* robot);

private:
    NaoRobotAPI* robot;
    BumperSensor bumper;
    SonarSensor sonar;
    ForceSensor force;
};

#endif // MENU_H
