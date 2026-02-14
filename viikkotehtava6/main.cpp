#include <iostream>
#include <vector>
#include "Student.h"
#include <algorithm>

using namespace std;

int main()
{
    int selection = 0;
    vector<Student> studentList;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection)
        {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            string name;
            int age;

            Student student("", 0);

            cout << "Enter name: ";
            cin >> name;
            cout << endl;

            cout << "Enter age: ";
            cin >> age;
            cout << endl;

            student.setName(name);
            student.setAge(age);

            studentList.emplace_back(student);
            break;
        }

        case 1:
        {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        }

        case 2:
        {
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            vector<Student> sorted = studentList;
            sort(sorted.begin(), sorted.end(),
                 [](Student &a, Student &b) {
                     return a.getName() < b.getName();
                 });

            for (auto &student : sorted) {
                student.printStudentInfo();
            }
            break;
        }

        case 3:
        {
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            vector<Student> sortedAge = studentList;
            sort(sortedAge.begin(), sortedAge.end(),
                 [](Student &a, Student &b) {
                     return a.getAge() < b.getAge();
                 });

            for (auto &student : sortedAge) {
                student.printStudentInfo();
            }
            break;
        }

        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            string fname;
            cout << "Enter a name to find: ";
            cin >> fname;
            cout << endl;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [fname](Student &student) {
                                  return student.getName() == fname;
                              });

            if (it != studentList.end()) {
                cout << "Name found: " << endl;
                it->printStudentInfo();
            } else {
                cout << "Name not found" << endl;
            }
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }

    } while (selection < 5);

    return 0;
}

