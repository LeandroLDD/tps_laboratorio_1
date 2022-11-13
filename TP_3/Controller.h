#include "Jugador.h"
#include "Seleccion.h"
#include "Gentilicio.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador); // Hecho
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador); //Hecho
int controller_agregarJugador(LinkedList* pArrayListJugador); //Heho
int controller_editarJugador(LinkedList* pArrayListJugador); //Hecho
int controller_menuEditarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio); //Hecho
int controller_removerJugador(LinkedList* pArrayListJugador); //Hecho
int controller_listarJugadores(LinkedList* pArrayListJugador);//HEcho
int controller_listarJugadoresTodosLosDatos(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//Hecho
int controller_listarJugadoresTodosLosDatosFiltro(int (*pFunc)(Jugador* ),LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion); //Hecho
int controller_mostrarUnJugador(Jugador* pJugador, LinkedList* pArrayListSeleccion);
int controller_mostrarPaisSiConvocado(Jugador* pJugador ,LinkedList* pArrayListSeleccion);//Hecho
int controller_convocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, LinkedList* pArrayListGentilicio);//Hecho
int controller_desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);// Hecho Mio
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

int controller_darDeAltaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,LinkedList* pArrayListGentilicio, int *id);
int controller_pedirJugadorPorID(LinkedList* pArrayListJugador, char* msj, int imprJugadores);
int controller_validarJugadorPorID(LinkedList* pArrayListJugador, int id);
Jugador* controller_obtenerJugadorPorID(LinkedList* pArrayListJugador, int id);

int controller_pedirJugadorNombreCommpleto(Jugador* this);
int controller_pedirJugadorEdad(Jugador* this);
int controller_pedirJugadorPosicion(Jugador* this);
int controller_pedirJugadorNacionalidad(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio);
int controller_pedirJugadorDatos(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio);

int controller_hayJugadoresConvocados(LinkedList* pArrayListJugador);

/**
 * @brief Valida si un jugador fue convocado o no
 * @param pArrayListJugador donde se buscara al jugador
 * @param indiceArray indice del pArrayListJugador del jugador a validar
 * @param convocadoCtr 0. Valida NO convocado | 1. Valida SI convocado
 * @return Retorno binario. 1. Se cumplio la condicion | 0. NO cumplio la condicion
 */
int controller_esJugadorConvocado(LinkedList* pArrayListJugador,int indiceArray, void* convocadoCtr);
int controller_esJugadorNacionalidad(LinkedList* pArrayListJugador,int indiceArray, void* nacionalidadCtr);

int controller_pedirSeleccionPorID(LinkedList* pArrayListSeleccion, char* msj);
int controller_validarSeleccionPorID(LinkedList* pArrayListSeleccion, int id);
Seleccion* controller_obtenerSeleccionPorID(LinkedList* pArrayListSeleccion, int id);

int controller_leerIDDesdeTXT(char* rutaID, int* idRetorno);
int controller_escribirIDEnTXT(char* rutaID, int id);
int controller_IDAsignar(int* id);

int controller_cargarGentiliciosDesdeTexto(char* ruta, LinkedList* pArrayListGentilicio);
Gentilicio* controller_obtenerGentilicioPorID(int idSeleccion, LinkedList* pArrayListGentilicio);

int controller_validarLinkedList(LinkedList* pArrayList);

/**
 * @brief
 */
int controller_obtenerLinkedListFiltro(LinkedList* pArrayList, LinkedList* pArrayListRetorno, int (*pFunc)(LinkedList*,int indice, void*), void* criterio);
//int controller_escribirNacionalidades(char* ruta);
