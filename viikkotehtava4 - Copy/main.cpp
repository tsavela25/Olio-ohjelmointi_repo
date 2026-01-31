#include <iostream>
#include <viikkotehtava4.h>

using namespace std;

int main()
{
    /*Pankkitili käyttötili("Matti");

    Luottotili luottotili("Matti", 1000);

    cout << "saldo: " << käyttötili.getBalance() << endl;;
    cout << "luotto: " << luottotili.getBalance() << endl;

    käyttötili.deposit(250);
    luottotili.withdraw(500);


    cout << "saldo: " << käyttötili.getBalance() << endl;;
    cout << "luotto: " << luottotili.getBalance() << endl;*/

    Asiakas aapeli("Aapeli", 1000);
    Asiakas matti("Matti", 1000);


    cout <<  "Aapelin Saldo: " << endl;
    aapeli.showSaldo();
    cout << endl;

    cout << "Matin Saldo: " << endl;
    matti.showSaldo();
    cout << endl;

    aapeli.talletus(200);
    aapeli.tiliSiirto(50, matti);

    cout <<  "Aapelin Saldo: " << endl;
    aapeli.showSaldo();
    cout << endl;

    cout << "Matin Saldo: " << endl;
    matti.showSaldo();
    cout << endl;

    return 0;
}
