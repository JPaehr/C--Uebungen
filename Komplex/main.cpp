#include <iostream>
#include "komplex.h"
using namespace std;

int main()
{
    Komplex meineZahl(5.6, 7.8);
    meineZahl.info();
    Komplex meineZahl2(5.6, 7.8);
    meineZahl2.info();

    Komplex zahl3;
    zahl3 = meineZahl+meineZahl2;
    zahl3.info();

    Komplex zahl5(5,6);
    Komplex zahl6(7,8);
    Komplex zahl7;
    zahl7 = zahl5-zahl6;
    zahl7.info();

    return 0;
}

