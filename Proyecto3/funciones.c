#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"
#define MAXSTRING 30

int preguntarDatoEntero()
{
    int dato=0;

    printf("Ingrese un dato: ");
    scanf("%i",&dato);

    return dato;
}

void limpiarPantalla()
{
    system("cls");
}


stUsuario crearUsuario(char archivoUsuarios[])
{
    stUsuario aux;

    do
    {
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(aux.nombre);

    }while(verificarSoloLetrasEnString(aux.nombre));

    do
    {
        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(aux.apellido);

    }while(verificarSoloLetrasEnString(aux.apellido));



    do
    {
        printf("Ingrese su DNI: ");
        scanf("%i",&aux.DNI);

    }while(verficarDNI(aux.DNI));


    do
    {
        printf("Ingrese su clave/Pin (5 digitos):");
        fflush(stdin);
        gets(aux.clave);

    }while(verificarClave(aux.clave));

    aux.estado=1;
    aux.saldo=0;
    aux.cbu=obtenerUltimoCBU(archivoUsuarios);


    return aux;
}


int obtenerUltimoCBU(char archivoUsuarios[])
{
    stUsuario aux;
    int ultimoCbu=0;
    FILE *buffer=fopen(archivoUsuarios,"rb");

    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stUsuario),SEEK_END);

        fread(&aux,sizeof(stUsuario),1,buffer);

        ultimoCbu=aux.cbu;

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return ultimoCbu;
}

void escribirUsuarioEnArchivo(char archivoUsuarios[])
{
    stUsuario aux;

    FILE*buffer=fopen(archivoUsuarios,"ab");

    if(buffer != NULL)
    {
        aux=crearUsuario(archivoUsuarios);

        fwrite(&aux,sizeof(stUsuario),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}


void ingresoACuenta(char archivoUsuario[], char archivoMovimientos[])
{


}


