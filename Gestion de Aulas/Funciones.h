#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "clsDepartamento.h"
#include "clsAula.h"
#include "clsPeticion.h"
#include "clsUsuario.h"
#include "clsComision.h"
#include "Cadena.h"

using namespace std;
using namespace rlutil;

void ComisionesAdmin();
int verificarUsuario(int dni);
void darAlta(int dni);
void darBaja();
void darBaja(int cod, const char *rol);
void darAlta(int CodDep,const char *rol);
Departamento buscarDep(int Cod);
void verInfoDep(int CodDep);
void mostrarDepCompleto(int codigo, int x, int y);
void verAulas();
void verComisiones(int CodDep);
void verComisiones(const char *nombre);
Comision verificarComision(int CodDep, int CodComi);
int contarAulas();
bool verificar_Peticion(Aula *Vec, int tam, const char *aula, int capacidad);
void cargar_Aulas_Disponibles(Aula *Vec);
void Mostrar_Aulas(Aula *V, int tam);
int contarComisiones(int CodDep);
void cargarComisiones(Comision *v, int Cod);
void mostrarComisiones(Comision *v, int tam);
void PedirCambios(int CodDep);
void Historial(int codDep);
void Asignacion_Baja(const char *nombre);
void darBajaAulas();
int verificarAulas(char *nombre);
int contarPeticiones();
void CargarPeticiones(Peticion *v);
void cambiarAulas(Peticion pet);
void modificarArchPeticion(Peticion aux);
void verPeticiones();
void Asignacion_Alta(const char *nombre);
void darAltaAulas();
void terminalSize(int &x, int &y);
#endif // FUNCIONES_H_INCLUDED
