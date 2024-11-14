#include "clsPersona.h"
#include "Cadena.h"
#include <iostream>
#include <cstring>
using namespace std;

Persona::Persona(const char *n, const char *a, int d, int c) {
    strcpy(apellido, a);
    strcpy(nombre, n);
    celular = c;
    dni = d;
}

void Persona::setApellido(const char *a) {
    strcpy(apellido, a);
}

void Persona::setNombre(const char *n) {
    strcpy(nombre, n);
}

void Persona::setCelular(int c) {
    celular = c;
}

void Persona::setDni(int d) {
    dni = d;
}

const char *Persona::getApellido() {
    return apellido;
}

const char *Persona::getNombre() {
    return nombre;
}

int Persona::getCelular() {
    return celular;
}

int Persona::getDni() {
    return dni;
}

void Persona::Cargar_Persona(int DNI) {
    cout << "Ingrese el nombre: ";
    cargarCadena(nombre, 30);
    cout << "Ingrese el apellido: ";
    cargarCadena(apellido, 30);
    dni = DNI;
    cout << "Ingrese el numero de celular: ";
    cin >> celular;
}

void Persona::Mostrar_Persona() {
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Dni: " << dni << endl;
    cout << "Celular: " << celular << endl;
}
