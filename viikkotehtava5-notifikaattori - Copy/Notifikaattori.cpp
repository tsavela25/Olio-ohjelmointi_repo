#include <iostream>
#include "Notifikaattori.h"

Notifikaattori::Notifikaattori(){
    cout << "Luodaan notifikaattori" << endl;
    seuraajat = nullptr;
}

void Notifikaattori::lisaa(Seuraaja* s)
{
    cout << "Notifikaattori lisaa seuraajan: " << s->getNimi() << endl;
    if (!s) {
        return;
    }

    s->next = seuraajat;
    seuraajat = s;
}

void Notifikaattori::poista(Seuraaja* s)
{
    cout << "Notifikaattori poistaa seuraajan: " << s->getNimi() << endl;

    if (seuraajat == s){
        seuraajat = seuraajat->next;
        s->next = nullptr;
        return;
    }

    Seuraaja* ptr = seuraajat;
    while (ptr->next != s){
        ptr = ptr->next;
    }

    if (ptr->next == s){
        ptr -> next = s->next;
        s->next = nullptr;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja* ptr = seuraajat;
    while (ptr){
        cout << "Luodaan seuraaja: " << ptr->getNimi() << endl;
        ptr = ptr->next;
    }
}

void Notifikaattori::postita(string posti)
{
    Seuraaja* ptr = seuraajat;
    while (ptr){
        ptr->paivitys(posti);
        ptr = ptr->next;
    }

}
