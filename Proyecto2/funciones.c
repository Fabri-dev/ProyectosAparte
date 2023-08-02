#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#define MAXDIMSTR 40

const char* paises[] =
{
    "Afganistan",
    "Albania",
    "Alemania",
    "Andorra",
    "Angola",
    "Antigua y Barbuda",
    "Arabia Saudita",
    "Argelia",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaiyan",
    "Bahamas",
    "Banglades",
    "Barbados",
    "Barein",
    "Belgica",
    "Belice",
    "Benin",
    "Bielorrusia",
    "Birmania",
    "Bolivia",
    "Bosnia",
    "Botsuana",
    "Brasil",
    "Brunei",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Butan",
    "Cabo Verde",
    "Camboya",
    "Camerun",
    "Canada",
    "Catar",
    "Chad",
    "Chile",
    "China",
    "Chipre",
    "Vaticano",
    "Colombia",
    "Comoras",
    "Corea del Norte",
    "Corea del Sur",
    "Costa de Marfil",
    "Costa Rica",
    "Croacia",
    "Cuba",
    "Dinamarca",
    "Dominica",
    "Ecuador",
    "Egipto",
    "El Salvador",
    "Emiratos Arabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "España",
    "Estados Unidos",
    "Estonia",
    "Eswatini",
    "Etiopia",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gabon",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea-Bisau",
    "Guinea Ecuatorial",
    "Guyana",
    "Haiti",
    "Honduras",
    "Hungria",
    "India",
    "Indonesia",
    "Irak",
    "Iran",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salomon",
    "Israel",
    "Italia",
    "Jamaica",
    "Japon",
    "Jordania",
    "Kazajistan",
    "Kenia",
    "Kirguistan",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "Libano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Mali",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "México",
    "Micronesia",
    "Moldavia",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Oman",
    "Paises Bajos",
    "Pakistan",
    "Palaos",
    "Panama",
    "Papua Nueva Guinea",
    "Paraguay",
    "Peru",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "Republica Centroafricana",
    "Republica Checa",
    "Republica Democrática del Congo",
    "Republica Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Cristobal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Lucia",
    "Santo Tome y Príncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sudafrica",
    "Sudan",
    "Sudan del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikistan",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "Tunez",
    "Turkmenistan",
    "Turquia",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Yibuti",
    "Zambia",
    "Zimbabue"
};

// crear datos personales

stPersona datosPersonales()
{
    stPersona aux;

    do
    {
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(aux.nombre);

    }
    while(validarNombreyApellido(aux.nombre));

    do
    {

        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(aux.apellido);

    }
    while(validarNombreyApellido(aux.apellido));


    do
    {
        printf("Ingrese su nacionalidad: ");
        fflush(stdin);
        gets(aux.nacionalidad);
    }
    while(validarPais(aux.nacionalidad)==0);

    do
    {
        printf("Ingrese su edad: ");
        fflush(stdin);
        scanf("%i",&aux.edad);
    }
    while(validarEdad(aux.edad)==1);

    do
    {
        printf("Ingrese su DNI: ");
        scanf("%i",&aux.DNI);
    }
    while(validarDNI(aux.DNI)==1);

    limpiarPantalla();

    return aux;
}

int validarNombreyApellido(char dato[])
{
    int flag=0;

    if(strlen(dato) < 3 || strlen(dato) > 20)
    {
        puts("ERROR: Ingrese una palabra valida por favor(entre 3 y 40 letras)");
        flag=1;
    }


    return flag;
}

int validarPais(char dato[])
{
    int cantPaises= 192,i=0,flag=0;

    while(i < cantPaises && flag==0)
    {

        if(strcmpi(dato,paises[i])==0)
        {
            flag = 1;

        }
        i++;

    }
    if(flag==0)
    {
        puts("Ingrese un pais valido");
    }

    return flag;
}

int validarEdad(int dato)
{
    int flag=0, mayor=65,menor=18;

    if(dato < menor || dato > mayor)
    {
        flag = 1;
        puts("Ingrese una edad valida (entre 18 y 65)");
    }


    return flag;
}

int validarDNI(int dato)
{
    int menor=47000000,mayor=20000000,flag=0;

    if(dato < mayor)
    {
        flag=1;
        puts("Ingrese un DNI valido que no sea mayor de edad");
    }
    else if(dato>menor)
    {
        flag=1;
        puts("Ingrese un DNI valido que no sea menor de edad");
    }


    return flag;

}

// cargar archivo datos personales
void cargarArchivoDatosPersonales(char archivo[])
{
    char op='s';

    stPersona aux;

    FILE* buffer= fopen(archivo,"ab");
    if(buffer != NULL)
    {
        do
        {
            aux=datosPersonales();
            fwrite(&aux,sizeof(stPersona),1,buffer);

            printf("Desea seguir ingresando mas datos personales? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }
        while(op=='s');

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}

//Buscar datos personales por dni

stPersona buscarDatosPersonalesXDNI(int DNI,char archivoDatosPersonales[])
{
    stPersona aux;
    int flag=0;
    FILE* buffer=fopen(archivoDatosPersonales,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stPersona),1,buffer)>0 && flag == 0)
        {
            if(aux.DNI == DNI)
            {
                flag =1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return aux;
}


//preguntar dato
int preguntarDato()
{
    int dato=0;

    printf("Ingrese un dato: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

//limpiar pantalla
void limpiarPantalla()
{
    system("cls");
}

//verificar si existe el DNI

int validarSiDniExiste(int dato,char archivoP[])
{
    int flag=0;
    stPersona aux;
    FILE* buffer= fopen(archivoP,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stPersona),1,buffer) >0)
        {
            if (dato == aux.DNI)
            {
                flag = 1;
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    if(flag == 0)
    {
        puts("Porfavor Ingrese un DNI valido");
    }
    return flag;
}

//validar horas diarias
int validarHorasDiarias(int dato)
{
    int flag=0;

    if(dato >=12 || dato < 2)
    {
        flag = 1;
        puts("Ingrese un horario valido (entre 2 y 12)");
    }

    return flag;
}

void mostrarPuestos()
{
    puts("1. Recursos Humanos");
    puts("2. Gerente");
    puts("3. Entrenador");
    puts("4. Crew");
    puts("5. Mantenimiento");
    puts("6. Limpieza");
}

//validar cargo

int validarPuesto(int dato, char cargo[])
{
    int flag=0;
    switch(dato)
    {
    case 1:
        strcpy(cargo,"Recursos Humanos");
        flag=0;
        break;
    case 2:
        strcpy(cargo,"Gerente");
        flag=0;
        break;
    case 3:
        strcpy(cargo,"Entrenador");
        flag=0;
        break;
    case 4:
        strcpy(cargo,"Crew");
        flag=0;
        break;
    case 5:
        strcpy(cargo,"Mantenimiento");
        flag=0;
        break;
    case 6:
        strcpy(cargo,"Limpieza");
        flag=0;
        break;
    default:
        puts("Ingrese un cargo valido");
        flag=1;
        break;
    }
    return flag;
}

//validar salario
int validarSalario(float dato)
{
    int minimo=1000,maximo=600000, flag=0;
    if(dato < minimo || dato>maximo)
    {
        puts("Ingrese un salario correspondiente");
        flag=1;
    }

    return flag;
}

//Alta empleado

stEmpleado cargarUnEmpleado(char archivoDatosPersonales[])
{
    stEmpleado aux;
    int dato=0;

    aux.estado=1;

    do
    {
        printf("Ingrese el DNI para buscar los datos personales del empleado en la base de datos: ");
        scanf("%i",&aux.datosPersonales.DNI);

    }
    while(validarSiDniExiste(aux.datosPersonales.DNI,archivoDatosPersonales)==0);
    puts("DNI encontrado, siga cargando los datos pedidos.");
    aux.datosPersonales=buscarDatosPersonalesXDNI(aux.datosPersonales.DNI,archivoDatosPersonales);

    do
    {
        printf("Cuantas horas diarias hara el empleado?: ");
        scanf("%i",&aux.horasDiarias);
    }
    while(validarHorasDiarias(aux.horasDiarias));

    do
    {
        mostrarPuestos();
        puts("Ingrese el puesto del empleado");
        dato=preguntarDato();
    }
    while(validarPuesto(dato,aux.puesto));

    do
    {
        printf("Ingrese el salario: ");
        scanf("%f",&aux.salario);
    }
    while(validarSalario(aux.salario));

    return aux;
}

//cargar Empleado a archivo

void cargarArchivoEmpleado(char archivoEmp[],char archivoDatosPersonales[])
{
    stEmpleado aux;

    char op='s';

    FILE* buffer=fopen(archivoEmp,"ab");

    if(buffer != NULL)
    {
        while(op=='s')
        {
            aux=cargarUnEmpleado(archivoDatosPersonales);
            fwrite(&aux,sizeof(stEmpleado),1,buffer);

            printf("Quiere seguir cargando empleados? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
            limpiarPantalla();
        }


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }




}


//mostrar un empleado

void mostrarUnEmpleado(stEmpleado aux)
{
    puts("\n----------------DATOS PERSONALES---------------");
    printf(" Nombre..............: %s \n",aux.datosPersonales.nombre );
    printf(" Apellido............: %s \n",aux.datosPersonales.apellido );
    printf(" DNI.................: %i \n",aux.datosPersonales.DNI );
    printf(" Edad................: %i \n",aux.datosPersonales.edad );
    printf(" Nacionalidad........: %s \n",aux.datosPersonales.nacionalidad );

    puts("\n---------------------DATOS EMPLEADO----------------");
    printf(" Puesto..............: %s \n",aux.puesto);
    printf(" Salario.............: %.2f\n",aux.salario );
    printf(" Horas Diarias.......: %i \n",aux.horasDiarias );
    printf(" Estado..............: %i \n",aux.estado);

}



//mostrar empleados
void mostrarEmpleados(char archivoEmpleados[])
{
    stEmpleado aux;
    FILE* buffer=fopen(archivoEmpleados,"rb");
    while(fread(&aux,sizeof(stEmpleado),1,buffer)> 0)
    {
        mostrarUnEmpleado(aux);
    }

}


//mostrar empleados de un puesto especifico

void mostrarEmpleadosXpuesto(char archivoEmpleados[], char puesto[])
{
    stEmpleado aux;
    int flag=0;
    FILE* buffer=fopen(archivoEmpleados,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stEmpleado),1,buffer)>0)
        {
            if(strcmpi(aux.puesto,puesto) == 0)
            {
                flag=1;
                mostrarUnEmpleado(aux);
            }
        }


        fclose(buffer);
    }
    else
    {
        puts("error con el archivo");
    }

    if (flag==1)
    {
        puts("No hay empleados con ese puesto");
    }

}

void elegirQuePuestoMostrar(char archivoEmpleados[], int dato)
{
    switch(dato)
    {
    case 1:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Recursos Humanos");
        break;
    case 2:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Gerente");
        break;
    case 3:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Entrenador");
        break;
    case 4:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Crew");
        break;
    case 5:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Mantenimiento");
        break;
    case 6:
        mostrarEmpleadosXpuesto(archivoEmpleados,"Limpieza");
        break;
    default:
        printf("error");
        break;

    }

}

void mostrarEmpleadoXedad(char archiEmpleados[], int dato)
{
    stEmpleado aux;
    int flag=0;
    FILE* buffer=fopen(archiEmpleados,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stEmpleado),1,buffer)>0)
        {
            if(aux.datosPersonales.edad == dato)
            {
                flag=1;
                mostrarUnEmpleado(aux);
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    if(flag==0)
    {
        puts("No hay empleados de esa nacionalidad");
    }

}

void mostrarEmpleadosXnacionalidad(char archiEmpleados[], char nacionalidad[])
{
    stEmpleado aux;
    int flag=0;

    FILE* buffer=fopen(archiEmpleados,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stEmpleado),1,buffer)>0)
        {
            if(strcmpi(aux.datosPersonales.nacionalidad,nacionalidad)==0)
            {
                flag=1;
                mostrarUnEmpleado(aux);
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    if(flag==0)
    {
        puts("No hay empleados de esa nacionalidad");
    }

}

//buscar empleado por DNI

stEmpleado buscarEmpleadoXdni(char archivoEmpleados[], int dni)
{
    stEmpleado aux;
    int flag=0;
    FILE* buffer=fopen(archivoEmpleados,"rb");

    if(buffer!=NULL)
    {
        while(fread(&aux,sizeof(stEmpleado),1,buffer)>0 && flag==0)
        {
            if(aux.datosPersonales.DNI == dni)
            {
                flag = 1;
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


    return aux;

}


//Consultar datos generales







