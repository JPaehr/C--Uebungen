#include "komplex.h"
#include <iostream>

using std::cout;
using std::endl;

Komplex::Komplex()
{
    this->real = 0;
    this->imag = 0;
}
Komplex::Komplex(double real){
    this->real = real;
    this->imag = 0;
}
Komplex::Komplex(double real, double imag){
    this->real = real;
    this->imag = imag;
}
void Komplex::info(){
    cout << "Realteil:      " << this->real << endl;
    cout << "Imaginaerteil: " << this->imag << endl;
}

Komplex& Komplex::operator+(Komplex &a){
    Komplex zahl(a.real+this->real, a.imag+this->imag);
    return zahl;
}

Komplex& Komplex::operator-(Komplex &b){
    Komplex neu(this->real- b.real, this->imag- b.imag);
    return neu;
}
