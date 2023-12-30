#include<iostream>
#include"NaoRobotAPI.h"
#include"SonarSensor.h"

NaoRobotAPI* nao;

// main function
int main() {
	//Create a robot object
    nao = new NaoRobotAPI();
	//Make connection to Nao
    nao->connect();
	//Create instances of the sensors connected to nao
	SonarSensor sensor(nao);

	    std::cout << "SonarSensor testing..." << std::endl;
	
		//Print initial sensor values
	    std::cout << "Initial sensor values: "
	        << "\nsonarRight: " << sensor[1]
	        << "\nsonarLeft: " << sensor[0] << std::endl;
	
		//Test updateSensor() function
	    sensor.updateSensor();
	    std::cout << "Updated sensor values: "
	        << "\nsonarRight: " << sensor[1]
	        << "\nsonarLeft: " << sensor[0] << std::endl;
	
		//Test getMin() and getMax() functions
	    std::cout << "Minimum value is: " << sensor.getMin() << std::endl;
	    std::cout << "Maximum value is: " << sensor.getMax() << std::endl;
	
		//Test [] operator
	    std::cout << "getRange(0): " << sensor.getRange(0)
	        << "\ngetRange(1): " << sensor.getRange(1) << std::endl;
	
	    std::cout << "sonar[0]: " << sensor.operator[](0)
	        << "\nsonar[1]: " << sensor.operator[](1) << std::endl;
	
	    Sleep(500);

	//Close connection to the robot
    nao->disconnect();

	//Delete the robot object
    delete nao;
    return 0;
}