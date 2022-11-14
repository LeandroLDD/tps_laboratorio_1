#include "Seleccion.h"

Seleccion* selec_new(){
	Seleccion* nuevaSeleccion;
	nuevaSeleccion = NULL;
	nuevaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	return nuevaSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* nuevaSeleccion;
	nuevaSeleccion = NULL;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){
		nuevaSeleccion = selec_new();

		if(nuevaSeleccion != NULL){
			*nuevaSeleccion = selec_constructorDeCadena(idStr, paisStr, confederacionStr, convocadosStr);
		}
	}
	return nuevaSeleccion;
}
Seleccion selec_constructorDeCadena(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion constructSeleccion;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){
		constructSeleccion.id = atoi(idStr);
		strcpy(constructSeleccion.pais,paisStr);
		strcpy(constructSeleccion.confederacion,confederacionStr);
		constructSeleccion.convocados = atoi(convocadosStr);
	}
	return constructSeleccion;
}

void selec_delete(Seleccion* this){
	if(this != NULL){
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id){
	int ok;
	ok = 0;

	if(this != NULL && id != NULL){
		ok = 1;
		*id = this->id;
	}
	return ok;
}
int selec_getPais(Seleccion* this,char* pais){
	int ok;
	ok = 0;

	if(this != NULL && pais != NULL){
		ok = 1;
		strcpy(pais,this->pais);
	}
	return ok;
}
int selec_getConfederacion(Seleccion* this,char* confederacion){
	int ok;
	ok = 0;

	if(this != NULL && confederacion != NULL){
		ok = 1;
		strcpy(confederacion, this->confederacion);
	}
	return ok;
}

int selec_setConvocados(Seleccion* this,int convocados){
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		this->convocados = convocados;
	}
	return ok;
}
int selec_getConvocados(Seleccion* this,int* convocados){
	int ok;
	ok = 0;

	if(this != NULL && convocados != NULL){
		ok = 1;
		*convocados = this->convocados;
	}
	return ok;
}

int selec_mostrarTextCabecera(char* path){
	char idStr[50];
	char paisStr[50];
	char confederacionStr[50];
	char convocadosStr[50];
	int ok;
	FILE* pArchivo;
	pArchivo = NULL;
	ok = -1;

	if(path != NULL){
		ok = 0;
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			ok = 1;
			selec_leerText(pArchivo, idStr, paisStr, confederacionStr, convocadosStr);
			//      | ID | PAIS | CONFEDERACION | CONVOCADOS |
			printf("====================================================\n"
				   "| %-3s| %-15s| %-14s| %-11s|\n"
				   "====================================================\n",idStr,paisStr,confederacionStr,convocadosStr);
		}
		fclose(pArchivo);
	}
	return ok;
}
int selec_leerText(FILE* pFile, char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	int ok;
	ok = 0;

	if(pFile != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){
		ok = 1;
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]",idStr, paisStr, confederacionStr, convocadosStr);
	}
	return ok;
}
int selec_escribirText(FILE* pArchivo, Seleccion* pSeleccion){
	int ok;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	ok = 0;

	if(pArchivo != NULL && pSeleccion != NULL){
		ok = 1;
		selec_getId(pSeleccion, &id);
		selec_getPais(pSeleccion, pais);
		selec_getConfederacion(pSeleccion, confederacion);
		selec_getConvocados(pSeleccion, &convocados);
		fprintf(pArchivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
	}
	return ok;
}
int selec_mostrar(Seleccion* this){
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	int ok;
	ok = 0;

	if(this != NULL){
		ok = 1;
		selec_getId(this, &id);
		selec_getPais(this, pais);
		selec_getConfederacion(this, confederacion);
		selec_getConvocados(this, &convocados);
		printf("| %-3d| %-15s| %-13s | %-11d|\n", id,pais,confederacion,convocados);
	}
	return ok;
}
