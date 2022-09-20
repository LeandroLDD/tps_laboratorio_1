#include "msjEnPantalla.h"
#include <stdio.h>
#include <stdlib.h>

float imprYGuardarNum(char* msj){
	float var;
	printf(msj);
	scanf("%f", &var);

	return var;
}

float imprYGuardarNumConMinYMax(char * msj, int min, int max,  int limpiarSalida){
	float var;

	do{
		if(limpiarSalida){
			system("cls");
		}

		var = imprYGuardarNum(msj);

		fflush(stdin);
		}while(var < min || var > max);

	return var;
}

void imprAviso(char* msj){
	puts(msj);
	system("pause");
}

void imprDobleOpcionIgualACero(char *msj,char* msjOpcion1,float valorOpcion1, char* msjOpcion2, int valorOpcion2){
	char aviso[strlen(msj)];
	strcpy(aviso,msj);

	if(valorOpcion1 == 0){
		strcat(aviso,msjOpcion1);
	}
	if(valorOpcion2 == 0){
		if(valorOpcion1 == 0){
			strcat(aviso," y ");
		}
		strcat(aviso,msjOpcion2);
	}
	imprAviso(aviso);
}


