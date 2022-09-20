#ifndef MSJENPANTALLA_H_
#define MSJENPANTALLA_H_

#include <string.h>

float imprYGuardarNum(char* msj);
/*Imprime un mensaje en consola, pide un valor y lo retorna
 * "msj" mensaje que se va a imprimir
 * "return" retorno del valor ingresado en la funcion
 */

float imprYGuardarNumConMinYMax(char* msj, int min, int max, int limpiarSalida);
/*Imprime un mensaje en consola, pide un valor, lo valida en un rango y lo retorna
 * "msg" mensaje que se va a imprimir
 * "min" validacion minima
 * "max" validacion maxima
 * "limpiarSalida" limpiar la consola con cada iteracion. 1 = true 0 = false
 * "return" retorno del valor ingresado en la funcion
 */

void imprAviso(char* msj);
/*Imprime un mensaje y luego pide que se presione alguna tecla para continuar
 * "msj" mensaje que se va a imprimir
 */

void imprDobleOpcionIgualACero(char *msj,char* msjOpcion1,float valorOpcion1, char* msjOpcion2, int valorOpcion2);
/*Imprime un mensaje si falta la primera opcion, la segunda o ambas
 * "msg" mensaje para contextializar las opciones
 * "msjOpcion1" primera opcion
 * "valorOpcion1" Valor que representa msjOpcion1
 * "msjOpcion2" segunda opcion
 * "valorOpcion2" Valor que representa msjOpcion2
 */

#endif /* MSJENPANTALLA_H_ */
