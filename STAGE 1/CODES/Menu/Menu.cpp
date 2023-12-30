#include "Menu.h"
#include <iostream>

/**
 * @file
 * @brief This file contains the implementation of the Menu class and the main function.
 */

 /**
  * @brief Displays the main menu and handles user input.
  */
void Menu::displayMenu()
{
    int choice;
    std::cout << "1. Connection" << std::endl;
    std::cout << "2. Motion" << std::endl;
    std::cout << "3. Sensors" << std::endl;
    std::cout << "4. Quit" << std::endl;

    std::cin >> choice;

    switch (choice)
    {

    case 1:
        handleConnection();
        break;

    case 2:
        handleMotion();
        break;

    case 3:
        handleSensors();
        break;

    case 4:
        std::cout << "Exiting..." << std::endl;
        exit(0);
        break;
    }
}

/**
 * @brief Constructor for the Menu class.
 * @param robot Pointer to the NaoRobotAPI object.
 */
Menu::Menu(NaoRobotAPI* robot)
    : robot(robot), bumper(robot), sonar(robot), force(robot) {
    // Additional initialization code can be added here if necessary.
}

/**
 * @brief Handles the connection menu.
 */
void Menu::handleConnection() {
    int choice;
    do {
        std::cout << "Connection Menu\n";
        std::cout << "1. Connect Robot\n";
        std::cout << "2. Disconnect Robot\n";
        std::cout << "3. Back\n";
        std::cout << "Choose one: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            robot->connect();
            std::cout << "Robot is connected...\n";
            displayMenu();
            break;

        case 2:
            robot->disconnect();
            std::cout << "Robot is disconnected...\n";
            displayMenu();
            break;

        case 3:
            std::cout << "Returning to the main menu... \n";
            displayMenu();
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (true);  // Keep looping until an explicit break is encountered
}

/**
 * @brief Handles the motion menu.
 */
void Menu::handleMotion() {

    RobotControl robotControl;
    int choice;

    do {
        std::cout << "\nMotion Menu\n";
        std::cout << "1. Turn Left\n";
        std::cout << "2. Turn Right\n";
        std::cout << "3. Move Forward\n";
        std::cout << "4. Move Backward\n";
        std::cout << "5. Move Left\n";
        std::cout << "6. Move Right\n";
        std::cout << "7. Quit\n";
        std::cout << "Choose one: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Turning left..." << std::endl;
            robotControl.turnLeft();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 2:
            std::cout << "Turning right..." << std::endl;
            robotControl.turnRight();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 3:
            std::cout << "Moving forward..." << std::endl;
            robotControl.forward();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 4:
            std::cout << "Moving backward..." << std::endl;
            robotControl.backward();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 5:
            std::cout << "Moving left..." << std::endl;
            robotControl.moveLeft();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 6:
            std::cout << "Moving right..." << std::endl;
            robotControl.moveRight();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            robotControl.stop();
            robotControl.print();
            break;
        case 7:
            std::cout << "Quitting the motion menu.\n";
            displayMenu();
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
}

/**
 * @brief Handles the sensors menu.
 */
void Menu::handleSensors() {
    int choice;
    std::cout << "1. Bumper Sensor" << std::endl;
    std::cout << "2. Sonar Sensor" << std::endl;
    std::cout << "3. Force Sensor" << std::endl;

    std::cin >> choice;

    switch (choice)
    {

    case 1:
        BumperSensorMenu();
        break;
    case 2:
        SonarSensorMenu();
        break;
    case 3:
        ForceSensorMenu();
        break;
    }
}

/**
 * @brief Handles the bumper sensor menu.
 */
void Menu::BumperSensorMenu()
{
    std::cout << "Bumper Sensor Menu" << std::endl
        << "1. Get state" << std::endl
        << "2. Check touch" << std::endl
        << "3. Update force sensor" << std::endl
        << "4. Back" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Type the index of the bumper: " << std::endl;
        int index;
        std::cin >> index;
        bumper.getState(index);
        displayMenu();
        break;
    case 2:
        if (bumper.checkTouch()) {
            std::cout << "Robot has fallen" << std::endl;
            displayMenu();
        }
        else {
            std::cout << "No fall detected" << std::endl;
            displayMenu();
        }
        break;

    case 3:
        bumper.updateSensor();
        displayMenu();
        break;
    case 4:
        handleSensors();
        break;
    default:
        std::cout << "Select an action from the menu" << std::endl;
        break;
    }
}

/**
 * @brief Handles the sonar sensor menu.
 */
void Menu::SonarSensorMenu()
{
    std::cout << "Sonar Sensor Menu" << std::endl
        << "1. Get range" << std::endl
        << "2. Get maximum" << std::endl
        << "3. Get minimum" << std::endl
        << "4. Update sonar sensor" << std::endl
        << "5. Back" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Type the index of the sonar: " << std::endl;
        int index;
        std::cin >> index;
        std::cout << "Range of the sonar with the given index: " << sonar.getRange(index) << std::endl;
        displayMenu();
        break;
    case 2:
        std::cout << "Maximum sonar value: " << sonar.getMax() << std::endl;
        displayMenu();
        break;
    case 3:
        std::cout << "Minimum sonar value: " << sonar.getMin() << std::endl;
        displayMenu();
        break;
    case 4:
        sonar.updateSensor();
        displayMenu();
    case 5:
        handleSensors();
    default:
        std::cout << "Select an action from the menu" << std::endl;
        SonarSensorMenu();
        break;
    }
}

/**
 * @brief Handles the force sensor menu.
 */
void Menu::ForceSensorMenu()
{
    std::cout << "Force Sensor Menu" << std::endl
        << "1. Get force" << std::endl
        << "2. Get force value" << std::endl
        << "3. Check fall" << std::endl
        << "4. Update force sensor" << std::endl
        << "5. Back" << std::endl;

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        force.getForce();
        displayMenu();
        break;
    case 2:
        std::cout << "Value of the force: " << force.getForceValue() << std::endl;
        displayMenu();
        break;
    case 3:
        if (force.checkFall())
            std::cout << "Robot has fallen" << std::endl;
        else
            std::cout << "No fall has detected" << std::endl;
        break;
    case 4:
        force.updateSensor();
        displayMenu();
        break;
    case 5:
        handleSensors();
        break;
    default:
        std::cout << "Select an action from the menu" << std::endl;
        ForceSensorMenu();
        break;
    }
}

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
