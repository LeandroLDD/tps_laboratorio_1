#ifndef MSJENPANTALLA_H_
#define MSJENPANTALLA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float msjYGuardarNum(char* msj);
/*Imprime un mensaje en consola, pide un valor y lo retorna
 * "msj" mensaje que se va a imprimir
 * "return" retorno del valor ingresado en la funcion
 */

float msjYGuardarNumConMinYMax(char * msj, int min, int max, int limpiarSalida);
/*Imprime un mensaje en consola, pide un valor, lo
 * valida en un rago y lo retorna
 * "msg" mensaje que se va a imprimir
 * "min" validacion minima
 * "max" validacion maxima
 * "limpiarSalida" limpiar la consola con cada iteracion. 1 = true 0 = false
 * "return" retorno del valor ingresado en la funcion
 */


#endif /* MSJENPANTALLA_H_ */
