/**
 * @file informesFifa.h
 * @author Leandro David Dominguez
 * @title Informes de futbol
 * @brief Funciones de informes
 */

#ifndef INFORMESFIFA_H_
#define INFORMESFIFA_H_

#include "leangenerales.h"
#include "jugador.h"
#include "confederacion.h"

/**
 * @brief Ordena una lista eJugador alfabeticamente por nombre de confederacion y como segundo criterio por nombre de jugador
 * @param listaJugadorResult Lista eJugador ordenada retornada
 * @param listaJugador Lista eJugador a ordenar
 * @param tamConfederacion Tamaño de listaJugador
 * @return Retorna binario extendido. -1. Error en los parametros | 1. Se ordeno | 0. NO tuvo que ordenar
 */
int ordenarListaJugadorAlfabeticoNomConfederacionNomJugador(eJugador listaJugadorResult[] ,eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Muestra por pantalla una lista eJugador separara y ordenada por Confederacion
 * @param listaJugador Lista eJugador a mostrar
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion a mostrar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int mostrarListaJugadoresPorConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Obtiene la suma de todos los años de contrato de los eJugador de una eConfederacion
 * @param listaJugador Lista eJugador a buscar
 * @param tamJugador Tamaño de listaJugador
 * @param idConfederacion ID de la confederacion con la que se va filtrar
 * @return Retorna -1. Error en los parametros | Suma de los años de contrato
 */
short obtenerTotalAniosContratoDeConfederacion(eJugador listaJugador[], int tamJugador, int idConfederacion);

/**
 * @brief Muestra por pantalla la confederacion
 * @param listaJugador Lista eJugador a sumar años de contrato
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion a mostrar el mayor
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int mostrarConfederacionMayorAniosContrato(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Obtiene el porcentaje de jugadores de una eConfederacion
 * @param listaJugador Lista eJugador donde buscara los eJugadores de unaConfederacion
 * @param tamJugador Tamaño de listaJugador
 * @param unaConfederacion Lista eConfederacion con la que se filtrara los eJugadores
 * @return Retorna el porcentaje
 */
float obtenerPorcentajeDeJugadoresConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion *unaConfederacion);

/**
 * @brief Muestra por pantalla el porcentaje de una lista eJugadores de una lista eConfederacion
 * @param listaJugador Lista eJugador a mostrar
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion a mostrar sus porcentajes
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int mostrarPorcentajeDeJugadoresListaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Obtiene la confederacion con más jugadores
 * @param idConfederacionReturn Variable donde se retornara la id de la confederacion más jugadores
 * @param listaJugador Lista eJugador a buscar
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion donde se buscara la que tenga más jugadores
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int obtenerConfederacionConMasJugadores(int *idConfederacionReturn ,eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Muestra por pantalla la region con más jugadores
 * @param listaJugador Lista eJugador para obtener los jugadores
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion donde se buscara la region que tenga más jugadores
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int mostrarRegionConMasJugadores(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

#endif /* INFORMESFIFA_H_ */
