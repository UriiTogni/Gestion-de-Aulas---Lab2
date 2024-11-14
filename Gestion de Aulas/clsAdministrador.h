#ifndef CLSADMINISTRADOR_H_INCLUDED
#define CLSADMINISTRADOR_H_INCLUDED
#include "clsPersona.h"
///ACCIONES
///ADMINISTRADOR: VER AULAS, VER PETICIONES, DELEGAR AULAS Y DECIDIR CAMBIOS.

class Administrador : public Persona {
private:
    int codigo, numero;
    char mail[45], contrasenia[30];
    bool estado, lectura=true, escritura=true;

public:
    Administrador(const char *m="", const char *c="", bool e=false, int n=1, int co=1);

    void setContrasenia(const char *c);
    void setMail(const char *m);
    void setEstado(bool e);
    void setEscritura(bool e);
    void setLectura(bool l);
    void setCodigo(int c);
    void setNumero(int n);

    const char *getConstrasenia();
    bool getEstado();
    bool getEscritura();
    const char *getMail();
    bool getLectura();
    int getCodigo();
    int getNumero();

    void Cargar(int dni);
    void Mostrar();
};

class ArchAdm {
private:
    char nombre[30];

public:
    ArchAdm(const char *n="administrador.dat");

    Administrador leerRegistro(int pos);
    void grabarRegistro(Administrador obj);
    void modificarRegistro(Administrador obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

#endif // CLSADMINISTRADOR_H_INCLUDED
