/**
 * @file jugador.h
 * @author Leandro David Dominguez
 * @title Jugador de futbol
 * @brief Estructura y funciones del jugador
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#define OCUPADO 0
#define LIBRE 1
#include "leangenerales.h"
#include "menu.h"
#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/**
 * @brief Valida si en una lista eJugador hay almenos 1 eJugador con isEmpty == OCUPADO
 * @param listaJugador Lista eJugador a validar
 * @param tamJugador Tamaño de listaJugador
 * @param avisar Recibe 1. Informa por pantalla si no hay jugadores  | 0. No informa nada
 * @return Retorno binario. 1. Encontro jugador | 0. No encontro jugador
 */
int validarSiHayJugadores(eJugador listaJugador[], int tamJugador, int avisar);

/**
 * @brief Muestra por pantalla un eJugador
 * @param unJugador Jugador a mostrar
 * @param listaConfederacion Lista eConfederacion donde buscara la de unJugador
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1- Todo bien | 0- Todo mal
 */
int mostrarJugador(eJugador* unJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Muestra por pantalla una lista eJugador
 * @param listaJugador lista eJugador a mostrar
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion Lista eConfederacion donde buscara la de cada eJugador
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1- Todo bien | 0- Todo mal
 */
int mostrarListaJugador(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Realiza isEmpty = LLIBRE e id = 0 de una lista eJugador
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @return Retorno binario. 1- Todo bien | 0- Todo mal
 */
int darDeBajaListaJugador(eJugador listaJugador[], int tamJugador);

/**
 * @brief Busca en listaJugador un eJugador que su isEmpty sea LIBRE
 * @param posResult Variable donde se retornara la posicion en listaJugador encontrada
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @return Retorno binario. 1- Encontro espacio disponible | 0- NO encontro espacio disponible
 */
int obtenerEspacioLibreJugador(int* posResult, eJugador listaJugador[], int tamJugador);

/**
 * @brief Valida que un eJugador exista en una lista eJugador
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @param idBuscar id del jugador a buscar
 * @return Retorno binario. 1- El jugador existe | 0- El jugador NO existe
 */
int validarIDJugador(eJugador listaJugador[], int tamJugador, int idBuscar);

/**
 * @brief Obtiene la posicion en listaJugador de un eJugador pasado por id
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @param idBuscar id del jugador a buscar
 * @param posResult Variable donde se retornara la posicion en lista del jugador encontrado
 * @return Retorno binario. 1. El jugador existe | 0. El jugador NO existe
 */
int obtenerJugador(eJugador listaJugador[], int tamJugador, int idBuscar, int *posResult);

/**
 * @brief Obtiene la cantidad de jugadores en una eConfederacion
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @param unaConfedereacion Confederacion para filtrar a los jugadres
 * @param contadorResult Variable donde se retornara la cantidad de jugadres encontrados
 * @return Retorno binario extendido. -1.  Fallo en los parametros dados | 0. No encontro jugadores | 1. Encontro jugadres
 */
int obtenerCantidadJugadoresDeUnaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion* unaConfederacion, int* contadorResult);

/**
 * @brief Obtiene una lista eJugador de una eConfederacion
 * @param listaJugadorResult lista eJugador donde se retornaran los jugadores encontrados
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @param unaConfedereacion Confederacion para filtrar a los jugadres
 * @return Retorna la cantidad de jugadores encontrados
 */
int obtenerJugadoresDeUnaConfederacion(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, eConfederacion *unaConfederacion);

/**
 * @brief Obtiene una lista eJugador filtrada por un salario mayor al determinado
 * @param listaJugadorResult lista eJugador donde se retornaran los jugadores encontrados
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @param salario Variable para filtrar jugades con un salario mayor
 * @return Retorna la cantidad de jugadores encontrados
 */
int obtenerJugadoresSalarioMayor(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, float salario);

/**
 * @brief Obtiene la suma de todos los salarios de una lista eJugador
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @return Retorna la suma de los salarios
 */
float obtenerSumaTotalSalarioJugadores(eJugador listaJugador[], int tamJugador);

/**
 * @brief Obtiene el promedio de salarios de una lista eJugador
 * @param listaJugador lista eJugador donde se buscara
 * @param tamJugador Tamaño de listaJugador
 * @return Retorna el promedio
 */
float obtenerPromedioSalarioJugadores(eJugador listaJugador[], int tamJugador);

/**
 * @brief Copia todos los datos de una lista eJugador a otra
 * @param listaJugadorResult lista eJugador copia retornada
 * @param listaJugador lista eJugador de donde se copiaran los datos
 * @param tamJugador Tamaño de listaJugador
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int copiarListaJugador(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador);

/**
 * @brief Intercambia los datos entre 2 eJugador
 * @param jugador1 Primer eJugador
 * @param jugador2 Segundo eJugador
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int swapearJugadores(eJugador *jugador1, eJugador *jugador2);

/**
 * @brief Ordena una lista eJugador por ID de menor a mayor
 * @param listaJugador lista eJugador a ordenar
 * @param listaJugadorResult lista eJugador donde se retornara la lista ordenada
 * @param tamJugador Tamaño de listaJugador
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int ordernarPorIDListaJugador(eJugador listaJugador[], eJugador listaJugadorResult[], int tamJugador);

/**
 * @brief Reacomoda una lista eJugador, poniendo en las ultimas posiciones de la lista a los eJugador con isEmpty = LIBRE e idConfederacion = 0
 * @param listaJugador lista eJugador a reacomodar
 * @param tamJugador Tamaño de listaJugador
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int reacomodarPosListaJugador(eJugador listaJugador[], int tamJugador);

/**
 * @brief Muestra en pantalla una lista eJugador y pide elegir una ID
 * @param listaJugador lista eJugador a mostrar y elegir
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion lista eConfederacion para mostrar la confederacion del jugador
 * @param tamConfederacion Tamaño de listaConfederacion
 * @param Variable donde se retornara la posicion en lista del eJugador elegido
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int elegirJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int *posResult);

/**
 * @brief Pide ingresar un nombre para almacenar en un eJugador
 * @param unJugador Donde se almacenara el nombre
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirNombreJugador(eJugador* unJugador);

/**
 * @brief Pide ingresar una posicion para almacenar en un eJugador
 * @param unJugador Donde se almacenara la posicion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirPosicionJugador(eJugador* unJugador);

/**
 * @brief Pide ingresar un N° de camiseta para almacenar en un eJugador
 * @param unJugador Donde se almacenara el N° de camiseta
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirNumCamisetaJugador(eJugador* unJugador);

/**
 * @brief Pide ingresar un salario para almacenar en un eJugador
 * @param unJugador Donde almacenara el N° de camiseta
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirSalarioJugador(eJugador* unJugador);

/**
 * @brief Pide ingresar los años de contrato para almacenar en un eJugador
 * @param unJugador Donde almacenara los años de contrato
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirAniosContrato(eJugador* unJugador);

/**
 * @brief Muestra en pantalla opciones con las que se podrá modificar un eJugador
 * @param unJugador eJugador a modificar
 * @param listaConfederacion lista eConfederacion para complementar las modificaciones
 * @tamConfederacion listaConfederacion Tamaño de listaConfederacion
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Se modifico | 0. NO se modifico
 */
int elegirOpcionModificarJugador(eJugador* unJugador, eConfederacion listaConfederacion[] , int tamConfederacion);

/**
 * @brief Da de alta y se ingresa un eJugador en un espacio LIBRE
 * @param listaJugador donde se buscara el espacio libre
 * @param maxJugadores capacidad maxima para agregar jugadores en listaJugador
 * @param tamJugador Cantidad de jugadres ingresados (Se le sumara 1 al ingresar a la funcion)
 * @param listaConfederacion Lista eConfederacion para complentar el ingreso de datos
 * @param tamConfederacion Tamaño de listaConfederacion
 * @param id Donde que se le asignara al eJugador (Si la id ya fue asignada irá autoincrementando hasta encontrar una disponible)
 * @return Retorno binario extendido. 1. Todo bien | 0. Error en los parametros
 */
int altaJugador(eJugador listaJugador[], int maxJugadores, int *tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int* id);

/**
 * @brief Pide los datos de un eJugador y lo retorna
 * @param listaConfederacion Lista eConfederacion para complentar el ingreso de datos
 * @param tamConfederacion Tamaño de listaConfederacion
 * @param id Donde que se le asignara al eJugador
 * @return Retorna un eJugador con sus campos ingresados
 */
eJugador pedirDatosJugador(eConfederacion listaConfederacion[], int tamConfederacion, int id);

/**
 * @brief Muestra en pantalla una lista eJugador y pide elegir un eJugador a dar de baja
 * @param listaJugador lista eJugador que se mostrara en pantalla
 * @param tamJugador Tamaño de listaJugador (Si se da de baja un eJugador se resta 1 tamJugador)
 * @param listaConfederacion Lista eConfederacion para complentar la muestra en pantalla
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Se dio de baja | 0. NO se dio de baja
 */
int menuBajaJugador(eJugador listaJugador[], int* tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Da de baja un eJugador a través de una id
 * @param listaJugador lista eJugador donde se buscara al eJugador
 * @param tamJugador Tamaño de listaJugador
 * @param idEliminar eJugador a eliminar pasado por id
 * @param avisar. 1. Imprime en pantalla si dio de baja a un eJugador | 0. No imprime nada
 * @return Retorno binario. 1. Se dio de baja | 0. Error en los parametros
 */
int bajaUnJugador(eJugador listaJugador[],int tamJugador, int idEliminar, int avisar);

/**
 * @brief Da de baja a 1 o mas eJugador de una lista a través de una idConfederacion
 * @param listaJugador lista eJugador donde se buscara al eJugador
 * @param tamJugador Tamaño de listaJugador
 * @param idConfederacionEliminar id de la eConfederacion con la que se eliminaran a los eJugador
 * @return Retorno binario. -1. Error en los parametros | 1. Se dio de baja | 0. NO se dio de baja
 */
int eliminarConfederacionDeJugador(eJugador listaJugador[], int tamJugador, int idConfederacionEliminar);

/**
 * @brief Muestra en pantalla una lista eJugador y pide elegir un eJugador a modificar
 * @param listaJugador lista eJugador donde se buscara al eJugador
 * @param tamJugador Tamaño de listaJugador
 * @param listaConfederacion lista eConfedearcion para complementar la modificacion
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. -1. Error en los parametros | 1. Se modifico | 0. NO se modifico
 */
int modificarJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion);

#endif /* JUGADOR_H_ */
