#include "leangenerales.h"
//SHORT-------------------------------
int getShort(short* var){
	int ok;
	ok = 0;
		if(var != NULL){
			ok = 1;
			scanf("%hi",var);
			fflush(stdin);
		}

		return ok;
}

int imprYGuardarShort(char* msj, short *var){
    int ok;
    ok = 0;
    if(msj != NULL && var != NULL){
    	ok = 1;
    	printf("%s ",msj);
    	getShort(var);
    }
	return ok;
}

int imprYGuardarShortConMinYMax(char* msj, char* msjError, short *var, int min, int max){
    int ok;
    int criterio;
    ok = 0;

    if(msj != NULL && msjError != NULL && var != NULL && min <= max){
        ok = 1;
    	do{
    		criterio = 1;
    		imprYGuardarShort(msj,var);
    		if(*var < min || *var > max){
    			criterio = 0;
    			imprAviso(msjError);
    		}
    	}while(!criterio);
    }
	return ok;
}

//INT---------------------------------------

int esEntero(char* numStr){
	int esDigito;
	esDigito = -1;

	if(numStr != NULL){
		esDigito = 1;
		for(int i = 0 ; i < strlen(numStr); i++){
			if(!isdigit(numStr[i]) && numStr[i] != '-'){
				esDigito = 0;
				break;
			}
		}
	}
	return esDigito;
}

int getInt(int* var){
	int ok;
	char numStr[11];
	int banderaEsNum;
	ok = 0;

	if(var != NULL){
		ok = 1;
		do{
			scanf("%s",numStr);
			banderaEsNum = esEntero(numStr);
			fflush(stdin);
		}while(!banderaEsNum);
		*var = atoi(numStr);
	}

	return ok;
}

int imprYGuardarEntero(char* msj, int* var){
    int ok;
    ok = 0;
    if(msj != NULL && var != NULL){
    	ok = 1;
    	printf("%s ",msj);
    	getInt(var);
    }
	return ok;
}

int imprYGuardarEnteroConMinYMax(char* msj,char* msjError,int* var, int min, int max){
    int ok;
    int criterio;
    ok = 0;
    
    if(msj != NULL && msjError != NULL && var != NULL && min <= max){
        ok = 1;
    	do{
    		criterio = 1;
    		imprYGuardarEntero(msj,var);
    		if(*var < min || *var > max){
    			criterio = 0;
    			imprAviso(msjError);
    		}
    	}while(!criterio);
    }
	return ok;
}

int imprYGuardarEnteroMayor(char* msj, char* msjError, int *var, int min){
	int ok;
	int criterio;
	ok = 0;

	if(msj != NULL && msjError != NULL && var != NULL){
		ok = 1;

		do{
			criterio = 1;
			imprYGuardarEntero(msj, var);
			if(*var < min){
				criterio = 0;
				imprAviso(msjError);
			}
		}while(!criterio);
	}
	return ok;
}

int imprYGuardarEnteroDistintoDe(char* msj, char* msjError, int *var, int cmp){
	int ok;
	int criterio;
	ok = 0;

	if(msj != NULL && msjError != NULL && var != NULL){
		ok = 1;

		do{
			criterio = 1;
			imprYGuardarEntero(msj,var);

			if(*var == cmp){
				criterio = 0;
				imprAviso(msjError);
			}
		}while(!criterio);
	}

	return ok;
}

//FLOAT-----------------------------------------------------------------------------

int getFloat(float* var){
	int ok;
	ok = 0;

	if(var != NULL){
		ok = 1;
		scanf("%f",var);
		fflush(stdin);
	}

	return ok;
}

int imprYGuardarFloat(char* msj, float* var){
    int ok;
    ok = 0;

    if(msj != NULL && var != NULL){
    	printf("%s ",msj);
    	getFloat(var);
    	ok = 1;
    }
	return ok;
}

int imprYGuardarFloatConMinYMax(char* msj,char* msjError,float* var, float min, float max){
    int ok;
    int criterio;
    ok = 0;

    if(msj != NULL && msjError != NULL && var != NULL && min <= max){
        ok = 1;
    	do{
    		criterio = 1;
    		imprYGuardarFloat(msj,var);

    		if(*var < min || *var > max){
    			criterio = 0;
    		   imprAviso(msjError);
    		}
    	}while(!criterio);
    }
	return ok;
}

int imprYGuardarFloatMayor(char* msj, char* msjError, float *var, float min){
	int ok;
	int criterio;
	ok = 0;

	if(msj != NULL && msjError != NULL && var != NULL){
		ok = 1;
		do{
			criterio = 1;
			imprYGuardarFloat(msj, var);
			if(*var < min){
				criterio = 0;
				imprAviso(msjError);
			}
		}while(!criterio);
	}
	return ok;
	}

int floatACadena(char *str,float num){
	int ok;
	ok = 1;

	if(str != NULL && sprintf(str, "%f", num) == -1){
		perror("Error al convertir entero a cadena");
		ok = 0;
	}

	return ok;
}

//CHAR-----------------------------------------------------------------------------------

int getChar(char* var){
	int ok;
	ok = 0;

	if(var != NULL){
		ok = 1;
		scanf("%c",var);
		fflush(stdin);
	}

	return ok;
}

int imprYGuardarChar(char* msj, char* var){
    int ok;
    ok = 0;

    if(msj != NULL && var != NULL){
    	printf("%s ",msj);
    	getChar(var);
    	ok = 1;
    }
	return ok;
}

int imprYGuardarCharConMinYMax(char* msj,char* msjError,char* var, int min, int max,  int normalizar){
    int ok;
    int criterio;
    ok = 0;

    if(msj != NULL && msjError != NULL && var != NULL && min <= max){
        ok = 1;
    	do{
    		criterio = 1;
    		imprYGuardarChar(msj,var);

    		if(normalizar){
    			*var = toupper(*var);
    			min = toupper(min);
    			max = toupper(max);
    		 }

    		if(*var < min || *var > max){
    			criterio = 0;
    			puts(msjError);
    		}
    	}while(!criterio);
    }
	return ok;
}

//CADENA DE CARACTERES----------------------------------------------
int imprYGuardarCadena(char* msj, char* var){
	int ok;
	    ok = 0;

	    if(msj != NULL&& var != NULL){
	    	printf("%s ",msj);

	    	fflush(stdin);
	    	gets(var);
	    	ok = 1;
	    }
		return ok;
}

int imprYGuardarCadenaConMinYMax(char *msj, char* msjError, char* var, int min, int max, short validarDigit){
	int ok;
	int banderaCondicion;
	ok  = 0;

	if(msj != NULL && msjError != NULL && var != NULL && min <= max && validarDigit >= 0 && validarDigit <=1){
		do{
			ok = 1;
			banderaCondicion = 1;
			imprYGuardarCadena(msj, var);

			if((strlen(var) < min || strlen(var) > max) || (validarDigit && validarDigitoEnCadenaChar(var))){
				banderaCondicion = 0;
				puts(msjError);
			}

		}while(!banderaCondicion);
	}
	return ok;
}

int validarDigitoEnCadenaChar(char* str){
	int banderaTieneDigito;
	banderaTieneDigito = 0;

	for(int i = 0; i < strlen(str); i++){
		if(isdigit(str[i]) != 0){
			banderaTieneDigito = 1;
			break;
		}
	}

	return banderaTieneDigito;
}

//---------------------------------------------------------------------

void imprAviso(char* msj){
	puts(msj);
	system("pause");
}

int intACadena(char* str,int num){
	int ok;
	ok = 0;

    if(str != NULL && sprintf(str, "%d", num) == -1){
    	perror("Error al convertir entero a cadena");
    	ok = 1;
    }

    return ok;
}

int swap(int* num1, int* num2){
    int ok;
    int aux;
    ok = 0;
    
    if(num1 != num2){
        aux = *num1;
        *num1 = *num2;
        *num2 = aux;
        ok = 1;
    }
    
    return ok;
}

int avisoBinario(int bandera, char* msjVerdadero, char* msjFalso){
	int ok;

	if(msjVerdadero != NULL && msjFalso != NULL){
		ok = 1;
		if(bandera == 1){
			imprAviso(msjVerdadero);
		}
		else{
			imprAviso(msjFalso);
		}
	}
	return ok;
}

int avisoBinarioExtendido(int bandera, char* msjVerdadero, char* msjFalso, char* msjOtro){
	int ok;

	if(msjVerdadero != NULL && msjFalso != NULL && msjOtro != NULL){
		ok = 1;
		if(bandera == 1){
			imprAviso(msjVerdadero);
		}
		else{
			if(bandera == 0){
			imprAviso(msjFalso);
			}
			else{
				imprAviso(msjOtro);
			}
		}
	}
	return ok;
}
