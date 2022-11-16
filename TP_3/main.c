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
    LinkedList* listaAuxiliar;
    char errorNoJugadores[50] = "¡No hay jugadores!";
    int salir;
    int atras;
    int banderaBinaria;
    int banderaCambiosRealizados;
    int idDisponible;
    char rutaIDs[50] = "jugadorIDdisponible.txt";
    char rutaJugadores[50] = "jugadores.csv";
    char rutaSelecciones[50] = "selecciones.csv";
    char rutaNacionalidades[50] = "nacionalidadesCopaMundial.csv";
    char rutaJugadoresConfedearcion[50] = "jugadoresDeUnaConfederacion.bin";
    salir = 0;
    idDisponible = 0;
    banderaCambiosRealizados = 0;

    do{
    	atras = 0;
        switch(mostrarMenuYElegirOpcionNumerico("MENU FIFA", "Eliga una opcion", "Respuesta invalida", menuPrincipal, 11))
        {
            case 1:
            	imprYGuardarEnteroConMinYMax("¿Está seguro que desea cargar los archivos?\n"
            								 "Se perderan todos los cambios no guardados de jugadores y seleccion (1. Si | 0. No) ", "Respuesta invalida", &banderaBinaria, 0, 1);
            	if(!banderaBinaria){
            		break;
            	}
				controller_leerIDDesdeTXT(rutaIDs, &idDisponible);
				banderaBinaria = controller_cargarJugadoresDesdeTexto(rutaJugadores,listaJugadores);
				avisoBinario(banderaBinaria, "¡Se cargaron los jugadores exitosamente!", "¡Error al intentar cargar a los jugadores!");

				banderaBinaria = controller_cargarSeleccionesDesdeTexto(rutaSelecciones,listaSelecciones);
				if(banderaBinaria == 1){ //Si cargó bien las selecciones, cargara los gentilicios
					controller_cargarGentiliciosDesdeTexto(rutaNacionalidades, listaGentilicios);
				}
				avisoBinario(banderaBinaria, "¡Se cargaron las selecciones exitosamente!", "¡Error al intentar cargar las selecciones!");
				banderaCambiosRealizados = 0;

			break;

            case 2:
            	banderaBinaria = controller_darDeAltaJugador(listaJugadores, listaSelecciones,listaGentilicios, &idDisponible);
            	if(banderaBinaria == 1){
            		banderaCambiosRealizados = 1;
            	}
            	avisoBinario(banderaBinaria, "¡Se cargo al jugador exitosamente!", "¡Error al intentar cargar al jugador!\n"
            			"*Posibles cuasas\n"
            			"- No hay paises cargados\n"
            			"- No existe la lista de jugadores\n"
            			"- La id es invalida\n");
			break;

            case 3:
            	banderaBinaria = controller_menuEditarJugador(listaJugadores,listaSelecciones,listaGentilicios);
            	if(banderaBinaria == 1){
					banderaCambiosRealizados = 1;
				}
            	avisoBinarioExtendido(banderaBinaria, "¡Se realizo el cambio exitosamente!", "",errorNoJugadores);
			break;

            case 4:
            	banderaBinaria = controller_darDeBajaJugador(listaJugadores, listaSelecciones);
            	if(banderaBinaria == 1){
					banderaCambiosRealizados = 1;
				}
            	avisoBinarioExtendido(banderaBinaria, "¡Jugador eliminado exitosamente!", "", errorNoJugadores);
			break;

            case 5:
            	do{
            		switch(mostrarMenuYElegirOpcionAlfanumerico("MENU LISTADOS","Eliga una opcion", "Respuesta invalida", menuListado, 4)){
            			case 'A':
            				banderaBinaria = controller_listarJugadores(listaJugadores);
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
							banderaBinaria = controller_menuConvocarJugador(listaSelecciones, listaJugadores,listaGentilicios);
							if(banderaBinaria == 1){
								banderaCambiosRealizados = 1;
							}
							if(banderaBinaria == -2){
								break;
							}
							avisoBinarioExtendido(banderaBinaria, "¡Jugador convocado exitosamente!","¡No hay mas cupos para convocar de ninguna seleccion!","¡Faltan selecciones y/o selecciones!");
						break;

            			case 'B':
            				banderaBinaria = controller_menuDesconvocarJugador(listaJugadores, listaSelecciones);
            				if(banderaBinaria == 1){
								banderaCambiosRealizados = 1;
							}
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
							banderaBinaria = controller_listarJugadoresOrdenados(listaJugadores, controller_cmpJugadorNacionalidad, -1);
							avisoBinario(banderaBinaria, "", errorNoJugadores);
						break;

						case 'B':
							banderaBinaria = controller_listarSeleccionOrdenadas(listaSelecciones, controller_cmpSeleccionConfederacion, -1);
							avisoBinario(banderaBinaria, "", "¡No hay selecciones!");
						break;

						case 'C':
							banderaBinaria = controller_listarJugadoresOrdenados(listaJugadores, controller_cmpJugadorEdad, -1);
							avisoBinario(banderaBinaria, "", errorNoJugadores);
						break;

						case 'D':
							banderaBinaria = controller_listarJugadoresOrdenados(listaJugadores, controller_cmpJugadorNombre, -1);
							avisoBinario(banderaBinaria, "", errorNoJugadores);
						break;

						case 'E':
							atras = 1;
						break;
					}
				}while(!atras);
			break;

            case 8:
            	banderaBinaria = controller_guardarJugadoresDeUnaConfederacionModoBinario(rutaJugadoresConfedearcion, listaJugadores, listaSelecciones);
            	if(banderaBinaria == 1){
					banderaCambiosRealizados = 1;
				}
            	if(banderaBinaria == 0){
					break;
				}
            	avisoBinario(banderaBinaria, "¡El archivo binario se genero exitosamente!", "¡No hay ningun jugador convocado!");
			break;

            case 9:
            	listaAuxiliar = ll_newLinkedList();
            	banderaBinaria = controller_cargarJugadoresDesdeBinario(rutaJugadoresConfedearcion, listaAuxiliar);
            	if(banderaBinaria == 1){
            		controller_listarJugadores(listaAuxiliar);
            	}
            	ll_deleteLinkedList(listaAuxiliar);

            	avisoBinario(banderaBinaria, "", "¡NO se genero el archivo binario!");
			break;

            case 10:
            	if(!banderaCambiosRealizados){
					imprAviso("¡Todavia no realizo ningun cambio!");
					break;
				}
            	imprYGuardarEnteroConMinYMax("¿Está seguro que desea guardar todos los\n"
            								 "cambios de jugadors y selecciones? (1. Si | 0. No)", "Respuesta invalida", &banderaBinaria, 0, 1);
            	if(!banderaBinaria){
            		break;
            	}

				banderaBinaria = controller_guardarJugadoresModoTexto(rutaJugadores, listaJugadores);
				avisoBinario(banderaBinaria, "¡Se guardaron los jugadores exitosamente!", "¡Error al intentar guardar los jugadores");

				banderaBinaria = controller_guardarSeleccionesModoTexto(rutaSelecciones, listaSelecciones);
				avisoBinario(banderaBinaria, "¡Se guardaron las selecciones exitosamente!", "¡Error al intentar guardar las selecciones");

				controller_escribirIDEnTXT(rutaIDs, idDisponible);
				banderaCambiosRealizados = 0;
			break;

            case 11:
            	printf("¿Desea sair del programa?(1. Si | 0. No)");
            	if(banderaCambiosRealizados){
            		printf("\n*HAY CAMBIOS NO GUARDADOS*\n");
            	}
            	imprYGuardarEnteroConMinYMax("", "Respuesta invalida", &banderaBinaria, 0, 1);

            	if(banderaBinaria == 1){
            		salir = 1;
            	}
			break;
        }
    }while(!salir);

    return 0;
}

