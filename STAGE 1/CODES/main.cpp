#include <iostream>
#include "Menu.h"
#include <thread>
#include <chrono>

/**
 * @brief The main function is the entry point of the program.
 * @return 0 on successful execution.
 */
int main() {
    // Create a NaoRobotAPI object to interact with the robot.
    NaoRobotAPI* robot = new NaoRobotAPI();

    // Create a Menu object to manage robot operations.
    Menu menu(robot);

    // Display the main menu and handle user interaction.
    menu.displayMenu();

    // Clean up and exit the program.
    delete robot;

    return 0;
}
