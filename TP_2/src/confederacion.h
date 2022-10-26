/**
 * @file confederacion.h
 * @author Leandro David Dominguez
 * @title Confederacion de futbol
 * @brief Estructura y funciones de confederacion
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define OCUPADO 0
#define LIBRE 1
#include "leangenerales.h"
#include "menu.h"

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

/**
 * @brief Intercambia los datos entre 2 eConfederaciones
 * @param confederacion1 Primera eConfederacion
 * @param confederacion2 Segunda eConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int swapearConfederaciones(eConfederacion* confederacion1, eConfederacion* confederacion2);

/**
 * @brief Copia los valores de una eConfederacion a otra
 * @param listaConfederacionReturn eConfederacion donde se almacenaran los datos
 * @param listaConfederacion eConfederacion de donde se copiaran los datos
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int copiarListaConfederacion(eConfederacion listaConfederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Ordena una lista eConfederacion por ID
 * @param listaConfederacionReturn eConfederacion donde se almacenaran los datos ordenados
 * @param listaConfederacion eConfederacion a ordenar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int ordenarListaConfederacionPorID(eConfederacion listaConfedederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Ordena una lista eConfederacion por ID
 * @param listaConfederacionReturn eConfederacion donde se almacenaran los datos ordenados
 * @param listaConfederacion lista eConfederacion a ordenar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Encontro espacio libre | 0. NO encontro espacio libre
 */
int obtenerEspacioLibreConfederacion(int* posLibreReturn,eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Pide el nombre de una eConfederacion
 * @param unaConfederacion eConfederacion donde se almacenará el nombre
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirNombreConfederacion(eConfederacion *unaConfederacion);

/**
 * @brief Pide la region de una eConfederacion
 * @param unaConfederacion eConfederacion donde se almacenará la region
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirRegionConfederacion(eConfederacion *unaConfederacion);

/**
 * @brief Pide el año de creacion de una eConfederacion
 * @param unaConfederacion eConfederacion donde se almacenará el año de creacion
 * @return Retorno binario. 1. Todo bien | 0. Error en los parametros
 */
int pedirAnioCreacionConfederacion(eConfederacion *unaConfederacion);

/**
 * @brief Da de alta y se ingresa una eConfederacion en un espacio LIBRE
 * @param listaConfederacion lista eConfederacion donde buscara espacio libre
 * @param maxConfederaciones capacidad maxima para agregar eConfederacion en listaConfederacion
 * @param tamConfederacion Cantidad de confederaciones ingresadass (Se le sumara 1 al ingresar a la funcion)
 * @param id Donde que se le asignara a la eConfederacion (Si la id ya fue asignada irá autoincrementando hasta encontrar una disponible)
 * @return Retorno binario extendido. 1. Todo bien | 0. Error en los parametros
 */
int altaConfederacion(eConfederacion listaConfederacion[],int maxConfederaciones, int *tamConfederacion, int *id);

/**
 * @brief Pide los datos de una eConfederacion y la retorna
 * @param id Donde que se le asignara a la eConfederacion
 * @return Retorna una eConfederacion con sus campos ingresados
 */
eConfederacion pedirDatosConfederacion(int id);

/**
 * @brief Muestra en pantalla una lista eConfederacion y pide elegir una eConfederacion a dar de baja
 * @param listaConfederacion lista eConfederacion que se mostrara en pantalla
 * @param tamConfederacion Tamaño de listaConfederacion (Si se da de baja una eConfederacion se resta 1 a tamConfederacion)
 * @param idEliminar Variable donde se retornara la idConfederacion de la eConfederacion eleminiada
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Se dio de baja | 0. NO se dio de baja
 */
int menuBajaConfederacion(eConfederacion listaConfederacion[], int *tamConfederacion, int *idEliminar);

/**
 * @brief Da de baja una eConfederacion a través de una id
 * @param listaConfederacion lista eConfederacion donde se buscara la eConfederacion a eliminar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @param idEliminar eConfederacion a eliminar pasado por id
 * @param avisar. 1. Imprime en pantalla si dio de baja a un eJugador | 0. No imprime nada
 * @return Retorno binario. 1. Se dio de baja | 0. Error en los parametros
 */
int bajaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion, int idEliminar, int avisar);

/**
 * @brief Muestra en pantalla una lista eConfederacion y pide elegir una eConfederacion a modificar
 * @param listaConfederacion lista eConfederacion donde se buscara la eConfederacion
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Se modifico | 0. NO se modifico
 */
int modificarConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Muestra en pantalla opciones con las que se podrá modificar un eJugador
 * @param unaConfederacion eConfederacion a modificar
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Se modifico | 0. NO se modifico
 */
int elegirOpcionModificarConfederacion(eConfederacion *unaConfederacion);

/**
 * @brief Muestra por pantalla una eConfederacion
 * @param unJugador Jugador a mostrar
 * @return Retorno binario. 1- Todo bien | 0- Error en los parametros
 */
int mostrarConfederacion(eConfederacion* unaConfederacion);

/**
 * @brief Muestra por pantalla una lista eConfederacion
 * @param listaConfederacion lista eConfederacion a mostrar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario. 1- Todo bien | 0- Error en los parametros
 */
int mostrarListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Valida si en una lista eJugador hay almenos 1 eJugador con isEmpty == OCUPADO
 * @param listaConfederacion Lista eConfederacion a validar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @param avisar Recibe 1. Informa por pantalla si no hay jugadores  | 0. No informa nada
 * @return Retorno binario. 1. Encontro una confederacion | 0. No Encontro una confederacion
 */
int validarSihayConfederaciones(eConfederacion listaConfederacion[], int tamConfederacion, int avisar);

/**
 * @brief Valida que exista una eConfederacion
 * @param unaConfederacion eConfederacion que se va a validar
 * @return Retorno binario. 1. La confederacion existe | 0.  La confederacion no existe
 */
int validarUnaConfederacion(eConfederacion *unaConfederacion);

/**
 * @brief Valida que exista una eConfederacion en una lista eConfederacion
 * @param listaConfederacion Lista eConfederacion donde se va a buscar
 * @parma tamConfederacion Tamaño de listaConfederacion
 * @param IDBuscar ID de la eConfederacion a buscar
 * @return Retorno binario. 1. Encontro una confederacion | 0. No Encontro una confederacion
 */
int validarConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar);

/**
 * @brief Valida que exista una eConfederacion en una lista eConfederacion y retorna por parametro la posicion encontrada
 * @param listaConfederacion Lista eConfederacion donde se va a buscar
 * @parma tamConfederacion Tamaño de listaConfederacion
 * @param IDBuscar ID de la eConfederacion a buscar
 * @param posResult Variable donde se retornara la posicion encontrada
 * @return Retorno binario. 1. Encontro una confederacion | 0. No Encontro una confederacion
 */
int obtenerConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar, int* posResult);

/**
 * @brief Muestra en pantalla una lista eConfederacion y pide elegir una ID
 * @param listaConfederacion lista eConderacion a mostrar y elegir
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno Retorna la id elegida
 */
int elegirConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * @brief Reacomoda una lista eConderacion, poniendo en las ultimas posiciones de la lista a las eConderacion con isEmpty = LIBRE
 * @param listaConfederacion lista eConfederacion a reacomodar
 * @param tamConfederacion Tamaño de listaConfederacion
 * @return Retorno binario extendido. -1. Error en los parametros | 1. Reacomodo la lsita | 0. NO tuvo que reacomodar
 */
int reacomodarPosListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion);


#endif /* CONFEDERACION_H_ */
