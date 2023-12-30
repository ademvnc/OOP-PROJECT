// Pose.cpp

#include "Pose.h"
#include <iostream>
#include <cmath>

/**
 * @file
 * @brief This file contains the implementation of the Pose class.
 */

 // Default constructor
Pose::Pose() : x_(0.0), y_(0.0), th_(0.0) {}

// Parameterized constructor
Pose::Pose(double x, double y, double th) : x_(x), y_(y), th_(th) {}

// Getter function for X coordinate
double Pose::getX() const {
    return x_;
}

// Getter function for Y coordinate
double Pose::getY() const {
    return y_;
}

// Getter function for orientation (theta)
double Pose::getTh() const {
    return th_;
}

// Setter function for X coordinate
void Pose::setX(double x) {
    x_ = x;
}

// Setter function for Y coordinate
void Pose::setY(double y) {
    y_ = y;
}

// Setter function for orientation (theta)
void Pose::setTh(double th) {
    th_ = th;
}

// Comparison operator (==) to check if two poses are equal
bool Pose::operator==(const Pose& other) const {
    return (x_ == other.getX() && y_ == other.getY() && th_ == other.getTh());
}

// Comparison operator (<) to compare poses (used for sorting)
bool Pose::operator<(const Pose& other) const {
    // You can define the comparison logic based on your requirements
    // For example, compare based on X, then Y, then theta
    if (x_ != other.getX()) {
        return x_ < other.getX();
    }
    else if (y_ != other.getY()) {
        return y_ < other.getY();
    }
    else {
        return th_ < other.getTh();
    }
}

// Addition operator (+) to add two poses
Pose Pose::operator+(const Pose& other) const {
    return Pose(x_ + other.getX(), y_ + other.getY(), th_ + other.getTh());
}

// Subtraction operator (-) to subtract two poses
Pose Pose::operator-(const Pose& other) const {
    return Pose(x_ - other.getX(), y_ - other.getY(), th_ - other.getTh());
}

// Compound addition operator (+=) to add another pose to the current pose
Pose& Pose::operator+=(const Pose& other) {
    x_ += other.getX();
    y_ += other.getY();
    th_ += other.getTh();
    return *this;
}

// Compound subtraction operator (-=) to subtract another pose from the current pose
Pose& Pose::operator-=(const Pose& other) {
    x_ -= other.getX();
    y_ -= other.getY();
    th_ -= other.getTh();
    return *this;
}

// Get the X, Y, and theta values of the pose
void Pose::getPose(double& x, double& y, double& th) const {
    x = x_;
    y = y_;
    th = th_;
}

// Set the X, Y, and theta values of the pose
void Pose::setPose(double x, double y, double th) {
    x_ = x;
    y_ = y;
    th_ = th;
}

// Calculate the Euclidean distance between two poses
double Pose::findDistanceTo(const Pose& pos) const {
    double dx = x_ - pos.getX();
    double dy = y_ - pos.getY();
    return std::sqrt(dx * dx + dy * dy);
}

// Calculate the angle (in radians) between two poses
double Pose::findAngleTo(const Pose& pos) const {
    return std::atan2(pos.getY() - y_, pos.getX() - x_);
}
