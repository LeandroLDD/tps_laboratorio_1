#include "informesFifa.h"

int ordenarListaJugadorAlfabeticoNomConfederacionNomJugador(eJugador listaJugadorResult[] ,eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int posConfederacionI;
	int posConfederacionJ;
	int condicionConfederacion;
	ok = -1;
	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 1)){
		ok = 0;
		copiarListaJugador(listaJugadorResult, listaJugador, tamJugador);

		for(int i = 0; i < tamJugador-1; i++){
			for(int j = i+1; j < tamJugador; j++){
				//Obtengo las posiciones de listaConfederacion con la ID de listaJugadorResult[]
				obtenerConfederacionPorID(listaConfederacion, tamConfederacion, listaJugadorResult[i].idConfederacion, &posConfederacionI);
				obtenerConfederacionPorID(listaConfederacion, tamConfederacion, listaJugadorResult[j].idConfederacion, &posConfederacionJ);
				//Comparo los nombre de las confederaciones con las posiciones obtenidas
				condicionConfederacion = strcmp(listaConfederacion[posConfederacionI].nombre,listaConfederacion[posConfederacionJ].nombre);

				if(condicionConfederacion > 0 || (condicionConfederacion == 0 && strcmp(listaJugadorResult[i].nombre,listaJugadorResult[j].nombre) > 0)){
					swapearJugadores(&listaJugadorResult[i], &listaJugadorResult[j]);
					ok = 1;
				}
			}
		}
	}
	return ok;
}

int mostrarListaJugadoresPorConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	eJugador jugadoresConfederacion[tamJugador];
	int tamJugadoresConfederacion;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 1)){
		for(int i = 0; i < tamConfederacion; i++){
			tamJugadoresConfederacion = obtenerJugadoresDeUnaConfederacion(jugadoresConfederacion, listaJugador, tamJugador, listaConfederacion[i].id);
			if(tamJugadoresConfederacion > 0){
			printf("%s\n",listaConfederacion[i].nombre);
			mostrarListaJugador(jugadoresConfederacion, tamJugadoresConfederacion, listaConfederacion, tamConfederacion);
			}
		}
	}
	return ok;
}

short obtenerTotalAniosContratoDeConfederacion(eJugador listaJugador[], int tamJugador, int idConfederacion){
	short sumaAniosContratos;
	sumaAniosContratos = -1;
	if(validarSiHayJugadores(listaJugador, tamJugador, 0 && idConfederacion > 0)){
		sumaAniosContratos = 0;
		for(int i = 0; i < tamJugador; i++){
			if(listaJugador[i].isEmpty == OCUPADO && listaJugador[i].idConfederacion == idConfederacion){
				sumaAniosContratos += listaJugador[i].aniosContrato;
			}
		}
	}

	return sumaAniosContratos;
}

int mostrarConfederacionMayorAniosContrato(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int banderaPrimeraConfederacion;
	short aniosContratoConfederacion;
	short MAXaniosContratoConfederacion;
	eConfederacion *auxConfederacionMaxContratos;
	ok = 0;
	banderaPrimeraConfederacion = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0 && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0))){
		for(int i = 0; i < tamConfederacion; i++){
			aniosContratoConfederacion = obtenerTotalAniosContratoDeConfederacion(listaJugador, tamJugador, listaConfederacion[i].id);

			if(!banderaPrimeraConfederacion || aniosContratoConfederacion > MAXaniosContratoConfederacion){
				auxConfederacionMaxContratos = &listaConfederacion[i];
				MAXaniosContratoConfederacion = aniosContratoConfederacion;
				banderaPrimeraConfederacion = 1;
			}
		}
	}
	mostrarListaConfederacion(auxConfederacionMaxContratos, 1);

	return ok;
}


float obtenerPorcentajeDeJugadoresConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion *unaConfederacion){
	float porcentaje;
	int contadorJugadores;
	porcentaje = 0;
	contadorJugadores = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && unaConfederacion->isEmpty == OCUPADO && obtenerCantidadJugadoresDeUnaConfederacion(listaJugador, tamJugador, unaConfederacion, &contadorJugadores)){
		porcentaje = (contadorJugadores * 100) / (float)tamJugador;
	}

	return porcentaje;
}

int mostrarPorcentajeDeJugadoresListaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	float porcentajeConfederacion;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 1;
		for(int i = 0; i < tamConfederacion; i++){
			porcentajeConfederacion = obtenerPorcentajeDeJugadoresConfederacion(listaJugador, tamJugador, &listaConfederacion[i]);
			printf("\n%s  %.2f%c\n",
					listaConfederacion[i].nombre,porcentajeConfederacion,'%');
		}
	}

	return ok;
}

int obtenerConfederacionConMasJugadores(int *idConfederacionReturn ,eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int porcentajeConfederacion;
	int MAXporcentajeConfederacion;
	int banderaPrimeraConfederacion;
	ok = 0;
	banderaPrimeraConfederacion = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 1;
		for(int i = 0; i < tamJugador; i++){
			porcentajeConfederacion = obtenerPorcentajeDeJugadoresConfederacion(listaJugador, tamJugador, &listaConfederacion[i]);

			if(!banderaPrimeraConfederacion || porcentajeConfederacion > MAXporcentajeConfederacion){
				MAXporcentajeConfederacion = porcentajeConfederacion;
				banderaPrimeraConfederacion = 1;
				*idConfederacionReturn = listaConfederacion[i].id;
			}
		}
	}

	return ok;
}
int mostrarRegionConMasJugadores(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int idConfMasJugadores;
	int posConfMasJugadores;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 1;
		obtenerConfederacionConMasJugadores(&idConfMasJugadores, listaJugador, tamJugador, listaConfederacion, tamConfederacion);
		obtenerConfederacionPorID(listaConfederacion, tamConfederacion, idConfMasJugadores, &posConfMasJugadores);

		printf("\n%s | ",listaConfederacion[posConfMasJugadores].region);
		mostrarListaJugadoresPorConfederacion(listaJugador, tamJugador, &listaConfederacion[posConfMasJugadores], 1);
	}

	return ok;
}


