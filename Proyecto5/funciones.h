#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXDIM 30

typedef struct{
    int id;
    char nombre[MAXDIM];
    char apellido[MAXDIM];
    int dni;
    char email[MAXDIM];
    float monto;
    int formaPago; //1-Efectivo , 2-Transferencia
    int mes;

}stFactura;

stFactura crearFactura(char archivoFacturas[]);
void menuPrincipal(char archivoFacturas[]);
void escribirFacturaArchivo(char archivoFacturas[], stFactura dato);
void cargarFacturaArchivo(char archivoFacturas[]);
int buscarUltimoID(char archivoFacturas[]);


#endif // FUNCIONES_H_INCLUDED
