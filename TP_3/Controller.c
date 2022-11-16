#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "leangenerales.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador){
	int ok;
	FILE* pArchivo;
	ok = -1;
	pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){
		ok = 0;
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			ll_clear(pArrayListJugador);
			ok = parser_JugadorFromText(pArchivo, pArrayListJugador);
		}

		fclose(pArchivo);
	}
    return ok;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int ok;
	FILE* pArchivo;
	ok = -1;
	pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){
		ok = 0;
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL){
			ll_clear(pArrayListJugador);
			ok = parser_JugadorFromBinary(pArchivo, pArrayListJugador);
		}

		fclose(pArchivo);
	}
	return ok;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador){
	int indiceRetorno;
	Jugador* jugadorNuevo;
	jugadorNuevo = NULL;
	indiceRetorno = -1;

	if(pArrayListJugador != NULL){
		jugadorNuevo = jug_new();
		if(jugadorNuevo != NULL){
			ll_add(pArrayListJugador, jugadorNuevo);
			indiceRetorno =  ll_indexOf(pArrayListJugador, jugadorNuevo);
		}
	}
    return indiceRetorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador){
	int idModificar;
	idModificar = 0;

	if(controller_validarLinkedList(pArrayListJugador)){
		idModificar = controller_pedirJugadorPorID(pArrayListJugador, "Eliga la ID del jugador a modificar",1);
	}
    return idModificar;
}
int controller_menuEditarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio){
	eMenu menuModificar[5] = {
			{"Nombre completo",'A'},
			{"Edad",'B'},
			{"Posicion",'C'},
			{"Nacionalidad",'D'},
			{"Atras",'E'}};
	Jugador* ptrJugadorModificar;
	int idModificar;
	int atras;
	int ok;
	ok = -1;
	atras = 0;

	idModificar = controller_editarJugador(pArrayListJugador);//Obtengo la ID a modificar
	ptrJugadorModificar = controller_obtenerJugadorPorID(pArrayListJugador, idModificar);//Obtengo al jugador por la ID previamente pedida y validada

	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && controller_validarLinkedList(pArrayListGentilicio)){
		ok = 0;
		controller_mostrarUnJugador(ptrJugadorModificar, pArrayListSeleccion);
		switch(mostrarMenuYElegirOpcionAlfanumerico("Menu Modificar Jugador", "Eliga una opcion", "Opcion invalida", menuModificar, 5)){
			case 'A':
				controller_pedirJugadorNombreCompleto(ptrJugadorModificar);
			break;

			case 'B':
				controller_pedirJugadorEdad(ptrJugadorModificar);
			break;

			case 'C':
				controller_pedirJugadorPosicion(ptrJugadorModificar);
			break;

			case 'D':
				controller_pedirJugadorNacionalidad(ptrJugadorModificar, pArrayListSeleccion, pArrayListGentilicio);
			break;

			case 'E':
				atras = 1;
			break;
		}
		if(!atras){
			ok = 1;
		}
	}
	return ok;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador){
	int idEliminar;
	idEliminar = -1;

	if(controller_validarLinkedList(pArrayListJugador)){
		idEliminar = controller_pedirJugadorPorID(pArrayListJugador, "Eliga la ID del jugador a eliminar",1);
	}
    return idEliminar;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador){
	int ok;
	Jugador* jugadorMostrar;
	ok = 0;

	if(controller_validarLinkedList(pArrayListJugador)){
		ok = 1;
		jug_mostrarTextCabecera(0);
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			jugadorMostrar = ll_get(pArrayListJugador, i);
			jug_mostrar(jugadorMostrar);
			puts("");
		}

		puts("=================================================================================");
	}
	return ok;
}
int controller_listarJugadoresTodosLosDatos(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	Jugador* jugadorMostrar;
	ok = 0;

	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && !ll_isEmpty(pArrayListJugador)){
		ok = 1;
		jug_mostrarTextCabecera(1);
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			jugadorMostrar = ll_get(pArrayListJugador, i);
			jug_mostrar(jugadorMostrar);
			controller_mostrarPaisSiConvocado(jugadorMostrar, pArrayListSeleccion);
		}

		puts("==================================================================================================");
	}
	return ok;
}
int controller_listarJugadoresTodosLosDatosFiltro(int (*pFunc)(Jugador* ),LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	Jugador* jugadorMostrar;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && pFunc != NULL){
		ok = 0;
		jug_mostrarTextCabecera(1);
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			jugadorMostrar = ll_get(pArrayListJugador, i);

			if(pFunc(jugadorMostrar)){
				ok = 1;
				jug_mostrar(jugadorMostrar);
				controller_mostrarPaisSiConvocado(jugadorMostrar, pArrayListSeleccion);
			}
		}

		puts("==================================================================================================");
	}
	return ok;
}
int controller_listarJugadoresOrdenados(LinkedList* pArrayListJugador, int (*ordenamiento)(void*,void*), int orden){
	int ok;
	LinkedList* listaOrdenada;
	ok = 0;

	if(controller_validarLinkedList(pArrayListJugador) && ordenamiento != NULL){
		ok = 1;
		listaOrdenada = ll_clone(pArrayListJugador);
		if(orden != 0 && orden != 1){
			imprYGuardarEnteroConMinYMax("1. Menor a mayor\n0. Mayor a menor\n", "Respuesta invalida", &orden, 0, 1);
		}
		controller_ordenarLista(listaOrdenada, ordenamiento, orden);
		controller_listarJugadores(listaOrdenada);
	}

	return ok;
}
int controller_mostrarUnJugador(Jugador* pJugador, LinkedList* pArrayListSeleccion){
	int ok;
	LinkedList* jugadorMostrar;
	ok = 0;

	if(pJugador != NULL){
		ok = 1;
		jugadorMostrar = ll_newLinkedList();
		ll_add(jugadorMostrar, pJugador);

		controller_listarJugadoresTodosLosDatos(jugadorMostrar, pArrayListSeleccion);
	}
	return ok;
}
int controller_mostrarPaisSiConvocado(Jugador* pJugador ,LinkedList* pArrayListSeleccion){
	int ok;
	int idSelec;
	char nomSelec[50];
	Seleccion* seleccionMostrar;
	jug_getIdSeleccion(pJugador, &idSelec);
	strcpy(nomSelec,"No convocado");
	ok = 0;

	if(pJugador != NULL && controller_validarLinkedList(pArrayListSeleccion) && idSelec > 0){
		ok = 1;
		seleccionMostrar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSelec);
		selec_getPais(seleccionMostrar, nomSelec);
	}
		printf(" %-15s|\n",nomSelec);
	return ok;
}

int controller_obtenerJugadoresConvocables(int idSelecConvocar, LinkedList* listaJugadoresConvocablesRetorno,LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, LinkedList* pArrayListGentilicio){
	int ok;
	char nacionalidadConcovar[50];
	Gentilicio* nacionalidadConvocar;
	Seleccion* selecConvocar;
	int cantidadConvocados;
	int maxJugadores = 22;

	ok = -1;
	if(controller_validarSeleccionPorID(pArrayListSeleccion, idSelecConvocar) && controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && controller_validarLinkedList(pArrayListGentilicio)){
		ok = 1;
		selecConvocar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSelecConvocar);
		selec_getConvocados(selecConvocar, &cantidadConvocados);

		nacionalidadConvocar = controller_obtenerGentilicioPorID(idSelecConvocar, pArrayListGentilicio);//Con la id obtengo la nacionalidad
		gen_getDescripcion(nacionalidadConvocar, nacionalidadConcovar);
		if(cantidadConvocados >= maxJugadores || !controller_obtenerLinkedListFiltro(pArrayListJugador, listaJugadoresConvocablesRetorno, controller_esJugadorNacionalidad, nacionalidadConcovar)){
			ok = 0;
		}
	}
	return ok;
}

int controller_menuConvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, LinkedList* pArrayListGentilicio){
	int ok;
	int idSelecConvocar;
	int idJugadorConvocar;
	LinkedList* listaJugadoresConvocar;
	Jugador* JugadorConvocar;
	Seleccion* selecConvocar;
	int cantidadConvocados;
	int banderaError;
	int maxJugadores = 22;
	listaJugadoresConvocar = ll_newLinkedList();
	ok = -1;
	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && controller_validarLinkedList(pArrayListGentilicio)){
		ok = 0;
		if(controller_validarLinkedListFiltro(pArrayListJugador,controller_esJugadorConvocado,0) && controller_validarLinkedListFiltro(pArrayListSeleccion,controller_esSeleccionCantidadConvocadosMenor,&maxJugadores)){
			ok = 1;
			do{
				banderaError = 0;
				idSelecConvocar = controller_pedirSeleccionPorID(pArrayListSeleccion, "Eliga una seleccion (0. Atras)",1,0);//Pide la id de la selec
				if(idSelecConvocar == 0){
					ok = -2;
					break;
				}
				if(controller_obtenerJugadoresConvocables(idSelecConvocar, listaJugadoresConvocar, pArrayListSeleccion, pArrayListJugador, pArrayListGentilicio) == 0){
					banderaError = 1;
					imprAviso("¡Seleccion invalida!\n"
							  "*Posibles cuasas\n"
							  "- La seleccion llego a la maxima cantidad de jugadores\n"
							  "- No hay jugadores disponbiles en el pais\n");
				}
			}while(banderaError);
			if(idSelecConvocar != 0){
				idJugadorConvocar = controller_pedirJugadorPorID(listaJugadoresConvocar, "Eliga la ID de un jugador",1);
				JugadorConvocar = controller_obtenerJugadorPorID(pArrayListJugador, idJugadorConvocar);

				jug_setIdSeleccion(JugadorConvocar, idSelecConvocar);

				selecConvocar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSelecConvocar);
				selec_getConvocados(selecConvocar, &cantidadConvocados);
				selec_setConvocados(selecConvocar, cantidadConvocados+1);
			}
		}
	}

	return ok;
}
int controller_menuDesconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	int idJugadorDesconvocar;
	int reconfirmacion;
	int auxObtenerConvocado;
	Jugador* jugadorDesconvocar;
	LinkedList* listaJugadoresConvocados;
	ok = -1;
	reconfirmacion = 0;
	auxObtenerConvocado = 1;

	if(controller_hayJugadoresConvocados(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion)){
		ok = 0;
		listaJugadoresConvocados = ll_newLinkedList();

		controller_obtenerLinkedListFiltro(pArrayListJugador, listaJugadoresConvocados, controller_esJugadorConvocado, &auxObtenerConvocado);
		controller_listarJugadoresTodosLosDatos(listaJugadoresConvocados, pArrayListSeleccion);
		idJugadorDesconvocar = controller_pedirJugadorPorID(listaJugadoresConvocados, "Eliga la ID del jugador a desconvocar ",0);
		jugadorDesconvocar = controller_obtenerJugadorPorID(listaJugadoresConvocados, idJugadorDesconvocar);

		controller_mostrarUnJugador(jugadorDesconvocar, pArrayListSeleccion);
		imprYGuardarEnteroConMinYMax("¿Está seguro que desea desconvocar este jugador?(1. Si | 0. No)", "Respuesta invalida", &reconfirmacion, 0, 1);
		if(reconfirmacion){
			ok = 1;
			controller_desconvocarJugador(jugadorDesconvocar, pArrayListSeleccion);
		}
	}
	return ok;
}
int controller_desconvocarJugador(Jugador* pJugador, LinkedList* pArrayListSeleccion){
	int ok;
	int idSeleccionDesconvocar;
	int cantidadConvocados;
	Seleccion* selecDesconvocar;
	ok = 0;

	if(jug_esConvocado(pJugador) && controller_validarLinkedList(pArrayListSeleccion)){
		ok = 1;
		jug_getIdSeleccion(pJugador, &idSeleccionDesconvocar);
		jug_setIdSeleccion(pJugador, 0);

		selecDesconvocar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSeleccionDesconvocar);
		selec_getConvocados(selecDesconvocar, &cantidadConvocados);
		selec_setConvocados(selecDesconvocar, cantidadConvocados-1);
	}
	return ok;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador){
	int ok;
	ok = 0;

    return ok;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador){
	int ok;
	FILE* pArchivo;
	Jugador* jugadorAgregar;
	ok = -1;

	if(path != NULL && pArrayListJugador != NULL){
		ok = 0;

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){
			ok = 1;
			fprintf(pArchivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
			for(int i = 0; i < ll_len(pArrayListJugador);i++){
				jugadorAgregar = ll_get(pArrayListJugador, i);
				jug_escribirText(pArchivo, jugadorAgregar);
			}
		}
		fclose(pArchivo);
	}
    return ok;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){
	int ok;
	FILE* pArchivo;
	Jugador* jugadorAgregar;
	ok = -1;

	if(path != NULL && pArrayListJugador != NULL){
		ok = 0;

		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL){
			ok = 1;
			for(int i = 0; i < ll_len(pArrayListJugador);i++){
				jugadorAgregar = ll_get(pArrayListJugador, i);
				jug_escribirBin(pArchivo, jugadorAgregar);
			}
		}

		fclose(pArchivo);
	}
	return ok;
}
int controller_guardarJugadoresFiltradosModoBinario(char* path , LinkedList* pArrayListJugador, void* criterio, int (*pFunc)(LinkedList*,int indice, void*)){
	int ok;
	LinkedList* listaFiltrada;
	ok = -1;

	if(path != NULL && controller_validarLinkedList(pArrayListJugador) && criterio != NULL && pFunc != NULL){
		ok = 0;
		listaFiltrada = ll_newLinkedList();
		if(controller_obtenerLinkedListFiltro(pArrayListJugador, listaFiltrada, pFunc, criterio)){
			ok = 1;
			controller_guardarJugadoresModoBinario(path, listaFiltrada);
		}
	}

	return ok;
}

int controller_guardarJugadoresDeUnaConfederacionModoBinario(char* path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	int banderaObtenerJugadorsConvocados;
	int idSeleccionesConvocados;
	LinkedList* SeleccionesConvocados;
	ok = -1;

	if(path != NULL && controller_hayJugadoresConvocados(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion)){
		ok = 0;

		SeleccionesConvocados = ll_newLinkedList();
		banderaObtenerJugadorsConvocados = 1;
		controller_obtenerLinkedListFiltro(pArrayListSeleccion, SeleccionesConvocados, controller_esSeleccionConvocados, &banderaObtenerJugadorsConvocados);
		idSeleccionesConvocados = controller_pedirSeleccionPorID(SeleccionesConvocados, "Eliga la ID de la confederacion a guardar jugadores (0. Atras)",1,0);

		if(idSeleccionesConvocados != 0){
			ok = 1;
			controller_guardarJugadoresFiltradosModoBinario(path, pArrayListJugador, &idSeleccionesConvocados, controller_esJugadorIdSeleccion);
			ll_deleteLinkedList(SeleccionesConvocados);
		}
	}
	return ok;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion){
	int ok;
	FILE* pArchivo;
	ok = -1;
	pArchivo = NULL;

	if(path != NULL && pArrayListSeleccion != NULL){
		ok = 0;
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			ll_clear(pArrayListSeleccion);
			ok = parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
		}

		fclose(pArchivo);
	}
	return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion){
	int ok;
	Seleccion* SeleccionMostrar;
	int tamSeleccion;
	ok = 0;

	if(controller_validarLinkedList(pArrayListSeleccion)){
		ok = 1;
		tamSeleccion = ll_len(pArrayListSeleccion);

		selec_mostrarTextCabecera("selecciones.csv");
		for(int i = 0; i < tamSeleccion; i++){
			SeleccionMostrar = ll_get(pArrayListSeleccion, i);
			selec_mostrar(SeleccionMostrar);
		}
		puts("====================================================");

	}
    return ok;
}
int controller_listarSeleccionOrdenadas(LinkedList* pArrayListSeleccion, int (*ordenamiento)(void*,void*), int orden){
	int ok;
	LinkedList* listaOrdenada;
	ok = 0;

	if(controller_validarLinkedList(pArrayListSeleccion) && ordenamiento != NULL){
		ok = 1;
		listaOrdenada = ll_clone(pArrayListSeleccion);
		if(orden != 0 && orden != 1){
			imprYGuardarEnteroConMinYMax("1. Menor a mayor\n0. Mayor a menor\n", "Respuesta invalida", &orden, 0, 1);
		}
		controller_ordenarLista(listaOrdenada, ordenamiento, orden);
		controller_listarSelecciones(listaOrdenada);
	}

	return ok;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion){
	int ok;
	FILE* pArchivo;
	Seleccion* seleccionAgregar;
	ok = -1;

	if(path != NULL && pArrayListSeleccion != NULL){
		ok = 0;

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){
			ok = 1;
			fprintf(pArchivo,"id,pais,confederacion,convocados\n");
			for(int i = 0; i < ll_len(pArrayListSeleccion);i++){
				seleccionAgregar = ll_get(pArrayListSeleccion, i);
				selec_escribirText(pArchivo, seleccionAgregar);
			}
		}

		fclose(pArchivo);
	}
	return ok;
}

int controller_darDeAltaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,LinkedList* pArrayListGentilicio, int *id){
	int ok;
	Jugador* jugadorNuevo;
	int indiceJugadorNuevo;
	ok = -1;

	if(pArrayListJugador != NULL && controller_validarLinkedList(pArrayListSeleccion) && id != NULL){
		ok = 0;
		indiceJugadorNuevo = controller_agregarJugador(pArrayListJugador);
		if(indiceJugadorNuevo > -1){
			ok = 1;
			jugadorNuevo = ll_get(pArrayListJugador, indiceJugadorNuevo);
			controller_pedirJugadorDatos(jugadorNuevo, pArrayListSeleccion, pArrayListGentilicio);
			jug_setId(jugadorNuevo, controller_IDAsignar(id));
		}
	}

	return ok;
}
int controller_darDeBajaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	int indiceEliminarLinkedList;
	int reconfirmacion;
	int idEliminar;
	Jugador* jugadorEliminar;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador)){
		ok = 0;
		idEliminar = controller_removerJugador(pArrayListJugador);
		jugadorEliminar = controller_obtenerJugadorPorID(pArrayListJugador, idEliminar);

		indiceEliminarLinkedList = ll_indexOf(pArrayListJugador, jugadorEliminar);

		controller_mostrarUnJugador(jugadorEliminar, pArrayListSeleccion);
		imprYGuardarEnteroConMinYMax("¿Desea eliminar al jugador elegido?(1. Si | 0. No) ", "Respuesta incorrecta", &reconfirmacion, 0, 1);
		if(reconfirmacion){
			ok = 1;
			if(jug_esConvocado(jugadorEliminar)){
				controller_desconvocarJugador(jugadorEliminar, pArrayListSeleccion);
			}
			ll_remove(pArrayListJugador, indiceEliminarLinkedList);
			jug_delete(jugadorEliminar);
		}
	}

	return ok;
}
int controller_pedirJugadorPorID(LinkedList* pArrayListJugador, char* msj, int imprJugadores){
	int idElegida;
	int banderaJugadorExiste;
	idElegida = -1;

	if(controller_validarLinkedList(pArrayListJugador) && msj != NULL){
		if(imprJugadores == 1){
			controller_listarJugadores(pArrayListJugador);
		}
		do{
			imprYGuardarEntero(msj, &idElegida);
			banderaJugadorExiste = controller_validarJugadorPorID(pArrayListJugador, idElegida);
			if(!banderaJugadorExiste){
				imprAviso("¡La ID no existe!");
			}
		}while(!banderaJugadorExiste);
	}
	return idElegida;
}
int controller_validarJugadorPorID(LinkedList* pArrayListJugador, int id){
	int banderaJugadorEncontrado;
	Jugador* aux;
	int idAux;
	aux = NULL;
	banderaJugadorEncontrado = 0;
	if(controller_validarLinkedList(pArrayListJugador)){
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			aux = ll_get(pArrayListJugador, i);
			jug_getId(aux, &idAux);

			if(idAux == id){
				banderaJugadorEncontrado = 1;
				break;
			}
		}
	}
	return banderaJugadorEncontrado;
}
Jugador* controller_obtenerJugadorPorID(LinkedList* pArrayListJugador, int id){
	Jugador* ptrJugadorRetorno;
	Jugador* aux;
	int idAux;
	aux = NULL;
	ptrJugadorRetorno = NULL;
	if(controller_validarLinkedList(pArrayListJugador)){
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			aux = ll_get(pArrayListJugador, i);
			jug_getId(aux, &idAux);

			if(idAux == id){
				ptrJugadorRetorno = aux;
				break;
			}
		}
	}
	return ptrJugadorRetorno;
}
int controller_pedirJugadorNombreCompleto(Jugador* this){
	int ok;
	char nombreCompleto[100];
	ok = 0;

	if(this != NULL){
		imprYGuardarCadenaConMinYMax("Ingrese el nombre completo", "Nombre invalido", nombreCompleto, 2, 50, 1);
		jug_setNombreCompleto(this, nombreCompleto);
		ok = 1;
	}
	return ok;
}
int controller_pedirJugadorEdad(Jugador* this){
	int ok;
	int edad;
	ok = 0;

	if(this != NULL){
		imprYGuardarEnteroConMinYMax("Ingrese la edad", "Edad invalida", &edad, 2, 100);
		jug_setEdad(this, edad);
		ok = 1;
	}
	return ok;
}
int controller_pedirJugadorPosicion (Jugador* this){
	int ok;
	char posicion[30];
	ok = 0;

	if(this != NULL){
		imprYGuardarCadenaConMinYMax("Ingrese la posicion", "Posicion invalida", posicion, 2, 29,1);
		jug_setPosicion(this, posicion);
		ok = 1;
	}
	return ok;
}
int controller_pedirJugadorNacionalidad(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio){
	int ok;
	int idPaisElegido;
	char gentilicio[50];
	Gentilicio* gentilicioElegido;
	Seleccion* pPaisElegido;
	ok = -1;

	if(this != NULL && pArrayListSeleccion != NULL){
		ok = 0;
		idPaisElegido = controller_pedirSeleccionPorID(pArrayListSeleccion, "Eliga la ID del pais",0,0);
		pPaisElegido = controller_obtenerSeleccionPorID(pArrayListSeleccion, idPaisElegido);
		selec_getPais(pPaisElegido, gentilicio);//De forma predeterminada se guarda el pais

		gentilicioElegido = controller_obtenerGentilicioPorID(idPaisElegido, pArrayListGentilicio);
		if(gentilicioElegido != NULL){//Si no existe el gentilicio del pais, se guarda el nombre del pais
			gen_getDescripcion(gentilicioElegido, gentilicio); //Si encontro el gentilicio, se guarda el gentilicio
			ok = 1;
		}
		jug_setNacionalidad(this, gentilicio);
	}
	return ok;
}

int controller_pedirJugadorDatos(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio){
	int ok;
	ok = 0;

	if(this != NULL && pArrayListSeleccion != NULL){
		puts("INGRESAR JUGADOR");

		controller_pedirJugadorNombreCompleto(this);
		controller_pedirJugadorEdad(this);
		controller_pedirJugadorPosicion(this);
		controller_pedirJugadorNacionalidad(this,pArrayListSeleccion,pArrayListGentilicio);
		jug_setIdSeleccion(this, 0);
		ok = 1;
	}
	return ok;
}

int controller_hayJugadoresConvocados(LinkedList* pArrayListJugador){
	int banderaHayConvocados;
	Jugador* auxJugador;
	banderaHayConvocados = 0;

	if(controller_validarLinkedList(pArrayListJugador)){
		for(int i = 0 ; i < ll_len(pArrayListJugador); i++){
			auxJugador = ll_get(pArrayListJugador, i);
			if(jug_esConvocado(auxJugador)){
				banderaHayConvocados = 1;
			}
		}
	}
	return banderaHayConvocados;
}

int controller_cmpJugadorNacionalidad(void* unJugador, void* otroJugador){
	int cmp;
	char nacionalidadJug1[50];
	char nacionalidadJug2[50];
	Jugador* jugador1;
	Jugador* jugador2;

	if(unJugador != NULL && otroJugador != NULL){
		jugador1 = (Jugador*)unJugador;
		jugador2 = (Jugador*)otroJugador;
		jug_getNacionalidad(jugador1, nacionalidadJug1);
		jug_getNacionalidad(jugador2, nacionalidadJug2);

		cmp = strcmp(nacionalidadJug1,nacionalidadJug2);
	}
	return cmp;
}
int controller_cmpJugadorEdad(void* unJugador, void* otroJugador){
	int cmp;
	int edadJug1;
	int edadJug2;
	Jugador* jugador1;
	Jugador* jugador2;

	if(unJugador != NULL && otroJugador != NULL){
		jugador1 = (Jugador*)unJugador;
		jugador2 = (Jugador*)otroJugador;
		jug_getEdad(jugador1, &edadJug1);
		jug_getEdad(jugador2, &edadJug2);

		cmp = 0;

		if(edadJug1 > edadJug2){
			cmp = 1;
		}
		if(edadJug1 < edadJug2){
			cmp = -1;
		}
	}
	return cmp;
}
int controller_cmpJugadorNombre(void* unJugador, void* otroJugador){
	int cmp;
	char nombreJug1[50];
	char nombreJug2[50];
	Jugador* jugador1;
	Jugador* jugador2;

	if(unJugador != NULL && otroJugador != NULL){
		jugador1 = (Jugador*)unJugador;
		jugador2 = (Jugador*)otroJugador;
		jug_getNombreCompleto(jugador1, nombreJug1);
		jug_getNombreCompleto(jugador2, nombreJug2);

		cmp = strcmp(nombreJug1,nombreJug2);
	}
	return cmp;
}
int controller_cmpSeleccionConfederacion(void* unaConfederacion, void* otraConfederacion){
	int cmp;
	char confeSelec1[50];
	char confeSelec2[50];
	Seleccion* seleccion1;
	Seleccion* seleccion2;

	if(unaConfederacion != NULL && otraConfederacion != NULL){
		seleccion1 = (Seleccion*)unaConfederacion;
		seleccion2 = (Seleccion*)otraConfederacion;
		selec_getConfederacion(seleccion1, confeSelec1);
		selec_getConfederacion(seleccion2, confeSelec2);

		cmp = strcmp(confeSelec1,confeSelec2);
	}
	return cmp;
}

int controller_esJugadorConvocado(LinkedList* pArrayListJugador,int indiceArray, void* convocadoCtr){
	int ok;
	int idSeleccion;
	int *banderaConvocado;
	Jugador* auxJugador;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador) && convocadoCtr != NULL){
		ok = 0;
		banderaConvocado = convocadoCtr;
		auxJugador = ll_get(pArrayListJugador, indiceArray);
		jug_getIdSeleccion(auxJugador, &idSeleccion);
		if(*banderaConvocado == 1 && idSeleccion != 0){
			ok = 1;
		}
		if(*banderaConvocado == 0 && idSeleccion == 0){
			ok = 1;
		}
	}

	return ok;
}
int controller_esJugadorIdSeleccion(LinkedList* pArrayListJugador,int indiceArray, void* idSeleccionCtr){
	int ok;
	int idSeleccionJug;
	int *idSeleccionCriterio;
	Jugador* auxJugador;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador) && idSeleccionCtr != NULL){
		ok = 0;
		idSeleccionCriterio = idSeleccionCtr;
		auxJugador = ll_get(pArrayListJugador, indiceArray);
		jug_getIdSeleccion(auxJugador, &idSeleccionJug);

		if(idSeleccionJug == *idSeleccionCriterio){
			ok = 1;
		}
	}

	return ok;
}
int controller_esJugadorNacionalidad(LinkedList* pArrayListJugador,int indiceArray, void* nacionalidadCtr){
	int ok;
	int idSeleccion;
	char nacionalidadJugador[50];
	Jugador* auxJugador;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador) && nacionalidadCtr != NULL){
		ok = 0;
		auxJugador = ll_get(pArrayListJugador, indiceArray);
		jug_getNacionalidad(auxJugador, nacionalidadJugador);
		jug_getIdSeleccion(auxJugador, &idSeleccion);
		if(strcmp(nacionalidadJugador,nacionalidadCtr) == 0 && idSeleccion == 0){
			ok = 1;
		}
	}

	return ok;
}

int controller_pedirSeleccionPorID(LinkedList* pArrayListSeleccion, char* msj, short agregarOpcSalir, int opcSalir){
	int idElegida;
	int banderaSeleccionExiste;
	idElegida = -1;

	if(controller_validarLinkedList(pArrayListSeleccion) && !ll_isEmpty(pArrayListSeleccion)){
		controller_listarSelecciones(pArrayListSeleccion);
		do{
			imprYGuardarEntero(msj, &idElegida);

			if(agregarOpcSalir == 1 && idElegida == opcSalir){
				break;
			}
			banderaSeleccionExiste = controller_validarSeleccionPorID(pArrayListSeleccion, idElegida);
			if(!banderaSeleccionExiste){
				imprAviso("¡La ID no existe!");
			}
		}while(!banderaSeleccionExiste);
	}
	return idElegida;
}
int controller_validarSeleccionPorID(LinkedList* pArrayListSeleccion, int id){
	int banderaSeleccionEncontrada;
	Seleccion* aux;
	int idAux;
	aux = NULL;
	banderaSeleccionEncontrada = 0;
	if(controller_validarLinkedList(pArrayListSeleccion) && !ll_isEmpty(pArrayListSeleccion)){
		for(int i = 0 ; i < ll_len(pArrayListSeleccion); i++){
			aux = ll_get(pArrayListSeleccion, i);
			selec_getId(aux, &idAux);

			if(idAux == id){
				banderaSeleccionEncontrada = 1;
				break;
			}
		}
	}
	return banderaSeleccionEncontrada;
}
Seleccion* controller_obtenerSeleccionPorID(LinkedList* pArrayListSeleccion, int id){
	Seleccion* ptrSeleccionRetorno;
	Seleccion* aux;
	int idAux;
	aux = NULL;
	ptrSeleccionRetorno = NULL;
	if(controller_validarLinkedList(pArrayListSeleccion)){
		for(int i = 0 ; i < ll_len(pArrayListSeleccion); i++){
			aux = ll_get(pArrayListSeleccion, i);
			selec_getId(aux, &idAux);
			if(idAux == id){
				ptrSeleccionRetorno = aux;
				break;
			}
		}
	}
	return ptrSeleccionRetorno;
}

int controller_esSeleccionConvocados(LinkedList* pArrayListSeleccion, int indiceArray, void* validConvocados){
	int ok;
	int *banderaValidarConvocados;
	int cantidadConvocados;
	Seleccion* auxSeleccion;
	ok = -1;

	if(controller_validarLinkedList(pArrayListSeleccion)){
		ok = 0;
		banderaValidarConvocados = validConvocados;
		auxSeleccion = ll_get(pArrayListSeleccion, indiceArray);
		selec_getConvocados(auxSeleccion, &cantidadConvocados);

		if(cantidadConvocados > 0 && *banderaValidarConvocados == 1){
			ok = 1;
		}
		if(cantidadConvocados == 0 && *banderaValidarConvocados == 0){
			ok = 0;
		}
	}

	return ok;
}

int controller_esSeleccionCantidadConvocadosMenor(LinkedList* pArrayListSeleccion, int indiceArray, void* cantConvocados){
	int ok;
	int *ptrCantConvocados;
	int cantidadConvocados;

	Seleccion* auxSeleccion;
	ok = -1;

	if(controller_validarLinkedList(pArrayListSeleccion)){
		ok = 0;
		ptrCantConvocados = cantConvocados;
		auxSeleccion = ll_get(pArrayListSeleccion, indiceArray);
		selec_getConvocados(auxSeleccion, &cantidadConvocados);
		if(cantidadConvocados < *ptrCantConvocados){
			ok = 1;
		}
	}

	return ok;
}

int controller_leerIDDesdeTXT(char* rutaID, int* idRetorno){
	FILE* pArchivo;
	int ok;
	ok = -1;

	if(rutaID != NULL){
		ok = 0;
		pArchivo = fopen(rutaID,"r");

		if(pArchivo != NULL){
			ok = 1;
			fscanf(pArchivo,"%d",idRetorno);
		}
		fclose(pArchivo);
	}
	return ok;
}
int controller_escribirIDEnTXT(char* rutaID, int id){
	FILE* pArchivo;
	int ok;
	ok = -1;

	if(rutaID != NULL){
		ok = 0;
		pArchivo = fopen(rutaID,"w");

		if(pArchivo != NULL){
			ok = 1;
			fprintf(pArchivo,"%d",id);
		}
		fclose(pArchivo);
	}
	return ok;

}
int controller_IDAsignar(int* id){
	int idRetorno;

	idRetorno = -1;

	if(id != NULL){
		*id = *id + 1;
		idRetorno = *id;
	}

	return idRetorno;
}

int controller_ordenarLista(LinkedList* pArrayList, int (*ordenamiento)(void*,void*), int orden){
	int ok;
		ok = 0;

	if(controller_validarLinkedList(pArrayList) && ordenamiento != NULL){
		ok = 1;
		ll_sort(pArrayList, ordenamiento, orden);
	}

	return ok;
}

int controller_cargarGentiliciosDesdeTexto(char* ruta, LinkedList* pArrayListGentilicio){
	int ok;
	FILE* pArchivo;
	ok = -1;
	pArchivo = NULL;

	if(ruta != NULL && pArrayListGentilicio != NULL){
		ok = 0;
		pArchivo = fopen(ruta,"r");

		if(pArchivo != NULL){
			ll_clear(pArrayListGentilicio);
			ok = parser_GentilicioFromText(pArchivo, pArrayListGentilicio);
		}

		fclose(pArchivo);
	}
	return ok;
}

Gentilicio* controller_obtenerGentilicioPorID(int idSeleccion, LinkedList* pArrayListGentilicio){
	Gentilicio* ptrGentilicioRetorno;
	Gentilicio* aux;
	int idSeleccionAux;
	aux = NULL;
	ptrGentilicioRetorno = NULL;
	if(controller_validarLinkedList(pArrayListGentilicio)){

		for(int i = 0 ; i < ll_len(pArrayListGentilicio); i++){
			aux = ll_get(pArrayListGentilicio, i);
			gen_getIdSeleccion(aux, &idSeleccionAux);

			if(idSeleccionAux == idSeleccion){
				ptrGentilicioRetorno = aux;
				break;
			}
		}
	}
	return ptrGentilicioRetorno;
}


int controller_validarLinkedList(LinkedList* pArrayList){
	int ok;
	ok = 0;
	if(pArrayList != NULL && !ll_isEmpty(pArrayList)){
		ok = 1;
	}

	return ok;
}

int controller_obtenerLinkedListFiltro(LinkedList* pArrayList, LinkedList* pArrayListRetorno, int (*pFunc)(LinkedList*,int indice, void*), void* criterio){
	int ok;
	LinkedList* ptrAux;
	ok = -1;

	if(controller_validarLinkedList(pArrayList) && pArrayListRetorno != NULL && pFunc != NULL){
		ok = 0;
		for(int i = 0 ; i < ll_len(pArrayList); i++){
			if(pFunc(pArrayList,i,criterio)){
				ok = 1;
				ptrAux = ll_get(pArrayList, i);
				ll_add(pArrayListRetorno, ptrAux);
			}
		}
	}
	return ok;
}
int controller_validarLinkedListFiltro(LinkedList* pArrayList, int (*pFunc)(LinkedList*,int indice, void*), void* criterio){
	int ok;
	ok = -1;

	if(controller_validarLinkedList(pArrayList) && pFunc != NULL){
		ok = 0;
		for(int i = 0 ; i < ll_len(pArrayList); i++){
			if(pFunc(pArrayList,i,criterio)){
				ok = 1;
			}
		}
	}
	return ok;
}
