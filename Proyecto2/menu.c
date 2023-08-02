#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"
#define MAXDIMSTR 40


void menuPrincipal(char archivoDatosPersonales[], char archivoEmpleados[])
{
    char op='s';
    int opsw=0;

    do
    {
        elegirOpciones();

        opsw=preguntarDato();
        switch(opsw)
        {
        case 1:
            cargarArchivoDatosPersonales(archivoDatosPersonales);
            break;
        case 2:
            cargarArchivoEmpleado(archivoEmpleados,archivoDatosPersonales);
            break;
        case 3:
            elegirQueMostrar(archivoEmpleados,archivoDatosPersonales);
            break;
        case 4:
            break;
        case 5:
            break;
        }

        printf("Desea seguir navegando? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();
    }
    while(op=='s');
}


void elegirQueMostrar(char archivoEmpleados[], char archivoDatosPersonales[])
{
    char op='s',datoString[MAXDIMSTR];
    int opsw=0,flag=0, dato=0;
    do
    {
        opcionesDeMostrar();
        opsw=preguntarDato();

             switch(opsw)
        {
        case 1:
            flag=0;
            mostrarEmpleados(archivoEmpleados);
            break;
        case 2:

            do
            {
                mostrarPuestos();
                printf("que puesto quiere mostrar?: ");
                dato=preguntarDato();
            }while(validarMostrarPuestos(dato)==1);

            elegirQuePuestoMostrar(archivoEmpleados,dato);
            flag=0;
            break;
        case 3:

            do
            {
                printf("Que edad quiere mostrar?: ");
                dato=preguntarDato();
            }while(validarEdad(dato));
            mostrarEmpleadoXedad(archivoEmpleados,dato);
            flag=0;
            break;
        case 4:
            do
            {
                printf("Que pais quiere mostrar?: ");
                fflush(stdin);
                gets(datoString);
            }while(validarPais(datoString)==0);

            mostrarEmpleadosXnacionalidad(archivoEmpleados,datoString);

            flag=0;

            break;
        case 5:
            flag=1;
            op='n';
            break;
        default:
            puts("Ingrese un dato correcto");
            break;
        }

        if (flag == 0)
        {
            puts("Desea seguir mostrando empleados? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }
            limpiarPantalla();


    }
    while(op=='s');

}

int validarMostrarPuestos(int dato)
{
    int flag=0;
    if (dato < 1 || dato>6)
    {
        flag=1;
        puts("Ingrese un dato correcto por favor");
    }
    return flag;

}

void opcionesDeMostrar()
{
    puts("---------------------------------------------------------");
    puts("1. Mostrar todos los empleados");
    puts("2. Mostrar empleados de un puesto en especifico");
    puts("3. Mostrar empleados de una edad especifica");
    puts("4. Mostrar empleados de una nacionalidad especifica");
    puts("5. Volver atras");
    puts("---------------------------------------------------------");
}

void elegirOpciones()
{
    puts("-----------------------------------------------------------------------------------------------");
    puts("1. Cargar archivo datos personales");
    puts("2. Cargar archivo empleados");
    puts("3. Mostrar empleados");
    puts("4. Consultar datos generales");
    puts("5. Modificar datos empleados");
    puts("---------------------------------Bienvenido, que desea hacer?---------------------------------- \n\n");
}

void elegirConsultas()
{
    puts("1.");

    // contar cuantos empleados hay
    // contar cuantos empleados de X puesto hay
    // buscar a un empleado por DNI
    // mostrar el empleado con mas salario
    // mostrar al empleado con menos salario
    // mostrar al empleado mas viejo
    // mostrar al empleado mas joven
    // mostrar al empleado que mas horas diarias hace
    // mostrar al empleado que menos horas diarias hace
    // mostrar a los empleados con un nombre especifico









}


void menuModificar(char archivoEmpleados[], char archivoDatosPersonales[])
{
    int dni=0, dato=0;
    stEmpleado aux;
    do
    {

    mostrarEmpleados(archivoEmpleados);
    puts("---------------------------------------------------");
    puts("Estos son todos los empleados, ingrese el DNI del empleado que quiere modificar");
    dni=preguntarDato();
    }while(validarSiDniExiste(dni,archivoDatosPersonales));

    aux=buscarEmpleadoXdni(archivoEmpleados,dni);

    puts("Eligio este empleado para modificar");
    mostrarUnEmpleado(aux);
    puts("---------------------------------------------------");
    mostrarOpcionesModificar();
    dato = preguntarDato();
}


void mostrarOpcionesModificar()
{
    puts("1.Modificar Nombre");
    puts("2.Modificar Apellido");
    puts("3.Modificar Nacionalidad");
    puts("4.Modificar Edad");
    puts("5.Modificar DNI");
    puts("6.Modificar Puesto");
    puts("7.Modificar Horas diarias");
    puts("9.Modificar Salario");
    puts("10.Modificar Estado");
    puts("---------------------------------------------------");
    puts("Que desea hacer?");


}





