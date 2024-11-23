#ifndef PAGINAS_MENUS_H_INCLUDED
#define PAGINAS_MENUS_H_INCLUDED
#include <iostream>
#include "clsUsuario.h"
#include "clsAula.h"
#include "clsAdministrador.h"
#include "Funciones.h"
#include "clsPersona.h"

using namespace std;
using namespace rlutil;

void Login();
void Ingreso();
void SelectorMenu(Usuario obj);
void Alerta(int x, int y);
int Opcion(int x,int y);
void Becado(Usuario obj);
void Docente(Usuario obj);
void Director(Usuario obj);
void IngresoAdmin();
void Aulas(Administrador obj);
void Admin(Administrador obj);
#endif // PAGINAS_MENUS_H_INCLUDED
