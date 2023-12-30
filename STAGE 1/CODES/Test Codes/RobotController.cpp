//
// //---------------------------------------------------------------------------------
// //  Description:  Example controller program for Nao robot.
// //                This demonstrates how to use NaoRobotAPI
// //---------------------------------------------------------------------------------
//
//#include "NaoRobotAPI.h"
//#include <iostream>
//#include"BumperSensor.h"
//#include"ForceSensor.h"
//#include"SonarSensor.h"
//
//NaoRobotAPI* nao;
//
//void print() {
//
//	//Read sonar range values
//	double sonarLeft, sonarRight;
//	nao->getSonarRange(sonarLeft, sonarRight);
//
//	//Read foot bumper values
//	bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
//	nao->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
//
//	cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
//	cout << "POSE         : (X) " << nao->getX() << " meters, " 
//		<<"(Y) " << nao->getY() << " meters, " 
//		<<"(Th) " << nao->getTh() << " degrees" << endl << endl;
//	cout << "SONAR RANGES : (LEFT) "<<sonarLeft
//		<<" meters, (RIGHT) "<<sonarRight<<" meters" << endl << endl;
//	cout << "FOOT FORCE   : " << nao->getFootForce() << " kg.f" << endl;
//	cout << "----------------------------------------------------------------------" << endl;
//}
//
//
//// main function
//int main() {
//	//Create a robot object
//    nao = new NaoRobotAPI();
//	//Make connection to Nao
//    nao->connect();
//	//Create instances of the sensors connected to nao
//	BumperSensor bumperSensor(nao);
//	SonarSensor sonarSensor(nao);
//	ForceSensor forceSensor(nao);
//
//	bumperSensor.Test();
//	std::cout << "\n\n\n";
//	sonarSensor.Test();
//	std::cout << "\n\n\n";
//	forceSensor.Test();
//	std::cout << "\n\n\n";
//
//	//Print the real values
//	print();
//
//	//Close connection to the robot
//    nao->disconnect();
//
//	//Delete the robot object
//    delete nao;
//    return 0;
//}
//
////Extra test code
//
//
////   //Update the sensor values
//   //sonarSensor.updateSensor();
//   //bumperSensor.updateSensor();
//   //forceSensor.updateSensor();
//
//   //Sleep(1000);
//
//
//   ////Get the value of sonar sensor with the index 1
//   //sonarSensor.getRange(1);
//   ////Get the sensor value with index of 1, works same as the [] operator
//   //sonarSensor[1];
//
//   ////Get max and min values among the sonar values
//   //sonarSensor.getMax();
//   //sonarSensor.getMin();
//   //Sleep(1000);
//
//
//   ////Check bumper values for touch, return 1 if any has a touch
//   //std::cout<<bumperSensor.checkTouch()<<std::endl;
//
//   ////Check for fall using force sensors of the robot
//   //std::cout << forceSensor.checkFall() << std::endl;
//   //Sleep(1000);
//
