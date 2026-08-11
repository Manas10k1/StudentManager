#include <iostream>
#include <limits>
#include "Student.h"
#include "StudentManager.h"
using namespace std;

StudentManager::StudentManager(){
    do{
        cout << "Enter number of Students: ";
        Student::checkInput(size);
    } while(size <= 0);

    students = new Student[size];

}

void StudentManager::addStudent(){
    if(count == size){
        cout << "\nSTORAGE FULL\n";
    }
    else{
        students[count].input();
        count++;
        isSorted = false;
    }
}

void StudentManager::displayAll(){
    if(count == 0){
        cout << "No students available.\n";
        return;
    }
    
    for(int i = 0; i < count; i++){
    students[i].display();
    }
}

void StudentManager::insert(){
    if(count == size){
        cout << "\nStorage Full\n";
    }
    else{
        int index;
        do{
            cout << "Enter Index to input: ";
            Student::checkInput(index);
        } while(index < 1 || index > count+1);

        for(int i = count; i > index-1; i--){
            students[i] = students[i-1];
        }
        students[index-1].input();
        count++;
        isSorted = false;
    }
}

void StudentManager::updateStudent(){

    if(count == 0){
        cout << "No students available.\n";
        return;
    }

    int index;
    do{
        cout << "Enter Index to input: ";
        Student::checkInput(index);
    } while(index < 1 || index > count);
    int choice;
    cout << "Update NAME(1)\n" << "AGE(2)\n" << "ROLL NUMBER(3)\n";
    cin >> choice;
    
    switch(choice){
        case 1:{
            cout << "Enter Name of Student: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::string newName;
            getline(cin, newName);
            students[index-1].setName(newName);
            break;
        }
        
        case 2:{
            int newAge;
            do{
                cout << "Enter age of Student: ";
                Student::checkInput(newAge);
            } while(newAge < 1);
            
            students[index-1].setAge(newAge);
            break;
        }
        case 3:{
            int newRoll;
            do{
                cout << "Enter Roll number of Student: ";
                Student::checkInput(newRoll);
            } while(newRoll < 1);
            students[index-1].setRoll(newRoll);
            isSorted = false;
            break;
        }
        default:
            cout << "Invalid Choice! --- TRY AGAIN" <<endl;

    }
}

void StudentManager::deletEle(){
    int index;
    if(count == 0){
        cout << "No students to delete.\n";
        return;
    }
    
    do{
        cout << "Enter Index to Delete: ";
        Student::checkInput(index);
    } while(index < 1 || index > count);

    for(int i = index-1; i < count-1; i++){
        students[i]=students[i+1];
    }
    count--;
    isSorted = false;

}

void StudentManager::nameSearch(){
    bool searcheck = false;
    
    if(count == 0){
        cout << "No students available.\n";
        return;
    }

    string searchName;
    cout << "Enter name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);

    for(int i = 0; i < count; i++){
        if(students[i].getname() == searchName){
            cout << "Found at index " << i+1 << endl;
            students[i].display();
            searcheck = true;
        }
    }
    if(!searcheck){
        cout << "NO SEARCH RESULTS" << endl;
    }
}

void StudentManager::rollSearch(){
    bool searcheck = false;
    
    if(count == 0){
        cout << "No students available.\n";
        return;
    }

    int searchRoll;
    cout << "Enter Roll number to search: ";
    Student::checkInput(searchRoll);
    
    for(int i = 0; i < count; i++){
        if(students[i].getRoll() == searchRoll){
            cout << "Found at index " << i+1 <<endl;
            students[i].display();
            searcheck = true;
        }
    }
    if(!searcheck){
        cout << "NO SEARCH RESULTS" << endl;
    }
}

void StudentManager::sortStudents(){
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (students[j].getRoll() < students[minIndex].getRoll()) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }

    cout << "Students sorted successfully.\n";
    isSorted = true;
}

void StudentManager::binarySearch(){
    
    if(count == 0){
        cout << "No students available.\n";
        return;
    }

    if(isSorted == true){
        int start = 0;
        int end = count -1;
        int searchRoll;
        cout << "Enter Roll number to search: ";
        Student::checkInput(searchRoll);
        while(start <=end){
            int mid = (start + end)/2;
            if(searchRoll == students[mid].getRoll()){
                cout << "Found at index " << mid + 1 << endl;
                students[mid].display();
                return;
            }

            else if(searchRoll < students[mid].getRoll()){
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }
        cout << "NO SEARCH RESULTS" << endl;
    }

    else {
        cout << "Use sort feature 1st" << endl;
    }
}

void StudentManager::clearAll(){
    cout << "All Data deleted" << endl;
    count = 0;
    isSorted = false;
}

StudentManager::~StudentManager() {
    delete[] students;
}