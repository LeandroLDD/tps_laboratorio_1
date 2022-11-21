#ifndef GENERALES_H_
#define GENERALES_H_

#include <string.h>

/* Imprime un mensaje en consola, pide un valor y lo retorna
 * "msj" mensaje que se va a imprimir
 * "return" retorno del valor ingresado en la funcion
 */
int imprYGuardarNum(char* msj);

/* Imprime un mensaje en consola, pide un valor, lo valida en un rango y lo retorna
 * "msg" mensaje que se va a imprimir
 * "min" validacion minima
 * "max" validacion maxima
 * "limpiarSalida" limpiar la consola con cada iteracion. 1 = true 0 = false
 * "return" retorno del valor ingresado en la funcion
 */
int imprYGuardarNumConMinYMax(char *msj, char* msjError, int min, int max, int limpiarSalida);

/* Imprime un mensaje en consola, pide un valor, lo valida en un numero mayor y lo retorna
 * "msg" mensaje que se va a imprimir
 * "min" numero minimo
 * "return" retorno del valor ingresado en la funcion
 */
int imprYGuardarNumMayor(char *msj, char* msjError, int min);

/* Imprime un mensaje y luego pide que se presione alguna tecla para continuar
 * "msj" mensaje que se va a imprimir
 */
void imprAviso(char* msj);

/* Imprime un mensaje en pantalla si cumple la condicion
 * "msj" mensaje que se va a imprimir
 * "valor" valor que validar
 * "criterio" condicion de igualdad a cumplir
 * "return" retorno binario. 0. No cumplio la condicion | 1. Cumplio la condicion
 */
int imprSi(char *msj, int valor, int criterio);


#endif /* GENERALES_H_ */
