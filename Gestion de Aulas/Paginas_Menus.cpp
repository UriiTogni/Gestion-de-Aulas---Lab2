#include <iostream>
#include <cstring>
#include <windows.h>

#include "Cadena.h"
#include "clsUsuario.h"
#include "clsAdministrador.h"
#include "rlutil.h"
#include "Funciones.h"
#include "Paginas_Menus.h"


using namespace std;
using namespace rlutil;

void Ingreso() {
    int width, length;
    getSizeScreen(width, length);

    int legajo;
    Usuario obj, aux;
    ArchUsuario archU;
    bool encontro = false;


    while(!encontro) {

    system("cls");

    char text []="Ingresando al SysadAulas";
    int midWidth = (width-strlen(text))/2; //       Centra el texto dependiendo el tamaño del primer texto de ese menu
    int midLegth = ((length)/2);           //

    locate(midWidth, midLegth-3);
    cout << text;

    locate(midWidth, midLegth);
    char  text2 []="Legajo:";
    cout << text2;

    locate(midWidth+sizeof(text2), midLegth);
    cin >> legajo;

    system("cls");

    obj.setEstado(false);


        int tam = archU.contarRegistros();
        for(int i = 0; i < tam; i++) {
            aux = archU.leerRegistro(i);
            if(aux.getLegajo() == legajo && aux.getLegajo() != 0) {
                obj = aux;
                encontro = true;

                if(obj.getEstado()) {
                    SelectorMenu(obj);
                } else {
                    locate(midWidth, midLegth-2);
                    cout << "INGRESE NUEVAMENTE!!!";
                    locate(midWidth, midLegth);
                    cout << "Legajo dado de baja";
                    system("pause>nul");
                }
            }
        }

        if(!encontro) {
            locate(midWidth, midLegth-2);
            cout << "INGRESE NUEVAMENTE!!!";
            locate(midWidth, midLegth);
            cout << "El Legajo no figura en el sistema"<< '\n';

            locate(midWidth, midLegth+2);
            system("pause>nul");
        }
    }
}

void SelectorMenu(Usuario obj) {
    int width, length;
    getSizeScreen(width, length);

    system("cls");

    char text[]="Hola ";
    int midWidth = (width-(strlen(text)+strlen(obj.getNombre())))/2.5;
    int midLength = length/2;

    locate(midWidth, midLength-2);
    cout<< text << obj.getNombre();

    locate(midWidth, midLength);
    cout << "Yendo al menu de acuerdo a su puesto como " <<obj.getRol();

    locate(midWidth, midLength+1);
    system("pause>nul");
    system("cls");

    if(strcmp(obj.getRol(), "Becado")==0) {
        Becado(obj);
    } else if(strcmp(obj.getRol(), "Docente")==0) {
        Docente(obj);
    } else if(strcmp(obj.getRol(), "Director")==0) {
        Director(obj);
    }
}

void Becado(Usuario obj) { //Ver aulas, ver comisiones y pedir cambios
    int op;

    int width, length;
    getSizeScreen(width,length);
    char text[]="Bienvenido ";
    int midWidth = (width-(strlen(text)+strlen(obj.getNombre())))/2;
    int midLength = length/2;
    locate(midWidth, midLength-6);
    cout <<  text << obj.getNombre();

    locate(midWidth,midLength-4);
    cout << "1. Ver las Aulas";
    locate(midWidth, midLength-3);
    cout << "2. Ver las Comisiones del Departamento";
    locate(midWidth, midLength-2);
    cout << "3. Pedir Cambios de Aulas"; //Generar arch Cambios?
    locate(midWidth, midLength-1);
    cout << "0. Cerrar Sesion";

    locate(midWidth, midLength+1);
    cout << "Ingrese una opcion: ";
    locate(midWidth, midLength+2);
    cin >> op;

    switch(op) {
    case 1:
        verAulas();
        break;
    case 2:
        verComisiones(obj.getCodDep());
        break;

    case 0:
        locate(midWidth,midLength+4);
        cout << "Volviendo al menu";
        system("pause>nul");
        return;
    }
}

void Docente(Usuario obj) { //Ver aulas, info del departamento y ver las comisiones en las que da clases
    int op;

    int width, length;
    getSizeScreen(width,length);
    char text[]="Bienvenido ";
    int midWidth = (width-(strlen(text)+strlen(obj.getNombre())))/2;
    int midLength = length/2;
    locate(midWidth, midLength-6);
    cout <<  text << obj.getNombre();

    locate(midWidth, midLength-4);
    cout << "1. Ver las Aulas";
    locate(midWidth, midLength-3);
    cout << "2. Ver sus Comisiones";
    locate(midWidth, midLength-2);
    cout << "3. Ver informacion del Departamento";
    locate(midWidth, midLength-1);
    cout << "0. Cerrar Sesion";
    locate(midWidth, midLength+1);
    cout << "Ingrese una opcion: ";
    locate(midWidth, midLength+2);
    cin >> op;

    switch(op) {
    case 1:
        verAulas();
        break;
    case 2:
        verComisiones(obj.getNombre());
        break;
    case 3:
        verInfoDep(obj.getCodDep());
        break;
    case 0:
        locate(midWidth,midLength+4);
        cout << "Volviendo al menu";
        system("pause>nul");
        return;
    }
}

void Director(Usuario obj) { //Ver Aulas, ver comisiones, dar de alta y baja a becados
    int op;

    int width, length;
    getSizeScreen(width,length);
    char text[]="Bienvenido ";
    int midWidth = (width-(strlen(text)+strlen(obj.getNombre())))/2;
    int midLength = length/2;
    locate(midWidth, midLength-6);
    cout <<  text << obj.getNombre();

    locate(midWidth, midLength-4);
    cout << "1. Ver las Aulas";
    locate(midWidth, midLength-3);
    cout << "2. Agregar a un Becado al Departamento";
    locate(midWidth, midLength-2);
    cout << "3. Dar de Baja a un Becado del Departamento";
    locate(midWidth, midLength-1);
    cout << "4. Ver las Comisiones del departamento";
    locate(midWidth, midLength);
    cout << "5. Ver informacion del Departamento";
    locate(midWidth, midLength+1);
    cout << "0. Cerrar Sesion";
    locate(midWidth, midLength+3);
    cout << "Ingrese una opcion: ";
    locate(midWidth, midLength+4);
    cin >> op;

    switch(op) {
    case 1:
        verAulas();
        break;
    case 2:
        darAlta(obj.getCodDep(), "Becado");
        break;
    case 3:
        darBaja(obj.getCodDep(), "Becado");
        break;
    case 4:
        verComisiones(obj.getCodDep());
        break;
    case 5:
        verInfoDep(obj.getCodDep());
        break;
    case 0:
        locate(midWidth,midLength+6);
        cout << "Volviendo al menu";
        system("pause>nul");
        return;
    }
}

void IngresoAdmin() {
    Administrador obj;
    ArchAdm archA;
    char contrasenia[30];
    system("cls");

    int width, length;
    getSizeScreen(width,length);
    char text[]="Ingresando al SysadAulas";
    int midWidth = (width-(strlen(text)))/2;
    int midLength = length/2;

    locate(midWidth, midLength-2);
    cout<<text;

    locate(midWidth, midLength-1);
    cout << "contrasenia: ";
    locate(midWidth, midLength);
    cargarCadena(contrasenia, 29);

    int tam = archA.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = archA.leerRegistro(i);
        if(strcmp(obj.getConstrasenia(), contrasenia) == 0) {
            locate(midWidth, midLength-1);
            cout << "Hola " << obj.getNombre();
            locate(midWidth, midLength);
            cout << "Yendo al menu de administrador ";
            Admin(obj);
        }
    }
}

void Admin(Administrador obj) { //Ver comisiones, confirmar cambios, dar de alta, baja y ver aulas
    int opcion;
    while(true) {
        system("pause>nul");
        system("cls");

        int width, length;
        getSizeScreen(width,length);
        char text[]="Bienvenido ";
        int midWidth = (width-(strlen(text)+strlen(obj.getNombre())))/2;
        int midLength = length/2;
        locate(midWidth, midLength-6);
        cout <<  text << obj.getNombre();

        locate(midWidth, midLength-4);
        cout << "1. Ver/Modificar las Aulas"; //Modificar = hacer/Confirmar cambios, dar de baja y alta
        locate(midWidth, midLength-3);
        cout << "2. Ver las todas las Comisiones";
        locate(midWidth, midLength-2);
        cout << "3. Dar de baja a Usuarios";
        locate(midWidth, midLength-1);
        cout << "4. Dar de alta a Usuarios";
        locate(midWidth, midLength);
        cout << "0. Cerrar Sesion";
        locate(midWidth, midLength+2);
        cout << "Ingrese la opcion: ";
        locate(midWidth, midLength+3);
        cin >> opcion;

        switch(opcion) {
        case 1:

            break;
        case 2:
            allComisiones();
            break;
        case 3:
            darBaja();
            break;
        case 4:
            darAlta();
            break;
        case 0:
            locate(midWidth,midLength+4);
            cout << "Volviendo al menu";
            system("pause>nul");
            return;
        }
    }
}
