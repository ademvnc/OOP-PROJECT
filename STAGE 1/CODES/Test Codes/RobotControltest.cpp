//152120211109
#include "RobotControl.h"
#include <iostream>
#include <thread>
#include <chrono>

void robotcontroltest() {
    // RobotControl nesnesi oluþtur
    RobotControl robotControl;

    // Sola dönme hareket ve sensör deðerlerini yazdýr
    std::cout << "Turning left..." << std::endl;
    robotControl.turnLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();

    // Ýleri hareket ve sensör deðerlerini yazdýr
    std::cout << "Moving forward..." << std::endl;
    robotControl.forward();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();

    // Geri hareket ve sensör deðerlerini yazdýr
    std::cout << "Moving backward..." << std::endl;
    robotControl.backward();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Sola hareket ve sensör deðerlerini yazdýr
    std::cout << "Moving left..." << std::endl;
    robotControl.moveLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Saða hareket ve sensör deðerlerini yazdýr
    std::cout << "Moving right..." << std::endl;
    robotControl.moveRight();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    robotControl.stop();
    robotControl.print();

    // Saða dönme ve sensör deðerlerini yazdýr
    std::cout << "Turning left..." << std::endl;
    robotControl.turnLeft();
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    robotControl.stop();
    robotControl.print();
}

int main() {

    robotcontroltest();  // test fonksiyonunu çaðýr

    return 0;
}