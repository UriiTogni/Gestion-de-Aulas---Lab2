#ifndef CLSAULA_H_INCLUDED
#define CLSAULA_H_INCLUDED

class Aula {
private:
    char nombre[5], deparLlave[10];
    int capacidad, numero;
    bool llave, disponibilidad, estado;

public:
    Aula(const char *n = "ABC", const char *de = "T", int c = 0, bool l = true, bool d = true, bool e = false, int num = 1);

    void setDeparLlave(const char *d);
    void setDisponibilidad(bool d);
    void setNombre(const char *n);
    void setCapacidad(int c);
    void setEstado(bool e);
    void setNumero(int n);
    void setLlave(bool l);
    bool getDisponibilidad();
    const char *getDeparLlave();
    const char *getNombre();
    int getCapacidad();
    bool getEstado();
    int getNumero();
    bool getLlave();
    void Cargar();
    void Mostrar();
    void Mostrar_Peticion();
};

class ArchAula {
private:
    char nombre[30];

public:
    ArchAula(const char *n = "aulas.dat");
    Aula leerRegistro(int pos);
    void grabarRegistro(Aula obj);
    void modificarRegistro(Aula obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

#endif // CLSAULA_H_INCLUDED
