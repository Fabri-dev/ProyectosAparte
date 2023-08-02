#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"
#define MAXSTRING 30




int main()
{
    char archivoUsuarios[]="Usuarios";
    char archivoMovimientos[]="Movimientos";



    menuInicioSesion(archivoUsuarios);

    return 0;
}
