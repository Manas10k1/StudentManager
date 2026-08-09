#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"

class StudentManager{
    private:
        Student* students;
        int size;
        int count=0;

    public:
        StudentManager();
        void addStudent();
        void displayAll();
        void insert();
        void deletEle();
        void nameSearch();
        void rollSearch();
        void sortStudents();
        ~StudentManager();

};

#endif