#include <iostream>
#include <ItalialainenKokki.h>
using namespace std;


int main()
{
    Chef kokkiOlio;

    kokkiOlio.setName("Gordon");
    cout << kokkiOlio.makeSoup(3);
    cout << kokkiOlio.makeSalad(5);

    ItalianChef itaChef;

    itaChef.askSecret("pizza", 5, 5);


    return 0;
}
