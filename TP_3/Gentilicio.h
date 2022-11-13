#ifndef GENTILICIO_H_
#define GENTILICIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int idSeleccion;
	char descripcion[50];
}Gentilicio;

Gentilicio* gen_nuevo();
Gentilicio* gen_nuevoParametros(char* idSeleccion, char* descripcion);
Gentilicio gen_constructorDeCadena(char* idSeleccion, char* descripcion);
Gentilicio gen_constructor(int idSeleccion, char* descripcion);
int gen_eliminar(Gentilicio *this);

int gen_setIdSeleccion(Gentilicio* this, int idSeleccion);
int gen_getIdSeleccion(Gentilicio* this, int* idSeleccion);

int gen_setDescripcion(Gentilicio* this, char* descripcion);
int gen_getDescripcion(Gentilicio* this, char* descripcion);

int gen_leerText(FILE* pFile, char* idSeleccionStr, char* descripcionStr);

int gen_mostrar(Gentilicio* this);


#endif /* GENTILICIO_H_ */
