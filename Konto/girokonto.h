#ifndef GIROKONTO_H
#define GIROKONTO_H

#include "konto.h"

class Girokonto : public Konto
{
public:
    Girokonto();
    Girokonto(string inhaber, int ueberzug);
    virtual void abheben(int);
    virtual void info();
protected:
    int ueberzug;

};

#endif // GIROKONTO_H
