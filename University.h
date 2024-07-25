#ifndef UNTITLED_UNIVERSITY_H
#define UNTITLED_UNIVERSITY_H

#include "Building.h"
#include <iostream>

using namespace std;

class University {
private:
    char* universityName;
    Building building[20];
    int numberOfBuildings;

    void copyFrom(const University& other); // helper function for copying

public:
    University(); // default constructor
    University(const char* universityName); // parameterized constructor
    University(const University& other); // copy constructor
    University& operator=(const University& other); // assignment operator
    ~University(); // destructor

    char* getUniversityName() const;
    void setUniversityName(const char* universityName);

    void printBuildings();
    int getNumberOfBuildings() const;
    const Building* getBuilding() const;

    void printAvailableOffices();
    void printTotalCapacityOfOffices();
    void printSuitableClassrooms();
    void printRoomsByType();
    void printRooms();

    void addBuilding(char* buildingName, int buildingSize);
};

#endif //UNTITLED_UNIVERSITY_H
