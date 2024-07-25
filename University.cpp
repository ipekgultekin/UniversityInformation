#include "University.h"
#include <iostream>
#include <cstring>

using namespace std;

University::University() {
    universityName = new char[strlen("METU NCC") + 1];
    strcpy(universityName, "METU NCC");
    numberOfBuildings = 0;
}

University::University(const char* universityName) {
    this->universityName = new char[strlen(universityName) + 1];
    strcpy(this->universityName, universityName);
    numberOfBuildings = 0;
}

University::University(const University& other) {
    copyFrom(other);
}

University& University::operator=(const University& other) {
    if (this != &other) {
        delete[] universityName;
        copyFrom(other);
    }
    return *this;
}

void University::copyFrom(const University& other) {
    universityName = new char[strlen(other.universityName) + 1];
    strcpy(universityName, other.universityName);
    numberOfBuildings = other.numberOfBuildings;
    for (int i = 0; i < numberOfBuildings; i++) {
        building[i] = other.building[i];
    }
}

University::~University() {
    delete[] universityName;
}

int University::getNumberOfBuildings() const {
    return numberOfBuildings;
}

char* University::getUniversityName() const {
    return universityName;
}

const Building* University::getBuilding() const {
    return building;
}

void University::setUniversityName(const char* universityName) {
    delete[] this->universityName;
    this->universityName = new char[strlen(universityName) + 1];
    strcpy(this->universityName, universityName);
}

void University::addBuilding(char* buildingName, int buildingSize) {
    if (numberOfBuildings < 20) {
        building[numberOfBuildings++] = Building(buildingName, buildingSize);
    } else {
        cout << "Error. Max number of buildings reached." << endl;
    }
}

void University::printBuildings() {
    cout << "University Name: " << universityName << endl;
    cout << "Number of Buildings in " << universityName << " university: " << numberOfBuildings << endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << "\nBuilding " << i + 1 << ":" << endl;
        building[i].printBuilding();
    }
}

void University::printRooms() {
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << "All rooms in " << building[i].getBuildingName() << " building:\n" << endl;
        building[i].printRooms();
    }
}

void University::printRoomsByType() {
    int roomType;
    cout << "Please enter the type of room (1: Classroom / 2: Office): " << endl;
    cin >> roomType;

    if (roomType == 1 || roomType == 2) {
        for (int i = 0; i < numberOfBuildings; i++) {
            building[i].printRoomsByType(roomType);
        }
    } else {
        cout << "Wrong room type!" << endl;
    }
}

void University::printAvailableOffices() {
    cout << "Available offices in " << universityName << ": " << std::endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        building[i].printAvailableOffices();
    }
}

void University::printTotalCapacityOfOffices() {
    int totalCapacity = 0;
    for (int i = 0; i < numberOfBuildings; i++) {
        totalCapacity += building[i].getTotalCapacity();
    }
    cout << "Total capacity of offices in " << universityName << ": " << totalCapacity << std::endl;
}

void University::printSuitableClassrooms() {
    int numberOfStudents;
    cout << "Please enter number of students: ";
    cin >> numberOfStudents;
    cout << "Suitable classes in " << universityName << " for " << numberOfStudents << " students: " << std::endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        building[i].printSuitableClassrooms(numberOfStudents);
    }
}
