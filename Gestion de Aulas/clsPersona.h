#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

class Persona{
private:
    char nombre[30], apellido[30];
    int dni, celular;

public:
    Persona(const char *n="", const char *a="", int d=0, int l=0, int c=0, const char *m="", const char *r="")
    {
        strcpy(apellido, a);
        strcpy(nombre, n);
        celular = c;
        dni = d;
    }
    void setApellido(const char *a){strcpy(apellido, a);}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setCelular(int c){celular = c;}
    void setDni(int d){dni = d;}
    const char *getApellido(){return apellido;}
    const char *getNombre(){return nombre;}
    int getCelular(){return celular;}
    int getDni(){return dni;}

    void Cargar_Persona(int DNI)
    {
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre, 29);
        cout << "Ingrese el apellido: ";
        cargarCadena(apellido, 29);
        dni = DNI;
//        cout << "Ingrese el dni: ";
//        cin >> dni;
        cout << "Ingrese el numero de celular: ";
        cin >> celular;
    }

    void Mostrar_Persona()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dni: " << dni << endl;
        cout << "Celular: " << celular << endl;
    }
};


#endif // CLSPERSONA_H_INCLUDED
