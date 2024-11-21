#ifndef CLSPETICION_H_INCLUDED
#define CLSPETICION_H_INCLUDED

class Peticion{
private:
    int codDep, codComi, cant, numero;
    char asignada[5], pedida[5], respuesta[2];  // respuesta = si, no
    bool estado, visto;                         // Visto por el Admin

public:
    Peticion(int dep=0, int com=0, int ca=0, int n=0, const char *a="", const char *p="", const char *r="")
    {
        codDep = dep;
        codComi = com;
        cant = ca;
        numero = n;
        strcpy(asignada, a);
        strcpy(pedida, p);
        strcpy(respuesta, r);
        estado = true; visto = false;
    }
    void setRespuesta(const char *r){strcpy(respuesta, r);}
    void setVisto(bool v){visto = v;}
    void setEstado(bool e){estado = e;}
    void setNumero(int n){numero = n;}
    int getNumero(){return numero;}
    int getCodDep(){return codDep;}
    int getCodComi(){return codComi;}
    const char *getAsignada(){return asignada;}
    const char *getPedida(){return pedida;}
    const char *getRespuesta(){return respuesta;}
    bool getVisto(){return visto;}
    bool getEstado(){return estado;}

    void Cargar(Comision obj, char *aula)
    {
        codDep = obj.getCodDep();
        codComi = obj.getCodComision();
        cant = obj.getCantidad();
        strcpy(asignada, obj.getAula());
        strcpy(pedida, aula);
        estado = true;
    }
    void Mostrar()
    {
        cout << "Codigo del departamento: " << codDep << endl;
        cout << "Codigo de la comision: " << codComi << endl;
        cout << "Aula asignada anteriormente: " << asignada << endl;
        cout << "Aula solicitada por el departamento: " << pedida << endl;
        cout << "Cantidad de estudiantes: " << cant << endl;
        if(visto){setColor(1); cout << "El Administrador dijo: " << respuesta << endl;}
        else{setColor(4); cout << "Falta Confirmacion del Administrador" << endl;}
        cout << endl;
    }

    void Mostrar_Peticion()
    {
        if(!visto)
        {
            cout << "Codigo del departamento: " << codDep << endl;
            cout << "Codigo de la comision: " << codComi << endl;
            cout << "Aula asignada anteriormente: " << asignada << endl;
            cout << "Aula solicitada por el departamento: " << pedida << endl;
            cout << "Cantidad de estudiantes: " << cant << endl;
            cout << endl <<  "Escriba su respuesta (si/no): ";
        }
    }
};


class ArchPeticion{
    private:
        char nombre[30];
    public:
        ArchPeticion(const char *n="Peticion.dat"){strcpy(nombre, n);}
        Peticion leerRegistro(int pos);
        void grabarRegistro(Peticion obj);
        void modificarRegistro(Peticion obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};


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


#endif // CLSPETICION_H_INCLUDED
