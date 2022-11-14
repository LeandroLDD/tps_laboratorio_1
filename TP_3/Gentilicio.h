#ifndef GENTILICIO_H_
#define GENTILICIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int idSeleccion;
	char descripcion[50];
}Gentilicio;

/**
 * @brief Reserva espacio en memoria dinamica para un Gentilicio
 * @return Retorna un puntero a la dir reservada | Caso contrario NULL
 */
Gentilicio* gen_nuevo();
/**
 * @brief Reserva espacio en memoria dinamica para un gentilicio y lo rellena con datos
 * @param Todos los datos de un gentilicio pasados como cadenas de char
 * @return Retorna un puntero a la dir reservada con sus datos | Caso contrario NULL
 */
Gentilicio* gen_nuevoParametros(char* idSeleccion, char* descripcion);
/**
 * @brief Constructor de Gentilicio con cadenas char
 * @param Todos los datos de un gentilicio pasados como cadenas de char
 * @return Retorna un gentilicio con sus datos
 */
Gentilicio gen_constructorDeCadena(char* idSeleccion, char* descripcion);
/**
 * @brief Constructor de Gentilicio
 * @param Todos los datos del gentilicio
 * @return Retorna un Gentilicio con sus datos
 */
Gentilicio gen_constructor(int idSeleccion, char* descripcion);

/**
 * @brief Libera memoria de un Gentilicio
 * @param this Un gentilicio
 */
int gen_eliminar(Gentilicio *this);

/**
 * @brief Setter de idSeleccion
 * @param this Un gentilicio
 * @param idSeleccion Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_setIdSeleccion(Gentilicio* this, int idSeleccion);
/**
 * @brief Getter de idSeleccion
 * @param this Un gentilicio
 * @param idSeleccion Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_getIdSeleccion(Gentilicio* this, int* idSeleccion);

/**
 * @brief Setter de descripcion
 * @param this Un gentilicio
 * @param descripcion Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_setDescripcion(Gentilicio* this, char* descripcion);
/**
 * @brief Getter de descripcion
 * @param this Un gentilicio
 * @param descripcion Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_getDescripcion(Gentilicio* this, char* descripcion);

/**
 * @brief Leé una linea de un archivo texto de gentilicio y deuelve sus datos
 * @param pArchivo Archivo a leer
 * @param Retorna todos los datos del gentilicio por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_leerText(FILE* pFile, char* idSeleccionStr, char* descripcionStr);

/**
 * @brief Muestra los datos de un gentilicio
 * @param this Un gentilicio
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int gen_mostrar(Gentilicio* this);

#endif /* GENTILICIO_H_ */
