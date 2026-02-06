#include <iostream>
#include "Notifikaattori.h"
#include "Seuraaja.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("Matti");
    Seuraaja b("Kasperi");
    Seuraaja c("Jaakko");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Ilmoitus 1!");

    n.poista(&b);

    n.postita("Ilmoitus 2!");


    return 0;
}
