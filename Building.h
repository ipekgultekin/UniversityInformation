#ifndef UNTITLED_BUILDING_H
#define UNTITLED_BUILDING_H

#include <cstring>
#include "Room.h"

class Building {
private:
    char* buildingName;
    int buildingSize;
    Room* rooms[100];
    int numberOfRooms;

public:
    Building();

    Building(const char* buildingName, int buildingSize);

    Building(const Building& other); // Copy constructor

    Building& operator=(const Building& build);

    ~Building();

    char* getBuildingName() const;

    void setBuildingName(const char* buildingName);

    int getBuildingSize() const;

    void setBuildingSize(int buildingSize);

    int getNumberOfRooms() const;

    void printBuilding() const;

    void printRooms() const;

    int getTotalCapacity() const;

    void printAvailableOffices() const;

    void printSuitableClassrooms(int numStudents) const;

    int getNumberOfClassrooms() const;

    int getNumberOfOffices() const;

    void printRoomsByType(bool isOffice) const;

    void addRoom(int buildingNo, int roomType, const char* roomName, int floorNumber);
};

#endif //UNTITLED_BUILDING_H
