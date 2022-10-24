#ifndef JUGADOR_H_
#define JUGADOR_H_

#define OCUPADO 0
#define LIBRE 1
#include "leangenerales.h"
#include "menu.h"
#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

int validarSiHayJugadores(eJugador listaJugador[], int tamJugador, int avisar);

int mostrarJugador(eJugador* unJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int mostrarListaJugador(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int darDeBajaListaJugador(eJugador listaJugador[], int tamJugador);

int obtenerEspacioLibreJugador(int* posResult, eJugador listaJugador[], int tamJugador);

int validarIDJugador(eJugador listaJugador[], int tamJugador, int idBuscar);

int obtenerJugador(eJugador listaJugador[], int tamJugador, int idBuscar, int *posResult);

int obtenerCantidadJugadoresDeUnaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion* unaConfederacion, int* contadorResult);

int obtenerJugadoresDeUnaConfederacion(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, int idConfederacion);

int obtenerJugadoresSalarioMayor(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, float salario);

float obtenerSumaTotalSalarioJugadores(eJugador listaJugador[], int tamJugador);

float obtenerPromedioSalarioJugadores(eJugador listaJugador[], int tamJugador);

int copiarListaJugador(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador);

int swapearJugadores(eJugador *jugador1, eJugador *jugador2);

int ordernarPorIDListaJugador(eJugador listaJugador[], eJugador listaJugadorResult[], int tamJugador);

int reacomodarPosListaJugador(eJugador listaJugador[], int tamJugador);

int elegirJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int *posResult);

int pedirNombreJugador(eJugador* unJugador);

int pedirPosicionJugador(eJugador* unJugador);

int pedirNumCamisetaJugador(eJugador* unJugador);

float pedirSalarioJugador(eJugador* unJugador);

short pedirAniosContrato(eJugador* unJugador);

int elegirOpcionModificarJugador(eJugador* unJugador, eConfederacion listaConfederacion[] , int tamConfederacion);

int altaJugador(eJugador listaJugador[], int maxJugadores, int *tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int* id);

eJugador pedirDatosJugador(eConfederacion listaConfederacion[], int tamConfederacion, int id);

int bajaJugador(eJugador listaJugador[], int* tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int modificarJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

#endif /* JUGADOR_H_ */
