#ifndef FUNCFUTBOL_H_
#define FUNCFUTBOL_H_

#define MAXDEFENSORESYMEDIOCAMPISTAS 8
#define MAXARQUEROS 2
#define MAXDELANTEROS 4
#define PORCENTAJEDEAUMENTOEUROPEO 35
#define MAXJUGADORES 22

#include "generales.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Muestra un menu y pide el costo de mantenimiento
 * "hospedaje" Costo de hospedaje
 * "comida" Costo de comida
 * "transporte" Costo de transporte
 * "return" Retorna la opcion elegida en el menu
 */
int cargarCosto(int hospedaje, int comida, int transporte);

/* Pide monto gastado en un costo y lo modifica
 * "hospedaje" Costo de hospedaje
 * "comida" Costo de comida
 * "transporte" Costo de transporte
 * "costoElegido" Costo a modificar (Se basa en el retorno de cargarCostos())
 * "return" Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int modificarCosto(int *hospedaje, int *comida, int *transporte, int costoElegido);

/* Valida si una posicion llego a la cantidad maxima disponible
 * "arqueros" Cantidad de arqueros
 * "defensores" Cantidad de defensores
 * "mediocampistas" Cantidad de mediocampistas
 * "delanteros" Cantidad de delanteros
 * "posicion" Posicion a validar (Se basa en el retorno de cargarJugador())
 * "avisar" Avisa por pantalla si llego a la cantidad maxima. 1. Si | 0. No
 * "return" Retorno binaria. 0. Llego a la cantidad maxima | 1. NO llego a la cantidad maxima
 */
int validarPosicionDisponible(int arqueros, int defensores,int mediocampistas,int delanteros, int posicion, int avisar);

/* Muestra un menu y pide la posicion del jugador
 * "arqueros" Cantidad de arqueros
 * "defensores" Cantidad de defensores
 * "mediocampistas" Cantidad de mediocampistas
 * "delanteros" Cantidad de delanteros
 * "return" Retorna la opcion elegida en el menu
 */
int cargarJugador(int arqueros, int defensores,int mediocampistas,int delanteros);

/* Aumenta el contador de una posicion
 * "arqueros" Cantidad de arqueros
 * "defensores" Cantidad de defensores
 * "mediocampistas" Cantidad de mediocampistas
 * "delanteros" Cantidad de delanteros
 * "posicionSeleccionada" Posicion a aumentar (Se basa en el retorno de cargarJugador())
 * "return" Retorna la opcion elegida en el menu
 */
int aumentarContadorPosicionJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int posicionSeleccionada);

/* Pide el numero de camiseta
 * "return" Retorna el numero de camiseta
 */
int pedirCamisetaJugador();

/* Pide la coconfederacion y aumenta su contador
 * "cantidadUefa" Cantidad UEFA
 * "cantidadConmebol" Cantidad CONMEBOL
 * "cantidadConcacaf" Cantidad CONCACAF
 * "cantidadAfc" Cantidad AFC
 * "cantidadOfc" Cantidad OFC
 * "cantidadCaf" Cantidad AFC
 * "return" Retorna la confederacion elegida
 */
int pedirConfederacionJugador(int cantidadUefa, int cantidadConmebol, int cantidadConcacaf, int cantidadAfc, int cantidadOfc, int cantidadCaf);

/* Aumenta el contador de una confederacion
 * "cantidadUefa" Cantidad UEFA
 * "cantidadConmebol" Cantidad CONMEBOL
 * "cantidadConcacaf" Cantidad CONCACAF
 * "cantidadAfc" Cantidad AFC
 * "cantidadOfc" Cantidad OFC
 * "cantidadCaf" Cantidad AFC
 * "confeSeleccionada" Confederacion a aumentar (Se basa en pedirCofederacionJugador())
 * "return" Retorno binario extendido. -1. Error en parametros | 0. No aumento | 1. Aumento una confederacion
 */
int aumentarContadorConfederacion(int *cantidadUefa, int *cantidadConmebol, int *cantidadConcacaf, int *cantidadAfc, int *cantidadOfc, int *cantidadCaf, int confeSeleccionada);

/* Valida si es posible realizar los calculos
 * "banderaCostosCargados" Bandera de costos cargados
 * "banderaJugadoresCargados" BAndera de jugadores cargados
 * "return" Retorno binario. 0. No se pueden realizar los calculos | 1. Se pueden realizar calculos
 */
int validarRealizarCalculos(int banderaCostosCargados, int banderaJugadoresCargados);

/* Obtiene el aumento europeo si son mayoria
 * "cantidadUefa" Cantidad de jugadores en UEFA
 * "cantidadDeJugadoresTotal" Cantidad de jugadors TOTAL
 * "mantenimiento" Costos de mantenimient
 * "return" Retorna el aumentoo europeo | Caso contrario 0
 */
int realizarAumentoEuropeo(int cantidadUefa, int cantidadDeJugadoresTotal, int mantenimiento);

/* Informa los jugadores promedio de cada confederacion
 * "promedioUefa" Promedio UEFA
 * "promedioConmebol" Promedio CONMEBOL
 * "promedioConcacaf" Promedio CONCACAF
 * "promedioAfc" Promedio AFC
 * "promedioOfc" Promedio OFC
 * "promedioCaf" Promedio AFC
 */
void informarPromedioConfederaciones(float promedioUefa,float promedioConmebol,float promedioConcacaf,float promedioAfc,float promedioOfc,float promedioCaf);

/* Informa los costos de mantenimineto
 * "mantenimiento" Costos de mantenimiento
 * "aumentoEuropeo" Aumento europeo
 * "mantenimientoEuropeo" Costos totales con aumento europeo
 */
void informarCostosDeMantenimiento(int mantenimiento,int aumentoEuropeo, int mantenimientoEuropeo);

#endif /* FUNCFUTBOL_H_ */
