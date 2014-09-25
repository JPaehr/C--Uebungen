#ifndef KOMPLEX_H
#define KOMPLEX_H

class Komplex
{
public:
    Komplex();
    Komplex(double real);
    Komplex(double real, double imag);
    void info();
    Komplex& operator+(Komplex &a);
    Komplex& operator-(Komplex &b);
protected:
    double real;
    double imag;
};

#endif // KOMPLEX_H
