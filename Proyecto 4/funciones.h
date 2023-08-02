#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXDIM 100

typedef struct
{
    char contenido[MAXDIM];
    int estado;
    int id;

}stTarea;





void menuPrincipal(char archivoTareas[]);
void limpiarPantalla();
stTarea crearTarea(char archivoTareas[]);
void guardarContenido(char* texto);
int buscarUltimaID(char archivoTareas[]);
int contarTareas(char archivoTareas[]);
void mostrarTarea(stTarea aux);
void mostrarEstado(int estado);
void menuMostrarTareas(char archivoTareas[]);
void mostrarTareasSegunEstado(char archivoTareas[], int estado);
void mostrarTodasLasTareas(char archivoTareas[]);
void guardarTareaArchivo(char archivoTareas[]);
int verificarExistenciaXID(int id,char archivoTareas[]);
void menuEditarTarea(char archivoTareas[]);
stTarea retornarTareaXID(char archivoTareas[],int id);
void modificarTarea(int id, char archivoTareas[]);
void modificarContenidoTareaEnArchivo(stTarea*aux, char archivoTareas[]);
void escribirNuevoContenido(stTarea*aux);
int retornarPosicionTarea(int id,char archivoTareas[]);
void modificarEstadoTareaEnArchivo(stTarea*aux,char archivoTareas[]);
int menuModificarEstado(char archivoTareas[]);
int contarTareasSegunEstado(char archivoTareas[],int estado);






#endif // FUNCIONES_H_INCLUDED
