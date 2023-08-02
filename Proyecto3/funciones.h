#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXSTRING 30
#include "menu.h"

int preguntarDatoEntero();
void limpiarPantalla();
stUsuario crearUsuario(char archivoUsuarios[]);
int obtenerUltimoCBU(char archivoUsuarios[]);
void escribirUsuarioEnArchivo(char archivoUsuarios[]);


#endif // FUNCIONES_H_INCLUDED
