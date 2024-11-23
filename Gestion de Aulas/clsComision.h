#ifndef COMISION_H_INCLUDED
#define COMISION_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Cadena.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Comision {
private:
    int numero, codDep, codComi, cantidad;
    char aula[5], profe[30];
    bool estado;

public:
    Comision(int n = 1, int dep = 1, int com = 1, int can = 1, bool e = false, const char *a = "", const char *p = "");

    void setProfe(const char *p);
    void setAula(const char *a);
    void setCodComision(int c);
    void setCantidad(int c);
    void setEstado(bool e);
    void setCodDep(int c);
    void setNumero(int n);

    const char *getProfe();
    const char *getAula();
    int getCodComision();
    int getCantidad();
    bool getEstado();
    int getCodDep();
    int getNumero();

    void Cargar();
    void Mostrar();
    void Mostrar_Becado(int x, int y);
    void Mostrar_Docente(int x, int y);
};

class ArchComision{
    private:
        char nombre[30];
    public:
        ArchComision();
        Comision leerRegistro(int pos);
        void grabarRegistro(Comision obj);
        void modificarRegistro(Comision obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};
#endif // COMISION_H_INCLUDED
