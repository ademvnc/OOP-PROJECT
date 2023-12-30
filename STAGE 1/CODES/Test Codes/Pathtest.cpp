// 152120211109
// PathTest.cpp
#include "Path.h"
#include <iostream>

// Function to perform tests
void PathTest() {
    // Default constructor test
    Path path1;
    std::cout << "Default Constructor Test:\n";
    path1.print();
    std::cout << "\n";

    // Pose addition test
    Pose pose1(1.0, 2.0, 45.0);
    Pose pose2(3.0, 4.0, 90.0);
    Pose pose3(5.0, 6.0, 135.0);

    path1.addPos(pose1);
    path1.addPos(pose2);
    path1.addPos(pose3);

    std::cout << "Add Position Test:\n";
    path1.print();
    std::cout << "\n";

    // Indexing and Get Position test
    std::cout << "Indexing and Get Position Test:\n";
    Pose retrievedPose1 = path1[0];
    Pose retrievedPose2 = path1.getPos(1);
    std::cout << "Retrieved Pose 1: (" << retrievedPose1.getX() << ", " << retrievedPose1.getY() << ", " << retrievedPose1.getTh() << " degrees)\n";
    std::cout << "Retrieved Pose 2: (" << retrievedPose2.getX() << ", " << retrievedPose2.getY() << ", " << retrievedPose2.getTh() << " degrees)\n\n";

    // Inserting a position after an index test
    Pose pose4(7.0, 8.0, 180.0);
    path1.insertPos(1, pose4);

    std::cout << "Insert Position Test:\n";
    path1.print();
    std::cout << "\n";

    // Removing a position at an index test
    path1.removePos(2);

    std::cout << "Remove Position Test:\n";
    path1.print();
    std::cout << "\n";
}

int main() {
    // Call the test function
    PathTest();

    return 0;
}
