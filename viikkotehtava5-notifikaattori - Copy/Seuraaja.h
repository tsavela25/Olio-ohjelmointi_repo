#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
using namespace std;

class Seuraaja{
public:

    Seuraaja(const string &n);
    string getNimi();
    Seuraaja * next = nullptr;
    void paivitys(string &posti){
        cout << nimi << " sai viestin: " << posti << endl;
    }
private:
    string nimi;
};


#endif // SEURAAJA_H
