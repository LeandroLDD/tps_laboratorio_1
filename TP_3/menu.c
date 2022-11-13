#include "menu.h"

int crearMenu(eMenu menuPtr[], int opcInicial,int tam, char opcDescripcion[][30]){
	int ok;
	ok = 0;
	if(tam > 0){
		ok = 1;
		for(int i = 0; i < tam;i++){
			menuPtr[i].opcion = opcInicial+i;
			strcpy(menuPtr[i].descripcion,opcDescripcion[i]);
		}
	}
	return ok;
}

int normalizarOpcionesMenu(eMenu menu[],int tam){
	int ok;
	ok = 0;

	if(tam > 0){
		ok = 1;
		for(int i = 0; i < tam;i++){
			menu[i].opcion = toupper(menu[i].opcion);
		}
	}
	return ok;
}

int validarOrdenEnOpcionMenu(eMenu menu[], int tam){
	int ok;
	int min;
	ok = 1;
	min = menu[0].opcion;

	for(int i = 0 ; i < tam; i++){

		if(menu[i].opcion != min+i){
			ok = 0;
			perror("Las opciones del menu estan desordenadas y/o el\ntam es invalido	-menu.c :11");
			break;
		}
	}

	return ok;
}

int mostrarMenuYElegirOpcionAlfanumerico(char *titulo,char *msjIngreso,char *msjError,eMenu menu[], int tam){
	char opc;
	int min;
	int max;
	opc = -1;
	if(menu[0].opcion > -1 && tam > 0 && validarOrdenEnOpcionMenu(menu, tam)){
		system("cls");
		normalizarOpcionesMenu(menu, tam);

		min = menu[0].opcion;
		max = menu[tam-1].opcion;

		printf("%20s\n\n",titulo);

		for(int i = 0;i < tam ;i++){
			printf("%c. %s\n",menu[i].opcion,menu[i].descripcion);
			fflush(stdin);
		}

		imprYGuardarCharConMinYMax(msjIngreso, msjError, &opc,min, max, 1);
	}
	return opc;
}

int mostrarMenuYElegirOpcionNumerico(char *titulo,char *msjIngreso,char *msjError,eMenu menu[], int tam){
	int opc;
	int min;
	int max;
	opc = -1;
	if(menu[0].opcion > -1 && tam > 0 && validarOrdenEnOpcionMenu(menu, tam)){
		system("cls");
		normalizarOpcionesMenu(menu, tam);

		min = menu[0].opcion;
		max = menu[tam-1].opcion;

		printf("%20s\n\n",titulo);

		for(int i = 0;i < tam ;i++){
			printf("%d. %s\n",menu[i].opcion,menu[i].descripcion);
			fflush(stdin);
		}

		imprYGuardarEnteroConMinYMax(msjIngreso, msjError, &opc,min, max);
	}
	return opc;
}
