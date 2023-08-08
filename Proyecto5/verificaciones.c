#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "verificaciones.h"

int verificarNumeroEnString(char dato[])
{
    int max=strlen(dato),flag=0;
    for(int i=0; i < max; i++)
    {
        if(isalpha(dato[i])==0)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        puts("Por favor ingrese un nombre valido");
    }
    return flag;
}

int verificarDni(int dato)
{
    int min=10000000,flag=0;
    if(dato < min)
    {
        puts("Por favor ingrese un DNI valido");
        flag=1;
    }

    return flag;
}


int verificarEmail(char mail[])
{
    int flag=0,max=strlen(mail);

    for(int i=0;i <= max; i++)
    {
        if(mail[i]== '@')
        {
            flag=1;
        }
    }
    if (flag==0)
    {
        puts("Por favor ingrese una direccion email correcta");
    }
    return flag;
}

int verificarMonto(float dato)
{
    int min=10,flag=0;

    if(dato < min)
    {
        puts("Por favor ingrese un monto valido");
        flag=1;
    }
    return flag;
}

int verificarFormaPago(int dato)
{
    int flag=0;
    switch(dato)
    {
    case 1:
        flag=0;
        break;
    case 2:
        flag=0;
        break;
    default:
        puts("Por favor ingrese una forma de pago correcta");
        flag=1;
        break;
    }
    return flag;
}

int verificarMes(int dato)
{
    int flag=0, min=1,max=12;
    if(dato<min || dato>max)
    {
        puts("Por favor ingrese un mes correcto");
        flag=1;
    }
    return flag;
}
