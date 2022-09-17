/*
 ============================================================================
 Name        : TP1.c
 Author      : Leandro David Dominguez
 Description : Trabajo practico 1
 ============================================================================
 */

#include "msjEnPantalla.h"
#include <conio.h>

int main(void) {
	setbuf(stdout,NULL);

	int hospedaje;
	int comida;
	int transporte;
	int mantenimiento;
	int costoSeleccionado;
	float montoGastado;

	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int posicionSeleccionada;
	int numCamiseta;
	int confederacionSeleccionada;

	int rpt; //Opcion selecionada en el menu

	hospedaje = 0;
	comida = 0;
	transporte = 0;
	arqueros = 0;

	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;

	rpt = 0;

	do{
		system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
		puts("\t\tMenu Principal\n");
		puts("1.Ingreso de los costos de Mantenimiento");
		printf(" Costo de Hospedaje -> $%d\n", hospedaje);
		printf(" Costo de Comida -> $%d\n", comida);
		printf(" Costo de Transporte -> $%d\n", transporte);
		puts("2.Carga de jugadores");
		printf(" Arqueros -> %d\n", arqueros);
		printf(" Defensores -> %d\n", defensores);
		printf(" Mediocampistas -> %d\n", mediocampistas);
		printf(" Delanteros -> %d\n", delanteros);
		puts("3.Realizar todos los calculos");
		puts("4.Informar todos los resultados");
		puts("5.Salir");

		rpt = msjYGuardarNumConMinYMax("\nSeleccione una opcion ",1,5,0);
		system("cls");

		switch(rpt){//switch de opciones del menu principal
			case 1://------------INGRESO DE LOS COSTOS DE MANTENIMIENTO-----------

				printf("\t\tIngreso de los costos de Mantenimiento\n"
						"\n1.Costo de Hospedaje -> $%d"
						"\n2.Costo de Comida -> $%d"
						"\n3.Costo de Transporte -> $%d"
						"\n4.Volver al menu\n",hospedaje,comida,transporte);

				costoSeleccionado = msjYGuardarNumConMinYMax("\nSeleccione un costo ",1, 4,0);

				if(costoSeleccionado != 4){//Si es diferente de 4 pregunta el monto
				montoGastado = msjYGuardarNum("Monto gastado $");
				}

				switch(costoSeleccionado){//switch de Costos
					case 1:
						hospedaje += montoGastado;
					break;

					case 2:
						comida += montoGastado;
					break;

					case 3:
						transporte += montoGastado;
					break;
				}
			break;

			case 2://------------CARGA DE JUGADORES-----------
				printf("\t\tCarga de jugadores\n"
										"\n1.Arqueros -> %d"
										"\n2.Defensores -> %d"
										"\n3.Mediocampistas -> %d"
										"\n4.Delanteros -> %d"
										"\n5.Volver al menu\n",arqueros,defensores,mediocampistas,delanteros);

								posicionSeleccionada = msjYGuardarNumConMinYMax("\nSeleccione una posicion ",1, 5,0);

								if(posicionSeleccionada != 5){//Si es diferente de 5 pregunta los datos del jugador
								numCamiseta = msjYGuardarNum("Numero de Camiseta: ");
								confederacionSeleccionada = msjYGuardarNumConMinYMax("\n"
										"\n1. UEFA"
										"\n2. CONMEBOL"
										"\n3. CONCACAF"
										"\n4. AFC"
										"\n5. OFC"
										"\n6. CAF", 1, 5, 0);
								}

								switch(posicionSeleccionada){//switch de Costos
									case 1:
										arqueros++;
									break;

									case 2:
										defensores++;
									break;

									case 3:
										mediocampistas++;
									break;

									case 4:
										delanteros++;
									break;
								}
			break;

			case 3:
				mantenimiento = hospedaje + comida + transporte;
			break;

			case 4:
			break;

			case 5:
			break;

		}
	}while(rpt != 5);





	return EXIT_SUCCESS;
}
