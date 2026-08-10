#include <iostream>
#include <limits>
#include "StudentManager.h"
using namespace std;

int main(){
    StudentManager sm;
    int choice;

    do {
        cout << "\n========== STUDENT MANAGEMENT SYSTEM V1 ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Insert Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Search by Name\n";
        cout << "6. Search by Roll Number\n";
        cout << "7. Sort by Roll Number\n";
        cout << "8. Binary Search by Roll Number\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        Student::checkInput(choice);

        cout << endl;

        switch (choice) {
            case 1:
                sm.addStudent();
                break;

            case 2:
                sm.displayAll();
                break;

            case 3:
                sm.insert();
                break;

            case 4:
                sm.deletEle();
                break;

            case 5:
                sm.nameSearch();
                break;

            case 6:
                sm.rollSearch();
                break;

            case 7:
                sm.sortStudents();
                break;

            case 8:
                sm.binarySearch();
                break;
            
                case 9:
                cout << "Program Exited.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}
