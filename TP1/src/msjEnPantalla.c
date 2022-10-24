#include "msjEnPantalla.h"
#include <stdio.h>
#include <stdlib.h>

float imprYGuardarNum(char* msj){
	float var;
	printf(msj);
	scanf("%f", &var);
	fflush(stdin);

	return var;
}

float imprYGuardarNumConMinYMax(char *msj, char* msjError, int min, int max, int limpiarSalida){
	float var;
	int criterio;

	do{
		criterio = 1;
		if(limpiarSalida){
			system("cls");
		}

		var = imprYGuardarNum(msj);

		if(var < min || var > max){
			criterio = 0;
			imprAviso(msjError);
		}
	}while(!criterio);

	return var;
}

void imprAviso(char* msj){
	puts(msj);
	system("pause");
}

void imprDobleOpcionIgualACero(char *msj,char* msjOpcion1,float valorOpcion1, char* msjOpcion2, int valorOpcion2){
//	char aviso[];
//	strcpy(aviso,msj);

	if(valorOpcion1 == 0){
		puts("Antes de valorOpcion1");
		strcat(msj,msjOpcion1);
		puts("DEspues de valorOpcion1");
	}
	if(valorOpcion2 == 0){
		if(valorOpcion1 == 0){
			strcat(msj," y ");
		}
		strcat(msj,msjOpcion2);
	}
	imprAviso(msj);
}

int validarBanderaBinaria(char *msjFalse, int bandera){
	int ok;
	ok = 1;

	if(bandera > 1 || bandera < 0){
		if(bandera == 0){
			imprAviso(msjFalse);
		}
	}


	return ok;
}
