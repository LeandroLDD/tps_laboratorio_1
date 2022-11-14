#ifndef PARSER_H_
#define PARSER_H_

/**
 * @brief Parsea y guarda los datos de un archivo texto a una Lista de jugadores
 * @param pFile Archivo a leer
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * @brief Parsea y guarda los datos de un archivo binario a una Lista de jugadores
 * @param pFile Archivo a leer
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * @brief Parsea y guarda los datos de un archivo texto a una Lista de selecciones
 * @param pFile Archivo a leer
 * @param pArrayListJugador Lista de selecciones
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

/**
 * @brief Parsea y guarda los datos de un archivo texto a una Lista de gentilicios
 * @param pFile Archivo a leer
 * @param pArrayListJugador Lista de gentilicios
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int parser_GentilicioFromText(FILE* pFile, LinkedList* pArrayListGentilicio);

#endif /* PARSER_H_ */
