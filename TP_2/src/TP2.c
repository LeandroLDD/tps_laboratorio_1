#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include "menu.h"
#include "informesFifa.h"

#define MAXJUGADOR 3000
#define TAMCONFEDERACION 6

int main(void) {
	setbuf(stdout,NULL);
	eMenu menuPrincipal[5] = {
			{"Alta de jugador",'1'},
			{"Baja de jugador",'2'},
			{"Modificacion de jugador",'3'},
			{"Informes",'4'},
			{"Salir",'5'}};
	eMenu menuInformes[7] ={
			{"Lista jugadores ordenados por alfabeticamente por nombre de confederacion y nombre de jugador",'1'},
			{"Lista confederacion con sus jugadores",'2'},
			{"Total y promedio de todos los salarios y cuantos jugadores cobran más del salario promedio",'3'},
			{"Confederación con mayor cantidad de años de contratos total",'4'},
			{"Porcentaje de jugadores por cada confederación",'5'},
			{"Región con más jugadores",'6'},
			{"Atras",'7'}
	};

	eConfederacion confederacion[TAMCONFEDERACION] = {
			{100,"CONMEBOL","SUDAMERICA",1916,OCUPADO},
			{101,"UEFA","EUROPA",1954,OCUPADO},
			{102,"AFC","ASIA",1954,OCUPADO},
			{103,"CAF","AFRICA",1957,OCUPADO},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,OCUPADO},
			{105,"OFC","OCEANIA",1966,OCUPADO}
	};
//	eJugador jugadorHardcodeado[MAXJUGADOR] = {
//			{1,"Juan Roman Riquelme","Volante",10,100,9720000,5,OCUPADO},
//			{2,"Diego Armando Maradona","Delantero",10,101,10000000,8,OCUPADO},
//			{4,"Emiliano Martinez","Arquero",1,101,6800000,4,OCUPADO},
//			{5,"Cristian Romero","Defensa",13,101,5500000,5,OCUPADO},
//			{6,"Lisandro Martinez","Defensa",2,101,5000000,3,OCUPADO},
//			{7,"Nicolas Otamendi","Defensa",19,101,3500000,2,OCUPADO},
//			{8,"Leandro Paredes","Volante",5,101,1700000,3,OCUPADO},
//			{9,"Rodrigo de Paul","Volante",7,101,3500000,4,OCUPADO},
//			{11,"Giovani Lo Celso","Volante",20,101,2200000,6,OCUPADO},
//			{3,"Angel Di Maria","Delantero",11,101,3500000,2,OCUPADO},
//			{10,"Lionel Messi","Delantero",10,101,50000000,3,OCUPADO},
//			{12,"Lautaro Martinez","Delantero",22,101,7500000,5,OCUPADO},
//			{13,"Sadio Mane","Delantero",17,103,2200000,4,OCUPADO},
//	};

/*ESTRUCURA HARDCODEADA.
 * PARA HABILIAR HARDCODEO CAMBIAR EL "tamJugador" DE LA LINEA 66 A LA CANTIDAD DE JUGADORES Y
 * DESCOMENTAR LA LINEA 73
*/
	eJugador jugador[MAXJUGADOR];
	eJugador jugadorFiltro[MAXJUGADOR];

	darDeBajaListaJugador(jugador, MAXJUGADOR);

	int tamJugador;
	int IDJugador;
	int opc;
	short salir;
	char reconfirmarSalir;
	float totalSalario;
	float promedioSalario;
	int tamAux;
	tamJugador = 0;
	IDJugador = 0;

	//copiarListaJugador(jugador, jugadorHardcodeado, tamJugador);

	do{
		salir = 0;
		opc = mostrarMenuYElegirOpcionAlfanumerico("MENU", "\nElija una opcion ","Opcion Invalida", menuPrincipal, 5);

		switch(opc){
			case '1':
				altaJugador(jugador, MAXJUGADOR, &tamJugador, confederacion, TAMCONFEDERACION, &IDJugador);
			break;

			case '2':
				bajaJugador(jugador, &tamJugador, confederacion, TAMCONFEDERACION);
			break;

			case '3':
				modificarJugador(jugador, tamJugador, confederacion, TAMCONFEDERACION);
			break;

			case '4':
				if(validarSiHayJugadores(jugador, tamJugador, 1)){
					do{
						opc = mostrarMenuYElegirOpcionAlfanumerico("INFORMES", "Elija una opcion", "Respuesta invalida", menuInformes, 7);

						switch(opc){
							case '1':
								ordenarListaJugadorAlfabeticoNomConfederacionNomJugador(jugadorFiltro, jugador, tamJugador, confederacion, TAMCONFEDERACION);
								mostrarListaJugador(jugadorFiltro, tamJugador, confederacion, TAMCONFEDERACION);
							break;

							case '2':
								mostrarListaJugadoresPorConfederacion(jugador, tamJugador, confederacion, TAMCONFEDERACION);
							break;

							case '3':
								totalSalario = obtenerSumaTotalSalarioJugadores(jugador, tamJugador);
								promedioSalario = obtenerPromedioSalarioJugadores(jugador, tamJugador);
								tamAux = obtenerJugadoresSalarioMayor(jugadorFiltro, jugador, tamJugador, promedioSalario);
								printf("\nTOTAL DE LOS SALARIOS $%.2f\n"
									   "PROMEDIO DE LOS SALARIOS $%.2f\n"
									   "\nJUGADORES CON UN SALARIO MAYOR AL PROMEDIO %d\n",
										totalSalario,
										promedioSalario,
										tamAux);

								mostrarListaJugador(jugadorFiltro, tamAux, confederacion, TAMCONFEDERACION);
							break;

							case '4':
								mostrarConfederacionMayorAniosContrato(jugador, tamJugador, confederacion, TAMCONFEDERACION);
							break;

							case '5':
								mostrarPorcentajeDeJugadoresListaConfederacion(jugador, tamJugador, confederacion, TAMCONFEDERACION);
							break;

							case '6':
								mostrarRegionConMasJugadores(jugador, tamJugador, confederacion, TAMCONFEDERACION);
							break;
						}
					}while(opc != '7');
				}
			break;

			case '5':
				imprYGuardarCharConMinYMax("¿Desea cerrar el programa?(1. Si | 0. NO)", "Respuesta invalida", &reconfirmarSalir, '0', '1', 0);
				if(reconfirmarSalir == '1'){
					salir = 1;
				};
			break;
		}
	}while(!salir);
	return EXIT_SUCCESS;
}
