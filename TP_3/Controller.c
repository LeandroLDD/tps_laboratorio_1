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

	if(path != NULL && controller_validarLinkedList(pArrayListJugador)){
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
			indiceRetorno = ll_len(pArrayListJugador);
			ll_add(pArrayListJugador, jugadorNuevo);
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
		idModificar = controller_pedirJugadorPorID(pArrayListJugador, "Eliga una ID a modificar",1);
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
		switch(mostrarMenuYElegirOpcionAlfanumerico("Menu Modificar Jugador", "Eliga una opcion", "Opcion invalida", menuModificar, 5)){
			case 'A':
				controller_pedirJugadorNombreCommpleto(ptrJugadorModificar);
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
	Jugador* jugadorEliminar;
	int ok;
	int idEliminar;
	int indiceEliminarLinkedList;
	int reconfirmacion;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador)){
		ok = 0;
		idEliminar = controller_pedirJugadorPorID(pArrayListJugador, "Eliga un jugador a eliminar",1);
		jugadorEliminar = controller_obtenerJugadorPorID(pArrayListJugador, idEliminar);
		indiceEliminarLinkedList = ll_indexOf(pArrayListJugador, jugadorEliminar);

		puts("---------------------------------------------------------------------------------");
		jug_mostrar(jugadorEliminar);
		puts("\n---------------------------------------------------------------------------------");
		imprYGuardarEnteroConMinYMax("¿Desea eliminar al jugador elegido?(1. Si | 0. No) ", "Respuesta incorrecta", &reconfirmacion, 0, 1);

		if(reconfirmacion){
			ok = 1;
			ll_remove(pArrayListJugador, indiceEliminarLinkedList);
			jug_delete(jugadorEliminar);
		}
	}
    return ok;
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

int controller_convocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, LinkedList* pArrayListGentilicio){
	int ok;
	int idSelecConvocar;
	int idJugadorConvocar;
	char nacionalidadConcovar[50];
	Gentilicio* nacionalidadConvocar;
	LinkedList* listaJugadoresConvocar;
	Jugador* JugadorConvocar;
	Seleccion* selecConvocar;
	int cantidadConvocados;
	listaJugadoresConvocar = ll_newLinkedList();
	ok = -2;
	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && controller_validarLinkedList(pArrayListGentilicio)){
		ok = -1;
		puts("Aca");

		idSelecConvocar = controller_pedirSeleccionPorID(pArrayListSeleccion, "Eliga una seleccion");//Pide la id de la selec

		selecConvocar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSelecConvocar);
		selec_getConvocados(selecConvocar, &cantidadConvocados);

		nacionalidadConvocar = controller_obtenerGentilicioPorID(idSelecConvocar, pArrayListGentilicio);//Con la id obtengo la nacionalidad
		gen_getDescripcion(nacionalidadConvocar, nacionalidadConcovar);

		if(cantidadConvocados < 22){
			ok = 0;
			if(controller_obtenerLinkedListFiltro(pArrayListJugador, listaJugadoresConvocar, controller_esJugadorNacionalidad, nacionalidadConcovar)){
				ok = 1;
				idJugadorConvocar = controller_pedirJugadorPorID(listaJugadoresConvocar, "Eliga un jugador",1);
				JugadorConvocar = controller_obtenerJugadorPorID(pArrayListJugador, idJugadorConvocar);

				jug_setIdSeleccion(JugadorConvocar, idSelecConvocar);
				selec_setConvocados(selecConvocar, cantidadConvocados+1);
			}
		}
	}

	return ok;
}
int controller_desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ok;
	int idJugadorDesconvocar;
	int idSeleccionDesconvocar;
	int reconfirmacion;
	int cantidadConvocados;
	int auxObtenerConvocado;
	Jugador* jugadorDesconvocar;
	Seleccion* selecDesconvocar;
	LinkedList* listaJugadoresConvocados;
	ok = -1;
	reconfirmacion = 0;
	auxObtenerConvocado = 1;

	if(controller_validarLinkedList(pArrayListJugador) && controller_validarLinkedList(pArrayListSeleccion) && controller_hayJugadoresConvocados(pArrayListJugador)){
		ok = 0;
		listaJugadoresConvocados = ll_newLinkedList();

		controller_obtenerLinkedListFiltro(pArrayListJugador, listaJugadoresConvocados, controller_esJugadorConvocado, &auxObtenerConvocado);
		controller_listarJugadoresTodosLosDatos(listaJugadoresConvocados, pArrayListSeleccion);
		idJugadorDesconvocar = controller_pedirJugadorPorID(listaJugadoresConvocados, "Eliga una ID del jugador a desconvocar: ",0);
		jugadorDesconvocar = controller_obtenerJugadorPorID(listaJugadoresConvocados, idJugadorDesconvocar);

		controller_mostrarUnJugador(jugadorDesconvocar, pArrayListSeleccion);
		imprYGuardarEnteroConMinYMax("¿Está seguro que desea desconvocar este jugador?(1. Si | 0. No)", "Respuesta invalida", &reconfirmacion, 0, 1);
		if(reconfirmacion){
			ok = 1;
			jug_getIdSeleccion(jugadorDesconvocar, &idSeleccionDesconvocar);
			jug_setIdSeleccion(jugadorDesconvocar, 0);

			selecDesconvocar = controller_obtenerSeleccionPorID(pArrayListSeleccion, idSeleccionDesconvocar);
			selec_getConvocados(selecDesconvocar, &cantidadConvocados);
			selec_setConvocados(selecDesconvocar, cantidadConvocados-1);
		}
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
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
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

	if(controller_validarLinkedList(pArrayListSeleccion) && !ll_isEmpty(pArrayListSeleccion)){
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
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}

int controller_darDeAltaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,LinkedList* pArrayListGentilicio, int *id){
	int ok;
	Jugador* jugadorNuevo;
	int indiceJugadorNuevo;
	ok = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && id != NULL){
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
int controller_pedirJugadorPorID(LinkedList* pArrayListJugador, char* msj, int imprJugadores){
	int idElegida;
	int banderaJugadorExiste;

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
int controller_pedirJugadorNombreCommpleto(Jugador* this){
	int ok;
	char nombreCompleto[100];
	ok = -1;

	if(this != NULL){
		ok = 0;
		if(imprYGuardarCadenaConMinYMax("Ingrese el nombre completo", "Nombre invalido", nombreCompleto, 2, 50, 1)){
			jug_setNombreCompleto(this, nombreCompleto);
			ok = 1;
		}
	}
	return ok;
}
int controller_pedirJugadorEdad(Jugador* this){
	int ok;
	int edad;
	ok = -1;

	if(this != NULL){
		ok = 0;
		if(imprYGuardarEnteroConMinYMax("Ingrese la edad", "Edad invalida", &edad, 2, 100)){
			jug_setEdad(this, edad);
			ok = 1;
		}
	}
	return ok;
}
int controller_pedirJugadorPosicion (Jugador* this){
	int ok;
	char posicion[30];
	ok = -1;

	if(this != NULL){
		ok = 0;
		if(imprYGuardarCadenaConMinYMax("Ingrese la posicion", "Posicion invalida", posicion, 2, 29,1)){
			jug_setPosicion(this, posicion);
			ok = 1;
		}
	}
	return ok;
}
int controller_pedirJugadorNacionalidad(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio){
	int ok;
	char gentilicio[50];
	Gentilicio* gentilicioElegido;
	int idPaisElegido;
	ok = -1;

	if(this != NULL && pArrayListSeleccion != NULL){
		ok = 0;

		idPaisElegido = controller_pedirSeleccionPorID(pArrayListSeleccion, "Eliga la nacionalidad");
		gentilicioElegido = controller_obtenerGentilicioPorID(idPaisElegido, pArrayListGentilicio);
		gen_getDescripcion(gentilicioElegido, gentilicio);
		printf("\ngentilicio: %s\n",gentilicio);

		jug_setNacionalidad(this, gentilicio);
		ok = 1;
	}
	return ok;
}

int controller_pedirJugadorDatos(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio){
	int ok;
	ok = 0;

	if(this != NULL && pArrayListSeleccion != NULL){
		puts("INGRESAR JUGADOR");

		controller_pedirJugadorNombreCommpleto(this);
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

int controller_esJugadorConvocado(LinkedList* pArrayListJugador,int indiceArray, void* convocadoCtr){
	int ok;
	int idSeleccion;
	Jugador* auxJugador;
	ok = -1;

	if(controller_validarLinkedList(pArrayListJugador) && convocadoCtr != NULL){
		ok = 0;
		auxJugador = ll_get(pArrayListJugador, indiceArray);
		jug_getIdSeleccion(auxJugador, &idSeleccion);
		if(convocadoCtr == 1 && idSeleccion != 0){
			ok = 1;
		}
		if(convocadoCtr == 0 && idSeleccion == 0){
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

int controller_pedirSeleccionPorID(LinkedList* pArrayListSeleccion, char* msj){
	int idElegida;
	int banderaSeleccionExiste;

	if(controller_validarLinkedList(pArrayListSeleccion) && !ll_isEmpty(pArrayListSeleccion)){
		controller_listarSelecciones(pArrayListSeleccion);
		do{
			imprYGuardarEntero(msj, &idElegida);
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

//int controller_escribirNacionalidades(char* ruta){
//	int ok;
//	ok = 0;
//	FILE* pArchivo;
//
//	Gentilicio nacionalidades[32] = {
//			{27,"Qatari"},
//			{13,"Ecuatoriano"},
//			{28,"Senegales"},
//			{19,"Holandes"},
//			{20,"Ingles"},
//			{21,"Irani"},
//			{15,"Estado Unidense"},
//			{17,"Gales"},
//			{3,"Argentino"},
//			{2,"Saudita"},
//			{24,"Mexicano"},
//			{25,"Polaco"},
//			{14,"Espanol"},
//			{10,"Costarricense"},
//			{1,"Aleman"},
//			{22,"Japones"},
//			{5,"Belga"},
//			{8,"Canadiense"},
//			{23,"Marroqui"},
//			{11,"Croata"},
//			{6,"Brasilero"},
//			{29,"Serbio"},
//			{30,"Suizo"},
//			{7,"Camerunes"},
//			{26,"Portugues"},
//			{18,"Ghanes"},
//			{32,"Uruguayo"},
//			{9,"Surcoreano"},
//			{16,"Frances"},
//			{4,"Australiano"},
//			{12,"Danes"},
//			{31,"Tunecito"}};
//
//	pArchivo = fopen("nacionalidadesCopaMundial.csv","w");
//
//	for(int i = 0 ; i < 32; i++){
//		fprintf(pArchivo,"%d,%s\n",nacionalidades[i].idSeleccion,nacionalidades[i].descripcion);
//	}
//	fclose(pArchivo);
//	return ok;
//}
