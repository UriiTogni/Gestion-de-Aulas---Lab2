#ifndef CLSADMINISTRADOR_H_INCLUDED
#define CLSADMINISTRADOR_H_INCLUDED

///ACCIONES
///ADMINISTRADOR: VER AULAS, VER PETICIONES, DELEGAR AULAS Y DECIDIR CAMBIOS.

class Administrador : public Persona{
private:
    int codigo, numero;
    char mail[45], contrasenia[30];
    bool estado;

public:
    Administrador(const char *m="", const char *c="", bool e=false, int n=1, int co=1)
    {
        strcpy(contrasenia, c);
        strcpy(mail, m);
        numero = n;
        codigo = co;
        estado = e;
    }
    void setContrasenia(const char *c){strcpy(contrasenia, c);}
    void setMail(const char *m){strcpy(mail, m);}
    void setEstado(bool e){estado = e;}
    void setCodigo(int c){codigo = c;}
    void setNumero(int n){numero = n;}
    const char *getConstrasenia(){return contrasenia;}
    bool getEstado(){return estado;}
    const char *getMail(){return mail;}
    int getCodigo(){return codigo;}
    int getNumero(){return numero;}
    void Cargar()
    {
        Cargar_Persona();
        cout << "Ingrese el mail: ";
        cargarCadena(mail, 44);
        cout << "Ingrese la contrasenia: ";
        cargarCadena(contrasenia, 29);
        estado = true;
    }
    void Mostrar()
    {
        if(estado)
        {
            //Mostrar_Persona();
            cout << "Mail: " << mail << endl;
            cout << "Contrasenia: " << contrasenia << endl;
        }
    }

};

class ArchAdm{
    private:
        char nombre[30];
    public:
        ArchAdm(const char *n="administrador.dat"){strcpy(nombre, n);}
        Administrador leerRegistro(int pos);
        void grabarRegistro(Administrador obj);
        void modificarRegistro(Administrador obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};


Administrador ArchAdm::leerRegistro(int pos){
    Administrador obj;
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

void ArchAdm::grabarRegistro(Administrador obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchAdm::modificarRegistro(Administrador obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchAdm::listarRegistros(){
    Administrador obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
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

#endif // CLSADMINISTRADOR_H_INCLUDED
