#include "clsDepartamento.h"
#include "Funciones.h"

Departamento::Departamento(int c, const char *n, bool e, int nu) {
    strcpy(nombre, n);
    numero = nu;
    codigo = c;
    estado = e;
}

void Departamento::setNombre(const char *n) { strcpy(nombre, n); }
void Departamento::setEstado(bool e) { estado = e; }
void Departamento::setNumero(int n) { numero = n; }
void Departamento::setCodigo(int c) { codigo = c; }

const char *Departamento::getNombre() { return nombre; }
bool Departamento::getEstado() { return estado; }
int Departamento::getNumero() { return numero; }
int Departamento::getCodigo() { return codigo; }

void Departamento::Cargar() {
    cout << "Ingrese el codigo del departamento: ";
    cin >> codigo;
    cout << "Ingrese el nombre del departamento: ";
    cargarCadena(nombre, 9);
    estado = true;
}

void Departamento::Mostrar() {
    if (estado) {
        cout << "El codigo del departamento: " << codigo << endl;
        cout << "El nombre del departamento: " << nombre << endl;
    }
}

void Departamento::MostrarTodo(int x, int y) {
    if (estado) {
        locate(x - 10, y - 4);
        cout << "El codigo del departamento: " << codigo << endl;
        locate(x - 10, y - 3);
        cout << "El nombre del departamento: " << nombre << endl;
        mostrarDepCompleto(codigo, x - 10, y);
        system("pause>nul");
        system("cls");
    }
}

ArchDep::ArchDep(){
    strcpy(nombre, "departamento.dat");
}

Departamento ArchDep::leerRegistro(int pos){
    Departamento obj;
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

void ArchDep::grabarRegistro(Departamento obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchDep::modificarRegistro(Departamento obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchDep::listarRegistros(){
    Departamento obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
    }
}

int ArchDep::buscarRegistro(int num){
    Departamento obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchDep::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Departamento);
}
