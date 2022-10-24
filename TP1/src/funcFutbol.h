#ifndef FUNCFUTBOL_H_
#define FUNCFUTBOL_H_

#define MAXDEFENSORESYMEDIOCAMPISTAS 8
#define MAXARQUEROS 2
#define MAXDELANTEROS 4
#define PORCENTAJEDEAUMENTOEUROPEO 35
#define MAXJUGADORES 22

#include "msjEnPantalla.h"
#include "leanvectores.h"
#include "leanvalidaciones.h"

int cargarCosto(int *hospedaje, int *comida, int *transporte, int *banderaTodosLosCostosCargados);

int pedirCosto(int *hospedaje, int *comida, int *transporte, int costoElegido);

int validarPosicionDisponible(int arqueros, int defensores,int mediocampistas,int delanteros, int posicion, int avisar);

int cargarJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int *banderaJugadorCargado);

int pedirPosicionJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int posicionSeleccionada);

int pedirCamiseta(int camisetasSeleccionadas[]);

int pedirConfederacion(int *cantidadUefa, int *cantidadConmebol, int *cantidadConcacaf, int *cantidadAfc, int *cantidadOfc, int *cantidadCaf);

#endif /* FUNCFUTBOL_H_ */
