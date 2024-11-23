#include "clsPersona.h"

Persona::Persona(const char *n, const char *a, int d) {
    strcpy(apellido, a);
    strcpy(nombre, n);
    dni = d;
}

void Persona::setApellido(const char *a) {
    strcpy(apellido, a);
}

void Persona::setNombre(const char *n) {
    strcpy(nombre, n);
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

int Persona::getDni() {
    return dni;
}

void Persona::Cargar_Persona() {
    cout << "Ingrese el nombre: ";
    cargarCadena(nombre, 29);
    cout << "Ingrese el apellido: ";
    cargarCadena(apellido, 29);
    cout << "Ingrese el Dni: ";
    cin >> dni;
}

void Persona::Cargar_Persona(int DNI) {
    cout << "Ingrese el nombre: ";
    cargarCadena(nombre, 29);
    cout << "Ingrese el apellido: ";
    cargarCadena(apellido, 29);
    dni = DNI;
}

void Persona::Mostrar_Persona(int x, int y) {
    locate(x, y); cout << "Nombre: " << nombre << endl;
    locate(x, 1 + y); cout << "Apellido: " << apellido << endl;
    locate(x, 2 + y); cout << "Dni: " << dni << endl;
}
