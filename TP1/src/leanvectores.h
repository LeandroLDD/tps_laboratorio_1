#ifndef LEANVECTORES_H_
#define LEANVECTORES_H_

int buscarValorEnVector(int vec[],int tam,int vBuscar);
/*Busca un valor en un vector y retona si dicho valor fue encontrado
 * "vec" vector donde se va a buscar
 * "tam" cantidad de elementos del vector
 * "vBuscar" valor a buscar
 * "return" 1: Valor encontrado	  0: Valor no encontrado
 */

int obtenerPosicionEnVector(int vec[],int tam, int vBuscar);
/*Busca un valor en un vector y retonar su posicion en el vector
 * "vec" vector donde se va a buscar
 * "tam" cantidad de elementos del vector
 * "vBuscar" valor a buscar
 * "return" retorna la posicion del valor encontrado en el vector. En caso de no encontrar el valor retorna -1
 */

void rellenarVector(int vec[],int tam,int vInicial);
/*
 *Rellena todas las posiciones del vector con un valor
 * "vec" vector que se va rellenar
 * "tam" cantidad de elementos del vector
 * "vInicial" valor con el que se va a rellenar el vector
 */

int obtenerMayorDeUnVector(int *vec,int tam);
/*Busca el mayor numero en un vector
 * "vec" vector donde se va buscar
 * "tam" cantidad de elementos del vector
 * "return" si encontro un vector mayor devuelve 1 si no 0
 */

#endif /* LEANVECTORES_H_ */
