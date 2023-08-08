#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "verificaciones.h"

void menuPrincipal(char archivoFacturas[])
{
    int opsw=0;
    puts("-------------------Bienvenido-----------------");
    puts("1. Crear una factura");
    puts("-----------------------------------------------");
    printf("Que desea hacer?: ");
    scanf("%i",&opsw);

    switch(opsw)
    {
    case 1:
        cargarFacturaArchivo(archivoFacturas);
        break;
    case 2:
        break;
    default:
        break;
    }

}


stFactura crearFactura(char archivoFacturas[])
{
    stFactura aux;

    aux.id=buscarUltimoID(archivoFacturas);

    do
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(aux.nombre);


    }while(verificarNumeroEnString(aux.nombre));

    do
    {
        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(aux.apellido);

    }while(verificarNumeroEnString(aux.apellido));

    do
    {
        printf("Ingrese el DNI: ");
        scanf("%i",&aux.dni);

    }while(verificarDni(aux.dni));


    do
    {
        printf("Ingrese el E-mail: ");
        fflush(stdin);
        gets(aux.email);

    }while(verificarEmail(aux.email) == 0);

    do
    {
        printf("Ingrese el monto pagado: ");
        scanf("%f",&aux.monto);

    }while(verificarMonto(aux.monto));


    do
    {

        printf("Ingrese la forma de pago (1- Efectivo, 2- Transferencia): ");
        scanf("%i",&aux.formaPago);

    }while(verificarFormaPago(aux.formaPago));

    do
    {
        printf("Ingrese el mes de facturacion: ");
        scanf("%i",&aux.mes);
    }while(verificarMes(aux.mes));


    return aux;
}

int buscarUltimoID(char archivoFacturas[])
{
    int id=0;

    FILE*buffer=fopen(archivoFacturas,"r");

    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stFactura),SEEK_END);
        fscanf(buffer,"-----------------VENTA: %i",&id);
        if(id == NULL)
        {
            id=0;
        }
        else
        {
            id+=1;
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return id;
}
void escribirFacturaArchivo(char archivoFacturas[], stFactura dato)
{
    FILE*buffer=fopen(archivoFacturas,"a");

    if(buffer != NULL)
    {
        fprintf(buffer,"-----------------VENTA: %i-------------------\n",dato.id);
        fprintf(buffer,"Nombre: %s\n",dato.nombre);
        fprintf(buffer,"Apellido: %s\n",dato.apellido);
        fprintf(buffer,"DNI: %i\n",dato.dni);
        fprintf(buffer,"Email: %s\n",dato.email);
        fprintf(buffer,"Monto: %.2f\n",dato.monto);
        if(dato.formaPago == 1)
        {
            fputs("Forma de Pago: Efectivo\n",buffer);
        }
        else
        {
            fputs("Forma de Pago: Transferencia\n",buffer);
        }
        fprintf(buffer,"Mes: %i\n",dato.mes);

        fputs("------------------------------------------\n",buffer);


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

void cargarFacturaArchivo(char archivoFacturas[])
{
    stFactura aux=crearFactura(archivoFacturas);
    escribirFacturaArchivo(archivoFacturas,aux);

}





