// 152120211109
#include "Pose.h"
#include <iostream>

using namespace std;

void PoseTest() {
    // Örnek Pose nesneleri oluþtur
    Pose naoPose;
    Pose targetPose;

    // Nao'nun konumunu ayarla
    naoPose.setX(1.0);
    naoPose.setY(2.0);
    naoPose.setTh(45.0);

    // Hedef konumu ayarla
    targetPose.setX(3.0);
    targetPose.setY(4.0);
    targetPose.setTh(60.0);

    // Nao'nun ve hedefin konumlarýný ekrana yazdýr
    std::cout << "Nao's Pose: (" << naoPose.getX() << ", " << naoPose.getY() << ", " << naoPose.getTh() << " degrees)\n";
    std::cout << "Target Pose: (" << targetPose.getX() << ", " << targetPose.getY() << ", " << targetPose.getTh() << " degrees)\n";

    // Nao'nun hedefe olan mesafesini ve açýsýný hesapla
    double distance = naoPose.findDistanceTo(targetPose);
    double angle = naoPose.findAngleTo(targetPose);

    std::cout << "Distance to Target: " << distance << " meters\n";
    std::cout << "Angle to Target: " << angle << " degrees\n";


}

int main() {
    PoseTest();
    return 0;
};