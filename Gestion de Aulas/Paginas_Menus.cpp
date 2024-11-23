#include "Paginas_Menus.h"

void Login() {
    int op, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    while(true) {
        setColor(15);
        system("cls");
        locate(x, y-4);
        cout << "Ingresando al SysadAulas";
        locate(x, y-2);
        cout << "1. Usuario";
        locate(x, y-1);
        cout << "2. Administrador";
        locate(x, y+1);
        cout << "0. Cerrar Aplicacion";

        op = Opcion(x,y+3);
        switch(op) {
        case 1:
            Ingreso();
            break;
        case 2:
            IngresoAdmin();
            break;
        case 0:
            return;
            break;
        default:
            Alerta(x, y);
            break;
        }
    }
}

void Ingreso() {
    int legajo;
    Usuario obj, aux;
    ArchUsuario archU;
    bool encontro = false;

    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    system("cls");
    locate(x, y-2);
    cout << "Ingresando al SysadAulas";
    locate(x, y);
    cout << "Legajo: ";
    cin >> legajo;

    if(legajo < 0) {
        exit(1);
    }

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
                locate(x, y-2);
                setColor(4);
                cout << "INGRESE NUEVAMENTE!!!";
                locate(x, y);
                cout << "Legajo dado de baja";
                system("pause>nul");
            }
        }
    }

    if(!encontro) {
        locate(x, y-2);
        setColor(4);
        cout << "INGRESE NUEVAMENTE!!!";
        locate(x, y);
        cout << "El Legajo no figura en el sistema";
        system("pause>nul");
    }

}

void SelectorMenu(Usuario obj) {
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-44)/2;
    int y = totalY/2;

    system("cls");
    locate(x+17, y-3);
    cout << "Hola " << obj.getNombre();
    locate(x, y-1);
    cout << "Yendo al menu de acuerdo a su puesto como " <<obj.getRol();
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

void Alerta(int x, int y) {
    system("cls");
    locate(x, y);
    setColor(4);
    cout << "Opcion invalida!!!";
    system("pause>nul");
    setColor(15);
}

int Opcion(int x,int y) {
    int op;
    setColor(1);
    locate(x, y);
    cout << "Ingrese una opcion: ";
    cin >> op;
    setColor(15);
    return op;
}

void Becado(Usuario obj) { //Ver aulas, ver comisiones y pedir cambios
    int op, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    while(true) {
        locate(x+7, y-4);
        cout << "Bienvenido " << obj.getNombre();
        locate(x, y-2);
        cout << "1. Ver las Aulas";
        locate(x, y-1);
        cout << "2. Ver las Comisiones del Departamento";
        locate(x, y);
        cout << "3. Pedir Cambios de Aulas";
        locate(x, y+2);
        cout << "0. Cerrar Sesion";

        op = Opcion(x,y+4);

        switch(op) {
        case 1:
            verAulas();
            break;
        case 2:
            verComisiones(obj.getCodDep());
            break;
        case 3:
            PedirCambios(obj.getCodDep());
            break;
        case 0:
            system("cls");
            return;
            break;
        default:
            Alerta(x, y);
            break;
        }
    }
}

void Docente(Usuario obj) { //Ver aulas, info del departamento y ver las comisiones en las que da clases
    int op, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    while(true) {
        locate(x+7, y-4);
        cout << "Bienvenido " << obj.getNombre();
        locate(x, y-2);
        cout << "1. Ver las Aulas";
        locate(x, y-1);
        cout << "2. Ver sus Comisiones";
        locate(x, y);
        cout << "3. Ver informacion del Departamento";
        locate(x, y+1);
        cout << "0. Cerrar Sesion";

        op = Opcion(x,y+4);

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
            system("cls");
            return;
            break;
        default:
            Alerta(x, y);
            break;
        }
    }
}

void Director(Usuario obj) { //Ver Aulas, ver comisiones, dar de alta y baja a becados
    int op, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-30)/2;
    int y = totalY/2;

    while(true) {
        setColor(15);
        locate(x, y-6);
        cout << "Bienvenido " << obj.getNombre();
        locate(x, y-4);
        cout << "1. Ver las Aulas";
        locate(x, y-3);
        cout << "2. Agregar a un Becado al Departamento";
        locate(x, y-2);
        cout << "3. Dar de Baja a un Becado del Departamento";
        locate(x, y-1);
        cout << "4. Ver las Comisiones del departamento";
        locate(x, y);
        cout << "5. Ver informacion del Departamento";
        locate(x, y+2);
        cout << "0. Cerrar Sesion";

        op = Opcion(x, y+4);

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
            system("cls");
            return;
            break;
        default:
            Alerta(x, y);
            break;
        }
    }
}

void IngresoAdmin() {
    Administrador obj;
    ArchAdm archA;
    char contrasenia[30];
    bool entro = false;
    int totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    system("cls");
    locate(x, y-3);
    cout << "Ingresando al SysadAulas";
    locate(x, y-1);
    cout << "Contrasenia: ";
    cargarCadena(contrasenia, 29);

    int tam = archA.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = archA.leerRegistro(i);
        if(strcmp(obj.getContrasenia(), contrasenia) == 0) {
            entro = true;
            system("cls");
            locate(x+9, y-3);
            cout << "Hola " << obj.getNombre();
            locate(x-1, y-1);
            cout << "Yendo al menu de administrador ";
            system("pause>nul");
            system("cls");
            Admin(obj);
        }
    }

    if(!entro) {
        setColor(4);
        locate(x, y+1);
        cout << "Contrasena erronea!";
        system("pause>nul");
        setColor(15);
        system("cls");
    }

}
void Aulas(Administrador obj) {
    int opcion,totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-20)/2;
    int y = totalY/2;

    system("cls");
    while(true) {
        setColor(15);
        locate(x, y-6);
        cout << "Bienvenido al menu de Aulas";
        locate(x, y-4);
        cout << "1. Ver las Aulas";
        locate(x, y-3);
        cout << "2. Ver los cambios de Aulas";
        locate(x, y-2);
        cout << "3. Dar de baja a Aulas";
        locate(x, y-1);
        cout << "4. Dar de alta a Aulas";
        locate(x, y+1);
        cout << "0. Volver al menu anterior";

        opcion = Opcion(x,y+3);

        switch(opcion) {
        case 1:
            verAulas();
            break;
        case 2:
            verPeticiones();
            break;
        case 3:
            darBajaAulas();
            break;
        case 4:
            darAltaAulas();
            break;
        case 0:
            system("cls");
            return;
        default:
            Alerta(70, 19);
            break;
        }
    }
}


void Admin(Administrador obj) { //Ver comisiones, confirmar cambios, dar de alta, baja y ver aulas
    int opcion, totalX, totalY;

    terminalSize(totalX,totalY);
    int x=(totalX-15)/2;
    int y = totalY/2;

    while(true) {
        setColor(15);
        locate(x, y-6);
        cout << "Bienvenido " << obj.getNombre();
        locate(x, y-4);
        cout << "1. Menu de aulas"; //Menu de aulas
        locate(x, y-3);
        cout << "2. Ver las Comisiones"; // Mostrar los numeros del departamento e ingresar el CodDep
        locate(x, y-2);
        cout << "3. Dar de baja a Usuarios";
        locate(x, y-1);
        cout << "4. Dar de alta a Usuarios";
        locate(x, y+1);
        cout << "0. Cerrar Sesion";

        opcion = Opcion(x,y+3);

        switch(opcion) {
        case 1:
            Aulas(obj);
            system("cls");
            break;
        case 2:
            ComisionesAdmin();
            break;
        case 3:
            darBaja();
            break;
        case 4:
            darAlta(-1);
            break;
        case 0:
            system("cls");
            return;
        default:
            Alerta(x, y);
            break;
        }
    }
}
