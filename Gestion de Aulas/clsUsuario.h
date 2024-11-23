#ifndef CLSUSUARIO_H_INCLUDED
#define CLSUSUARIO_H_INCLUDED

///ACCIONES
///USUARIO: VER AULAS, PEDIR CAMBIOS.

class Usuario : public Persona{
private:
    int legajo, codDepartamento, numero;
    char rol[9], mail[45];
    bool estado;

public:
    Usuario(const char *r="", const char *m="", int l=0, int c=0, bool e=false, int num=1)
    {
        codDepartamento = c;
        strcpy(mail, m);
        strcpy(rol, r);
        estado = e;
        numero = num;
        legajo = l;
    }
    void setMail(const char *m){strcpy(mail, m);}
    void setRol(const char *r){strcpy(rol, r);}
    void setEstado(bool e){estado = e;}
    void setNumero(int n){numero = n;}
    void setLegajo(int l){legajo = l;}
    void setCodDep(int c){codDepartamento = c;}
    int getCodDep(){return codDepartamento;}
    bool getEstado(){return estado;}
    const char *getMail(){return mail;}
    const char *getRol(){return rol;}
    int getNumero(){return numero;}
    int getLegajo(){return legajo;}
    bool verificarDep(int codDep){
        if(codDep == 240 || codDep == 890 || codDep == 660 || codDep == 450){
            return true;
        }
        return false;
    }
    bool verificarRol(char* rol){
        if(strcmp(rol,"Becado")==0 || strcmp(rol,"Docente")==0||strcmp(rol,"Director")==0){
            return true;
        }
        return false;
    }

    void Cargar(int dni)
    {
        Cargar_Persona(dni);
        cout << "Ingrese el numero de legajo: ";
        cin >> legajo;
        cout << "Ingrese el codigo del departamento: ";
        cin >> codDepartamento;
        while(!verificarDep(codDepartamento)){
            cout << "El departamento no existe! Ingrese otro codigo de departamento: ";
            cin >> codDepartamento;
        }
        cout << "Ingrese el rol (Becado, Docente o Director): ";
        cargarCadena(rol, 8);
        while(!verificarRol(rol)){
            cout << "El rol no existe! Ingrese otro rol: ";
            cargarCadena(rol, 8);
        }
        cout << "Ingrese el mail: ";
        cargarCadena(mail, 44);
        setColor(1);
        cout << "Usuario dado de alta ";
        estado = true;
    }
    void Cargar(int cod, int dni, const char *puesto)
    {

        Cargar_Persona(dni);
        cout << "Ingrese el numero de legajo: ";
        cin >> legajo;
        cout << "Ingrese el mail: ";
        cargarCadena(mail, 44);
        strcpy(rol, puesto);
        estado = true;
        setColor(1);
        cout << "Usuario dado de alta ";
        setColor(15);

    }
    void Mostrar(int x = 0, int y = 0)
    {
        if(estado)
        {
            Mostrar_Persona(x, y);
            y +=4;
            locate(x, y); cout << "Legajo: " << legajo << endl;
            locate(x, 2+y); cout << "Codigo de Departamento: " << codDepartamento << endl;
            locate(x, 3+y); cout << "Rol: " << rol << endl;
            locate(x, 4+y); cout << "Mail: " << mail << endl;
        }
    }
};

class ArchUsuario{
    private:
        char nombre[30];
    public:
        ArchUsuario(const char *n="usuarios.dat"){strcpy(nombre, n);}
        Usuario leerRegistro(int pos);
        void grabarRegistro(Usuario obj);
        void modificarRegistro(Usuario obj, int pos);
        void listarRegistros();
        int buscarRegistro(int num);
        int contarRegistros();
};


Usuario ArchUsuario::leerRegistro(int pos){
    Usuario obj;
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

void ArchUsuario::grabarRegistro(Usuario obj){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchUsuario::modificarRegistro(Usuario obj, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
        return;
    }
    fseek(p, pos * sizeof obj , 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchUsuario::listarRegistros(){
    Usuario obj;
    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
    }
}

int ArchUsuario::buscarRegistro(int num){
    Usuario obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchUsuario::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Usuario);
}

void Alta_Usuarios(int dni)
{
    Usuario obj;
    ArchUsuario archU;

    obj.Cargar(dni);
    archU.grabarRegistro(obj);
}

void Alta_Usuarios(int cod, int dni, const char *puesto)
{
    Usuario obj;
    ArchUsuario archU;

    obj.Cargar(cod, dni, puesto);
    archU.grabarRegistro(obj);
}


#endif // CLSUSUARIO_H_INCLUDED
