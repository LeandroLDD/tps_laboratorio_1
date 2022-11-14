#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#include "leangenerales.h"

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/**
 * @brief Reserva espacio en memoria dinamica para un jugador
 * @return Retorna un puntero a la dir reservada | Caso contrario NULL
 */
Jugador* jug_new();
/**
 * @brief Reserva espacio en memoria dinamica para un jugador y lo rellena con datos
 * @param Todos los datos del jugador pasados como cadenas de char
 * @return Retorna un puntero a la dir reservada con sus datos | Caso contrario NULL
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);
/**
 * @brief Constructor de Jugador con cadenas char
 * @param Todos los datos del jugador pasados como cadenas de char
 * @return Retorna un jugador con sus datos
 */
Jugador jug_constructorDeCadena(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);
/**
 * @brief Constructor de Jugador
 * @param Todos los datos del jugador
 * @return Retorna un jugador con sus datos
 */
Jugador jug_constructor(int id,char* nombreCompletoStr,int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion);

/**
 * @brief Libera memoria de un Jugador
 * @param this Un Jugador
 */
void jug_delete(Jugador* this);

/**
 * @brief Setter de id
 * @param this Un Jugador
 * @param id ID a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setId(Jugador* this,int id);
/**
 * @brief Getter de id
 * @param this Un Jugador
 * @param id ID retornada por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getId(Jugador* this,int* id);

/**
 * @brief Setter de NombreCompleto
 * @param this Un Jugador
 * @param nombreCompleto Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
/**
 * @brief Getter de NombreCompleto
 * @param this Un Jugador
 * @param nombreCompleto Dato a retornar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * @brief Setter de posicion
 * @param this Un Jugador
 * @param posicion Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setPosicion(Jugador* this,char* posicion);
/**
 * @brief Getter de posicion
 * @param this Un Jugador
 * @param posicion Dato a retornar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getPosicion(Jugador* this,char* posicion);

/**
 * @brief Setter de nacionalidad
 * @param this Un Jugador
 * @param nacionalidad Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
/**
 * @brief Getter de nacionalidad
 * @param this Un Jugador
 * @param nacionalidad Dato a retornar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/**
 * @brief Setter de edad
 * @param this Un Jugador
 * @param edad Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setEdad(Jugador* this,int edad);
/**
 * @brief Getter de edad
 * @param this Un Jugador
 * @param edad Dato a retornar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getEdad(Jugador* this,int* edad);

/**
 * @brief Setter de idSeleccion
 * @param this Un Jugador
 * @param idSeleccion Dato a asignar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);
/**
 * @brief Getter de idSeleccion
 * @param this Un Jugador
 * @param idSeleccion Dato a retornar
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

/**
 * @brief Muestra la cabecera del archivo jugador
 * @param completo Mostrar idSeleccion 0. No | 1. Si
 * @return Retorno binario extendido. .-1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int jug_mostrarTextCabecera(short completo);

/**
 * @brief Leé una linea de un archivo texto de jugadores y deuelve sus datos
 * @param pArchivo Archivo a leer
 * @param Retorna todos los datos del jugador por parametro
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_leerText(FILE* pArchivo,char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);
/**
 * @brief Escribe una linea de un archivo de texto con los datos de un Jugador
 * @param pArchivo Archivo a escribir
 * @param pJugador Jugador a escribir
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_escribirText(FILE* pArchivo, Jugador* pJugador);

/**
 * @brief Escribe una linea de un archivo binario con los datos de un Jugador
 * @param pArchivo Archivo a escribir
 * @param pJugador Jugador a escribir
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_escribirBin(FILE* pArchivo, Jugador* pJugador);

/**
 * @brief Muestra los datos de un jugador sin idSeleccion
 * @param this Un Jugador
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int jug_mostrar(Jugador* this);

/**
 * @brief Valida si un jugador fue convocado
 * @param this Un Jugador
 * @return Retorno binario. 0. No fue convocado | 1. Si fue convocado
 */
int jug_esConvocado(Jugador* this);

#endif // jug_H_INCLUDED
