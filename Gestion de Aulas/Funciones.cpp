#include "Funciones.h"
#include <iostream>

void ComisionesAdmin() {
    int totalX, totalY,Dep;

    terminalSize(totalX,totalY);
    int x=(totalX-15)/2;
    int y = totalY/2;

    system("cls");

    locate(x, y-4);
    cout << "Ingrese el departamento para ver sus comisiones: ";
    cin >> Dep;

    verComisiones(Dep);
}

int verificarUsuario(int dni) {
    Usuario obj;
    ArchUsuario arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getDni() == dni) {
            return i;
        }
    }
    return -8;
}

void darAlta(int dni) {        //  Buscar por Dni
    system("cls");

    locate(1, 1);
    cout << "Ingrese el Dni de la persona: ";
    cin >> dni;

    int verificacion = verificarUsuario(dni);

    if(verificacion >= 0) {
        //Modificar estado y registro
        Usuario obj;
        ArchUsuario arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        obj.Mostrar();
        setColor(1);
        cout << obj.getNombre() << " " << obj.getApellido() << " Existe en el sistema y fue dado de Alta exitosamente";
    } else {
        Alta_Usuarios(dni);
    }
    system("pause>nul");
    system("cls");
}

void darBaja() { //buscar por Legajo
    int legajo, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-30)/2;
    int y = totalY/2;

    Usuario obj;
    ArchUsuario arch;

    system("cls");

    locate(x, y-4);
    cout << "Ingrese el legajo de la persona: ";
    locate(x, y-3);
    cin >> legajo;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getLegajo() == legajo) {
            obj.setEstado(false);
            arch.modificarRegistro(obj, i);
            setColor(1);
            locate(x, y);
            cout << "Dado de Baja Correctamente" << endl;
            setColor(0);
            system("pause");
            system("cls");
            return;
        }
    }
    setColor(4);
    locate(x, y);
    cout << "No se encontro el usuario" << endl;
    system("pause>nul");
    system("cls");
}


void darBaja(int cod, const char *rol) { //buscar por Legajo
    int legajo, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-30)/2;
    int y = totalY/2;

    Usuario obj;
    ArchUsuario arch;

    system("cls");

    locate(x, y-4);
    cout << "Ingrese el legajo de la persona: ";
    cin >> legajo;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getLegajo() == legajo && obj.getCodDep() == cod && strcmp(obj.getRol(), rol) == 0) {
            obj.setCodDep(0);
            arch.modificarRegistro(obj, i);
            setColor(1);
            locate(x, y-2);
            cout << "Eliminado del Departamento Correctamente";
            system("pause>nul");
            system("cls");
            return;
        }
    }
    setColor(4);
    locate(x, y-1);
    cout << "No se encontro el becado"<< endl;
    system("pause>nul");
    system("cls");
}

void darAlta(int CodDep,const char *rol) {        //  Buscar por Dni
    int dni, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    system("cls");

    locate (1,1);
    cout << "Ingrese el Dni de la persona: ";
    cin >> dni;
    cout << endl;

    int verificacion = verificarUsuario(dni);

    if(verificacion >= 0) {
        //Modificar estado y registro
        system("cls");
        Usuario obj;
        ArchUsuario arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        obj.Mostrar_Persona(x, y-3);
        setColor(1);
        locate(x, y+1);
        cout << obj.getNombre() << " " << obj.getApellido() << " existe en el sistema y fue dado de Alta exitosamente" << endl;
    } else {
        Alta_Usuarios(CodDep, dni, rol);
    }
    system("pause>nul");
    system("cls");
}


Departamento buscarDep(int Cod) {
    Departamento obj, aux;
    ArchDep arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getCodigo() == Cod) {
            aux = obj;
            return aux;
        }
    }
    obj.setCodigo(-1);
    return obj;
}

void verInfoDep(int CodDep) {
    Departamento obj;

    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-10)/2;
    int y = totalY/2;

    system("cls");
    obj = buscarDep(CodDep);
    if(obj.getCodigo() == -1) {
        cout << "No se encontro";
        system("pause>nul");
        system("cls");
    } else {
        obj.MostrarTodo(x, y);
    }


}

void mostrarDepCompleto(int codigo, int x, int y) {
    Usuario obj;
    ArchUsuario arch;
    Comision com;
    ArchComision archC;

    int tam = arch.contarRegistros();

    setColor(1);
    locate(x, y-6);
    cout << "Informacion del Departamento";
    setColor(15);
    y= y-2;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == codigo) {
            locate(x, y);
            cout << obj.getRol() << ": " << obj.getNombre() <<endl;
            y++;
        }
    }

    tam = archC.contarRegistros();
    for(int i=0; i<tam; i++) {
        com = archC.leerRegistro(i);
        if(com.getCodDep() == codigo) {
            locate(x, y);
            cout << "Comision del Departamento: " << com.getCodComision() << endl;
            y++;
        }
    }
}

void verAulas() {
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-30)/2;
    int y = totalY/2;

    Aula obj;
    ArchAula archA;

    system("cls");
    int tam = archA.contarRegistros();

    setColor(1);
    locate(x+20, y-6);
    cout << "Aulas";
    setColor(15);

    for(int i=0; i<tam; i++) {
        obj = archA.leerRegistro(i);
        obj.Mostrar_Peticion(x, y-4);
        y++;
    }
    system("pause>nul");
    system("cls");
}

void verComisiones(int CodDep) {
    Comision comi;
    ArchComision arch;

    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-10)/2;
    int y = totalY/2;

    system("cls");
    int tam = arch.contarRegistros();
    bool encontrado;

    setColor(1);
    locate(x, y-7);
    cout << "Comisiones";
    setColor(15);

    for(int i=0; i<tam; i++) {
        comi = arch.leerRegistro(i);
        if(comi.getCodDep() == CodDep) {
            encontrado = true;
            comi.Mostrar_Becado(x, y-5);
            y += 5;
        }
    }
    if(!encontrado) {
        locate(x, y-4);
        setColor(4);
        cout << "Error, Codigo mal ingresado" << endl << endl;
        y += 2;
        setColor(15);
    }
    system("pause>nul");
    system("cls");
}

void verComisiones(const char *nombre) {
    Comision comi;
    ArchComision arch;

    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-10)/2;
    int y = totalY/2;

    system("cls");
    int tam = arch.contarRegistros();

    setColor(1);
    locate(x, y-7);
    cout << "Comisiones";
    setColor(15);

    for(int i=0; i<tam; i++) {
        comi = arch.leerRegistro(i);
        if(strcmp(comi.getProfe(), nombre)==0) {
            comi.Mostrar_Docente(x, y-5);
            y += 5;
        }
    }
    system("pause>nul");
    system("cls");
}

Comision verificarComision(int CodDep, int CodComi) {
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == CodDep && obj.getCodComision() == CodComi) {
            return obj;
        }
    }
    obj.setNumero(-9);
    return obj;
}

int contarAulas() {
    Aula obj;
    ArchAula arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getDisponibilidad() && obj.getEstado()) {
            contador++;
        }
    }
    return contador;
}

bool verificar_Peticion(Aula *Vec, int tam, const char *aula, int capacidad) {
    for(int i=0; i<tam; i++) {
        if(strcmp(Vec[i].getNombre(), aula) == 0) {
            if(Vec[i].getCapacidad() >= capacidad) {
                return true;
            }
        }
    }
    return false;
}

void cargar_Aulas_Disponibles(Aula *Vec) {
    Aula aux;
    ArchAula arch;

    int tam = arch.contarRegistros(), espacio = 0;
    for(int i=0; i<tam; i++) {
        aux = arch.leerRegistro(i);
        if(aux.getDisponibilidad() && aux.getEstado()) {
            Vec[espacio] = aux;
            espacio++;
        }
    }
}

void Mostrar_Aulas(Aula *V, int tam) {
    for(int i=0; i<tam; i++) {
        V[i].Mostrar_Peticion();
    }
}

int contarComisiones(int CodDep) {
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getEstado() && obj.getCodDep() == CodDep) {
            contador++;
        }
    }
    return contador;
}

void cargarComisiones(Comision *v, int Cod) {
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getEstado() && obj.getCodDep() == Cod) {
            v[contador] = obj;
            contador++;
        }
    }
}


void mostrarComisiones(Comision *v, int tam) {
    for(int i=0; i<tam; i++) {
        v[i].Mostrar();
    }
}


void PedirCambios(int CodDep) {
    Comision *vComi;
    char op[3];
    int codigo;

    system("cls");

    // Mostrar e Ingresar comision elegida
    int contComi = contarComisiones(CodDep);
    vComi = new Comision[contComi];
    if(vComi == NULL) {
        exit(-1);
    }
    cargarComisiones(vComi, CodDep);
    mostrarComisiones(vComi, contComi);

    setColor(1);

    cout << endl <<"Ingrese la comision que quiera cambiar de aula: ";
    cin >> codigo;
    Comision obj = verificarComision(CodDep, codigo);

    system("cls");

    if(obj.getNumero() < 0) {
        cout << "No existe";
        delete []vComi;
        system("pause>nul");
        system("cls");
        setColor(15);
        return;
    }

    setColor(15);
    cout <<"La comision elegida" << endl;
    obj.Mostrar_Becado(0,0);
    setColor(1);
    cout << endl << "Desea continuar? (si/no): ";
    cargarCadena(op, 2);
    if(!(strcmp(op, "si") == 0)) {
        setColor(4);
        cout << endl << "Saliendo al menu";
        setColor(15);
        delete []vComi;
        system("pause>nul");
        system("cls");
        return;
    }

    // Mostrar e Ingresar el aula disponible
    Aula *vAulas;

    cout << endl;

    int aulasDisponibles = contarAulas();
    vAulas = new Aula[aulasDisponibles];
    if(vAulas == NULL) {
        exit (-2);
    }
    cargar_Aulas_Disponibles(vAulas);
    Mostrar_Aulas(vAulas, aulasDisponibles);

    char aula[5];
    setColor(1);
    cout << "Ingrese el aula: ";
    cargarCadena(aula, 4);

    bool verificado = verificar_Peticion(vAulas, aulasDisponibles, aula, obj.getCantidad());
    delete []vAulas;

    // CargarPeticion (Getters) y ArchivoPeticion
    if(verificado) {
        setColor(1);
        cout << endl << "Se dio de alta correctamente" << endl;
        Alta_Peticion(obj, aula);
        cout << endl << "Cargado y enviado al administrador" << endl;
        setColor(15);
    } else {
        setColor(4);
        cout << "No esta disponible" << endl;
        setColor(15);
    }
    delete []vComi;
    system("pause>nul");
    system("cls");
    setColor(15);
}

void Historial(int codDep) {
    Peticion obj;
    ArchPeticion arch;

    system("cls");

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == codDep) {
            obj.Mostrar();
        }
    }
}

void Asignacion_Baja(const char *nombre) {
    Comision objC;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        objC = arch.leerRegistro(i);
        if(strcmp(objC.getAula(), nombre) == 0) {
            objC.setAula("S/A");
            arch.modificarRegistro(objC, i);
            return;
        }
    }
}

void darBajaAulas() {
    char nombre[5];
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    Aula obj;
    ArchAula arch;

    system("cls");

    locate(x, y-4);
    cout << "Ingrese el nombre del aula: ";
    locate(x, y-2);
    cargarCadena(nombre, 4);

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(strcmp(obj.getNombre(), nombre) == 0) {
            if(obj.getEstado()) {
                obj.setEstado(false);
                arch.modificarRegistro(obj, i);
                Asignacion_Baja(obj.getNombre());
                setColor(1);
                locate(x, y);
                cout << "Aula dada de baja Correctamente";
                system("pause>nul");
                system("cls");
                return;
            } else {
                setColor(1);
                locate(x, y);
                cout << "Ya fue dada de baja" << endl;
                system("pause>nul");
                system("cls");
                return;
            }
        }
    }
    setColor(4);
    locate(x, y);
    cout << "No se encontro el aula";
    system("pause>nul");
    system("cls");
    setColor(15);
}

int verificarAulas(char *nombre) {
    Aula obj;
    ArchAula arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(strcmp(obj.getNombre(), nombre) == 0) {
            return i;
        }
    }
    return -8;
}

int contarPeticiones() {
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros(), cont = 0;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(!obj.getVisto()) {
            cont++;
        }
    }
    return cont;
}

void CargarPeticiones(Peticion *v) {
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros(), cont = 0;
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(!obj.getVisto()) {
            v[cont] = obj;
            cont++;
        }
    }
}

void cambiarAulas(Peticion pet) {
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getCodComision() == pet.getCodComi()) {
            obj.setAula(pet.getPedida());
            arch.modificarRegistro(obj, i);
        }
    }

    Aula objA;
    ArchAula archA;

    tam = archA.contarRegistros();
    for(int i=0; i<tam; i++) {
        objA = archA.leerRegistro(i);
        if(strcmp(objA.getNombre(), pet.getAsignada()) == 0) {
            objA.setDisponibilidad(true);
            archA.modificarRegistro(objA, i);
        }

        if(strcmp(objA.getNombre(), pet.getPedida()) == 0) {
            objA.setDisponibilidad(false);
            archA.modificarRegistro(objA, i);
        }
    }
}

void modificarArchPeticion(Peticion aux) {
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = arch.leerRegistro(i);
        if(obj.getNumero() == aux.getNumero()) {
            obj.setEstado(true);
            arch.modificarRegistro(aux, i);
        }
    }
}


void verPeticiones() {
    system("cls");
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;
    locate(x, y-4);
    setColor(15);

    cout << "Peticiones";

    int tam = contarPeticiones();

    if(tam == 0) {
        locate(x, y-2);
        setColor(2);
        cout << "No hay peticiones pendientes";
        system("pause>nul");
        system("cls");
        setColor(15);
        return;
    }

    Peticion *vPendientes;
    vPendientes = new Peticion[tam];
    if(vPendientes == NULL) {
        exit(-1);
    }
    CargarPeticiones(vPendientes);

    char op[3];

    for(int i=0; i<tam; i++) {
        system("cls");
        vPendientes[i].Mostrar_Peticion();
        cargarCadena(op, 2);
        vPendientes[i].setRespuesta(op);

        if(!(strcmp(op, "si") == 0)) {
            setColor(4);
            cout << "Peticion rechazada";
        }else{
            cambiarAulas(vPendientes[i]);
            cout << "Peticion aceptada";
        }
        vPendientes[i].setVisto(true);
        modificarArchPeticion(vPendientes[i]);

        setColor(15);
    }

    delete []vPendientes;
    system("pause>nul");
    system("cls");
    setColor(15);
}

void Asignacion_Alta(const char *nombre) {
    Comision objC;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++) {
        objC = arch.leerRegistro(i);
        if(strcmp(objC.getAula(), "S/A") == 0) {
            objC.setAula(nombre);
            arch.modificarRegistro(objC, i);
            return;
        }
    }
}

void darAltaAulas() {
    char nombre[5];
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;
    system("cls");

    locate(x, y-4);
    cout << "Ingrese el nombre del Aula: ";
    locate(x, y-2);
    cargarCadena(nombre, 4);
    cout << endl;

    int verificacion = verificarAulas(nombre);

    if(verificacion >= 0) {
        Aula obj;
        ArchAula arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        Asignacion_Alta(obj.getNombre());
        locate(x, y);
        setColor(1);
        cout << "El aula "<< obj.getNombre() << " Existe en el sistema y fue dado de Alta exitosamente";
    } else {
        char op[2];
        locate(x, y);
        cout << "No existe en el sistema";
        locate(x, y+1);
        cout << "Desea cargar un aula nueva?(si/no)";
        locate(x, y+2);
        cargarCadena(op, 2);
        if(strcmp(op, "si") == 0) {
            system("cls");
            Alta_Aulas(nombre);
        }
    }
    system("pause>nul");
    system("cls");
}

void terminalSize(int &x, int &y) // Te devuelve el ancho y largo de la terminal a traves de los parametros
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    x= columns;
    y=rows;

    return;
}
