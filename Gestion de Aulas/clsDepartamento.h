#ifndef CLSDEPARTAMENTO_H_INCLUDED
#define CLSDEPARTAMENTO_H_INCLUDED
class Departamento {
private:
    char nombre[10];
    int codigo, numero;
    bool estado, lectura = true, escritura = false;

public:
    Departamento(int c = 0, const char *n = "", bool e = false, int nu = 1);

    void setNombre(const char *n);
    void setEstado(bool e);
    void setNumero(int n);
    void setCodigo(int c);
    const char *getNombre();
    bool getEscritura();
    bool getLectura();
    bool getEstado();
    int getNumero();
    int getCodigo();

    void Cargar();
    void Mostrar();
    void MostrarTodo();
};

class ArchDep {
private:
    char nombre[30];

public:
    ArchDep(const char *n = "departamento.dat");
    Departamento leerRegistro(int pos);
    void grabarRegistro(Departamento obj);
    void modificarRegistro(Departamento obj, int pos);
    void listarRegistros();
    int buscarRegistro(int num);
    int contarRegistros();
};

#endif // CLSDEPARTAMENTO_H_INCLUDED
