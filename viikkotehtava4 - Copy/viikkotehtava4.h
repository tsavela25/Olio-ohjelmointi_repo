#ifndef VIIKKOTEHTAVA4_H
#define VIIKKOTEHTAVA4_H
#include <string>
#include <iostream>

using namespace std;

class Pankkitili {
public:
    Pankkitili(string name);
    double getBalance();
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
protected:
    string omistaja;
    double saldo = 0;
};

class Luottotili: public Pankkitili{
public:
    Luottotili(string name, double luottoraja);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
protected:
    double luottoRaja = 0;

};

class Asiakas{
public:
    Asiakas(string nimi, double luottoRaja);
    string getNimi();
    void showSaldo();
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, Asiakas &saaja);
private:
    string nimi;
    Pankkitili käyttötili;
    Luottotili luottotili;
};

Asiakas::Asiakas(string nimi, double luottoRaja) : nimi(nimi), käyttötili(nimi), luottotili(nimi, luottoRaja)
{
    cout << "Asiakkuus luotu: " << nimi << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "kayttotilin saldo: " << käyttötili.getBalance() << endl;
    cout << "luottotilin saldo: " << luottotili.getBalance() << endl;

}

bool Asiakas::talletus(double amount)
{
    return käyttötili.deposit(amount);
}

bool Asiakas::nosto(double amount)
{
    return käyttötili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount)
{
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount)
{
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &saaja)
{
    if (amount < 0)
        return false;
    if (!käyttötili.withdraw(amount)){
        return false;
    }
    saaja.käyttötili.deposit(amount);

    cout << "Pankkitili: " << nimi << " siirtaa " << amount << " " << saaja.nimi << ":lle" << endl;

    return true;
}


Pankkitili::Pankkitili(string name): omistaja(name), saldo(0.0)
{
    cout << "Pankkitili luotu " << omistaja << ":lle " << endl;

}

bool Pankkitili::deposit(double amount){

    if (amount > 0){
        saldo += amount;
        cout << "Pankkitili: talletus " << amount << " tehty\n";
        return true;
    }else {
        return false;
    }

}

bool Pankkitili::withdraw(double amount){

    if (amount > 0){
        saldo -= amount;
        std::cout << "Pankkitili: nosto " << amount << " tehty\n";
        return true;
    }else {
        return false;
    }
}

double Pankkitili::getBalance(){

    return saldo;
}

Luottotili::Luottotili(string name, double luottoRaja) : Pankkitili(name), luottoRaja()
{
    saldo = luottoRaja;
    cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << "\n";
}


bool Luottotili::deposit(double amount){

    if (amount < 0) {

        return false;
    }

    saldo += amount;

    if (saldo > luottoRaja) {
        saldo = luottoRaja;
    }
    cout << "Luottotili: velanmaksu " << amount << " tehty, luottoa jaljella " << saldo << "\n";
    return true;

}

bool Luottotili::withdraw(double amount){

    if (amount < 0){
        return false;
    }

    if (saldo < amount){
        return false;
    }

    saldo -= amount;
    cout << "Luottotili: nosto " << amount << " tehty, luottoa jaljella " << saldo << "\n";

    return true;
}

#endif // VIIKKOTEHTAVA4_H
