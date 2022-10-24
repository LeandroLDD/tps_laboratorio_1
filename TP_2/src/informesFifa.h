#ifndef INFORMESFIFA_H_
#define INFORMESFIFA_H_

#include "leangenerales.h"
#include "jugador.h"
#include "confederacion.h"

int ordenarListaJugadorAlfabeticoNomConfederacionNomJugador(eJugador listaJugadorResult[] ,eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int mostrarListaJugadoresPorConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

short obtenerTotalAniosContratoDeConfederacion(eJugador listaJugador[], int tamJugador, int idConfederacion);

int mostrarConfederacionMayorAniosContrato(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

float obtenerPorcentajeDeJugadoresConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion *unaConfederacion);

int mostrarPorcentajeDeJugadoresListaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int obtenerConfederacionConMasJugadores(int *idConfederacionReturn ,eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

int mostrarRegionConMasJugadores(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

#endif /* INFORMESFIFA_H_ */
