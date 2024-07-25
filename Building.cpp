#include "Building.h"
#include "Office.h"
#include "Classroom.h"
#include <iostream>

using namespace std;

Building::Building() {
    buildingName = new char[strlen("Undefined")+1];
    strcpy(buildingName, "Undefined");
    buildingSize = -1;
    numberOfRooms = 0;
}

Building::Building(const char* buildingName, int buildingSize) {
    this->buildingName = new char[strlen(buildingName)+1];
    strcpy(this->buildingName, buildingName);
    this->buildingSize = buildingSize;
    this->numberOfRooms = 0;
}

Building::Building(const Building& other) {
    buildingName = new char[strlen(other.buildingName) + 1];
    strcpy(buildingName, other.buildingName);
    buildingSize = other.buildingSize;
    numberOfRooms = other.numberOfRooms;
    for (int i = 0; i < numberOfRooms; ++i) {
        rooms[i] = other.rooms[i];
    }
}

Building& Building::operator=(const Building& other) {
    if (this != &other) {
        delete[] buildingName;
        buildingName = new char[strlen(other.buildingName) + 1];
        strcpy(buildingName, other.buildingName);
        buildingSize = other.buildingSize;
        numberOfRooms = other.numberOfRooms;
        for (int i = 0; i < numberOfRooms; ++i) {
            rooms[i] = other.rooms[i];
        }
    }
    return *this;
}

Building::~Building() {
    delete[] buildingName;
}

void Building::addRoom(int buildingNo, int roomType, const char* roomName, int floorNumber) {
    if (numberOfRooms < 100) {
        if (roomType == 1) { // Classroom
            int capacity;
            cout << "Please enter capacity of classroom: ";
            cin >> capacity;
            rooms[numberOfRooms++] = new Classroom(roomName, floorNumber, capacity);
        } else if (roomType == 2) { // Office
            int office;
            cout << "[1] Coordinator Office" << endl;
            cout << "[2] Standard Office" << endl;
            cout << "[3] Shared Office for 2 people" << endl;
            cout << "[4] Shared Office for 3 people" << endl;
            cout << "[5] Shared Office for 10 people" << endl;
            cout << "Please enter type of office: ";
            cin >> office;
            int numberOfPeople;
            officeType type = None;

            if (office == 1)
                type = CoordinatorOffice;
            else if (office == 2)
                type = StandardOffice;
            else if (office == 3)
                type = SharedOfficeFor2People;
            else if (office == 4)
                type = SharedOfficeFor3People;
            else if (office == 5)
                type = SharedOfficeFor10People;
            else
                cout << "Invalid office type." << endl;

            cout << "Please enter number of people in the office: ";
            cin >> numberOfPeople;
            rooms[numberOfRooms++] = new Office(roomName, floorNumber, type, numberOfPeople);
        } else {
            cout << "Invalid room type." << endl;
        }
    } else {
        cout << "Error. Max number of rooms reached." << endl;
    }
}

void Building::printBuilding() const {
    cout << "Building Name: " << buildingName << endl;
    cout << "Size: " << buildingSize << "m2" << endl;
    cout << "Number of Rooms: " << numberOfRooms << endl;
}

void Building::printRooms() const {
    cout << "All rooms in building:\n" << endl;
    for (int i = 0; i < numberOfRooms; i++) {
        rooms[i]->printRoom();
    }
}

int Building::getTotalCapacity() const {
    int totalCapacity = 0;
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i]->isItOfficeOrNot()) {
            totalCapacity += rooms[i]->getCapacity();
        }
    }
    return totalCapacity;
}

void Building::printAvailableOffices() const {
    cout << "Available offices in " << buildingName << ":" << endl;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (!rooms[i]->isFull() && rooms[i]->isItOfficeOrNot()) {
            rooms[i]->printRoom();
        }
    }
}

void Building::printSuitableClassrooms(int numStudents) const {
    cout << "Suitable classrooms in " << buildingName << " for " << numStudents << " students:" << endl;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (rooms[i]->checkSuitability(numStudents) && !rooms[i]->isItOfficeOrNot()) {
            rooms[i]->printRoom();
        }
    }
}

int Building::getNumberOfClassrooms() {
    int count = 0;
    for (int i = 0; i < numberOfRooms; i++) {
        if (!rooms[i]->isItOfficeOrNot()) {
            count++;
        }
    }
    return count;
}

int Building::getNumberOfOffices() {
    int count = 0;
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i]->isItOfficeOrNot()) {
            count++;
        }
    }
    return count;
}

void Building::printRoomsByType(bool isOffice) const {
    cout << (isOffice ? "Offices" : "Classrooms") << " in " << buildingName << ":" << endl;
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i]->isItOfficeOrNot() == isOffice) {
            rooms[i]->printRoom();
        }
    }
}

char* Building::getBuildingName() const {
    return buildingName;
}

void Building::setBuildingName(const char* buildingName) {
    delete[] this->buildingName;
    this->buildingName = new char[strlen(buildingName) + 1];
    strcpy(this->buildingName, buildingName);
}

int Building::getBuildingSize() const {
    return buildingSize;
}

void Building::setBuildingSize(int buildingSize) {
    this->buildingSize = buildingSize;
}

int Building::getNumberOfRooms() const {
    return numberOfRooms;
}
