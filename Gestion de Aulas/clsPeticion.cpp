#include "clsPeticion.h"

Peticion::Peticion(int dep, int com, int ca, int n, const char *a, const char *p, const char *r) {
    codDep = dep;
    codComi = com;
    cant = ca;
    numero = n;
    strcpy(asignada, a);
    strcpy(pedida, p);
    strcpy(respuesta, r);
    estado = true;
    visto = false;
}

void Peticion::setRespuesta(const char *r) { strcpy(respuesta, r); }
void Peticion::setVisto(bool v) { visto = v; }
void Peticion::setEstado(bool e) { estado = e; }
void Peticion::setNumero(int n) { numero = n; }
int Peticion::getNumero() { return numero; }
int Peticion::getCodDep() { return codDep; }
int Peticion::getCodComi() { return codComi; }
const char *Peticion::getAsignada() { return asignada; }
const char *Peticion::getPedida() { return pedida; }
const char *Peticion::getRespuesta() { return respuesta; }
bool Peticion::getVisto() { return visto; }
bool Peticion::getEstado() { return estado; }

void Peticion::Cargar(Comision obj, char *aula) {
    codDep = obj.getCodDep();
    codComi = obj.getCodComision();
    cant = obj.getCantidad();
    strcpy(asignada, obj.getAula());
    strcpy(pedida, aula);
    estado = true;
}

void Peticion::Mostrar() {
    cout << "Codigo del departamento: " << codDep << std::endl;
    cout << "Codigo de la comision: " << codComi << std::endl;
    cout << "Aula asignada anteriormente: " << asignada << std::endl;
    cout << "Aula solicitada por el departamento: " << pedida << std::endl;
    cout << "Cantidad de estudiantes: " << cant << std::endl;
    if (visto) {
        setColor(1);
        cout << "El Administrador dijo: " << respuesta << std::endl;
    } else {
        setColor(4);
        cout << "Falta Confirmacion del Administrador" << std::endl;
    }
    cout << std::endl;
}

void Peticion::Mostrar_Peticion() {
    if (!visto) {
        cout << "Codigo del departamento: " << codDep << std::endl;
        cout << "Codigo de la comision: " << codComi << std::endl;
        cout << "Aula asignada anteriormente: " << asignada << std::endl;
        cout << "Aula solicitada por el departamento: " << pedida << endl;
        cout << "Cantidad de estudiantes: " << cant << endl;
        cout << endl <<  "Escriba su respuesta (si/no): ";
        }
    }

ArchPeticion::ArchPeticion(){
    strcpy(nombre, "Peticion.dat");
}

Peticion ArchPeticion::leerRegistro(int pos){
    Peticion obj;
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

void ArchPeticion::grabarRegistro(Peticion obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchPeticion::modificarRegistro(Peticion obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchPeticion::listarRegistros(){
    Peticion obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
    }
}

int ArchPeticion::buscarRegistro(int num){
    Peticion obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchPeticion::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Peticion);
}

void Alta_Peticion(Comision auxComi, char *aula)
{
    Peticion obj;
    ArchPeticion arch;

    obj.Cargar(auxComi, aula);
    arch.grabarRegistro(obj);
}
