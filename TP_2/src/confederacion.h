#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define OCUPADO 0
#define LIBRE 1
#include "leangenerales.h"
#include "menu.h"

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

int swapearConfederaciones(eConfederacion* confederacion1, eConfederacion* confederacion2);

int copiarListaConfederacion(eConfederacion listaConfederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion);

int ordenarListaConfederacionPorID(eConfederacion listaConfedederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion);

int obtenerEspacioLibreConfederacion(int* posLibreReturn,eConfederacion listaConfederacion[], int tamConfederacion);

int pedirNombreConfederacion(eConfederacion *unaConfederacion);

int pedirRegionConfederacion(eConfederacion *unaConfederacion);

int pedirAnioCreacionConfederacion(eConfederacion *unaConfederacion);

int altaConfederacion(eConfederacion listaConfederacion[],int maxConfederaciones, int *tamConfederacion, int *id);

eConfederacion pedirDatosConfederacion(int id);

int bajaConfederacion(eConfederacion listaConfederacion[], int *tamConfederacion);

int modificarConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

int elegirOpcionModificarConfederacion(eConfederacion *unaConfederacion);

int mostrarConfederacion(eConfederacion* unaConfederacion);

int mostrarListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

int validarSihayConfederaciones(eConfederacion listaConfederacion[], int tamConfederacion, int avisar);

int validarConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar);

int obtenerConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar, int* posResult);

int elegirConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

int reacomodarPosListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);


#endif /* CONFEDERACION_H_ */
