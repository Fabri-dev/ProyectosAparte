#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXDIMSTR 40


///Prototipados

typedef struct
{
char nombre[MAXDIMSTR];
char apellido[MAXDIMSTR];
char nacionalidad[MAXDIMSTR];
int edad;
int DNI;
}stPersona;


typedef struct
{
stPersona datosPersonales;
char puesto[MAXDIMSTR];
int horasDiarias;
float salario;
int estado;
}stEmpleado;

//validaciones
int validarNombreyApellido(char dato[]);
int validarPais(char dato[]);
int validarEdad(int dato);
int validarDNI(int dato);
int validarSiDniExiste(int dato,char archivoP[]);
int validarHorasDiarias(int dato);
int validarSalario(float dato);
int validarPuesto(int dato, char cargo[]);



//varios
int preguntarDato();
void mostrarPuestos();
void limpiarPantalla();
void mostrarOpcionesModificar();


//Alta a datos personales
stPersona datosPersonales();

//cargar archivo datos personales
void cargarArchivoDatosPersonales(char archivo[]);

//buscar datos personales por dni
stPersona buscarDatosPersonalesXDNI(int DNI,char archivoDatosPersonales[]);

//Alta a empleado
stEmpleado cargarUnEmpleado(char archivoDatosPersonales[]);

//Cargar archivo empleados
void cargarArchivoEmpleado(char archivoEmp[],char archivoDatosPersonales[]);

//mostrar un empleado
void mostrarUnEmpleado(stEmpleado aux);

//mostrar todos los empleados
void mostrarEmpleados(char archivoEmpleados[]);

//mostrar empleados por datos especificos
void mostrarEmpleadosXpuesto(char archivoEmpleados[], char puesto[]);
void elegirQuePuestoMostrar(char archivoEmpleados[], int dato);

//mostrar empleados por edad especifica
void mostrarEmpleadoXedad(char archiEmpleados[], int dato);

//mostrar empleados por nacionalidad
void mostrarEmpleadosXnacionalidad(char archiEmpleados[], char nacionalidad[]);

//buscar empleado por DNI

stEmpleado buscarEmpleadoXdni(char archivoEmpleados[], int dni);


//Modificar archivo empleados
    //Dar de baja , etc

//Consultar datos empleados





























#endif // FUNCIONES_H_INCLUDED
