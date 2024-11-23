#ifndef CLSAULA_H_INCLUDED
#define CLSAULA_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Cadena.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Aula {
private:
    char nombre[5], deparLlave[10];
    int capacidad, numero;
    bool llave, disponibilidad, estado;

public:
    Aula(const char *n = "ABC", const char *de = "T", int c = 0, bool l = true, bool d = true, bool e = false, int num = 1);

    void setDisponibilidad(bool d);
    void setNombre(const char *n);
    void setCapacidad(int c);
    void setEstado(bool e);
    void setNumero(int n);

    bool getDisponibilidad();
    const char *getDeparLlave();
    const char *getNombre();
    int getCapacidad();
    bool getEstado();
    int getNumero();

    void Cargar(const char *_nombre);
    void Mostrar(int x = 0, int y = 0);
    void Mostrar_Peticion(int x = 0, int y = 0);
};

class ArchAula {
private:
    char nombre[30];

public:
    ArchAula();

    Aula leerRegistro(int pos);
    void grabarRegistro(Aula obj);
    void modificarRegistro(Aula obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

void Alta_Aulas(const char *nombre);

#endif // CLSAULA_H_INCLUDED
