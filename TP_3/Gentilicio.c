#include "Gentilicio.h"

Gentilicio* gen_nuevo(){
	Gentilicio* nuevoGentilicio;
	nuevoGentilicio = NULL;
	nuevoGentilicio = (Gentilicio*)malloc(sizeof(Gentilicio));

	return nuevoGentilicio;
}
Gentilicio* gen_nuevoParametros(char* idSeleccion, char* descripcion){
	Gentilicio* nuevoGentilicio;
	nuevoGentilicio = NULL;

	if(idSeleccion != NULL && descripcion != NULL){
		nuevoGentilicio = gen_nuevo();

		if(nuevoGentilicio != NULL){
			*nuevoGentilicio = gen_constructorDeCadena(idSeleccion, descripcion);
		}
	}
	return nuevoGentilicio;
}
Gentilicio gen_constructorDeCadena(char* idSeleccion, char* descripcion){
	Gentilicio constructGentilicio;

	if(idSeleccion != NULL && descripcion != NULL){
		constructGentilicio = gen_constructor(atoi(idSeleccion), descripcion);
	}
	return constructGentilicio;
}
Gentilicio gen_constructor(int idSeleccion, char* descripcion){
	Gentilicio constructGentilicio;

	if(descripcion != NULL){
		gen_setIdSeleccion(&constructGentilicio, idSeleccion);
		gen_setDescripcion(&constructGentilicio, descripcion);
	}
	return constructGentilicio;
}
int gen_eliminar(Gentilicio *this){
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		free(this);
	}
	return ok;
}

int gen_setIdSeleccion(Gentilicio* this, int idSeleccion){
	int ok;
	ok = 0;
	if(this != NULL){
		ok = 1;
		this->idSeleccion = idSeleccion;
	}
	return ok;
}
int gen_getIdSeleccion(Gentilicio* this, int* idSeleccion){
	int ok;
	ok = 0;
	if(this != NULL && idSeleccion != NULL){
		ok = 1;
		*idSeleccion = this->idSeleccion;
	}
	return ok;
}

int gen_setDescripcion(Gentilicio* this, char* descripcion){
	int ok;
	ok = 0;
	if(this != NULL && descripcion != NULL){
		ok = 1;
		strcpy(this->descripcion,descripcion);
	}
	return ok;
}
int gen_getDescripcion(Gentilicio* this, char* descripcion){
	int ok;
	ok = 0;
	if(this != NULL && descripcion != NULL){
		ok = 1;
		strcpy(descripcion,this->descripcion);
	}
	return ok;
}

int gen_leerText(FILE* pFile, char* idSeleccionStr, char* descripcionStr){
	int ok;
	ok = 0;

	if(pFile != NULL && idSeleccionStr != NULL && descripcionStr != NULL){
		ok = 1;
		fscanf(pFile,"%[^,], %[^\n]",idSeleccionStr, descripcionStr);
	}
	return ok;
}

int gen_mostrar(Gentilicio* this){
	int ok;
	int idSeleccion;
	char descripcion[50];
	ok = 0;

	if(this != NULL){
		ok = 1;
		gen_getIdSeleccion(this, &idSeleccion);
		gen_getDescripcion(this, descripcion);

		printf("%d. %s",idSeleccion, descripcion);
	}
	return ok;
}
