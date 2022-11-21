#include "generales.h"

#include <stdio.h>
#include <stdlib.h>

int imprYGuardarNum(char* msj){
	int var;
	printf("%s",msj);
	scanf("%d", &var);
	fflush(stdin);

	return var;
}

int imprYGuardarNumConMinYMax(char *msj, char* msjError, int min, int max, int limpiarSalida){
	int var;
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

int imprYGuardarNumMayor(char *msj, char* msjError, int min){
	int var;
	int criterio;

	do{
		criterio = 1;

		var = imprYGuardarNum(msj);

		if(var < min){
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

int imprSi(char *msj, int valor, int criterio){
	int ok;
	ok = 0;

	if(valor == criterio){
		ok = 1;
		imprAviso(msj);
	}


	return ok;
}
