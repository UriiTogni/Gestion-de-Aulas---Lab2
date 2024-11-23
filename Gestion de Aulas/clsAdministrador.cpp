#include "clsAdministrador.h"

Administrador::Administrador(const char *m, const char *c, bool e, int n, int co) {
    strcpy(contrasenia, c);
    strcpy(mail, m);
    numero = n;
    codigo = co;
    estado = e;
}

void Administrador::setContrasenia(const char *c) {
    strcpy(contrasenia, c);
}

void Administrador::setMail(const char *m) {
    strcpy(mail, m);
}

void Administrador::setEstado(bool e) {
    estado = e;
}

void Administrador::setCodigo(int c) {
    codigo = c;
}

void Administrador::setNumero(int n) {
    numero = n;
}

const char *Administrador::getContrasenia() {
    return contrasenia;
}

bool Administrador::getEstado() {
    return estado;
}

const char *Administrador::getMail() {
    return mail;
}

int Administrador::getCodigo() {
    return codigo;
}

int Administrador::getNumero() {
    return numero;
}

void Administrador::Cargar() {
    cout << "Ingrese el mail: ";
    cargarCadena(mail, 44);
    cout << "Ingrese la contrasenia: ";
    cargarCadena(contrasenia, 29);
    estado = true;
}

void Administrador::Mostrar() {
    if (estado) {
        cout << "Mail: " << mail << endl;
        cout << "Contrasenia: " << contrasenia << endl;
    }
}

ArchAdm::ArchAdm() {
    strcpy(nombre, "administrador.dat");
}

Administrador ArchAdm::leerRegistro(int pos) {
    Administrador obj;
    obj.setNumero(-1);
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == nullptr) {
        cout << "ERROR DE ARCHIVO" << endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    return obj;
}

void ArchAdm::grabarRegistro(Administrador obj) {
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == nullptr) {
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
}

void ArchAdm::modificarRegistro(Administrador obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == nullptr) {
        return;
    }
    fseek(p, pos * sizeof(obj), 0);
    fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
}

void ArchAdm::listarRegistros() {
    Administrador obj;
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        obj.Mostrar();
        if (obj.getEstado()) cout << endl;
    }
}

int ArchAdm::buscarRegistro(int num){
    Administrador obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchAdm::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Administrador);
}

void Alta_Admi()
{
    Administrador obj;
    ArchAdm arch;

    obj.Cargar();
    arch.grabarRegistro(obj);
}
