#include "Seuraaja.h"

Seuraaja::Seuraaja(const string &n) : nimi(n) {}

string Seuraaja::getNimi(){
    return nimi;
}
