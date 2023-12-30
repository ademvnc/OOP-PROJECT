//152120211109
#include "RobotControl.h"
#include <iostream>
#include <thread>
#include <chrono>

void robotcontroltest() {
    // RobotControl nesnesi olu�tur
    RobotControl robotControl;

    // Sola d�nme hareket ve sens�r de�erlerini yazd�r
    std::cout << "Turning left..." << std::endl;
    robotControl.turnLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();

    // �leri hareket ve sens�r de�erlerini yazd�r
    std::cout << "Moving forward..." << std::endl;
    robotControl.forward();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();

    // Geri hareket ve sens�r de�erlerini yazd�r
    std::cout << "Moving backward..." << std::endl;
    robotControl.backward();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Sola hareket ve sens�r de�erlerini yazd�r
    std::cout << "Moving left..." << std::endl;
    robotControl.moveLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Sa�a hareket ve sens�r de�erlerini yazd�r
    std::cout << "Moving right..." << std::endl;
    robotControl.moveRight();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Sa�a d�nme ve sens�r de�erlerini yazd�r
    std::cout << "Turning left..." << std::endl;
    robotControl.turnLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();
}

int main() {

    robotcontroltest();  // test fonksiyonunu �a��r

    return 0;
}