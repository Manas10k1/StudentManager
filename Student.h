#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class Student{
    private:
        std::string name;
        int age;
        int rollNum;

    public:
        Student();
        static void checkInput(int &input);
        void input();
        void display();
        std::string getname() const;
        int getRoll() const;
};

#endif