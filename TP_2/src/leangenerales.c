#include "leangenerales.h"
//SHORT-------------------------------
int getShort(short* var){
	int ok;
		ok = 0;
		if(var != NULL){
			ok = scanf("%hi",var);
			fflush(stdin);
		}

		return ok;
}

int imprYGuardarShort(char* msj, short *var){
    int ok;
    ok = 0;
    if(var != NULL){
    	printf("%s ",msj);
    	getShort(var);
    	ok = 1;
    }
	return ok;
}

int imprYGuardarShortConMinYMax(char* msj, char* msjError, short *var, int min, int max){
    int ok;
    int criterio;
    ok = 0;

    if(var != NULL && min <= max){
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

int getInt(int* var){
	int ok;
	ok = 0;

	ok = scanf("%d",var);
	fflush(stdin);

	return ok;
}

int imprYGuardarEntero(char* msj, int* var){
    int ok;
    ok = 0;
    if(var != NULL){
    	printf("%s ",msj);
    	getInt(var);
    	ok = 1;
    }
	return ok;
}

int imprYGuardarEnteroConMinYMax(char* msj,char* msjError,int* var, int min, int max){
    int ok;
    int criterio;
    ok = 0;
    
    if(var != NULL && min <= max){
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

	if(var != NULL){
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

	if(var != NULL){
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

	ok = scanf("%f",var);
	fflush(stdin);

	return ok;
}

int imprYGuardarFloat(char* msj, float* var){
    int ok;
    ok = 0;

    if(var != NULL){
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

    if(var != NULL && min <= max){
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

	if(var != NULL){
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

//CHAR-----------------------------------------------------------------------------------

int getChar(char* var){
	int ok;
	ok = 0;

	ok = scanf("%c",var);
	fflush(stdin);

	return ok;
}

int imprYGuardarChar(char* msj, char* var){
    int ok;
    ok = 0;

    if(var != NULL){
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

    if(var != NULL && min <= max){
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

	    if(var != NULL){
	    	printf("%s ",msj);

	    	fflush(stdin);
	    	gets(var);
	    	ok = 1;
	    }
		return ok;
}

int imprYGuardarCadenaConMinYMax(char *mjs, char* msjError, char* var, int min, int max, short validarDigit){
	int ok;
	int banderaCondicion;
	ok  = 0;

	if(min <= max){
		do{
			banderaCondicion = 1;
			imprYGuardarCadena(mjs, var);

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

int imprDobleOpcionIgualACero(char *msj,char* msjOpcion1,float valorOpcion1, char* msjOpcion2, int valorOpcion2){
    int opcionRetorno;
	char aviso[strlen(msj)];
	strcpy(aviso,msj);
	opcionRetorno = 0;

	if(valorOpcion1 == 0){
		strcat(aviso,msjOpcion1);
		opcionRetorno = 1; //Opcion 1
	}
	if(valorOpcion2 == 0){
	    opcionRetorno = 2; //Opcion 2
	    
		if(valorOpcion1 == 0){
			strcat(aviso," y ");
			opcionRetorno = 3; //Ambas opciones
		}
		
		strcat(aviso,msjOpcion2);
	}
	imprAviso(aviso);
	return opcionRetorno;
}

int imprMsjSiIgual(int num,int valorTrue, char *msj, char* msjTrue, char* msjFalse){
    char msjFinal[100];
    int ok;

    strcpy(msjFinal,msj);
    ok = 0;
    
    if(num == valorTrue){
        strcat(msjFinal,msjTrue);
        ok = 1;
    }
    else{
        strcat(msjFinal,msjFalse);
    }
    puts(msjFinal);
    return ok;
}

int intACadena(char* str,int num){
	int ok;
	ok = 1;

    if(sprintf(str, "%d", num) == -1){
    	perror("Error al convertir entero a cadena");
    	ok = 0;
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
