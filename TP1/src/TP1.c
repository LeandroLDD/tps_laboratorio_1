/*
 ============================================================================
 Name        : TP1.c
 Author      : Leandro David Dominguez
 Description : Trabajo practico 1
 ============================================================================
 */

#include "funcFutbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "generales.h"

int main(void) {
	setbuf(stdout,NULL);

	//Costos
	int hospedaje;
	int comida;
	int transporte;
	int banderaCostosCargados;

	//Carga de Jugadores
	int cantidadDeJugadoresTotal;
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;
	int contadorUefa;
	int contadorConmebol;
	int contadorConcacaf;
	int contadorAfc;
	int contadorOfc;
	int contadorCaf;
	int banderaJugadoresCargados;

	//Calculos
	float promedioUefa;
	float promedioConmebol;
	float promedioConcacaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;
	int mantenimiento;
	int aumentoEuropeo;
	int manteniminetoAumentoEuropa;
	int banderaCalculosRealizados;

	int rptMenuPrincipal; //Opcion selecionada en el menu
	int banderaAuxiliar;
	int numAux;

	hospedaje = 0;
	comida = 0;
	transporte = 0;
	banderaCostosCargados = 0;

	cantidadDeJugadoresTotal = 0;
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;
	contadorUefa = 0;
	contadorConmebol = 0;
	contadorConcacaf = 0;
	contadorAfc = 0;
	contadorOfc = 0;
	contadorCaf = 0;
	banderaJugadoresCargados = 0;

	promedioUefa = 0;
	promedioConmebol = 0;
	promedioConcacaf = 0;
	promedioAfc = 0;
	promedioOfc = 0;
	promedioCaf = 0;
	aumentoEuropeo = 0;
	manteniminetoAumentoEuropa = 0;
	banderaCalculosRealizados = 0;
	mantenimiento = 0;

	rptMenuPrincipal = 0;

	do{
		system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
		printf("\t\tMenu Principal\n"
			    "\t\t==============\n"
				"\n1.Ingreso de los costos de Mantenimiento"
				"\n Costo de Hospedaje -> $%d"
				"\n Costo de Comida -> $%d"
				"\n Costo de Transporte -> $%d"
				"\n2.Carga de jugadores"
				"\n Arqueros -> %d"
				"\n Defensores -> %d"
				"\n Mediocampistas -> %d"
				"\n Delanteros -> %d"
				"\n3.Realizar todos los calculos"
				"\n4.Informar todos los resultados"
				"\n5.Salir\n",hospedaje,comida,transporte,contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros);

		rptMenuPrincipal = imprYGuardarNumConMinYMax("\nSeleccione una opcion ","Respuesta invalida",1,5,0);

		switch(rptMenuPrincipal){//switch de opciones del menu principal

			case 1://------------INGRESO DE LOS COSTOS DE MANTENIMIENTO-----------
				banderaAuxiliar = cargarCosto(hospedaje, comida, transporte);

				if(banderaAuxiliar != 4){
					modificarCosto(&hospedaje, &comida, &transporte, banderaAuxiliar);

					if(hospedaje != 0 && comida != 0 && transporte != 0){//Si se cargaron todos los costos
						banderaCostosCargados = 1;
					}
					imprAviso("¡Se cargo el costo exitosamente!");
				}

			break;

			case 2://------------------------CARGA DE JUGADORES----------------------
				banderaAuxiliar = cargarJugador(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);

				if(banderaAuxiliar != 5 && banderaAuxiliar != -1){
					aumentarContadorPosicionJugador(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros, banderaAuxiliar);

					pedirCamisetaJugador();

					numAux = pedirConfederacionJugador(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf);
					aumentarContadorConfederacion(&contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf, numAux);

					banderaJugadoresCargados = 1;
					cantidadDeJugadoresTotal = contadorArqueros + contadorDefensores + contadorMediocampistas + contadorDelanteros;
					imprAviso("¡Se cargo el jugador exitosamente!");
				}
				imprSi("\nYa llego a la cantidad maxima de jugadores que pueden estar en el plantel", banderaAuxiliar, -1);

			break;

			case 3: //-----------------REALIZAR TODOS LOS CALCULOS-----------------
				if(validarRealizarCalculos(banderaCostosCargados, banderaJugadoresCargados)){

					promedioUefa = ((float)contadorUefa / cantidadDeJugadoresTotal)*100;
					promedioConmebol = ((float)contadorConmebol / cantidadDeJugadoresTotal)*100;
					promedioConcacaf = ((float)contadorConcacaf / cantidadDeJugadoresTotal)*100;
					promedioAfc = ((float)contadorAfc / cantidadDeJugadoresTotal)*100;
					promedioOfc = ((float)contadorOfc / cantidadDeJugadoresTotal)*100;
					promedioCaf = ((float)contadorCaf / cantidadDeJugadoresTotal)*100;

					mantenimiento = hospedaje + comida + transporte;

					aumentoEuropeo = realizarAumentoEuropeo(contadorUefa, cantidadDeJugadoresTotal, mantenimiento);
					manteniminetoAumentoEuropa = aumentoEuropeo + mantenimiento;

					banderaCalculosRealizados = 1;
					imprAviso("Se realizaron todos los calculos correctamente\n");
				}
				imprSi("Faltan cargar Costos", banderaCostosCargados, 0);
				imprSi("Faltan cargar Jugadores", banderaJugadoresCargados, 0);
			break;

			case 4://----------------INFORMAR TODOS LOS RESULTADOS-------------------
				if(banderaCalculosRealizados){

					informarPromedioConfederaciones(promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
					informarCostosDeMantenimiento(mantenimiento, aumentoEuropeo, manteniminetoAumentoEuropa);
				};
				imprSi("\nFaltan realizar los Calculos", banderaCalculosRealizados, 0);
			break;

			case 5://-------------------------SALIR------------------------
				banderaAuxiliar = imprYGuardarNumConMinYMax("¿Desea salir del programa? (1. Si | 0. No) ", "Respuesta invalida", 0, 1, 0);
				if(!banderaAuxiliar){
					rptMenuPrincipal = 0;
				}
			break;
		}

	}while(rptMenuPrincipal != 5);

	return EXIT_SUCCESS;
}
