/*
 ============================================================================
 Name        : TP1.c
 Author      : Leandro David Dominguez
 Description : Trabajo practico 1
 ============================================================================
 */

#define MAXDEFENSORESYMEDIOCAMPISTAS 8
#define MAXARQUEROS 2
#define MAXDELANTEROS 4
#define PORCENTAJEDEAUMENTOEUROPEO 35
#define MAXJUGADORES 22

#include "msjEnPantalla.h"
#include "leanvectores.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout,NULL);

	//Costos
	int hospedaje;
	int comida;
	int transporte;
	int costoSeleccionado;
	float montoGastado;
	int banderaCostosCargados;

	//Carga de Jugadores
	int cantidadDeJugadoresTotal;
	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int posicionSeleccionada;
	int numCamisetaSeleccionada;
	int camisetasSeleccionadas[MAXJUGADORES];
	int confederacionSeleccionada;
	int cantidadUefa;
	int cantidadConmebol;
	int cantidadConcacaf;
	int cantidadAfc;
	int cantidadOfc;
	int cantidadCaf;
	int banderaJugadoresCargados;
	int maximoPosicionSeleccionada;

	//Calculos
	float promedioUefa;
	float promedioConmebol;
	float promedioConcacaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;
	int mantenimiento;
	int aumentoEuropeo;
	int mantenimientoTotal;
	int banderaCalculosRealizados;

	int rptMenuPrincipal; //Opcion selecionada en el menu

	hospedaje = 0;
	comida = 0;
	transporte = 0;
	banderaCostosCargados = 0;

	cantidadDeJugadoresTotal = 0;
	arqueros = 0;
	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;
	cantidadUefa = 0;
	cantidadConmebol = 0;
	cantidadConcacaf = 0;
	cantidadAfc = 0;
	cantidadOfc = 0;
	cantidadCaf = 0;
	banderaJugadoresCargados = 0;
	rellenarVector(camisetasSeleccionadas, MAXJUGADORES, 0);

	promedioUefa = 0;
	promedioConmebol = 0;
	promedioConcacaf = 0;
	promedioAfc = 0;
	promedioOfc = 0;
	promedioCaf = 0;
	aumentoEuropeo = 0;
	mantenimientoTotal = 0;
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
				"\n5.Salir\n",hospedaje,comida,transporte,arqueros,defensores,mediocampistas,delanteros);

		rptMenuPrincipal = imprYGuardarNumConMinYMax("\nSeleccione una opcion ",1,5,0);

		switch(rptMenuPrincipal){//switch de opciones del menu principal

			case 1://------------INGRESO DE LOS COSTOS DE MANTENIMIENTO-----------
				system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
				printf("\t\tIngreso de los costos de Mantenimiento\n"
						"\t\t======================================\n"
						"\n1.Costo de Hospedaje -> $%d"
						"\n2.Costo de Comida -> $%d"
						"\n3.Costo de Transporte -> $%d"
						"\n4.Volver al menu\n",hospedaje,comida,transporte);

				costoSeleccionado = imprYGuardarNumConMinYMax("\nSeleccione un costo ",1, 4,0);

				if(costoSeleccionado == 4){//Si es igual a 4 sale del switch
				break;
				}

				do{
				montoGastado = imprYGuardarNum("\nMonto gastado $");

				if(montoGastado < 1 || montoGastado > 100000000){
					puts("\nEl monto ingresado NO es valido.");
				}

				}while(montoGastado < 1 || montoGastado > 100000000);

				switch(costoSeleccionado){//switch de Costos
					case 1:
						hospedaje = montoGastado;
					break;

					case 2:
						comida = montoGastado;
					break;

					case 3:
						transporte = montoGastado;
					break;
				}
				banderaCostosCargados = 1;
			break;

			case 2://------------------------CARGA DE JUGADORES----------------------
				if(cantidadDeJugadoresTotal == MAXJUGADORES){
					imprAviso("\nYa llego a la cantidad maxima de jugadores que pueden estar en el plantel");
					break;
				}
				system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
				printf("\t\tCarga de jugadores\n"
						"\t\t==================\n"
						"\n1.Arqueros -> %d"
						"\n2.Defensores -> %d"
						"\n3.Mediocampistas -> %d"
						"\n4.Delanteros -> %d"
						"\n5.Volver al menu\n",arqueros,defensores,mediocampistas,delanteros);

				do{//do while para determinar la cantidad maxima por posicion
					posicionSeleccionada = imprYGuardarNumConMinYMax("\nSeleccione una posicion ",1, 5,0);

					maximoPosicionSeleccionada = 0;

					switch(posicionSeleccionada){
						case 1:
							if(arqueros == MAXARQUEROS){
								maximoPosicionSeleccionada = 1;
								break;
							}
							arqueros++;
						break;

						case 2:
							if(defensores == MAXDEFENSORESYMEDIOCAMPISTAS){
								maximoPosicionSeleccionada = 1;
								break;
							}
							defensores++;
						break;

						case 3:
							if(mediocampistas == MAXDEFENSORESYMEDIOCAMPISTAS){
								maximoPosicionSeleccionada = 1;
								break;
							}
							mediocampistas++;
						break;

						case 4:
							if(delanteros == MAXDELANTEROS){
								maximoPosicionSeleccionada = 1;
								break;
							}
							delanteros++;
						break;
					}

					if(maximoPosicionSeleccionada){
					puts("\nLlego a la cantidad maxima de la posicion seleccionada.");
					}
				}while(maximoPosicionSeleccionada);

				if(posicionSeleccionada == 5){ //Si igual a 5 sale del switch
					break;
				}

				do{//do while para validacion de camiseta
				numCamisetaSeleccionada = imprYGuardarNum("\nIngrese el numero de Camiseta(1-99) ");

				if(buscarValorEnVector(camisetasSeleccionadas,MAXJUGADORES,numCamisetaSeleccionada) && numCamisetaSeleccionada != 0){
					puts("\nEl numero de Camiseta ya fue seleccionado.");
				}

				if(numCamisetaSeleccionada < 1 || numCamisetaSeleccionada > 99){
					puts("\nEl numero de Camiseta seleccionado no esta permitido.");
				}

				}while(buscarValorEnVector(camisetasSeleccionadas,MAXJUGADORES,numCamisetaSeleccionada) || numCamisetaSeleccionada < 1 || numCamisetaSeleccionada > 99);

				camisetasSeleccionadas[obtenerPosicionEnVector(camisetasSeleccionadas, MAXJUGADORES, 0)] = numCamisetaSeleccionada;

				puts("\n1. UEFA"
					"\n2. CONMEBOL"
					"\n3. CONCACAF"
					"\n4. AFC"
					"\n5. OFC"
					"\n6. CAF");

				confederacionSeleccionada = imprYGuardarNumConMinYMax("\nSeleccione una confederacion ", 1, 6, 0);

				switch(confederacionSeleccionada){//Crea una funcion switchIncremental(); fijate el retorno y parameters
					case 1:
						cantidadUefa++;
					break;

					case 2:
						cantidadConmebol++;
					break;

					case 3:
						cantidadConcacaf++;
					break;

					case 4:
						cantidadAfc++;
					break;

					case 5:
						cantidadOfc++;
					break;

					case 6:
						cantidadCaf++;
					break;
				}
				banderaJugadoresCargados = 1;
				cantidadDeJugadoresTotal = arqueros + defensores + mediocampistas + delanteros;
			break;

			case 3: //-----------------REALIZAR TODOS LOS CALCULOS-----------------
				if(!banderaCostosCargados || !banderaJugadoresCargados){//Pregunta si faltan datos por cargar
					imprDobleOpcionIgualACero("\nFaltan cargar datos de ", "Costos", banderaCostosCargados, "Jugadores", banderaJugadoresCargados);
					break;
				};

				promedioUefa = (float)cantidadUefa / 6;
				promedioConmebol = (float)cantidadConmebol / 6;
				promedioConcacaf = (float)cantidadConcacaf / 6;
				promedioAfc = (float)cantidadAfc / 6;
				promedioOfc = (float)cantidadOfc / 6;
				promedioCaf = (float)cantidadCaf / 6;

				mantenimiento = hospedaje + comida + transporte;

				if(cantidadUefa > (cantidadDeJugadoresTotal - cantidadUefa)){
					//Si cantidadUefa es mayor a la cantidad de jugadors de las demas confederaciones entra al if
					aumentoEuropeo = ((float)PORCENTAJEDEAUMENTOEUROPEO/100) * mantenimiento;
					mantenimientoTotal = aumentoEuropeo + mantenimiento;
				}
				else{
					aumentoEuropeo = 0;
					mantenimientoTotal = 0;
				}
				banderaCalculosRealizados = 1;
				printf("\n\tSe realizaron todos los calculos correctamente\n\n");
				system("pause");
			break;

			case 4://----------------INFORMAR TODOS LOS RESULTADOS-------------------
				if(!banderaCalculosRealizados){
					imprAviso("\nFaltan realizar los Calculos");
					break;
				};

				system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
				printf("\t\tInformar todos los Resultados\n"
						"\t\t=============================\n"
						"\nPromedio UEFA %.2f"
						"\nPromedio CONMEBOL %.2f"
						"\nPromedio CONCACAF %.2f"
						"\nPromedio AFC %.2f"
						"\nPromedio OFC %.2f"
						"\nPromedio CAF %.2f",promedioUefa,promedioConmebol,promedioConcacaf,promedioAfc,promedioOfc,promedioCaf);

				if(aumentoEuropeo == 0){
					printf("\n\nEl costo de mantenimiento es de $%d\n\n",mantenimiento);
				}
				else{
					printf("\n\nEl costo de mantenimiento era de $%d y recibio un aumento de $%d, su nuevo valor es de $%d\n\n",mantenimiento,aumentoEuropeo,mantenimientoTotal);
				}
				system("pause");
			break;

			case 5://-------------------------SALIR------------------------
				exit(1);
			break;
		}

	}while(rptMenuPrincipal != 5);

	return EXIT_SUCCESS;
}
