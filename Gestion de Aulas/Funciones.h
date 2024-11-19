#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void mostrarDepCompleto(int codigo, int x, int y), verAulas(), verComisiones(int CodDep), verComisiones(const char *nombre);
void verInfoDep(int CodDep), PedirCambios(int CodDep);
Departamento buscarDep(int Cod);

///Admin
void allComisiones(), darBaja(int legajo), darAlta(int dni);
int verificarUsuario(int dni);

void darAlta(const char *rol="Becado"), darBaja(int cod, int legajo, const char *rol);

void ComisionesAdmin()
{
    int x = 70, y = 8, Dep;

    system("cls");

    locate(x, y);cout << "Ingrese el departamento para ver sus comisiones: ";
    cin >> Dep;

    verComisiones(Dep);
}

int verificarUsuario(int dni)
{
    Usuario obj;
    ArchUsuario arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getDni() == dni)
        {
            return i;
        }
    }
    return -8;
}

void darAlta(int dni)          //  Buscar por Dni
{
    int x = 80, y = 8;

    system("cls");

    locate(x, y);cout << "Ingrese el Dni de la persona: ";
    locate(30+x, y);cin >> dni;

    int verificacion = verificarUsuario(dni);
    cout << verificacion;

    if(verificacion >= 0)
    {
        //Modificar estado y registro
        Usuario obj;
        ArchUsuario arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        obj.Mostrar();
        y += 3; setColor(1);
        locate(x, 2+y); cout << obj.getNombre() << " " << obj.getApellido() << " Existe en el sistema y fue dado de Alta exitosamente";
        setColor(0);
    }
    else{Alta_Usuarios(dni);}
    locate(x, 4+y); system("pause"); system("cls");
}

void darBaja() //buscar por Legajo
{
    int legajo, x = 70, y = 8;
    Usuario obj;
    ArchUsuario arch;

    system("cls");

    locate(x, y); cout << "Ingrese el legajo de la persona: ";
    locate(33+x, y); cin >> legajo;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getLegajo() == legajo)
        {
            obj.setEstado(false);
            arch.modificarRegistro(obj, i);
            setColor(1);
            locate(x, 1+y); cout << "Dado de Baja Correctamente" << endl;
            setColor(0);
            system("pause"); system("cls");
            return;
        }
    }
    setColor(4);
    locate(x, 2+y); cout << "No se encontro el usuario" << endl;
    setColor(0);
    locate(x, 4+y); system("pause"); system("cls");
}


void darBaja(int cod, const char *rol) //buscar por Legajo
{
    int legajo, x = 70, y = 8;
    Usuario obj;
    ArchUsuario arch;

    system("cls");

    locate(x, y); cout << "Ingrese el legajo de la persona: ";
    locate(33+x, y); cin >> legajo;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getLegajo() == legajo && obj.getCodDep() == cod && strcmp(obj.getRol(), rol) == 0)
        {
            obj.setCodDep(0);
            arch.modificarRegistro(obj, i);
            setColor(1); locate(x, 2+y); cout << "Eliminado del Departamento Correctamente"; setColor(0);
            locate(x, 4+y); system("pause"); system("cls");
            return;
        }
    }
    setColor(4);
    locate(x, 2+y); cout << "No se encontro el becado"<< endl; setColor(0);
    locate(x, 4+y); system("pause"); system("cls");
}

void darAlta(int CodDep,const char *rol)          //  Buscar por Dni
{
    int dni, x = 70, y = 8;

    system("cls");

    locate(x, y); cout << "Ingrese el Dni de la persona: ";
    locate(98, y); cin >> dni;
    cout << endl;

    int verificacion = verificarUsuario(dni);

    if(verificacion >= 0)
    {
        //Modificar estado y registro
        Usuario obj;
        ArchUsuario arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        obj.Mostrar_Persona(x, y);
        y += 5; setColor(1);
        locate(x, 1+y); cout << obj.getNombre() << " " << obj.getApellido() << " Existe en el sistema y fue dado de Alta exitosamente" << endl;
        setColor(0);
    }
    else{Alta_Usuarios(CodDep, dni, rol);}
    locate(x, 3+y); system("pause"); system("cls");
}


Departamento buscarDep(int Cod)
{
    Departamento obj, aux;
    ArchDep arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getCodigo() == Cod)
        {
            aux = obj;
            return aux;
        }
    }
    obj.setCodigo(-1);
    return obj;
}

void verInfoDep(int CodDep)
{
    Departamento obj;

    system("cls");
    obj = buscarDep(CodDep);
    if(obj.getCodigo() == -1){cout << "No se encontro";system("pause");system("cls");}
    else{obj.MostrarTodo(70, 8);}


}

void mostrarDepCompleto(int codigo, int x, int y)
{
    Usuario obj;
    ArchUsuario arch;
    Comision com;
    ArchComision archC;

    int tam = arch.contarRegistros();

    setColor(1);
    locate(x, 6); cout << "Informacion del Departamento";
    setColor(0);

    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == codigo)
        {
            locate(x, y); cout << obj.getRol() << ": " << obj.getNombre() <<endl;
            y++;
        }
    }

    tam = archC.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        com = archC.leerRegistro(i);
        if(com.getCodDep() == codigo)
        {
            locate(x, y); cout << "Comision del Departamento: " << com.getCodComision() << endl;
            y++;
        }
    }
    locate(x, 1+y); system("pause"); system("cls");
}

void verAulas()
{
    Aula obj;
    ArchAula archA;

    system("cls");
    int tam = archA.contarRegistros();
    int x = 62, y = 8;

    setColor(1);
    locate(82, 6);
    cout << "Aulas";
    setColor(0);

    for(int i=0; i<tam; i++)
    {
        obj = archA.leerRegistro(i);
        obj.Mostrar_Peticion(x, y);
        y++;
    }
    setColor(0);
    locate(x, 1+y);
    system("pause");
    system("cls");
}

void verComisiones(int CodDep)
{
    Comision comi;
    ArchComision arch;

    system("cls");
    int tam = arch.contarRegistros();
    int x = 70, y = 8;
    bool encontrado;

    setColor(1);
    locate(79, 6);
    cout << "Comisiones";
    setColor(0);

    for(int i=0; i<tam; i++)
    {
        comi = arch.leerRegistro(i);
        if(comi.getCodDep() == CodDep)
        {
            encontrado = true;
            comi.Mostrar_Becado(x, y);
            y += 5;
        }
    }
    if(!encontrado)
    {
        locate(x, y); setColor(4);
        cout << "Error, Codigo mal ingresado" << endl << endl; setColor(0);
        y += 2;
    }
    locate(x, y);
    system("pause");
    system("cls");
}

void verComisiones(const char *nombre)
{
    Comision comi;
    ArchComision arch;

    system("cls");
    int tam = arch.contarRegistros();
    int x = 70, y = 8;

    setColor(1);
    locate(79, 6);
    cout << "Comisiones";
    setColor(0);

    for(int i=0; i<tam; i++)
    {
        comi = arch.leerRegistro(i);
        if(strcmp(comi.getProfe(), nombre)==0)
        {
            comi.Mostrar_Docente(x, y);
            y += 5;
        }
    }
    locate(x, y);
    system("pause");
    system("cls");
}

Comision verficarComision(int CodDep, int CodComi)
{
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == CodDep && obj.getCodComision() == CodComi)
        {
            return obj;
        }
    }
    obj.setNumero(-9);
    return obj;
}

int contarAulas()
{
    Aula obj;
    ArchAula arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getDisponibilidad() && obj.getEstado())
        {
            contador++;
        }
    }
    return contador;
}

bool verificar_Peticion(Aula *Vec, int tam, const char *aula, int capacidad)
{
    for(int i=0; i<tam; i++)
    {
        if(strcmp(Vec[i].getNombre(), aula) == 0)
        {
            if(Vec[i].getCapacidad() >= capacidad)
            {
                return true;
            }
        }
    }
    return false;
}

void cargar_Aulas_Disponibles(Aula *Vec)
{
    Aula aux;
    ArchAula arch;

    int tam = arch.contarRegistros(), espacio = 0;
    for(int i=0; i<tam; i++)
    {
        aux = arch.leerRegistro(i);
        if(aux.getDisponibilidad() && aux.getEstado())
        {
            Vec[espacio] = aux;
            espacio++;
        }
    }
}

void Mostrar_Aulas(Aula *V, int tam)
{
    for(int i=0; i<tam; i++)
    {
        V[i].Mostrar_Peticion();
    }
}

int contarComisiones(int CodDep)
{
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getEstado() && obj.getCodDep() == CodDep)
        {
            contador++;
        }
    }
    return contador;
}

void cargarComisiones(Comision *v, int Cod)
{
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros(), contador = 0;
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getEstado() && obj.getCodDep() == Cod)
        {
            v[contador] = obj;
            contador++;
        }
    }
}


void mostrarComisiones(Comision *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        v[i].Mostrar();
    }
}


void PedirCambios(int CodDep)
{
    Comision *vComi;
    char op[3];
    int codigo, x = 70, y = 6;

    system("cls");

    // Mostrar e Ingresar comision elegida
    int contComi = contarComisiones(CodDep);
    vComi = new Comision[contComi];
    if(vComi == NULL){exit(-1);}
    cargarComisiones(vComi, CodDep);
    mostrarComisiones(vComi, contComi);

    cout << endl <<"Ingrese la comision que quiera cambiar de aula: "; cin >> codigo;
    Comision obj = verficarComision(CodDep, codigo);
    if(obj.getNumero() < 0){cout << "no existe"; delete []vComi; system("pause"); system("cls"); return;}

    setColor(1); cout << endl<<  "la comision elegida" << endl; setColor(0);
    obj.Mostrar_Becado();
    cout << endl << "Desea continuar? (si/no): ";
    cargarCadena(op, 2);
    if(strcmp(op, "no") == 0){setColor(4); cout << endl << "saliendo al menu"; setColor(0); delete []vComi; system("pause"); system("cls"); return;}

    // Mostrar e Ingresar el aula disponible
    Aula *vAulas;

    cout << endl;

    int aulasDisponibles = contarAulas();
    vAulas = new Aula[aulasDisponibles];
    if(vAulas == NULL){exit (-2);}
    cargar_Aulas_Disponibles(vAulas);
    Mostrar_Aulas(vAulas, aulasDisponibles);

    char aula[5];
    cout << "Ingrese el aula: ";
    cargarCadena(aula, 4);

    bool verificado = verificar_Peticion(vAulas, aulasDisponibles, aula, obj.getCantidad());
    delete []vAulas;

    // CargarPeticion (Getters) y ArchivoPeticion
    if(verificado)
    {
        setColor(1); cout << endl << "Se dio de alta correctamente" << endl;
        Alta_Peticion(obj, aula);
        cout << endl << "Cargado y enviado al administrador" << endl; setColor(0);
    }
    else
    {
        setColor(4); cout << "No esta disponible" << endl;setColor(0);
    }
    delete []vComi;
    system("pause"); system("cls");
}

void Historial(int codDep)
{
    Peticion obj;
    ArchPeticion arch;

    system("cls");

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getCodDep() == codDep)
        {
            obj.Mostrar();
        }
    }
}

void Asignacion_Baja(const char *nombre)
{
    Comision objC;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        objC = arch.leerRegistro(i);
        if(strcmp(objC.getAula(), nombre) == 0)
        {
            objC.setAula("S/A");
            arch.modificarRegistro(objC, i);
            return;
        }
    }
}

void darBajaAulas()
{
    char nombre[5];
    int x = 70, y = 8;
    Aula obj;
    ArchAula arch;

    system("cls");

    locate(x, y); cout << "Ingrese el nombre del aula: ";
    locate(28+x, y); cargarCadena(nombre, 4);

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(strcmp(obj.getNombre(), nombre) == 0)
        {
            if(obj.getEstado())
            {
                obj.setEstado(false);
                arch.modificarRegistro(obj, i);
                Asignacion_Baja(obj.getNombre());
                setColor(1);locate(x, 2+y); cout << "Aula dada de baja Correctamente"; setColor(0);
                locate(x, 4+y); system("pause"); system("cls");
                return;
            }
            else
            {
                setColor(1); locate(x, 2+y); cout << "Ya fue dada de baja" << endl; setColor(0);
                locate(x, 4+y); system("pause"); system("cls");
                return;
            }
        }
    }
    setColor(4);locate(x, 2+y); cout << "No se encontro el aula"; setColor(0);
    locate(x, 4+y); system("pause"); system("cls");
}

int verificarAulas(char *nombre)
{
    Aula obj;
    ArchAula arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(strcmp(obj.getNombre(), nombre) == 0)
        {
            return i;
        }
    }
    return -8;
}

int contarPeticiones()
{
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros(), cont = 0;
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(!obj.getVisto())
        {
            cont++;
        }
    }
    return cont;
}

void CargarPeticiones(Peticion *v)
{
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros(), cont = 0;
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(!obj.getVisto())
        {
            v[cont] = obj;
            cont++;
        }
    }
}

void cambiarAulas(Peticion pet)
{
    Comision obj;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getCodComision() == pet.getCodComi())
        {
            obj.setAula(pet.getPedida());
            arch.modificarRegistro(obj, i);
        }
    }

    Aula objA;
    ArchAula archA;

    tam = archA.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        objA = archA.leerRegistro(i);
        if(strcmp(objA.getNombre(), pet.getAsignada()) == 0)
        {
            objA.setDisponibilidad(true);
            archA.modificarRegistro(objA, i);
        }

        if(strcmp(objA.getNombre(), pet.getPedida()) == 0)
        {
            objA.setDisponibilidad(false);
            archA.modificarRegistro(objA, i);
        }
    }
}

void modificarArchPeticion(Peticion aux)
{
    Peticion obj;
    ArchPeticion arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        obj = arch.leerRegistro(i);
        if(obj.getNumero() == aux.getNumero())
        {
            obj.setEstado(true);
            arch.modificarRegistro(aux, i);
        }
    }
}


void verPeticiones()
{
    system("cls");
    int x = 70, y = 8;

    locate(72, 6); setColor(1); cout << "Peticiones"; setColor(0);

    int tam = contarPeticiones();

    if(tam == 0){locate(x, y); cout << "No hay peticiones pendientes"; locate(x, 2+y); system("pause"); system("cls"); return;}

    Peticion *vPendientes;
    vPendientes = new Peticion[tam];
    if(vPendientes == NULL){exit(-1);}
    CargarPeticiones(vPendientes);

    char op[3];

    for(int i=0; i<tam; i++)
    {
        system("cls");
        vPendientes[i].Mostrar_Peticion();
        cargarCadena(op, 2);
        vPendientes[i].setRespuesta(op);

        if(strcmp(op, "si") == 0) { cambiarAulas(vPendientes[i]); }
        vPendientes[i].setVisto(true);
        modificarArchPeticion(vPendientes[i]);

        system("pause");
    }

    delete []vPendientes;
    system("pause"); system("cls");
}

void Asignacion_Alta(const char *nombre)
{
    Comision objC;
    ArchComision arch;

    int tam = arch.contarRegistros();
    for(int i=0; i<tam; i++)
    {
        objC = arch.leerRegistro(i);
        if(strcmp(objC.getAula(), "S/A") == 0)
        {
            objC.setAula(nombre);
            arch.modificarRegistro(objC, i);
            return;
        }
    }
}

void darAltaAulas()
{
    char nombre[5];
    int x = 70, y = 6;

    system("cls");

    locate(x, y);cout << "Ingrese el nombre del Aula: ";
    locate(28+x, y); cargarCadena(nombre, 4);
    cout << endl;

    int verificacion = verificarAulas(nombre);

    if(verificacion >= 0)
    {
        Aula obj;
        ArchAula arch;

        obj = arch.leerRegistro(verificacion);
        obj.setEstado(true);
        arch.modificarRegistro(obj, verificacion);
        Asignacion_Alta(obj.getNombre());
        locate(x, 2+y);
        setColor(1); cout << "El aula "<< obj.getNombre() << " Existe en el sistema y fue dado de Alta exitosamente";
        setColor(0); locate(x, 4+y);
    }
    else
    {
        char op[2];
        locate(x, 2+y); cout << "No existe en el sistema";
        locate(x, 4+y); cout << "Desea cargar un aula nueva?";
        locate(x, 6+y); cargarCadena(op, 1);
        if(strcpy(op, "si") == 0)
        {
            Alta_Aulas(nombre);
        }
    }
    system("pause"); system("cls");
}



#endif // FUNCIONES_H_INCLUDED
