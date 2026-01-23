#ifndef ITALIALAINENKOKKI_H
#define ITALIALAINENKOKKI_H
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


class Chef {
public:
    Chef();
    ~Chef();
    string getName();
    void setName(string);
    int makeSalad(int);
    int makeSoup(int);
    string chefName;
};

class ItalianChef: public Chef{
public:
    ItalianChef();
    ~ItalianChef();
    bool askSecret(string, int, int);

private:
    int makePizza();
    int flour;
    int water;
    string password = "pizza";

};


Chef::Chef(){
    cout << "\nChef konstruktorissa\n" << endl;
}

Chef::~Chef(){
    cout << "\nChef destruktorissa" << endl;
}

void Chef::setName(string chefName){
    //cout << "setName funktiossa\n" << endl;
    this->chefName = chefName;
}

string Chef::getName(){
    //cout << "getName funktiossa \n" << endl;
    return chefName;
}

int Chef::makeSalad(int salad){
    //cout << "\n\nmakeSalad funktiossa" << endl;
    cout << "\nSalaatti annosten maara: ";
    return salad / 5;

}

int Chef::makeSoup(int soup){
    //cout << "makeSoup funktiossa" << endl;
    cout << getName() << ": " << endl;
    cout << "Soppa annosten maara: ";
    return soup / 3;
}

ItalianChef::ItalianChef(){
    cout << "ItalianChef konstruktorissa\n" << endl;;
}

ItalianChef::~ItalianChef(){
    cout << "ItalianChef destruktorissa" << endl;
}

bool ItalianChef::askSecret(string input, int flour, int water){
    cout << "askSecret funktiossa\n" << endl;

    if (input.compare(password) == 0){
        cout << "Password ok" << endl;
        this->flour = flour;
        this->water = water;
        makePizza();
        return true;
    } else {
        return false;
    }


}

int ItalianChef::makePizza(){
    cout << "makePizza funktiossa\n" << endl;

    int pizza = min(flour / 5, water / 5);
    cout << "Pizzojen maara: " << pizza << endl;

    return 0;
}



#endif // ITALIALAINENKOKKI_H
