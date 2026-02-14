#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
#include <iostream>

class Student{
public:
    Student(string, int);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentInfo();
private:
    string Name;
    int Age;
    
};
Student::Student(string Name, int Age){

}

void Student::setAge(int age){
    Age = age;
}

void Student::setName(string name){
    Name = name;
}

string Student::getName(){
    return Name;
}

int Student::getAge(){
    return Age;
}

void Student::printStudentInfo(){
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;

}

#endif // STUDENT_H
