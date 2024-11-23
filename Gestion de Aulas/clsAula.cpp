#include "clsAula.h"

Aula::Aula(const char *n, const char *de, int c, bool l, bool d, bool e, int num) {
    strcpy(deparLlave, de);
    disponibilidad = d;
    strcpy(nombre, n);
    capacidad = c;
    numero = num;
    estado = e;
    llave = l;
}

void Aula::setDisponibilidad(bool d) {
    disponibilidad = d;
}

void Aula::setNombre(const char *n) {
    strcpy(nombre, n);
}

void Aula::setCapacidad(int c) {
    capacidad = c;
}

void Aula::setEstado(bool e) {
    estado = e;
}

void Aula::setNumero(int n) {
    numero = n;
}

bool Aula::getDisponibilidad() {
    return disponibilidad;
}

const char *Aula::getDeparLlave() {
    return deparLlave;
}

const char *Aula::getNombre() {
    return nombre;
}

int Aula::getCapacidad() {
    return capacidad;
}

bool Aula::getEstado() {
    return estado;
}

int Aula::getNumero() {
    return numero;
}

void Aula::Cargar(const char *_nombre) {
    strcpy(nombre, _nombre);
    cout << "Ingrese la capacidad: ";
    cin >> capacidad;
    cout << "Se cierra con llave? 1 = si // 0 = no: ";
    cin >> llave;
    if (llave) {
        cout << "Ingrese el nombre del departamento encargado: ";
        cargarCadena(deparLlave, 9);
    }
    estado = true;
}

void Aula::Mostrar(int x, int y) {
    if (!estado) {
        setColor(4);
        cout << "NO SE PUEDE UTILIZAR, AULA DADA DE BAJA" << endl;
        setColor(0);
    }

    cout << "El aula es: " << nombre << endl;
    cout << "Cuenta con una capacidad de: " << capacidad << " bancos" << endl;

    if (llave) {
        cout << "Hay que pedir la llave a " << deparLlave << endl;
    }

    if (disponibilidad) {
        cout << "Esta disponible" << endl;
    } else {
        cout << "Esta ocupada" << endl;
    }
}

void Aula::Mostrar_Peticion(int x, int y) {
    locate(x, y);

    setColor(15);
    cout << "El aula " << nombre << " tiene " << capacidad << " bancos. ";
    if (estado) {
        if (disponibilidad) {
            setColor(2);
            cout << "Esta disponible" << endl; // Color verde
        } else {
            setColor(4);
            cout << "No esta disponible" << endl; // Color rojo
        }
        setColor(15);
    } else {
        cout << "DADA DE BAJA!!" << endl; // Color rojo
    }
}

ArchAula::ArchAula(){
    strcpy(nombre, "aulas.dat");
}

Aula ArchAula::leerRegistro(int pos){
    Aula obj;
    obj.setNumero(-1);
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

void ArchAula::grabarRegistro(Aula obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchAula::modificarRegistro(Aula obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchAula::listarRegistros(){
    Aula obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
    }
}

int ArchAula::buscarRegistro(int num){
    Aula obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchAula::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Aula);
}

void Alta_Aulas(const char *nombre)
{
    Aula obj;
    ArchAula arch;

    obj.Cargar(nombre);
    arch.grabarRegistro(obj);
}
