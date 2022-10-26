/**
 * @file leangenerales.h
 * @version 1.0
 * @date 26/09/2022
 * @author Leandro David Dominguez
 * @title Generales
 * @brief Funciones con objetivos generales
 * @code
	int main(void){
	int var;
	var = imprYGuardarNumConMinYMax("\nSeleccione un numero ", 1, 6, 0);
	imprDobleOpcionIgualACero("\nFaltan cargar datos de ", "Costos", banderaCostosCargados, "Jugadores", banderaJugadoresCargados);
	imprAviso("El numero seleccionado es invalido");
	}
 * @endcode
 */

#ifndef LEANGENERALES_H_
#define LEANGENERALES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//SHORT---------------------------------------------------

/**
 * @brief Pide un valor de tipo short int y lo almacena
 * @param var Variable donde se almacenara el valor ingresado
 * @return Retorno booleano numerico de correcto funcionamiento
 */
int getShort(short* var);

/**
 * @brief Imprime un mensaje en consola, pide un valor y lo guarda
 * @param msj Mensaje que se va a imprimir
 * @param var Direccion de memoria de un short int donde se guardara el valor
 * @return Retorno 1 si salio bien y en caso contrario 0
 */
int imprYGuardarShort(char* msj, short *var);

/**
 * @brief Imprime un mensaje en consola, pide un valor, lo valida en un rango y lo retorna
 * @param msj Mensaje que se va a imprimir
 * @param msjError Mensaje si no cumple la condicion
 * @param var Direccion de memoria de un short int donde se guardara el valor
 * @param min Validacion minima
 * @param max Validacion maxima
 * @return Retorna 1 si funciono correctamente y en caso contrario 0
 */
int imprYGuardarShortConMinYMax(char* msj, char* msjError, short *var, int min, int max);

//INT---------------------------------------------------------------
/**
 * @brief Pide un valor de tipo int y lo almacena
 * @param var Variable donde se almacenara el valor ingresado
 * @return Retorno booleano numerico de correcto funcionamiento
 */
int getInt(int* var);

/**
 * @brief Imprime un mensaje en consola, pide un valor y lo guarda
 * @param msj Mensaje que se va a imprimir
 * @param var Direccion de memoria de un entero donde se guardara el valor
 * @return Retorno 1 si salio bien y en caso contrario 0
 */
int imprYGuardarEntero(char* msj, int *var);

/**
 * @brief Imprime un mensaje en consola, pide un valor, lo valida en un rango y lo retorna
 * @param msj Mensaje que se va a imprimir
 * @param msjError Mensaje si no cumple la condicion
 * @param var Direccion de memoria de un entero donde se guardara el valor
 * @param min Validacion minima
 * @param max Validacion maxima
 * @return Retorna 1 si funciono correctamente y en caso contrario 0
 */
int imprYGuardarEnteroConMinYMax(char* msj, char* msjError, int *var, int min, int max);

int imprYGuardarEnteroMayor(char* msj, char* msjError, int *var, int min);

/**
 * @brief Valida un numero distinto de cmp con bucle
 * @param msj Mensaje que se va a imprimir
 * @param msjError Mensaje si no cumple la condicion
 * @param var Varible donde se almacenara el valor resultante
 * @param cmp Valor con el que se va a compara
 * @return Retorno booleano numerico de correcto funcionamiento
 */
int imprYGuardarEnteroDistintoDe(char* msj, char* msjError, int *var, int cmp);

//FLOAT----------------------------------------------------------------------------------

int getFloat(float* var);

int imprYGuardarFloat(char* msj, float* var);

int imprYGuardarFloatConMinYMax(char* msj,char* msjError,float* var, float min, float max);

int imprYGuardarFloatMayor(char* msj, char* msjError, float *var, float min);

int floatACadena(char *str,float num);

//CHAR-------------------------------------------------------------------------------------

/**
 * @brief Pide un valor de tipo char y lo almacena
 * @param var Variable donde se almacenara el valor ingresado
 * @return Retorno booleano numerico de correcto funcionamiento
 */
int getChar(char* var);

/**
 * @brief Imprime un mensaje en consola, pide un caracter y lo guarda
 * @param msj Mensaje que se va a imprimir
 * @param var Direccion de memoria de un entero donde se guardara el caracter
 * @return Retorno 1 si salio bien y en caso contrario 0
 */
int imprYGuardarChar(char* msj, char* var);

/**
 * @brief Imprime un mensaje en consola, pide un valor, lo valida en un rango y lo retorna
 * @param msj Mensaje que se va a imprimir
 * @param msjError Mensaje si no cumple la condicion
 * @param var Direccion de memoria de un entero donde se guardara el valor
 * @param min Validacion minima
 * @param max Validacion maxima
 * @param normalizar Transfroma var, min y max a mayuscula. 1 = true 0 = false
 * @return Retorna 1 si funciono correctamente y en caso contrario 0
 */
int imprYGuardarCharConMinYMax(char* msj, char* msjError, char* var, int min, int max, int normalizar);

//CADENA DE CARACTERES------------------------------------------------------

int imprYGuardarCadena(char* msj, char* var);

int imprYGuardarCadenaConMinYMax(char *mjs, char* msjError, char* var, int min, int max, short validarDigit);

int validarDigitoEnCadenaChar(char* str);

//------------------------------------------------------------------------

/**
 * @brief Imprime un mensaje en consola y luego pide que se presione alguna tecla para continuar
 * @param msj Mensaje que se va a imprimir
 */
void imprAviso(char* msj);

/**
 * @brief Imprime un mensaje si es igual a 0 la primera opcion, la segunda o ambas
 * @param msj Mensaje que se va a imprimir
 * @param msjOpcion1 Mensaje de la primera opcion
 * @param valorOpcion1 Valor que representa msjOpcion1
 * @param msjOpcion2 Mensaje de la segunda opcion
 * @param valorOpcion2 Valor que representa msjOpcion2
 * @return Retorna  que opcion es igual a 0. "0" ninguna opcion | "1" primera opcion | "2" segunda opcion | "3" ambas opciones
 */
int imprDobleOpcionIgualACero(char *msj,char* msjOpcion1,float valorOpcion1, char* msjOpcion2, int valorOpcion2);

/**
 * @brief Imprime un mensaje segun se cumple la igualdad entre num y valorTrue
 * @param num Valor a comparar
 * @param valorTrue Valor objetivo
 * @param msj Mensaje que acompaña
 * @param msjTrue Mensaje si cumple la condicion
 * @param msjFalse Mensaje si no cumple la condicion
 * return Retorna booleano numerico segun si se cumple o no la condicion
 */
int imprMsjSiIgual(int num,int valorTrue ,char *msj, char* msjTrue, char* msjFalse);

/**
 * @brief Convierte un valor entero a Cadena
 * @param num Entero a convertir
 * @return Retorna num con el tipo de dato char*
 */
int intACadena(char *str,int num);

/**
 * @brief Realiza un swap entre 2 enteros
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Retorna booleano numerico si se realizo o no el swap correctamente
 */
int swap(int* num1, int* num2);
 
#endif /* LEANGENERALES_H_ */
