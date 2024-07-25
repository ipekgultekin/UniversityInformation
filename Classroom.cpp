//
// Created by ipekg on 13.05.2024.
//

#include "Classroom.h"
#include "Room.h"
#include "Building.h"
#include <iostream>

using namespace std;

int Classroom::getCapacity() const {
    return capacity;
}

void Classroom::setCapacity(int classCapacity) {
    capacity = classCapacity;
}

bool Classroom::checkSuitability(int numOfStudents) const { // Compare the provided number of students against the classroom's capacity
    return numOfStudents <= capacity; // Return true if the classroom can accommodate the given number of students, false otherwise
}

void Classroom::printRoom() const {
    Room::printRoom();  // Call the base class print function to print room name and floor number
    cout << "Classroom name: " << getRoomName() << "\nFloor number: " << getFloorNo()
         << "\nClassroom capacity: " << getCapacity();
    if (!isFull()) {
        cout << "\nClassroom is not full" << endl;
    } else {
        cout << "\nClassroom is full" << endl;
    }
}