#ifndef CLSDIAS_H_INCLUDED
#define CLSDIAS_H_INCLUDED

#include <iostream>
#include <ctime>

class Dias {
private:
    int dia;
    int mes;
    int anio;

public:
    Dias(int d = 0, int m = 0, int a = 0);
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
    void Cargar();
    void Mostrar();
    void mostrarActual();
};

#endif // CLSDIAS_H_INCLUDED
