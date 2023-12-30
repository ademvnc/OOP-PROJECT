#include"BumperSensor.h"
#include"NaoRobotAPI.h"
#include<iostream>

NaoRobotAPI* nao;

/**
 * @brief Test the functionality of the BumperSensor class.
 */

 int main(){
     nao = new NaoRobotAPI();
     BumperSensor sensor(nao);

     nao->connect();

    std::cout << "BumperSensor testing... " << std::endl;

    std::cout << "Initial bumper values:\n"
        << "Left foot left bumper: " << sensor.get_lFoot_left()
        << "\nLeft foot right bumper: " << sensor.get_lFoot_right()
        << "\nRight foot left bumper: " << sensor.get_rFoot_left()
        << "\nRight foot right bumper: " << sensor.get_rFoot_right() << std::endl;

    sensor.updateSensor();

    std::cout << "Updated bumper values:\n"
        << "Left foot left bumper: " << sensor.get_lFoot_left()
        << "\nLeft foot right bumper: " << sensor.get_lFoot_right()
        << "\nRight foot left bumper: " << sensor.get_rFoot_left()
        << "\nRight foot right bumper: " << sensor.get_rFoot_right() << std::endl;

    std::cout << "Any touch: " << sensor.checkTouch() << std::endl;

    std::cout << "getState(0): " << sensor.getState(0)
        << "\ngetState(1): " << sensor.getState(1)
        << "\ngetState(2): " << sensor.getState(2)
        << "\ngetState(3): " << sensor.getState(3) << std::endl;

    Sleep(500);

    nao->disconnect();

    std::cout << "BumperSensor test is done..." << std::endl;

    return 0;
}
