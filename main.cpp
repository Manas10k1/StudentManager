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
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Search by Name\n";
        cout << "7. Search by Roll Number\n";
        cout << "8. Sort by Roll Number\n";
        cout << "9. Binary Search by Roll Number\n";
        cout << "0. Exit\n";
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
                sm.updateStudent();
                break;
            
            case 5:
                sm.deletEle();
                break;

            case 6:
                sm.nameSearch();
                break;

            case 7:
                sm.rollSearch();
                break;

            case 8:
                sm.sortStudents();
                break;

            case 9:
                sm.binarySearch();
                break;
            
            case 0:
                cout << "Program Exited.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
