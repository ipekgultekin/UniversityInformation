#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H
#include <cstring>

class Room {
private:
    char* roomName;
    int floorNo;

    void copyFrom(const Room& other); // Helper function for copying

public:
    Room(); // Default constructor
    Room(const char* roomName, int floorNo); // Parameterized constructor
    Room(const Room& other); // Copy constructor
    Room& operator=(const Room& other); // Assignment operator
    virtual ~Room(); // Destructor

    virtual void printRoom() const; // Virtual function to print room details - can be overridden by derived classes
    virtual int getCapacity() const { // Virtual function to get capacity, returns 0 by default, can be overridden
        return 0; // Default capacity is 0
    }
    virtual bool isOffice() const { // Virtual function to determine if the room is an office or not, can be overridden
        return false; // Default is not an office
    }
    virtual bool isFull() const { // Virtual function to check if the room is full, can be overridden
        return true; // Default is full
    }
    virtual bool checkSuitability(int numOfStudents) const { // Virtual function to check if the room is suitable for a number of students, can be overridden
        return true; // Default is suitable
    }

    char* getRoomName() const;
    void setRoomName(const char* roomName);
    int getFloorNo() const;
    void setFloorNo(int floorNo);
};

#endif //UNTITLED_ROOM_H
