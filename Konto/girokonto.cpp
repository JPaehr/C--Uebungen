#include "girokonto.h"

Girokonto::Girokonto(){
    this->inhaber = "";
    this->ueberzug = 0;
}

Girokonto::Girokonto(string inhaber, int ueberzug)
{
    this->ueberzug = ueberzug;
    this->inhaber = inhaber;
    this->saldo = 0;

}
void Girokonto::abheben(int betrag){
    if(betrag >= 0 && this->saldo+this->ueberzug - betrag >= 0){
        this->saldo -= betrag;
    }
}
void Girokonto::info(){
    Konto::info();
    cout << "Ueberzug:      " <<  this->ueberzug/100.0 << endl;
}
