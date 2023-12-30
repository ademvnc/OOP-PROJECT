// Path.cpp

#include "Path.h"
#include <iostream>

/**
 * @file
 * @brief This file contains the implementation of the Path class.
 */

 // Constructor
Path::Path() : head(nullptr), tail(nullptr), number(0) {}

// Destructor
Path::~Path() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    number = 0;
}

// Adds a new position to the path
void Path::addPos(const Pose& pos) {
    Node* newNode = new Node(pos);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    number++;
}

// Prints the list of poses to the console
void Path::print() const {
    Node* current = head;
    while (current != nullptr) {
        double x, y, th;
        current->data.getPose(x, y, th);
        std::cout << "X: " << x << " Y: " << y << " Th: " << th << std::endl;
        current = current->next;
    }
}

// Overloads the indexing operator to access poses by index
Pose Path::operator[](int index) const {
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        return current->data;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

// Gets the pose at the specified index
Pose Path::getPos(int index) const {
    return (*this)[index];
}

// Removes the pose at the specified index
void Path::removePos(int index) {
    if (index < 0 || index >= number) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = head;
    if (index == 0) {
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* toRemove = temp->next;
        temp->next = toRemove->next;
        delete toRemove;
        if (temp->next == nullptr) {
            tail = temp;
        }
    }
    number--;
}

// Inserts a new pose at the specified index
void Path::insertPos(int index, const Pose& pos) {
    if (index < 0 || index > number) {
        throw std::out_of_range("Index out of range");
    }
    Node* newNode = new Node(pos);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    number++;
}
