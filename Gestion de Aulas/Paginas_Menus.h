#ifndef PAGINAS_MENUS_H_INCLUDED
#define PAGINAS_MENUS_H_INCLUDED

void Ingreso(), SelectorMenu(Usuario obj), IngresoAdmin(), Alerta(int x, int y), Login();
void Becado(Usuario obj), Docente(Usuario obj), Director(Usuario obj), Admin(Administrador obj), Aulas(Administrador obj);
int Opcion(int y);

void Login() {
    int op;
    while(true) {
        setColor(15);
        system("cls");
        locate(70, 6);
        cout << "Ingresando al SysadAulas";
        locate(70, 8);
        cout << "1. Usuario";
        locate(70, 9);
        cout << "2. Administrador";
        locate(70, 11);
        cout << "0. Cerrar Aplicacion";

        op = Opcion(13);

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
            Alerta(70, 15);
            break;
        }
    }
}

void Ingreso() {
    int legajo;
    Usuario obj, aux;
    ArchUsuario archU;
    bool encontro = false;

    system("cls");
    locate(71, 4);
    cout << "Ingresando al SysadAulas";
    locate(71, 6);
    cout << "legajo:";
    locate(79, 6);
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
                locate(75, 8);
                setColor(4);
                cout << "INGRESE NUEVAMENTE!!!";
                locate(70, 10);
                cout << "Legajo dado de baja";
                system("pause>nul");
            }
        }
    }

    if(!encontro) {
        locate(75, 8);
        setColor(4);
        cout << "INGRESE NUEVAMENTE!!!";
        locate(70, 10);
        cout << "El Legajo no figura en el sistema";
        system("pause>nul");
    }

}

void SelectorMenu(Usuario obj) {
    system("cls");
    locate(70, 8);
    cout << "Hola " << obj.getNombre();
    locate(70, 10);
    cout << "Yendo al menu de acuerdo a su puesto como " <<obj.getRol();
    locate(70, 12);
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
    setColor(15);
}

int Opcion(int y) {
    int op;
    setColor(1);
    locate(70, y);
    cout << "Ingrese una opcion: ";
    locate(90, y);
    cin >> op;
    setColor(15);
    return op;
}

void Becado(Usuario obj) { //Ver aulas, ver comisiones y pedir cambios
    int op;
    while(true) {
        locate(70, 8);
        cout << "Bienvenido " << obj.getNombre();
        locate(70, 10);
        cout << "1. Ver las Aulas";
        locate(70, 11);
        cout << "2. Ver las Comisiones del Departamento";
        locate(70, 12);
        cout << "3. Pedir Cambios de Aulas";
        locate(70, 13);
        cout << "0. Cerrar Sesion";

        op = Opcion(15);

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
            Alerta(70, 17);
            break;
        }
    }
}

void Docente(Usuario obj) { //Ver aulas, info del departamento y ver las comisiones en las que da clases
    int op;
    while(true) {
        locate(70, 8);
        cout << "Bienvenido " << obj.getNombre();
        locate(70, 10);
        cout << "1. Ver las Aulas";
        locate(70, 11);
        cout << "2. Ver sus Comisiones";
        locate(70, 12);
        cout << "3. Ver informacion del Departamento";
        locate(70, 14);
        cout << "0. Cerrar Sesion";

        op = Opcion(16);

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
            Alerta(70, 18);
            break;
        }
    }
}

void Director(Usuario obj) { //Ver Aulas, ver comisiones, dar de alta y baja a becados
    int op;
    while(true) {
        locate(70, 8);
        cout << "Bienvenido " << obj.getNombre();
        locate(70, 10);
        cout << "1. Ver las Aulas";
        locate(70, 11);
        cout << "2. Agregar a un Becado al Departamento";
        locate(70, 12);
        cout << "3. Dar de Baja a un Becado del Departamento";
        locate(70, 13);
        cout << "4. Ver las Comisiones del departamento";
        locate(70, 14);
        cout << "5. Ver informacion del Departamento";
        locate(70, 16);
        cout << "0. Cerrar Sesion";

        op = Opcion(18);

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
            Alerta(70, 20);
            break;
        }
    }


}

void IngresoAdmin() {
    Administrador obj;
    ArchAdm archA;
    char contrasenia[30];
    bool entro = false;

    system("cls");
    locate(72, 4);
    cout << "Ingresando al SysadAulas";
    locate(72, 6);
    cout << "contrasenia: ";
    locate(84, 6);
    cargarCadena(contrasenia, 29);

    int tam = archA.contarRegistros();
    for(int i=0; i<tam; i++) {
        obj = archA.leerRegistro(i);
        if(strcmp(obj.getConstrasenia(), contrasenia) == 0) {
            entro = true;
            system("cls");
            locate(70, 8);
            cout << "Hola " << obj.getNombre();
            locate(70, 9);
            cout << "Yendo al menu de administrador ";
            locate(70, 10);
            system("pause>nul");
            system("cls");
            Admin(obj);
        }
    }

    if(!entro) {
        setColor(4);
        locate(72, 8);
        cout << "Contrasena erronea";
        locate(70, 9);
        system("pause>nul");
        locate(70, 10);
        setColor(15);
        system("cls");
    }

}
void Aulas(Administrador obj) {
    setColor(15);
    int opcion;
    system("cls");
    while(true) {
        locate(70, 8);
        cout << "Bienvenido al menu de Aulas";
        locate(70, 10);
        cout << "1. Ver las Aulas";
        locate(70, 11);
        cout << "2. Ver los cambios de Aulas";
        locate(70, 12);
        cout << "3. Dar de baja a Aulas";
        locate(70, 13);
        cout << "4. Dar de alta a Aulas";
        locate(70, 15);
        cout << "0. Volver al menu anterior";

        opcion = Opcion(17);

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
    int opcion;
    setColor(15);
    while(true) {
        locate(70, 8);
        cout << "Bienvenido " << obj.getNombre();
        locate(70, 10);
        cout << "1. Menu de aulas"; //Menu de aulas
        locate(70, 11);
        cout << "2. Ver las Comisiones"; // Mostrar los numeros del departamento e ingresar el CodDep
        locate(70, 12);
        cout << "3. Dar de baja a Usuarios";
        locate(70, 13);
        cout << "4. Dar de alta a Usuarios";
        locate(70, 15);
        cout << "0. Cerrar Sesion";

        opcion = Opcion(17);

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
            Alerta(70, 19);
            break;
        }
    }
}

#endif // PAGINAS_MENUS_H_INCLUDED
