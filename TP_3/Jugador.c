#include "Jugador.h"

Jugador* jug_new(){
	Jugador* nuevoJugador;
	nuevoJugador = NULL;
	nuevoJugador = (Jugador*)malloc(sizeof(Jugador));

	return nuevoJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	Jugador* nuevoJugador;
	nuevoJugador = NULL;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL){
		nuevoJugador = jug_new();

		if(nuevoJugador != NULL){
			*nuevoJugador = jug_constructorDeCadena(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
		}
	}
	return nuevoJugador;
}
Jugador jug_constructorDeCadena(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	Jugador constructJugador;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL){
		constructJugador = jug_constructor(atoi(idStr), nombreCompletoStr, atoi(edadStr), posicionStr, nacionalidadStr, atoi(idSeleccionStr));
	}
	return constructJugador;
}
Jugador jug_constructor(int id,char* nombreCompletoStr,int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion){
	Jugador constructJugador;

	if(nombreCompletoStr != NULL && posicionStr != NULL && nacionalidadStr != NULL){
		jug_setId(&constructJugador, id);
		jug_setNombreCompleto(&constructJugador, nombreCompletoStr);
		jug_setEdad(&constructJugador, edad);
		jug_setPosicion(&constructJugador, posicionStr);
		jug_setNacionalidad(&constructJugador, nacionalidadStr);
		jug_setIdSeleccion(&constructJugador, idSeleccion);
	}
	return constructJugador;
}

void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}

int jug_setId(Jugador* this,int id){
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		this->id = id;
	}
	return ok;
}
int jug_getId(Jugador* this,int* id){
	int ok;
	ok = 0;

	if(this != NULL && id != NULL){
		ok = 1;
		*id = this->id;
	}
	return ok;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int ok;
	ok = 0;

	if(this != NULL && nombreCompleto != NULL){
		ok = 1;
		strcpy(this->nombreCompleto,nombreCompleto);
	}
	return ok;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int ok;
	ok = 0;

	if(this != NULL && nombreCompleto != NULL){
		ok = 1;
		strcpy(nombreCompleto,this->nombreCompleto);
	}
	return ok;
}

int jug_setPosicion(Jugador* this,char* posicion){
	int ok;
	ok = 0;

	if(this != NULL && posicion != NULL){
		ok = 1;
		strcpy(this->posicion,posicion);
	}
	return ok;
}
int jug_getPosicion(Jugador* this,char* posicion){
	int ok;
	ok = 0;

	if(this != NULL && posicion != NULL){
		ok = 1;
		strcpy(posicion,this->posicion);
	}
	return ok;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int ok;
	ok = 0;

	if(this != NULL && nacionalidad != NULL){
		ok = 1;
		strcpy(this->nacionalidad,nacionalidad);
	}
	return ok;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int ok;
	ok = 0;

	if(this != NULL && nacionalidad != NULL){
		ok = 1;
		strcpy(nacionalidad,this->nacionalidad);
	}
	return ok;
}

int jug_setEdad(Jugador* this,int edad){
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		this->edad = edad;
	}
	return ok;
}
int jug_getEdad(Jugador* this,int* edad){
	int ok;
	ok = 0;

	if(this != NULL && edad != NULL){
		ok = 1;
		*edad = this->edad;
	}
	return ok;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		this->idSeleccion = idSeleccion;
	}
	return ok;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion){
	int ok;
	ok = 0;

	if(this != NULL && idSeleccion != NULL){
		ok = 1;
		*idSeleccion = this->idSeleccion;
	}
	return ok;
}

int jug_mostrarTextCabecera(short completo){
	char idStr[50];
	char nombreCompletoStr[100];
	char edadStr[15];
	char posicionStr[30];
	char nacionalidadStr[30];
	char idSeleccionStr[50];
	int ok;
	FILE* pArchivo;
	pArchivo = NULL;
	ok = -1;

	ok = 0;
	pArchivo = fopen("jugadores.csv","r");

	if(pArchivo != NULL){
		ok = 1;
		jug_leerText(pArchivo, idStr, nombreCompletoStr, edadStr,  posicionStr,  nacionalidadStr,  idSeleccionStr);
				//| ID | NOMBRE COMPLETO | EDAD | POSICION | NACIONALIDAD | ID SELECCION |
		if(completo == 1){
			printf("==================================================================================================\n"
				   "| %-3s| %-25s| %-5s| %-21s| %-16s| %-15s|\n"
				   "==================================================================================================\n",
				   idStr, nombreCompletoStr, edadStr,  posicionStr,  nacionalidadStr,  idSeleccionStr);
		}
		else{
			printf("=================================================================================\n"
				   "| %-3s| %-25s| %-5s| %-21s| %-16s|\n"
				   "=================================================================================\n",
				   idStr, nombreCompletoStr, edadStr,  posicionStr,  nacionalidadStr);
		}
	}
	fclose(pArchivo);
	return ok;
}
int jug_leerText(FILE* pFile,char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	int ok;
	ok = 0;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL){
		ok = 1;
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]",idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
	}
	return ok;
}

int jug_mostrar(Jugador* this){
	int ok;

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	ok = 0;
	if(this != NULL){
		ok = 1;

		jug_getId(this, &id);
		jug_getNombreCompleto(this, nombreCompleto);
		jug_getEdad(this, &edad);
		jug_getPosicion(this, posicion);
		jug_getNacionalidad(this, nacionalidad);

		//| ID | NOMBRE COMPLETO | EDAD | POSICION | NACIONALIDAD |
		printf("| %-3d| %-25s| %-5d| %-21s| %-16s|",id ,nombreCompleto,edad,posicion,nacionalidad);
	}
	return ok;
}

int jug_esConvocado(Jugador* this){
	int banderaConvocado;
	int idSelecValidar;
	banderaConvocado = 0;

	jug_getIdSeleccion(this, &idSelecValidar);
	if(idSelecValidar != 0){
		banderaConvocado = 1;
	}
	return banderaConvocado;
}
