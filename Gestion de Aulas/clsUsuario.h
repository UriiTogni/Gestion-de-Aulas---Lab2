#ifndef CLSUSUARIO_H_INCLUDED
#define CLSUSUARIO_H_INCLUDED
#include "clsPersona.h"

class Usuario : public Persona {
private:
    int legajo, codDepartamento, numero;
    char rol[9], mail[45];
    bool estado, lectura = true, escritura = false;

public:
    Usuario(const char *r = "", const char *m = "", int l = 0, int c = 0, bool e = false, int num = 1);

    void setMail(const char *m);
    void setRol(const char *r);
    void setEstado(bool e);
    void setNumero(int n);
    void setLegajo(int l);
    void setCodDep(int c);
    int getCodDep();
    bool getEstado();
    bool getEscritura();
    const char *getMail();
    bool getLectura();
    const char *getRol();
    int getNumero();
    int getLegajo();

    void Cargar(int dni);
    void Cargar(int cod, int dni, const char *puesto);
    void Mostrar();
};

class ArchUsuario {
private:
    char nombre[30];

public:
    ArchUsuario(const char *n = "usuario.dat");
    Usuario leerRegistro(int pos);
    void grabarRegistro(Usuario obj);
    void modificarRegistro(Usuario obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

void Alta_Usuarios(int dni);

void Alta_Usuarios(int cod, int dni, const char *puesto);

#endif // CLSUSUARIO_H_INCLUDED
