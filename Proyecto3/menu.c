#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"
#define MAXSTRING 30


void menuInicioSesion(char archivoUsuario[])
{

    int opcion=0;

    puts("------------------------------------------------");
    puts("\t\tUsuahia Bank CO.");
    puts("------------------------------------------------\n");

    puts("Ingrese una opcion:\n");
    puts("1. Crear cuenta");
    puts("2. Ingresar a cuenta\n");

    do
    {
        opcion=preguntarDatoEntero();

    }while(verificarOpcionUsuario(opcion));

    switch(opcion)
    {
    case 1:
        escribirUsuarioEnArchivo(archivoUsuario);
        break;
    case 2:
        break;
    }

}
