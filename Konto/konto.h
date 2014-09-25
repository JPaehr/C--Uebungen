#ifndef KONTO_H
#define KONTO_H
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Konto
{
public:
    Konto();
    Konto(string);

    void einzahlen(int);
    virtual void abheben(int);
    virtual void info();
    friend ostream& operator<< (ostream &o,const Konto &a);
    friend Konto& operator+=(Konto &a, Konto &b);
    int getZinssatz();
protected:
    static int zinssatz;
    string inhaber;
    long int saldo;
};

#endif // KONTO_H
