#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "clsDepartamento.h"


void mostrarDepCompleto(int codigo);
void verAulas();
void verComisiones(int CodDep);
void verComisiones(const char *nombre);
void verInfoDep(int CodDep);
void PedirCambios(int CodDep);
Departamento buscarDep(int Cod);

// Admin
void allComisiones();
void darBaja(int legajo);
void darAlta();
int verificarUsuario(int dni);
void darBaja();
void darAlta(int CodDep, const char *rol);
void darBaja (int cod, const char *rol);


void getSizeScreen(int &x, int &y);

#endif // FUNCIONES_H_INCLUDED
