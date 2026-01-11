#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int game(int maxnum);

int main(){
    int maxnum = 40;
    int arvausMäärä = game(maxnum);

    cout << "arvausten maara: " << arvausMäärä << endl;

    return 0;
}

int game(int maxnum){
    int arvaus;
    int arvausMäärä = 0;

    srand(time(NULL));
    int rnum = rand() % maxnum;


    do {

        cout << "Arvaa numero: ";
        cin >> arvaus;

        if (rnum < arvaus) {
            cout << "liian suuri" << endl;
        } else if (rnum > arvaus){
            cout << "liian pieni" << endl;
        } else {
            cout << "oikein!" << endl;
        }
        arvausMäärä++;

    } while (rnum != arvaus);

    return arvausMäärä;
}
