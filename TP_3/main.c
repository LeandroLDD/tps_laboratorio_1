#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);

	eMenu menuPrincipal[11] = {
			{"CARGA DE ARCHIVOS",1},
			{"ALTA DE JUGADOR",2},
			{"MODIFICACION DE JUGADOR",3},
			{"BAJA DE JUGADOR",4},
			{"LISTADOS",5},
			{"CONVOCAR JUGADORES",6},
			{"ORDENAR Y LISTAR",7},
			{"GENERAR ARCHIVO BINARIO",8},
			{"CARGAR ARCHIVO BINARIO",9},
			{"GUARDAR ARCHIVOS .CSV",10},
			{"SALIR",11}};
	eMenu menuListado[4] = {
			{"TODOS LOS JUGADORES",'A'},
			{"TODAS LAS SELECCIONES",'B'},
			{"JUGADORES CONVOCADOS",'C'},
			{"ATRAS",'D'}};
	eMenu menuConvocarJugadores[3] = {
			{"CONVOCAR JUGADORES",'A'},
			{"QUITAR DE LA SELECCION",'B'},
			{"ATRAS",'C'}};
	eMenu menuOrdenarYListar[5] = {
			{"JUGADORES POR NACIONALIDAD",'A'},
			{"SELECCIONES POR CONFEDERACION",'B'},
			{"JUGADORES POR EDAD",'C'},
			{"JUGADORES POR NOMBRE",'D'},
			{"ATRAS",'E'}};

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaGentilicios = ll_newLinkedList();
    char errorNoJugadores[50] = "¡No hay jugadores!";
    int salir;
    int atras;
    int banderaBinaria;
    int idDisponible;
    char rutaJugadores[50] = "jugadores.csv";
    char rutaSelecciones[50] = "selecciones.csv";
    char rutaNacionalidades[50] = "nacionalidadesCopaMundial.csv";
    salir = 0;
    idDisponible = 0;

    do{
    	atras = 0;
    	printf("TAM jug: %d\n",ll_len(listaJugadores));
    	printf("TAM selec: %d\n",ll_len(listaSelecciones));
    	printf("TAM Gentilicios: %d\n",ll_len(listaGentilicios));
        switch(mostrarMenuYElegirOpcionNumerico("MENU FIFA", "Eliga una opcion", "Respuesta invalida", menuPrincipal, 11))
        {
            case 1:
				controller_leerIDDesdeTXT("jugadorIDdisponible.txt", &idDisponible);
				banderaBinaria = controller_cargarJugadoresDesdeTexto(rutaJugadores,listaJugadores);
				avisoBinario(banderaBinaria, "¡Se cargaron los jugadores exitosamente!", "¡Error al intentar cargar a los jugadores!");

				banderaBinaria = controller_cargarSeleccionesDesdeTexto(rutaSelecciones,listaSelecciones);
				if(banderaBinaria){ //Si cargó bien las selecciones, cargara los gentilicios
					controller_cargarGentiliciosDesdeTexto(rutaNacionalidades, listaGentilicios);
				}
				avisoBinario(banderaBinaria, "¡Se cargaron las selecciones exitosamente!", "¡Error al intentar cargar las selecciones!");
			break;

            case 2:
            	banderaBinaria = controller_darDeAltaJugador(listaJugadores, listaSelecciones,listaGentilicios, &idDisponible);
            	avisoBinario(banderaBinaria, "¡Se cargo al jugador exitosamente!", "¡Error al intentar cargar al jugador!");
			break;

            case 3:
            	banderaBinaria = controller_menuEditarJugador(listaJugadores,listaSelecciones,listaGentilicios);
            	avisoBinarioExtendido(banderaBinaria, "¡Se realizo el cambio exitosamente!", "",errorNoJugadores);
			break;

            case 4:
            	banderaBinaria = controller_removerJugador(listaJugadores);
            	avisoBinarioExtendido(banderaBinaria, "¡Jugador eliminado exitosamente!", "", errorNoJugadores);
			break;

            case 5:
            	do{
            		switch(mostrarMenuYElegirOpcionAlfanumerico("MENU LISTADOS","Eliga una opcion", "Respuesta invalida", menuListado, 4)){
            			case 'A':
            				banderaBinaria = controller_listarJugadoresTodosLosDatos(listaJugadores, listaSelecciones);
            				avisoBinario(banderaBinaria,"" , errorNoJugadores);
            			break;

            			case 'B':
            				banderaBinaria = controller_listarSelecciones(listaSelecciones);
            				avisoBinario(banderaBinaria, "", errorNoJugadores);
						break;

            			case 'C':
            				banderaBinaria = 0;
            				if(controller_hayJugadoresConvocados(listaJugadores)){
            					banderaBinaria = controller_listarJugadoresTodosLosDatosFiltro(jug_esConvocado, listaJugadores, listaSelecciones);
            				}
            				avisoBinarioExtendido(banderaBinaria, "", "No hay jugadores convocados", "Error en parametros");
						break;

            			case 'D':
            				atras = 1;
						break;
            		}
            	}while(!atras);
			break;

            case 6:
            	do{
            		switch(mostrarMenuYElegirOpcionAlfanumerico("MENU CONVOCAR JUGADORES", "Eliga una opcion", "Respuesta invalida", menuConvocarJugadores, 3)){
            			case 'A':
            				banderaBinaria = 0;
            				if(controller_validarLinkedList(listaJugadores)){
								banderaBinaria = controller_convocarJugador(listaSelecciones, listaJugadores,listaGentilicios);
            				}
								avisoBinarioExtendido(banderaBinaria, "¡Jugador convocado exitosamente!",errorNoJugadores,"¡Llego a la cantidad maxima de jugadres para está seleccion!");
						break;

            			case 'B':
            				banderaBinaria = controller_desconvocarJugador(listaJugadores, listaSelecciones);
            				avisoBinarioExtendido(banderaBinaria, "¡Jugador desconvocado exitosamente!","",errorNoJugadores);
						break;

            			case 'C':
            				atras = 1;
						break;
            		}
            	}while(!atras);
			break;

            case 7:
            	do{
					switch(mostrarMenuYElegirOpcionAlfanumerico("MENU ORDENAR Y LISTAR", "Eliga una opcion", "Respuesta invalida", menuOrdenarYListar, 5)){
						case 'A':
						break;

						case 'B':
						break;

						case 'C':
						break;

						case 'D':
						break;

						case 'E':
							atras = 1;
						break;
					}
				}while(!atras);
			break;

            case 8:
			break;

            case 9:
			break;

            case 10:
			break;

            case 11:
            	salir = 1;
			break;
        }
    }while(!salir);

    return 0;
}

