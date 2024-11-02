#ifndef CLSDEPARTAMENTO_H_INCLUDED
#define CLSDEPARTAMENTO_H_INCLUDED

///ACCIONES
///DEPARTAMENTO: LISTAR INFORMACION DE LOS PUESTOS Y DOCENTES.

class Departamento{
private:
    char nombre[10];
    int codigo, numero;
    bool estado, lectura=true, escritura=false;

public:
    Departamento(int c=0, const char *n="", bool e=false, int nu=1)
    {
        strcpy(nombre, n);
        numero = nu;
        codigo = c;
        estado = e;
    }
    void setNombre(const char *n){strcpy(nombre, n);}
    void setEstado(bool e){estado = e;}
    void setNumero(int n){numero = n;}
    void setCodigo(int c){codigo = c;}
    const char *getNombre(){return nombre;}
    bool getEscritura(){return escritura;}
    bool getLectura(){return lectura;}
    bool getEstado(){return estado;}
    int getNumero(){return numero;}
    int getCodigo(){return codigo;}

    void Cargar()
    {
        cout << "Ingrese el codigo del departamento: ";
        cin >> codigo;
        cout << "Ingrese el nombre del departamento: ";
        cargarCadena(nombre, 9);
        estado = true;
    }

    void Mostrar()
    {
        if(estado)
        {
            cout << "El codigo del departamento: " << codigo << endl;
            cout << "El nombre del departamento: " << nombre << endl;
        }
    }
    void MostrarTodo()
    {
        if(estado)
        {
            cout << "El codigo del departamento: " << codigo << endl;
            cout << "El nombre del departamento: " << nombre << endl;
            mostrarDepCompleto(codigo);
        }
    }
};

class ArchDep{
    private:
        char nombre[30];
    public:
        ArchDep(const char *n="departamento.dat"){strcpy(nombre, n);}
        Departamento leerRegistro(int pos);
        void grabarRegistro(Departamento obj);
        void modificarRegistro(Departamento obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};


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
    return cant/sizeof(Aula);
}


#endif // CLSDEPARTAMENTO_H_INCLUDED
