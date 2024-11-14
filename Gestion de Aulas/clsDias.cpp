#include "clsDias.h"

#include <iostream>
#include <ctime>

using namespace std;

Dias::Dias(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

void Dias::setDia(int d) {
    dia = d;
}

void Dias::setMes(int m) {
    mes = m;
}

void Dias::setAnio(int a) {
    anio = a;
}

int Dias::getDia() {
    return dia;
}

int Dias::getMes() {
    return mes;
}

int Dias::getAnio() {
    return anio;
}

void Dias::Cargar() {
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
}

void Dias::Mostrar() {
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
}

void Dias::mostrarActual() {
    std::time_t t = std::time(nullptr);
    std::tm* tm_info = std::localtime(&t);
    anio = tm_info->tm_year + 1900;
    mes = tm_info->tm_mon + 1;
    dia = tm_info->tm_mday;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
}
