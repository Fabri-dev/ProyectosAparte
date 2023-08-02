#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



void menuPrincipal(char archivoTareas[])
{
    int opsw=0,flag=0;
    char op;
    do
    {



    puts("------------------------------------");
    puts("Gestor de Tareas");
    puts("------------------------------------\n");
    puts("1. Agregar tarea");
    puts("2. Editar ");
    puts("3. Visualizar ");
    puts("4. Salir \n");
    printf("Elija una opcion: ");
    scanf("%i",&opsw);

    switch(opsw)
    {
    case 1:
        flag=0;
        guardarTareaArchivo(archivoTareas);
        break;
    case 2:
        flag=0;
        menuEditarTarea(archivoTareas);
        break;
    case 3:
        flag=0;
        menuMostrarTareas(archivoTareas);
        break;
    case 4:
        flag=-1;
        break;
    default:
        flag=1;
        limpiarPantalla();
        puts("Por favor ingrese una opcion valida");
        break;
    }

    if(flag ==0)
    {

        printf("\nDesea seguir navegando por el menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();
    }


    }while(op=='s' || op=='S' || flag==1);

    puts("Adios.");

}
void limpiarPantalla()
{
    system("cls");
}

stTarea crearTarea(char archivoTareas[])
{
    stTarea aux;



    printf("Ingrese la tarea que quiere fijar (Maximo 100 caracteres): ");
    fflush(stdin);
    gets(aux.contenido);

    strcat(aux.contenido,".");


    aux.estado=1;

    aux.id=buscarUltimaID(archivoTareas);


    return aux;
}

int buscarUltimaID(char archivoTareas[])
{
    int cant=contarTareas(archivoTareas);
    int id=0;

    if(cant == 1)
    {
        id=1;
    }
    else
    {
        id=cant;
    }

    return id;
}

int contarTareas(char archivoTareas[])
{
    int cant=0;
    FILE* buffer=fopen(archivoTareas,"rb");

    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stTarea),SEEK_END);
        cant= ftell(buffer)/sizeof(stTarea);


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cant;
}

void guardarTareaArchivo(char archivoTareas[])
{
    stTarea aux;

    FILE*buffer=fopen(archivoTareas,"ab");

    if(buffer!= NULL)
    {
        aux= crearTarea(archivoTareas);


        fwrite(&aux,sizeof(stTarea),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}


void mostrarTarea(stTarea aux)
{
    puts("------------------------------------------------------");
    printf("  ID: %i\n",aux.id);
    mostrarEstado(aux.estado);
    printf("\n\n  Tarea: -%s\n",aux.contenido);
    puts("------------------------------------------------------");

}

void mostrarEstado(int estado)
{
    printf("\t\t\t\t Estado: ");
    switch(estado)
    {
    case 0:
        printf("Eliminada");
        break;
    case 1:
        printf("Pendiente");
        break;
    case 2:
        printf("Terminada");
        break;
    default:
        puts("Error");
        break;
    }
}

void menuMostrarTareas(char archivoTareas[])
{
    int opsw=0,flag=0;
    char op;
    do
    {

    puts("Visualizar Tareas");
    puts("------------------------------------");
    puts("1. Pendientes(Activas)");
    puts("2. Terminadas");
    puts("3. Todas");
    puts("4. Eliminadas");
    puts("5. Volver atras");
    puts("------------------------------------");
    printf("Ingrese una opcion: ");
    scanf("%i",&opsw);

    switch(opsw)
    {
    case 1:
        flag=0;
        mostrarTareasSegunEstado(archivoTareas,1);
        break;
    case 2:
        flag=0;
        mostrarTareasSegunEstado(archivoTareas,2);
        break;
    case 3:
        flag=0;
        mostrarTodasLasTareas(archivoTareas);
        break;
    case 4:
        flag=0;
        mostrarTareasSegunEstado(archivoTareas,0);
        break;
    case 5:
        flag=3;
        break;
    default:
        flag=1;
        limpiarPantalla();
        puts("Ingrese una opcion correcta");
        break;
    }

    if(flag==0)
    {

    puts("Desea seguir mostrando tareas? s/n: ");
    fflush(stdin);
    scanf("%c",&op);
    limpiarPantalla();
    }
    }while(flag==1 || op=='s');

}

void mostrarTodasLasTareas(char archivoTareas[])
{
    stTarea aux;
    FILE *buffer=fopen(archivoTareas,"rb");

    if(buffer!= NULL)
    {
        while(fread(&aux,sizeof(stTarea),1,buffer)>0)
        {

            mostrarTarea(aux);
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}

int contarTareasSegunEstado(char archivoTareas[],int estado)
{
    stTarea aux;
    int cant=0;
    FILE*buffer= fopen(archivoTareas,"rb");

    if(buffer!= NULL)
    {
        while(fread(&aux,sizeof(stTarea),1,buffer)>0)
        {

            if(aux.estado==estado)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cant;
}

void mostrarTareasSegunEstado(char archivoTareas[], int estado)
{
    stTarea aux;

    int cant= contarTareasSegunEstado(archivoTareas,estado);

    if(cant != 0)
    {
        FILE*buffer= fopen(archivoTareas,"rb");
        if(buffer!= NULL)
        {
            while(fread(&aux,sizeof(stTarea),1,buffer)>0)
            {

                if(aux.estado==estado)
                {
                    mostrarTarea(aux);
                }
            }
            fclose(buffer);
        }
        else
        {
            puts("Error con el archivo");
        }

    }
    else
    {
        puts("No hay ninguna tarea con ese estado");
    }




}

int verificarExistenciaXID(int id,char archivoTareas[])
{
    stTarea aux;
    int flag=0;
    FILE*buffer=fopen(archivoTareas,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stTarea),1,buffer)>0)
        {
            if(aux.id == id)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return flag;
}

stTarea retornarTareaXID(char archivoTareas[],int id)
{
    stTarea aux;
    int flag=0;
    FILE*buffer=fopen(archivoTareas,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stTarea),1,buffer) >0 && flag==0)
        {
            if(aux.id == id)
            {
                flag=1;
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
        puts("Error tarea no encontrada");
    }

    return aux;
}

void escribirNuevoContenido(stTarea*aux)
{

    printf("Ingrese el nuevo contenido de la tarea (Maximo 100 caracteres): ");
    fflush(stdin);
    gets(aux->contenido);
    strcat(aux->contenido,".");

}

int retornarPosicionTarea(int id,char archivoTareas[])
{
    stTarea aux;
    int pos=0;
    FILE*buffer=fopen(archivoTareas,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stTarea),1,buffer)>0)
        {
            if(id == aux.id)
            {
                pos=ftell(buffer)/sizeof(stTarea);
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return pos;
}

void modificarContenidoTareaEnArchivo(stTarea*aux, char archivoTareas[])
{

    int pos=0;
    FILE*buffer=fopen(archivoTareas,"r+b");
    if(buffer != NULL)
    {
        pos=retornarPosicionTarea(aux->id,archivoTareas);
        escribirNuevoContenido(aux);
        fseek(buffer,sizeof(stTarea)*pos,SEEK_SET);
        fwrite(aux,sizeof(stTarea),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}

void modificarEstadoTareaEnArchivo(stTarea*aux,char archivoTareas[])
{
    int pos=0,nuevoEstado=0;

    FILE*buffer=fopen(archivoTareas,"r+b");

    if(buffer != NULL)
    {

        pos=retornarPosicionTarea(aux->id,archivoTareas);
        fseek(buffer,sizeof(stTarea)*pos,SEEK_SET);
        nuevoEstado=menuModificarEstado(archivoTareas);
        aux->estado=nuevoEstado;
        fwrite(aux,sizeof(stTarea),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}



int menuModificarEstado(char archivoTareas[])
{
    int flag=0,opsw=0,dato=0;
    do
    {
        puts("0. Marcar como Eliminada");
        puts("1. Marcar como Pendiente");
        puts("2. Marcar como Terminada");
        printf("Ingrese su opcion: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 0:
            flag=0;
            dato=0;
            break;
        case 1:
            flag=0;
            dato=1;
            break;
        case 2:
            flag=0;
            dato=2;
            break;
        default:
            flag=1;
            puts("Por favor ingrese una opcion correcta");
            break;
        }

    }while(flag);

    return dato;
}

void modificarTarea(int id, char archivoTareas[])
{
    int opsw=0,flag=0;

    stTarea aux=retornarTareaXID(archivoTareas,id);

    do
    {


    mostrarTarea(aux);
    puts("1. Contenido");
    puts("2. Estado");
    puts("3. Volver atras");
    puts("-------------------------------------------");
    printf("Usted eligio esta tarea, que desea hacer?: ");
    scanf("%i",&opsw);


    switch(opsw)
    {
    case 1:
        modificarContenidoTareaEnArchivo(&aux,archivoTareas);
        break;
    case 2:
        modificarEstadoTareaEnArchivo(&aux,archivoTareas);
        break;
    case 3:
        flag=2;
        break;
    default:
        puts("Por favor ingrese una opcion valida");
        flag=1;
        break;
    }

    }while(flag == 1);
}

void menuEditarTarea(char archivoTareas[])
{
    int dato=0, flag=0;
    do
    {
    mostrarTodasLasTareas(archivoTareas);
    puts("\n--------------------------------------------------------");
    puts("Presione -1 para volver atras");
    printf("Ingrese el ID de la tarea que quiere modificar: ");
    scanf("%i",&dato);
    limpiarPantalla();

    if(dato == -1)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    }while(verificarExistenciaXID(dato,archivoTareas)==0 && flag==0);


    if(flag == 0)
    {
        modificarTarea(dato,archivoTareas);
    }




}





