#ifndef CLSDEPARTAMENTO_H_INCLUDED
#define CLSDEPARTAMENTO_H_INCLUDED

#include <cstring>
#include <iostream>
#include "Cadena.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Departamento {
private:
    char nombre[10];
    int codigo, numero;
    bool estado;

public:
    Departamento(int c = 0, const char *n = "", bool e = false, int nu = 1);

    void setNombre(const char *n);
    void setEstado(bool e);
    void setNumero(int n);
    void setCodigo(int c);

    const char *getNombre();
    bool getEstado();
    int getNumero();
    int getCodigo();

    void Cargar();
    void Mostrar();
    void MostrarTodo(int x = 0, int y = 0);
};

class ArchDep{
    private:
        char nombre[30];
    public:
        ArchDep();
        Departamento leerRegistro(int pos);
        void grabarRegistro(Departamento obj);
        void modificarRegistro(Departamento obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};

#endif // CLSDEPARTAMENTO_H_INCLUDED
