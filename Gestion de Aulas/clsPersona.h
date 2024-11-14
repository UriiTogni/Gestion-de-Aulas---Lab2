#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

class Persona {
private:
    char nombre[30], apellido[30];
    int dni, celular;

public:
    Persona(const char *n = "", const char *a = "", int d = 0, int c = 0);

    void setApellido(const char *a);
    void setNombre(const char *n);
    void setCelular(int c);
    void setDni(int d);
    const char *getApellido();
    const char *getNombre();
    int getCelular();
    int getDni();

    void Cargar_Persona(int DNI);
    void Mostrar_Persona();
};

#endif // CLSPERSONA_H_INCLUDED
