//
// Created by ipekg on 13.05.2024.
//

#ifndef UNTITLED_CLASSROOM_H
#define UNTITLED_CLASSROOM_H

#include "Room.h"

class Classroom : virtual public Room {
// Classroom class definition, derived from Room class
private:

public:
    int capacity;
    Classroom() : Room() {  // Default constructor that initializes the room and sets capacity to -1 (undefined), and call the base class constructor to initialize Room part
        capacity = -1;
    }

    Classroom(const char* name, int floor, int cap) : Room(name, floor) , capacity(cap) {}  // Constructor that takes name, floor, and capacity, initializes Room part with name and floor


    Classroom(char* roomName, int floorNo, int capacity){
        // Fully parameterized constructor to initialize all member variables
        setRoomName(roomName);
        setFloorNo(floorNo);
        setCapacity(capacity);
    }


    int getCapacity() const;
    void setCapacity(int cap);
    bool checkSuitability(int numOfStudents) const; // Returns true if numOfStudents is less than or equal to capacity
    void printRoom() const;
};


#endif //UNTITLED_CLASSROOM_H
