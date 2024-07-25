#include "Office.h"
#include <iostream>
#include <cstring>

using namespace std;

Office::Office() : Room("Undefined", -1), type(None), numberOfPeople(0) { // Default constructor
}

Office::Office(const char* name, int floor, officeType type, int people) : Room(name, floor), type(type), numberOfPeople(people) { // Parameterized constructor
}

Office::Office(const Office& other) : Room(other) { // Copy constructor
    type = other.type;
    numberOfPeople = other.numberOfPeople;
}

Office& Office::operator=(const Office& other) { // Assignment operator
    if (this != &other) {
        Room::operator=(other);
        type = other.type;
        numberOfPeople = other.numberOfPeople;
    }
    return *this;
}

Office::~Office() { // Destructor
}

officeType Office::getType() const {
    return type;
}

void Office::setType(officeType type) {
    this->type = type;
}

int Office::getNumberOfPeople() const {
    return numberOfPeople;
}

void Office::setNumberOfPeople(int numberOfPeople) {
    this->numberOfPeople = numberOfPeople;
}

int Office::getCapacity() const { // Returns the capacity of the office based on its type
    switch(type){
        case None:
            return 0;
        case CoordinatorOffice:
        case StandardOffice:
            return 1;
        case SharedOfficeFor2People:
            return 2;
        case SharedOfficeFor3People:
            return 3;
        case SharedOfficeFor10People:
            return 10;
        default:
            return 0;
    }
}

bool Office::isFull() const { // Checks if the office is full
    return numberOfPeople >= getCapacity();
}

void Office::printRoom() const {
    Room::printRoom();  // Call the base class print function to print room name and floor number
    cout << "Office name: " << getRoomName() << "\nFloor number: " << getFloorNo()
         << "\nOffice type: " << getType() << "\nNumber of people: " << getNumberOfPeople()
         << "\nOffice capacity: " << getCapacity();
    if (!isFull()) {
        cout << "\nOffice is not full" << endl;
    } else {
        cout << "\nOffice is full" << endl;
    }
}
