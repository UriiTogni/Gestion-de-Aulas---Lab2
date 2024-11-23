#include "clsComision.h"

Comision::Comision(int n, int dep, int com, int can, bool e, const char *a, const char *p) {
    strcpy(profe, p);
    strcpy(aula, a);
    cantidad = can;
    codComi = com;
    codDep = dep;
    numero = n;
    estado = e;
}

void Comision::setProfe(const char *p) { strcpy(profe, p); }
void Comision::setAula(const char *a) { strcpy(aula, a); }
void Comision::setCodComision(int c) { codComi = c; }
void Comision::setCantidad(int c) { cantidad = c; }
void Comision::setEstado(bool e) { estado = e; }
void Comision::setCodDep(int c) { codDep = c; }
void Comision::setNumero(int n) { numero = n; }
const char *Comision::getProfe() { return profe; }
const char *Comision::getAula() { return aula; }
int Comision::getCodComision() { return codComi; }
int Comision::getCantidad() { return cantidad; }
bool Comision::getEstado() { return estado; }
int Comision::getCodDep() { return codDep; }
int Comision::getNumero() { return numero; }

void Comision::Cargar() {
    cout << "Ingrese el codigo de Comision: ";
    cin >> codComi;
    cout << "Ingrese el codigo del Departamento: ";
    cin >> codDep;
    cout << "Ingrese la Cantidad de alumnos: ";
    cin >> cantidad;
    cout << "Ingrese el Docente a cargo: ";
    cargarCadena(profe, 29);
    cout << "Ingrese el Aula: ";
    cargarCadena(aula, 4);
    estado = true;
}

void Comision::Mostrar() {
    if (estado) {
        cout << "Codigo de la Comision: " << codComi << endl;
        cout << "Codigo del Departamento: " << codDep << endl;
        cout << "Cantidad de alumnos: " << cantidad << endl;
        cout << "Docente a cargo: " << profe << endl;
        cout << "Aula: " << aula << endl << endl;
    }
}

void Comision::Mostrar_Becado(int x, int y) {
    if (estado) {
        locate(x, y); cout << "Codigo de la Comision: " << codComi << endl;
        locate(x, 1 + y); cout << "Cantidad de alumnos: " << cantidad << endl;
        locate(x, 2 + y); cout << "Docente a cargo: " << profe << endl;
        locate(x, 3+y); cout << "Aula: " << aula << endl;
        }
    }

void Comision::Mostrar_Docente(int x = 0, int y = 0)
    {
        if(estado)
        {
            locate(x, y); cout << "Codigo de la Comision: " << codComi << endl;
            locate(x, 1+y); cout << "Codigo del Departamento: " << codDep << endl;
            locate(x, 2+y); cout << "Cantidad de alumnos: " << cantidad << endl;
            locate(x, 3+y); cout << "Aula: " << aula << endl;
        }
}

ArchComision::ArchComision(){
    strcpy(nombre, "comision.dat");
}


Comision ArchComision::leerRegistro(int pos){
    Comision obj;
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

void ArchComision::grabarRegistro(Comision obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchComision::modificarRegistro(Comision obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchComision::listarRegistros(){
    Comision obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
    }
}

int ArchComision::buscarRegistro(int num){
    Comision obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchComision::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Comision);
}
