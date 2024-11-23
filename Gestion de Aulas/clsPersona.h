#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Cadena.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Persona {
private:
    char nombre[30], apellido[30];
    int dni;

public:
    Persona(const char *n = "", const char *a = "", int d = 0);

    void setApellido(const char *a);
    void setNombre(const char *n);
    void setDni(int d);
    const char *getApellido();
    const char *getNombre();
    int getDni();

    void Cargar_Persona();
    void Cargar_Persona(int DNI);
    void Mostrar_Persona(int x = 0, int y = 0);
};

#endif // CLSPERSONA_H_INCLUDED
