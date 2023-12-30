#include<iostream>
#include"NaoRobotAPI.h"
#include"ForceSensor.h"

NaoRobotAPI* nao;

// main function
int main() {
	//Create a robot object
	nao = new NaoRobotAPI();
	//Make connection to Nao
	nao->connect();
	//Create instances of the sensors connected to nao
	ForceSensor sensor(nao);
	

		std::cout << "ForceSensor testing..." << std::endl;
		std::cout << "Initial force: " << sensor.getForceValue() << std::endl;
		sensor.updateSensor();
		std::cout << "Updated force: " << sensor.getForceValue() << std::endl;

		if (sensor.checkFall())
			std::cout << "Nao has fallen." << std::endl;
		else
			std::cout << "No fall detected." << std::endl;
		Sleep(500);
		std::cout << "ForceSensor test is done...";

	Sleep(500);

	//Close connection to the robot
	nao->disconnect();

	//Delete the robot object
	delete nao;
	return 0;
}

