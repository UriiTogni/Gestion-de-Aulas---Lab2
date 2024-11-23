#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <cstring>
#include "clsPersona.h"
#include "Cadena.h"

using namespace std;

class Usuario : public Persona {
private:
    int legajo, codDepartamento, numero;
    char rol[9], mail[45];
    bool estado;

public:
    Usuario(const char *r="", const char *m="", int l=0, int c=0, bool e=false, int num=1);

    void setMail(const char *m);
    void setRol(const char *r);
    void setEstado(bool e);
    void setNumero(int n);
    void setLegajo(int l);
    void setCodDep(int c);

    int getCodDep();
    bool getEstado();
    const char *getMail();
    const char *getRol();
    int getNumero();
    int getLegajo();

    bool verificarDep(int codDep);
    bool verificarRol(char* rol);

    void Cargar(int dni);
    void Cargar(int cod, int dni, const char *puesto);
    void Mostrar(int x = 0, int y = 0);
};

class ArchUsuario {
private:
    char nombre[30];

public:
    ArchUsuario();
    Usuario leerRegistro(int pos);
    void grabarRegistro(Usuario obj);
    void modificarRegistro(Usuario obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};


void Alta_Usuarios(int dni);
void Alta_Usuarios(int cod, int dni, const char *puesto);
#endif // USUARIO_H_INCLUDED
