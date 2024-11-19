#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

class Persona{
private:
    char nombre[30], apellido[30];
    int dni;

public:
    Persona(const char *n="", const char *a="", int d=0, int l=0, const char *m="", const char *r="")
    {
        strcpy(apellido, a);
        strcpy(nombre, n);
        dni = d;
    }
    void setApellido(const char *a){strcpy(apellido, a);}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setDni(int d){dni = d;}
    const char *getApellido(){return apellido;}
    const char *getNombre(){return nombre;}
    int getDni(){return dni;}

    void Cargar_Persona()
    {
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre, 29);
        cout << "Ingrese el apellido: ";
        cargarCadena(apellido, 29);
        cout << "Ingrese el Dni: ";
        cin >> dni;
    }
    void Cargar_Persona(int DNI)
    {
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre, 29);
        cout << "Ingrese el apellido: ";
        cargarCadena(apellido, 29);
        dni = DNI;
    }

    void Mostrar_Persona(int x = 0, int y = 0)
    {
        locate(x, y); cout << "Nombre: " << nombre << endl;
        locate(x, 1+y); cout << "Apellido: " << apellido << endl;
        locate(x, 2+y); cout << "Dni: " << dni << endl;
    }
};


#endif // CLSPERSONA_H_INCLUDED
