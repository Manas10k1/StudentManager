#include <iostream>
#include <limits>
#include "Student.h"
using namespace std;

Student::Student():name(" "), age(0), rollNum(0)
{
}

void Student::checkInput(int &input){
    while (true) {
            cin >> input;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again.\n";
            }
            else {
                break;
            }
        }
}

void Student::input(){
    cout << "Enter Name of Student: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
        
    do{
        cout << "Enter Age of Student: ";
        checkInput(age);
    } while(age < 1);
        
    do{
        cout << "Enter Roll Number of Student: ";
        checkInput(rollNum);
    } while(rollNum < 1);
    cout << endl;
}

void Student::display(){
    cout << "Name       : " << name << endl;
    cout << "Age        : " << age << endl;
    cout << "Roll Number: " << rollNum << endl;
}

void Student::setName(std::string newName){
    name = newName;
}

void Student::setAge(int newAge){
    age = newAge;
}

void Student::setRoll(int newRoll){
    rollNum = newRoll;
}

std::string Student::getname() const{
    return name;
}

int Student::getRoll() const{
    return rollNum;
}