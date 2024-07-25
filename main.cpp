#include <iostream>
#include "University.h"
#include "Office.h"
#include "Classroom.h"

using namespace std;

int main() {
    University university;
    int choice, sizeOfBuilding, roomType, floorNo, buildingNo, numStudents;
    char roomName[50];
    char nameOfBuilding[50];

    do {
        cout << "[1] Add a new building to the university\n"
                "[2] Add a new room to a selected building\n"
                "[3] Print the buildings in the university\n"
                "[4] Print the rooms in each building in the university\n"
                "[5] Print the rooms in each building in the university based on type\n"
                "[6] Print the total number of classrooms and offices in the university\n"
                "[7] Print the available offices in each building in the university\n"
                "[8] Print the total capacity of all the offices\n"
                "[9] Print the suitable classrooms in the university based on the given number of students\n"
                "[0] Exit\n"
                "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nPlease enter name of building: ";
                cin >> nameOfBuilding;
                cout << "\nPlease enter size of building in m2: ";
                cin >> sizeOfBuilding;
                university.addBuilding(nameOfBuilding, sizeOfBuilding);
                break;

            case 2:
                university.printBuildings();
                cout << "Please enter the number of building to which the room should be added: ";
                cin >> buildingNo;
                cout << "Please enter the type of room (1: Classroom / 2: Office): ";
                cin >> roomType;
                cout << "Please enter the name of the new room: ";
                cin >> roomName;
                cout << "Please enter the floor number of the new room: ";
                cin >> floorNo;
                university.addRoomToBuilding(buildingNo, roomType, roomName, floorNo);
                break;

            case 3:
                cout << "\nBuildings in " << university.getUniversityName() << ":\n";
                university.printBuildings();
                break;

            case 4:
                university.printRooms();
                break;

            case 5:
                cout << "Please enter type of room to display: \n"
                        "[1] Classrooms \n"
                        "[2] Offices \n";
                cin >> roomType;
                university.printRoomsByType(roomType == 2);
                break;

            case 6:
                university.printRoomTypeStatistics();
                break;

            case 7:
                university.printAvailableOffices();
                break;

            case 8:
                university.printTotalCapacity();
                break;

            case 9:
                cout << "Please enter the number of students: ";
                cin >> numStudents;
                university.printSuitableClassrooms(numStudents);
                break;

            case 0:
                cout << "Byee" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
