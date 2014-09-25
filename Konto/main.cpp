#include <iostream>
#include "konto.h"
#include "girokonto.h"

using namespace std;

int main()
{

    Konto meinKonto("Normal Konto");

    Konto meinKonto2("Normal Konto2");
    Girokonto meinGiro("GiroKonto", 50000);


    meinKonto2.einzahlen(111111);
    meinGiro.einzahlen(50000);
    meinKonto.einzahlen(200000);

    meinKonto += meinKonto2;
    meinKonto.info();
    //meinKonto.info();

    //cout << "\n" << endl;
    //meinGiro.info();

    Konto *arrayKonten[2];
    arrayKonten[0] = &meinKonto;
    arrayKonten[1] = &meinGiro;
    for(int i = 0;  i <2; i++){
        arrayKonten[i]->info();
        cout << endl;
    }




    return 0;
}

