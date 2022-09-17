#include "msjEnPantalla.h"

float msjYGuardarNum(char* msj){
	float var;
	printf(msj);
	scanf("%f", &var);

	return var;
}

float msjYGuardarNumConMinYMax(char * msj, int min, int max,  int limpiarSalida){
	float var;

	do{
		if(limpiarSalida){
			system("cls");
		}

		var = msjYGuardarNum(msj);
		}while(var < min || var > max);

	return var;
}

