#include "konto.h"
#include <iostream>

using std::cout;
using std::endl;

Konto::Konto(){
    this->inhaber = "";
}

Konto::Konto(string inhaber)
{
    this->inhaber = inhaber;
    this->saldo = 0;
    // inProzent
}
int Konto::zinssatz = 5;
void Konto::einzahlen(int betrag){
    if(betrag > 0){
        this->saldo += betrag;
    }
}
int Konto::getZinssatz(){
    return this->zinssatz;
}

void Konto::abheben(int betrag){
    if(betrag > 0 && this->saldo - betrag >= 0){
        this->saldo -= betrag;
    }
}

void Konto::info(){
    cout << "Inhaber:       " << this->inhaber << endl;
    cout << "Saldo:         " << this->saldo/100.0<<"€ " << endl;
    cout << "Zinssatz:      " << Konto::zinssatz/100.0 << endl;
}

ostream& operator<< (ostream &o,const Konto &ktr)
{
    o << "Inhaber:       " << ktr.inhaber << endl;
    o << "Saldo:         " << ktr.saldo/100.0 << endl;
    o << "Zinssatz:      " << Konto::zinssatz/100.0 << endl;
   return o;
}
Konto& operator+=(Konto &a, Konto &b){
    a.saldo+= b.saldo;
    return a;
}
