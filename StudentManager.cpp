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
    string searchName;
    cout << "Enter name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);

    if(count == 0){
        cout << "No students available.\n";
        return;
    }

    for(int i = 0; i < count; i++){
        if(students[i].getname() == searchName){
            cout << "Found at index " << i+1 << endl;
            students[i].display();
            searcheck = true;
        }
    }
    if(searcheck !=true){
        cout << "NO SEARCH RESULTS" << endl;
    }
}

void StudentManager::rollSearch(){
    bool searcheck = false;
    int searchRoll;
    cout << "Enter Roll number to search: ";
    Student::checkInput(searchRoll);

    if(count == 0){
        cout << "No students available.\n";
        return;
    }
    
    for(int i = 0; i < count; i++){
        if(students[i].getRoll() == searchRoll){
            cout << "Found at index " << i+1 <<endl;
            students[i].display();
            searcheck = true;
        }
    }
    if(searcheck != true){
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

StudentManager::~StudentManager() {
    delete[] students;
}