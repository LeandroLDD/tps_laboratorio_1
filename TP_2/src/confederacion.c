#include "confederacion.h"

int swapearConfederaciones(eConfederacion* confederacion1, eConfederacion* confederacion2){
	int ok;
	eConfederacion auxConfederacion;
	ok = 0;
	if(confederacion1 != NULL && confederacion2 != NULL){
		auxConfederacion = *confederacion1;
		*confederacion1 = *confederacion2;
		*confederacion2 = auxConfederacion;
	}

	return ok;
}

int copiarListaConfederacion(eConfederacion listaConfederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	ok = 0;

	if(validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		for(int i = 0 ; i < tamConfederacion; i++){
			listaConfederacionReturn[i] = listaConfederacion[i];
		}
	}

	return ok;
}

int ordenarListaConfederacionPorID(eConfederacion listaConfedederacionReturn[], eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	ok = 0;

	if(validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 1;
		copiarListaConfederacion(listaConfedederacionReturn, listaConfederacion, tamConfederacion);
		for(int i = 0; i < tamConfederacion-1;i++){
			for(int j = i+1; j < tamConfederacion; j++){
				if(listaConfedederacionReturn[i].id > listaConfedederacionReturn[j].id){
					swapearConfederaciones(&listaConfedederacionReturn[i], &listaConfedederacionReturn[j]);
				}
			}
		}
	}

	return ok;
}

int obtenerEspacioLibreConfederacion(int* posLibreReturn,eConfederacion listaConfederacion[], int tamConfederacion){
	int banderaEncontroEspacio;
		banderaEncontroEspacio = 0;

	if(tamConfederacion > 0){
		for(int i = 0; i < tamConfederacion;i++){
			if(listaConfederacion[i].isEmpty == LIBRE){
				banderaEncontroEspacio = 1;
				*posLibreReturn = i;
				break;
			}
		}
	}

	return banderaEncontroEspacio;
}

int pedirNombreConfederacion(eConfederacion *unaConfederacion){
	int ok;
	ok = 0;
	if(unaConfederacion != NULL){
		ok = 1;
		imprYGuardarCadenaConMinYMax("Ingrese el nombre(2-50): ", "Nombre invalido", unaConfederacion->nombre, 2, 50, 1);
	}

	return ok;
}

int pedirRegionConfederacion(eConfederacion *unaConfederacion){
	int ok;
	ok = 0;
	if(unaConfederacion != NULL){
		ok = 1;
		imprYGuardarCadenaConMinYMax("Ingrese la region(2-50): ", "Region invalida", unaConfederacion->region, 2, 50, 1);
	}

	return ok;
}

int pedirAnioCreacionConfederacion(eConfederacion *unaConfederacion){
	int ok;
	ok = 0;
	if(unaConfederacion != NULL){
		ok = 1;
		imprYGuardarEnteroConMinYMax("Ingrese el año de creacion: ", "Año invalido", &unaConfederacion->anioCreacion, 1900, 9999);
	}

	return ok;
}

int altaConfederacion(eConfederacion listaConfederacion[],int maxConfederaciones, int *tamConfederacion, int *id){
	int ok;
		int posConfederacionLibreLibre;
		ok = 0;
		if(maxConfederaciones > 0 && obtenerEspacioLibreConfederacion(&posConfederacionLibreLibre, listaConfederacion, *tamConfederacion)){
			puts("\n\tDAR DE ALTA CONFEDERACION");
			ok = 1;
			*id = *id + 1;
			*tamConfederacion = *tamConfederacion + 1;
			listaConfederacion[posConfederacionLibreLibre] = pedirDatosConfederacion(*id);
			imprAviso("¡Se ingreso al jugador exitosamente!");
		}
		return ok;
}

eConfederacion pedirDatosConfederacion(int id){
	eConfederacion unaConfederacion;
	unaConfederacion.id = id;
	pedirNombreConfederacion(&unaConfederacion);
	pedirRegionConfederacion(&unaConfederacion);
	pedirAnioCreacionConfederacion(&unaConfederacion);
	unaConfederacion.isEmpty = OCUPADO;
	return unaConfederacion;
}

int bajaConfederacion(eConfederacion listaConfederacion[], int *tamConfederacion){
	int ok;
	int idEliminar;
	int posEliminar;
	eConfederacion ConfederacionOrdenadasPorID[*tamConfederacion];
	short reconfirmacion;
	ok = 0;

	if(validarSihayConfederaciones(listaConfederacion, *tamConfederacion, 1)){
		puts("\n\tDAR DE BAJA CONFEDERACION");
		ordenarListaConfederacionPorID(ConfederacionOrdenadasPorID, listaConfederacion, *tamConfederacion);

		idEliminar = elegirConfederacion(ConfederacionOrdenadasPorID, *tamConfederacion);
		imprYGuardarShortConMinYMax("¿Desea borrar la confederacion?(1. Si | 0. No)", "Respuesta invalida", &reconfirmacion, 0, 1);

		if(reconfirmacion){

			obtenerConfederacionPorID(listaConfederacion, *tamConfederacion, idEliminar, &posEliminar);
			listaConfederacion[posEliminar].isEmpty = LIBRE;
			reacomodarPosListaConfederacion(listaConfederacion, *tamConfederacion);

			*tamConfederacion = *tamConfederacion - 1;

			imprAviso("¡Se elimino la confederacion exitosamente!");
		}
	}
	return ok;
}
int modificarConfederacion(eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int idModificar;
	int posModificar;
	eConfederacion ConfederacionOrdenadasPorID[tamConfederacion];
	ok = -1;

	if(validarSihayConfederaciones(listaConfederacion, tamConfederacion, 1)){
		puts("\n\tMODIFICAR CONFEDERACION");
		ordenarListaConfederacionPorID(ConfederacionOrdenadasPorID, listaConfederacion, tamConfederacion); //Ordena la lista por ID

		idModificar = elegirConfederacion(ConfederacionOrdenadasPorID, tamConfederacion);
		obtenerConfederacionPorID(listaConfederacion, tamConfederacion, idModificar, &posModificar);

		ok = elegirOpcionModificarConfederacion(&listaConfederacion[posModificar]);
	}

	return ok;
}

int elegirOpcionModificarConfederacion(eConfederacion *unaConfederacion){
	int ok;
	int opcElegidaModificar;
	ok = -1;

	if(unaConfederacion != NULL && unaConfederacion->isEmpty == OCUPADO){
		ok = 0;
		eMenu menuModificarConfederacion[4] = {
				{"Nombre", '1'},
				{"Region", '2'},
				{"Año de creacion", '3'},
				{"Atras", '4'},
		};

		opcElegidaModificar = mostrarMenuYElegirOpcionAlfanumerico("Modificar Confederacion", "Elija el dato a modificar ", "Respuesta invalida", menuModificarConfederacion, 4);

		switch(opcElegidaModificar){
			case '1':
				pedirNombreConfederacion(unaConfederacion);
			break;

			case '2':
				pedirRegionConfederacion(unaConfederacion);
			break;

			case '3':
				pedirAnioCreacionConfederacion(unaConfederacion);
			break;
		}

		if(opcElegidaModificar != '4'){
			ok = 1;
			imprAviso("Se realizó el cambio exitosamente");
		}
	}
	return ok;
}

int mostrarConfederacion(eConfederacion* unaConfederacion){
	int ok;
	ok = 0;
	if(unaConfederacion != NULL && unaConfederacion->isEmpty == OCUPADO){
		printf("| %-4d | %-8s | %-22s | %-12d |\n",
				unaConfederacion->id,
				unaConfederacion->nombre,
				unaConfederacion->region,
				unaConfederacion->anioCreacion);
	}

	return ok;
}

int mostrarListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	ok = 0;
	if(tamConfederacion > 0){
		puts("===========================================================\n"
			 "| ID   | NOMBRE   |   REGION               | AÑO CREACION |\n"
			 "-----------------------------------------------------------");
		for(int i = 0; i < tamConfederacion; i++){
			mostrarConfederacion(&listaConfederacion[i]);
		}
		puts("===========================================================\n");
	}

	return ok;
}

int validarSihayConfederaciones(eConfederacion listaConfederacion[], int tamConfederacion, int avisar){
	int banderaHayConfederaciones;

	if(tamConfederacion > 0){
		for(int i = 0; i < tamConfederacion; i++){
			if(listaConfederacion[i].isEmpty == OCUPADO){
				banderaHayConfederaciones = 1;
				break;
			}
		}
	}
	if(!banderaHayConfederaciones && avisar){
		imprAviso("¡No hay confederaciones!");
	}
	return banderaHayConfederaciones;
}

int validarConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar){
	int ok;
	ok = 0;

	if(tamConfederacion > 0 && IDBuscar > 0){
		for(int i = 0; i < tamConfederacion; i++){
			if(listaConfederacion[i].id == IDBuscar && listaConfederacion[i].isEmpty == OCUPADO){
				ok = 1;
				break;
			}
		}
	}

	return ok;
}

int obtenerConfederacionPorID(eConfederacion listaConfederacion[], int tamConfederacion, int IDBuscar, int* posResult){
	int ok;
	ok = 0;

	if(tamConfederacion > 0 && IDBuscar > 0){
		for(int i = 0; i < tamConfederacion; i++){
			if(listaConfederacion[i].id == IDBuscar && listaConfederacion[i].isEmpty == OCUPADO){
				ok = 1;
				*posResult = i;
				break;
			}
		}
	}

	return ok;
}

int elegirConfederacion(eConfederacion listaConfederacion[], int tamConfederacion){
	int idRetorno;
	int criterio;
	idRetorno = 0;

	if(tamConfederacion > 0){

		mostrarListaConfederacion(listaConfederacion, tamConfederacion);

		do{
			imprYGuardarEntero("Elija una ID", &idRetorno);
			criterio = validarConfederacionPorID(listaConfederacion, tamConfederacion, idRetorno);

			if(!criterio){
				imprAviso("La ID no existe");
			}
		}while(!criterio);
	}

	return idRetorno;
}

int reacomodarPosListaConfederacion(eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	ok = -1;

	if(validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 0;
		for(int i = 0; i < tamConfederacion-1; i++){
			for(int j = i+1; j < tamConfederacion; j++){
				if(listaConfederacion[i].isEmpty > listaConfederacion[j].isEmpty){
					ok = 1;
					swapearConfederaciones(&listaConfederacion[i], &listaConfederacion[j]);
				}
			}
		}
	}

	return ok;
}
