#ifndef CLSPETICION_H_INCLUDED
#define CLSPETICION_H_INCLUDED

#include <iostream>
#include <cstring>
#include "clsComision.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

class Peticion {
private:
    int codDep, codComi, cant, numero;
    char asignada[5], pedida[5], respuesta[2];  // respuesta = si, no
    bool estado, visto;                         // Visto por el Admin

public:
    Peticion(int dep=0, int com=0, int ca=0, int n=0, const char *a="", const char *p="", const char *r="");

    void setRespuesta(const char *r);
    void setVisto(bool v);
    void setEstado(bool e);
    void setNumero(int n);

    int getNumero();
    int getCodDep();
    int getCodComi();
    const char *getAsignada();
    const char *getPedida();
    const char *getRespuesta();
    bool getVisto();
    bool getEstado();

    void Cargar(Comision obj, char *aula);
    void Mostrar();
    void Mostrar_Peticion();
};

class ArchPeticion{
    private:
        char nombre[30];
    public:
        ArchPeticion();
        Peticion leerRegistro(int pos);
        void grabarRegistro(Peticion obj);
        void modificarRegistro(Peticion obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};

void Alta_Peticion(Comision auxComi, char *aula);

#endif // CLSPETICION_H_INCLUDED
