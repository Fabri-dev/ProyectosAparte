#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define MAXDIMSTR 40


void menuPrincipal(char archivoDatosPersonales[], char archivoEmpleados[]);
void elegirOpciones();
void opcionesDeMostrar();
void elegirQueMostrar(char archivoEmpleados[], char archivoDatosPersonales[]);
int validarMostrarPuestos(int dato);


#endif // MENU_H_INCLUDED
