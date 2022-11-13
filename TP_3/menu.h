/**
 * @file menu.h
 * @date 07/10/2022
 * @author Leandro David Dominguez
 * @title Generales
 * @brief Funciones generales
 */
#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leangenerales.h"

typedef struct{
	char descripcion[100];
	short opcion;
}eMenu;

/**
 * @brief Crea un menu
 * @param menuPtr donde se creara el menu
 * @param opcInicial Num para decidir el primer elemento del menu
 * @param tam Tamaño del eMenu
 * @return 1 Se realizo correctamente | 0 Hubo algun error
 */
int crearMenu(eMenu menuPtr[], int opcInicial, int tam, char opcDescripcion[][30]);

/**
 * @brief Pasa de minus a mayus las opciones del eMenu
 * @param menu eMenu
 * @param tam Tamaño del eMenu
 * @return 1 Se realizo correctamente | 0 Hubo algun error
 */
int normalizarOpcionesMenu(eMenu menu[],int tam);

/**
 * @brief Valida si el menu esta ordenado
 * @param menu eMenu
 * @param tam Tamaño del eMenu
 * @return 1 Se realizo correctamente | 0 Hubo algun error
 */
int validarOrdenEnOpcionMenu(eMenu menu[], int tam);

/**
 * @brief Muestra un eMenu
 * @param Titulo del menu
 * @param menu eMenu
 * @param tam Tamaño del eMenu
 * @return 1 Se realizo correctamente | 0 Hubo algun error
 */
int mostrarMenuYElegirOpcionAlfanumerico(char *titulo,char *msjIngreso,char *msjError,eMenu menu[], int tam);

int mostrarMenuYElegirOpcionNumerico(char *titulo,char *msjIngreso,char *msjError,eMenu menu[], int tam);


#endif /* MENU_H_ */
