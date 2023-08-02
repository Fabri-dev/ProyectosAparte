#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"
#define MAXSTRING 30

int verificarOpcionUsuario(int dato)
{
    if(dato == 1 || dato == 2)
    {
        return 0;
    }

    puts("Por favor ingrese una opcion valida");
    return 1;

}


int verificarSoloLetrasEnString(char dato[])
{
    int flag=0, i=0;

    while(i<strlen(dato))
    {
        if(isalpha(dato[i])==0)
        {
            flag= 1;
        }
        i++;
    }
    if(flag==1)
    {
        puts("Error: Ingrese solo letras por favor");
    }
    return flag;
}

int verficarDNI(int dato)
{
    int flag=0;
    int menorEdad=47000000;

    if(dato > menorEdad)
    {
        puts("Por favor ingrese un DNI mayor de 18 anios");
        flag=1;
    }

    return flag;
}

int verificarClave(char dato[])
{
    int flag=0, maxClave=5;

    if(strlen(dato) != maxClave)
    {
        puts("Por favor ingrese una clave de 5 digitos obligatorio");
        flag=1;
    }
    return flag;
}

