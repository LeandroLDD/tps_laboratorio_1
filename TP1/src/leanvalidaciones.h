/**
 * @file leanvalidaciones.h
 * @version 1.0
 * @date 29/09/2022
 * @author Leandro David Dominguez
 * @title Validaciones
 * @brief Funciones para validar datos
 */
 
#ifndef LEANVALIDACIONES_H_
#define LEANVALIDACIONES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Determina si un entero es Par
 * @param num Numero a validar
 * @return Retorno boleano numerico si cumple la condicion
 */
int esPar(int num);

/**
 * @brief Valida igualdad entre 2 valores e imprime mensaje
 * @param msj Mensaje que se imprime si se cumple la igualdad
 * @param num1 Primer valor a comparar
 * @param num2 Segundo valor a compararar
 * @return Retorno boleano numerico si cumple la condicion
 */
int esIgual(char* msj, int var, int igualdad);

#endif
