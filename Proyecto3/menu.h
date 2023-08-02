#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define MAXSTRING 30

//estructuras

typedef struct
{
    char nombre[MAXSTRING];
    char apellido[MAXSTRING];
    int DNI;
    char clave[5]; //si o si 5 numeros
    int estado; // 1 activo , 0 inactivo
    int saldo;
    int cbu; //es como el ID

}stUsuario;

typedef struct
{
    int cbuEmisor;
    int cbuReceptor;
    int fecha;
    int monto;
    char motivo;

}stMovimientos;


//funciones

void menuInicioSesion(char archivoUsuario[]);



#endif // MENU_H_INCLUDED
