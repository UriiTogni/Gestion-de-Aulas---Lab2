#ifndef CLSADMINISTRADOR_H_INCLUDED
#define CLSADMINISTRADOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "clsPersona.h"
#include "Cadena.h"
using namespace std;

class Administrador:public Persona {
private:
    int codigo, numero;
    char mail[45], contrasenia[30];
    bool estado;

public:
    Administrador(const char *m = "", const char *c = "", bool e = false, int n = 1, int co = 1);

    void setContrasenia(const char *c);
    void setMail(const char *m);
    void setEstado(bool e);
    void setCodigo(int c);
    void setNumero(int n);

    const char *getContrasenia();
    bool getEstado();
    const char *getMail();
    int getCodigo();
    int getNumero();

    void Cargar();
    void Mostrar();
};

class ArchAdm {
private:
    char nombre[30];

public:
    ArchAdm();

    Administrador leerRegistro(int pos);
    void grabarRegistro(Administrador obj);
    void modificarRegistro(Administrador obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

void Alta_Admi();

#endif // CLSADMINISTRADOR_H_INCLUDED
