#include "Room.h"
#include <iostream>
#include <cstring>

using namespace std;

Room::Room() { // Default constructor
    roomName = new char[strlen("Undefined") + 1];
    strcpy(roomName, "Undefined");
    floorNo = -1;
}

Room::Room(const char* roomName, int floorNo) { // Parameterized constructor
    this->roomName = new char[strlen(roomName) + 1];
    strcpy(this->roomName, roomName);
    this->floorNo = floorNo;
}

Room::Room(const Room& other) { // Copy constructor
    copyFrom(other);
}

Room& Room::operator=(const Room& other) { // Assignment operator
    if (this != &other) {
        delete[] roomName;
        copyFrom(other);
    }
    return *this;
}

void Room::copyFrom(const Room& other) { // Helper function for copying
    roomName = new char[strlen(other.roomName) + 1];
    strcpy(roomName, other.roomName);
    floorNo = other.floorNo;
}

Room::~Room() { // Destructor
    delete[] roomName;
}

char* Room::getRoomName() const {
    return roomName;
}

void Room::setRoomName(const char* room) {
    delete[] roomName;
    roomName = new char[strlen(room) + 1];
    strcpy(roomName, room);
}

int Room::getFloorNo() const {
    return floorNo;
}

void Room::setFloorNo(int floor) {
    floorNo = floor;
}

void Room::printRoom() const {
    // Prints the room's details including name and floor number.
    cout << "Room Name: " << roomName << "\nFloor No: " << floorNo << endl;
}
