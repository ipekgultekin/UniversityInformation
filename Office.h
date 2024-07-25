#ifndef UNTITLED_OFFICE_H
#define UNTITLED_OFFICE_H
#include "Room.h"
#include <cstring>

//enum
enum officeType {None, CoordinatorOffice, StandardOffice, SharedOfficeFor2People, SharedOfficeFor3People, SharedOfficeFor10People};

class Office : public Room { //inheritance type
private:
    int numberOfPeople;
    officeType type;

public:
    Office(); // Default constructor

    Office(const char* name, int floor, officeType type, int people); // Parameterized constructor

    Office(const Office& other); // Copy constructor

    Office& operator=(const Office& other); // Assignment operator

    ~Office(); // Destructor

    officeType getType() const;

    void setType(officeType type);

    int getNumberOfPeople() const;

    void setNumberOfPeople(int numberOfPeople);

    int getCapacity() const override;

    bool isFull() const override;

    void printRoom() const override;
};

#endif //UNTITLED_OFFICE_H
