#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
#include "leangenerales.h"

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/**
 * @brief Reserva espacio en memoria dinamica para una seleccion
 * @return Retorna un puntero a la dir reservada | Caso contrario NULL
 */
Seleccion* selec_new();
/**
 * @brief Reserva espacio en memoria dinamica para una seleccion y lo rellena con datos
 * @param Todos los datos de la seleccion pasados como cadenas de char
 * @return Retorna un puntero a la dir reservada con sus datos | Caso contrario NULL
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
/**
 * @brief Constructor de Seleccion con cadenas char
 * @param Todos los datos de la seleccion pasados como cadenas de char
 * @return Retorna una seleccion con sus datos
 */
Seleccion selec_constructorDeCadena(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/**
 * @brief Libera memoria de una Seleccion
 * @param this Una Seleccion
 */
void selec_delete(Seleccion* this);

/**
 * @brief Getter de id
 * @param this Una seleccion
 * @param id Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_getId(Seleccion* this,int* id);

/**
 * @brief Getter de pais
 * @param this Una seleccion
 * @param pais Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_getPais(Seleccion* this,char* pais);

/**
 * @brief Getter de confederacion
 * @param this Una seleccion
 * @param confederacion Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/**
 * @brief Setter de convocados
 * @param this Una seleccion
 * @param convocados Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_setConvocados(Seleccion* this,int convocados);
/**
 * @brief Getter de convocados
 * @param this Una seleccion
 * @param convocados Dato retornado por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_getConvocados(Seleccion* this,int* convocados);

/**
 * @brief Muestra la cabecera del archivo Seleccion
 * @param path Ruta del archivo texto
 * @return Retorno binario extendido. .-1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int selec_mostrarTextCabecera(char* path);

/**
 * @brief Leé una linea de un archivo texto de seleccion y deuelve sus datos
 * @param pArchivo Archivo a leer
 * @param Retorna todos los datos del seleccion por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_leerText(FILE* pFile, char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
/**
 * @brief Escribe una linea de un archivo de texto con los datos de una seleccion
 * @param pArchivo Archivo a escribir
 * @param pSeleccion Seleccion a escribir
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_escribirText(FILE* pArchivo, Seleccion* pSeleccion);

/**
 * @brief Muestra los datos de una seleccion
 * @param this Una seleccion
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int selec_mostrar(Seleccion* this);
#endif // selec_H_INCLUDED
