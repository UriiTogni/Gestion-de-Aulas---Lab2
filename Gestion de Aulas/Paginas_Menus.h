#ifndef PAGINAS_MENUS_H_INCLUDED
#define PAGINAS_MENUS_H_INCLUDED

void Ingreso(), SelectorMenu(Usuario obj), IngresoAdmin();
void Becado(Usuario obj), Docente(Usuario obj), Director(Usuario obj), Admin(Administrador obj);

void Ingreso()
{
    int legajo;
    Usuario obj, aux;
    ArchUsuario archU;
    bool encontro = false;

    system("cls");
    locate(72, 4);
    cout << "Ingresando al SysadAulas";
    locate(71, 6);
    cout << "legajo:";
    locate(79, 6);
    cin >> legajo;

    obj.setEstado(false);

    int tam = archU.contarRegistros();
    for(int i = 0; i < tam; i++)
    {
        aux = archU.leerRegistro(i);
        if(aux.getLegajo() == legajo && aux.getLegajo() != 0)
        {
            obj = aux;
            encontro = true;

            if(obj.getEstado()){ SelectorMenu(obj); }
            else
            {
                locate(75, 9);
                cout << "INGRESE NUEVAMENTE!!!";
                locate(70, 10);
                cout << "Legajo dado de baja";
                system("pause");
            }
        }
    }

    if(!encontro)
    {
        locate(75, 9);
        cout << "INGRESE NUEVAMENTE!!!";
        locate(70, 10);
        cout << "El Legajo no figura en el sistema";
        system("pause");
    }
}

void SelectorMenu(Usuario obj)
{
    system("cls");
    locate(70, 8);
    cout << "Hola " << obj.getNombre();
    locate(70, 9);
    cout << "Yendo al menu de acuerdo a su puesto como " <<obj.getRol();
    locate(70, 10);
    system("pause");
    system("cls");

    if(strcmp(obj.getRol(), "Becado")==0)
    {
        Becado(obj);
    }
    else if(strcmp(obj.getRol(), "Docente")==0)
    {
        Docente(obj);
    }
    else if(strcmp(obj.getRol(), "Director")==0)
    {
        Director(obj);
    }
}

void Becado(Usuario obj) //Ver aulas, ver comisiones y pedir cambios
{
    int op;

    locate(70, 8);
    cout << "Bienvenido " << obj.getNombre();
    locate(70, 10);
    cout << "1. Ver las Aulas";
    locate(70, 11);
    cout << "2. Ver las Comisiones del Departamento";
    locate(70, 12);
    cout << "3. Pedir Cambios de Aulas"; //Generar arch Cambios?
    locate(70, 14);
    cout << "0. Cerrar Sesion";

    locate(70, 16);
    cout << "Ingrese una opcion: ";
    locate(90, 16);
    cin >> op;

    switch(op)
    {
        case 1:
            verAulas();
        break;
        case 2:
            verComisiones(obj.getCodDep());
        break;

        case 0:
            cout << "Volviendo al menu";
            system("pause");
            return;
    }
}

void Docente(Usuario obj) //Ver aulas, info del departamento y ver las comisiones en las que da clases
{
    int op;

    locate(70, 8);
    cout << "Bienvenido " << obj.getNombre();
    locate(70, 10);
    cout << "1. Ver las Aulas";
    locate(70, 11);
    cout << "2. Ver sus Comisiones";
    locate(70, 12);
    cout << "3. Ver informacion del Departamento";
    locate(70, 13);
    cout << "0. Cerrar Sesion";
    locate(70, 16);
    cout << "Ingrese una opcion: ";
    locate(90, 16);
    cin >> op;

    switch(op)
    {
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
            cout << "Volviendo al menu";
            system("pause");
            return;
    }
}

void Director(Usuario obj) //Ver Aulas, ver comisiones, dar de alta y baja a becados
{
    int op;

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
    cout << "Ingrese una opcion: ";
    locate(90, 16);
    cin >> op;

    switch(op)
    {
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
            cout << "Volviendo al menu";
            system("pause");
            return;
    }
}

void IngresoAdmin()
{
    Administrador obj;
    ArchAdm archA;
    char contrasenia[30];

    system("cls");
    locate(72, 4);
    cout << "Ingresando al SysadAulas";
    locate(71, 6);
    cout << "contrasenia: ";
    locate(84, 6);
    cargarCadena(contrasenia, 29);

    int tam = archA.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = archA.leerRegistro(i);
        if(strcmp(obj.getConstrasenia(), contrasenia) == 0)
        {
            locate(70, 8);
            cout << "Hola " << obj.getNombre();
            locate(70, 9);
            cout << "Yendo al menu de administrador ";
            Admin(obj);
        }
    }
}

void Admin(Administrador obj) //Ver comisiones, confirmar cambios, dar de alta, baja y ver aulas
{
    int opcion;
    while(true)
    {
        system("pause");
        system("cls");
        locate(70, 8);
        cout << "Bienvenido " << obj.getNombre();
        locate(70, 10);
        cout << "1. Ver/Modificar las Aulas"; //Modificar = hacer/Confirmar cambios, dar de baja y alta
        locate(70, 11);
        cout << "2. Ver las todas las Comisiones";
        locate(70, 12);
        cout << "3. Dar de baja a Usuarios";
        locate(70, 13);
        cout << "4. Dar de alta a Usuarios";
        locate(70, 15);
        cout << "0. Cerrar Sesion";
        locate(70, 17);
        cout << "Ingrese la opcion: ";
        locate(78, 15);
        cin >> opcion;

        switch(opcion)
        {
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
            cout << "Volviendo al menu";
            system("pause");
            return;
        }
    }
}

#endif // PAGINAS_MENUS_H_INCLUDED
