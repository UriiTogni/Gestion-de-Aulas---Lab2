#include <iostream>
#include "rlutil.h"
#include <cstring>
#include <ctime>
#include <windows.h>

using namespace std;
using namespace rlutil;

#include "Declaraciones.h"
#include "clsDias.h"
#include "Cadena.h"
#include "clsAula.h"
#include "clsPersona.h"
#include "clsUsuario.h"
#include "clsAdministrador.h"
#include "clsComision.h"
#include "clsDepartamento.h"
#include "Funciones.h"
#include "Paginas_Menus.h"


/**

Ingreso();              ///LOGUEO USUARIO
IngresoAdmin();         ///LOGUEO ADMIN

**/

int main()
{
    IngresoAdmin();
    //Ingreso();

    return 0;
}
