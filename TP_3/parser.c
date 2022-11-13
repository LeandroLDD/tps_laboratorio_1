#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Gentilicio.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador){
	int ok;
	Jugador* auxJugador;
	char idStr[50];
	char nombreCompletoStr[100];
	char edadStr[15];
	char posicionStr[30];
	char nacionalidadStr[30];
	char idSeleccionStr[50];
	auxJugador = NULL;
	ok = -1;

	if(pFile != NULL && pArrayListJugador != NULL){
		ok = 0;
		jug_leerText(pFile, idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
		while(!feof(pFile)){
			jug_leerText(pFile, idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
			auxJugador = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
			if(feof(pFile)){
				jug_delete(auxJugador);
				break;
			}
			ok = 1;
			ll_add(pArrayListJugador, auxJugador);
		}
	}
    return ok;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador){
	int ok;
	Jugador* auxJugador;
	ok = -1;

	if(pFile != NULL && pArrayListJugador != NULL){
		ok = 0;

		while(!feof(pFile)){
			auxJugador = jug_new();
			fread(auxJugador,sizeof(Jugador),1,pFile);
			if(feof(pFile)){
				jug_delete(auxJugador);
				break;
			}
			ok = 1;
			ll_add(pArrayListJugador, auxJugador);
		}
	}
    return ok;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion){
	int ok;
	Seleccion* auxSeleccion;
	char idStr[50];
	char paisStr[50];
	char confederacionStr[50];
	char convocadosStr[50];
	auxSeleccion = NULL;
	ok = -1;

	if(pFile != NULL && pArrayListSeleccion != NULL){
		ok = 0;
		selec_leerText(pFile, idStr, paisStr, confederacionStr, convocadosStr);
		while(!feof(pFile)){
			selec_leerText(pFile, idStr, paisStr, confederacionStr, convocadosStr);
			auxSeleccion = selec_newParametros(idStr, paisStr, confederacionStr, convocadosStr);
			if(feof(pFile)){
				selec_delete(auxSeleccion);
				break;
			}
			ok = 1;
			ll_add(pArrayListSeleccion, auxSeleccion);
		}
	}
	return ok;
}

int parser_GentilicioFromText(FILE* pFile, LinkedList* pArrayListGentilicio){
	int ok;
	Gentilicio* auxGentilicios;
	char idSeleccionStr[50];
	char descripcionStr[50];
	auxGentilicios = NULL;
	ok = -1;

	if(pFile != NULL && pArrayListGentilicio != NULL){
		ok = 0;
		while(!feof(pFile)){
			gen_leerText(pFile, idSeleccionStr, descripcionStr);
			auxGentilicios = gen_nuevoParametros(idSeleccionStr, descripcionStr);
			if(feof(pFile)){
				gen_eliminar(auxGentilicios);
				break;
			}
			ok = 1;
			ll_add(pArrayListGentilicio, auxGentilicios);
		}
	}
	return ok;
}
