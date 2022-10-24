#include "jugador.h"

int validarSiHayJugadores(eJugador listaJugador[], int tamJugador, int avisar){
	int ok;
	ok = 0;

	if(tamJugador > 0){

		for(int i = 0; i < tamJugador; i++){
			if(listaJugador[i].isEmpty == OCUPADO){
				ok = 1;
				break;
			}
		}
	}

	if(!ok && avisar){
		imprAviso("¡Faltan jugadores!");
	}

	return ok;
}

int mostrarJugador(eJugador* unJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int posConfederacion;
	ok = 0;

	if(unJugador != NULL && unJugador->isEmpty == OCUPADO && tamConfederacion > 0){
		obtenerConfederacionPorID(listaConfederacion, tamConfederacion, unJugador->idConfederacion, &posConfederacion);
		printf("| %-4d| %-24s| %-14s| %-12hi| %-12.2f| %-14s|   %-15hi|\n",
				unJugador->id,
				unJugador->nombre,
				unJugador->posicion,
				unJugador->numeroCamiseta,
				unJugador->salario,
				listaConfederacion[posConfederacion].nombre,
				unJugador->aniosContrato);
	}
	return ok;
}

int mostrarListaJugador(eJugador listaJugador[],int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 0)){
		ok = 1;
		puts("================================================================================================================\n"
			 "| ID  |   NOMBRE                | POSICION      | N° CAMISETA | SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
			 "----------------------------------------------------------------------------------------------------------------");
		for(int i = 0; i < tamJugador; i++){
			mostrarJugador(&listaJugador[i], listaConfederacion, tamConfederacion);
		}
		puts("================================================================================================================\n");
	}

	return ok;
}

int darDeBajaListaJugador(eJugador listaJugador[], int tamJugador){
	int ok;
	ok = 0;

	for(int i = 0; i < tamJugador ;i++){
		listaJugador[i].isEmpty = LIBRE;
		listaJugador[i].id = 0;
	}

	return ok;
}

int obtenerEspacioLibreJugador(int* posResult, eJugador listaJugador[], int tamJugador){
	int banderaEncontroEspacio;
	banderaEncontroEspacio = 0;

	if(tamJugador > 0){
		for(int i = 0; i < tamJugador;i++){
			if(listaJugador[i].isEmpty == LIBRE){
				banderaEncontroEspacio = 1;
				*posResult = i;
				break;
			}
		}
	}

	return banderaEncontroEspacio;
}

int validarIDJugador(eJugador listaJugador[], int tamJugador, int idBuscar){
	int banderaEncontroJugador;
		banderaEncontroJugador = 0;

		if(validarSiHayJugadores(listaJugador, tamJugador, 1) && tamJugador > 0 && idBuscar > 0){
			for(int i = 0; i < tamJugador; i++){

				if(listaJugador[i].id == idBuscar && listaJugador[i].isEmpty == OCUPADO){
					banderaEncontroJugador = 1;
					break;
				}
			}
		}

		return banderaEncontroJugador;
}

int obtenerJugador(eJugador listaJugador[], int tamJugador, int idBuscar, int *posResult){
	int banderaEncontroJugador;
	banderaEncontroJugador = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && tamJugador > 0 && idBuscar > 0 && posResult != NULL){
		for(int i = 0; i < tamJugador; i++){

			if(listaJugador[i].id == idBuscar && listaJugador[i].isEmpty == OCUPADO){
				banderaEncontroJugador = 1;
				*posResult = i;
				break;
			}
		}
	}

	return banderaEncontroJugador;
}

int obtenerCantidadJugadoresDeUnaConfederacion(eJugador listaJugador[], int tamJugador, eConfederacion* unaConfederacion, int* contadorResult){
	int ok;
	*contadorResult = 0;
	ok = -1;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0) && contadorResult != NULL){
		ok = 0;
		for(int i = 0; i < tamJugador; i++){
			if(listaJugador[i].isEmpty == OCUPADO && listaJugador[i].idConfederacion == unaConfederacion->id){
				ok = 1;
				*contadorResult = *contadorResult + 1;
			}
		}
	}

	return ok;
}

int obtenerJugadoresDeUnaConfederacion(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, int idConfederacion){
	int contadorJugadores;
	contadorJugadores = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0)){
		for(int i = 0; i < tamJugador; i++){
			if(listaJugador[i].isEmpty == OCUPADO && listaJugador[i].idConfederacion == idConfederacion){
				listaJugadorResult[contadorJugadores] = listaJugador[i];
				contadorJugadores++;
			}
		}
	}
	return contadorJugadores;
}

int obtenerJugadoresSalarioMayor(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador, float salario){
	int contadorJugadores;
	contadorJugadores = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0)){
			for(int i = 0; i < tamJugador; i++){
				if(listaJugador[i].isEmpty == OCUPADO && listaJugador[i].salario > salario){
					listaJugadorResult[contadorJugadores] = listaJugador[i];
					contadorJugadores++;
				}
			}
		}

	return contadorJugadores;
}

float obtenerSumaTotalSalarioJugadores(eJugador listaJugador[], int tamJugador){
	float sumaTotalSalarios;
	sumaTotalSalarios = -1;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0)){
		sumaTotalSalarios = 0;
		for(int i = 0; i < tamJugador; i++){
			sumaTotalSalarios += listaJugador[i].salario;
		}
	}
	return sumaTotalSalarios;
}

float obtenerPromedioSalarioJugadores(eJugador listaJugador[], int tamJugador){
	float sumaTotalSalarios;
	float promedioSalario;
	promedioSalario = -1;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0)){
		sumaTotalSalarios = obtenerSumaTotalSalarioJugadores(listaJugador, tamJugador);
		promedioSalario = sumaTotalSalarios / tamJugador;
	}

	return promedioSalario;
}

int copiarListaJugador(eJugador listaJugadorResult[], eJugador listaJugador[], int tamJugador){
	int ok;
	ok = 0;

	if(tamJugador > 0){
		for(int i = 0 ; i < tamJugador; i++){
			listaJugadorResult[i] = listaJugador[i];
		}
	}

	return ok;
}

int swapearJugadores(eJugador *jugador1, eJugador *jugador2){
	int ok;
	eJugador jugadorAux;
	ok = 0;
	if(jugador1 != NULL && jugador2 != NULL){
		jugadorAux = *jugador1;
		*jugador1 = *jugador2;
		*jugador2 = jugadorAux;
	}

	return ok;
}

int ordernarPorIDListaJugador(eJugador listaJugador[], eJugador listaJugadorResult[], int tamJugador){
	int ok;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && tamJugador > 0){
		ok = 1;
		copiarListaJugador(listaJugadorResult, listaJugador, tamJugador);
		for(int i = 0; i < tamJugador-1;i++){
			for(int j = i+1; j < tamJugador; j++){
				if(listaJugadorResult[i].id > listaJugadorResult[j].id){
					swapearJugadores(&listaJugadorResult[i], &listaJugadorResult[j]);
				}
			}
		}
	}

	return ok;
}

int reacomodarPosListaJugador(eJugador listaJugador[], int tamJugador){
	int ok;
	ok = -1;

	if(validarSiHayJugadores(listaJugador, tamJugador, 0)){
		ok = 0;
		for(int i = 0; i < tamJugador-1; i++){
			for(int j = i+1; j < tamJugador; j++){
				if(listaJugador[i].isEmpty > listaJugador[j].isEmpty){
					ok = 1;
					swapearJugadores(&listaJugador[i], &listaJugador[j]);
				}
			}
		}
	}

	return ok;
}

int elegirJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int *idResult){
	int ok;
	int criterio;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && tamJugador > 0 && tamConfederacion > 0){
		ok = 1;
		mostrarListaJugador(listaJugador, tamJugador, listaConfederacion, tamConfederacion);

		do{
			imprYGuardarEntero("Elija una ID", idResult);
			criterio = validarIDJugador(listaJugador, tamJugador, *idResult);

			if(!criterio){
				imprAviso("La ID no existe");
			}
		}while(!criterio);
	}

	return ok;
}

int pedirNombreJugador(eJugador* unJugador){
	int ok;
	ok = 0;
	if(unJugador != NULL){
		ok = 1;
		imprYGuardarCadenaConMinYMax("Ingrese el nombre(2-50): ", "Nombre invalido", unJugador->nombre, 2, 50, 1);
	}

	return ok;
}

int pedirPosicionJugador(eJugador* unJugador){
	int ok;
	ok = 0;
	if(unJugador != NULL){
		ok = 1;
		imprYGuardarCadenaConMinYMax("Ingrese la posicion: ", "Posicion invalida", unJugador->posicion, 2, 50,1);
	}
	return ok;
}

int pedirNumCamisetaJugador(eJugador* unJugador){
	int ok;
	ok = 0;
	if(unJugador != NULL){
		ok = 1;
		imprYGuardarShortConMinYMax("Ingrese N° de Camiseta(1-99)", "Numero invalido", &unJugador->numeroCamiseta, 1, 99);
	}
	return ok;
}

float pedirSalarioJugador(eJugador* unJugador){
	int ok;
	ok = 0;
	if(unJugador != NULL){
		ok = 1;
		imprYGuardarFloatConMinYMax("Ingrese el salario", "salario invalido", &unJugador->salario, 1, 500000000);
	}
	return ok;
}

short pedirAniosContrato(eJugador* unJugador){
	int ok;
	ok = 0;
	if(unJugador != NULL){
		ok = 1;
		imprYGuardarShortConMinYMax("Ingrese los años de contrato", "Año invalido", &unJugador->aniosContrato,1, 100);
	}
	return ok;
}

int elegirOpcionModificarJugador(eJugador* unJugador, eConfederacion listaConfederacion[] , int tamConfederacion){
	int ok;
	int opcElegidaModificar;
	ok = -1;

	if(unJugador != NULL && tamConfederacion > 0){
		ok = 0;
		eMenu menuModificarJugador[7] = {
				{"Nombre", '1'},
				{"Posicion", '2'},
				{"Numero de camiseta", '3'},
				{"Confederacion", '4'},
				{"Salario", '5'},
				{"Años de contrato", '6'},
				{"Atras", '7'}
		};

		opcElegidaModificar = mostrarMenuYElegirOpcionAlfanumerico("Modificar Jugador", "Elija el dato a modificar ", "Respuesta invalida", menuModificarJugador, 7);

		switch(opcElegidaModificar){
			case '1':
				pedirNombreJugador(unJugador);
			break;

			case '2':
				pedirPosicionJugador(unJugador);
			break;

			case '3':
				pedirNumCamisetaJugador(unJugador);
			break;

			case '4':
				unJugador->idConfederacion = elegirConfederacion(listaConfederacion, tamConfederacion);
			break;

			case '5':
				pedirSalarioJugador(unJugador);
			break;

			case '6':
				pedirAniosContrato(unJugador);
			break;
		}

		if(opcElegidaModificar != '7'){
			ok = 1;
			imprAviso("Se realizó el cambio exitosamente");
		}
	}

	return ok;
}

int altaJugador(eJugador listaJugador[], int maxJugadores, int *tamJugador, eConfederacion listaConfederacion[], int tamConfederacion, int* id){
	int ok;
	int posJugadorLibre;
	ok = 0;
	if(maxJugadores > 0 && obtenerEspacioLibreJugador(&posJugadorLibre, listaJugador, maxJugadores)){
		puts("\n\tDAR DE ALTA JUGADOR");
		ok = 1;
		*id = *id + 1;
		*tamJugador = *tamJugador + 1;
		listaJugador[posJugadorLibre] = pedirDatosJugador(listaConfederacion, tamConfederacion, *id);
		imprAviso("¡Se ingreso al jugador exitosamente!");
	}
	return ok;
}

eJugador pedirDatosJugador(eConfederacion listaConfederacion[], int tamConfederacion, int id){
	eJugador unJugador;
	unJugador.id = id;
	pedirNombreJugador(&unJugador);
	pedirPosicionJugador(&unJugador);
	pedirNumCamisetaJugador(&unJugador);
	unJugador.idConfederacion = elegirConfederacion(listaConfederacion, tamConfederacion);
	pedirSalarioJugador(&unJugador);
	pedirAniosContrato(&unJugador);
	unJugador.isEmpty = OCUPADO;
	return unJugador;
}

int bajaJugador(eJugador listaJugador[], int* tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int idEliminar;
	int posEliminar;
	eJugador jugadoresOrdenadosPorID[*tamJugador];
	short reconfirmacion;
	ok = 0;

	if(validarSiHayJugadores(listaJugador, *tamJugador, 1) && *tamJugador > 0 && tamConfederacion > 0){
		puts("\n\tDAR DE BAJA JUGADOR");
		ordernarPorIDListaJugador(listaJugador, jugadoresOrdenadosPorID, *tamJugador);

		elegirJugador(jugadoresOrdenadosPorID, *tamJugador, listaConfederacion, tamConfederacion, &idEliminar);

		imprYGuardarShortConMinYMax("¿Desea borrar al jugador?(1. Si | 0. No)", "Respuesta invalida", &reconfirmacion, 0, 1);

		if(reconfirmacion){

			obtenerJugador(listaJugador, *tamJugador, idEliminar, &posEliminar);
			listaJugador[posEliminar].isEmpty = LIBRE;
			reacomodarPosListaJugador(listaJugador, *tamJugador);

			*tamJugador = *tamJugador - 1;

			imprAviso("¡Se elimino al jugador exitosamente!");
		}
	}
	return ok;
}

int modificarJugador(eJugador listaJugador[], int tamJugador, eConfederacion listaConfederacion[], int tamConfederacion){
	int ok;
	int idModificar;
	int posModificar;
	eJugador jugadoresOrdenadosPorID[tamJugador];
	ok = -1;

	if(validarSiHayJugadores(listaJugador, tamJugador, 1) && validarSihayConfederaciones(listaConfederacion, tamConfederacion, 1)){
		puts("\n\tMODIFICAR JUGADOR");
		ordernarPorIDListaJugador(listaJugador, jugadoresOrdenadosPorID, tamJugador); //Ordena la lista por ID

		elegirJugador(jugadoresOrdenadosPorID, tamJugador, listaConfederacion, tamConfederacion, &idModificar); //Muestra la lista Ordenada y devuelve por parametro la id a Modificar
		obtenerJugador(listaJugador, tamJugador, idModificar, &posModificar);//Obtiene la posicion en lista con idModificar

		ok = elegirOpcionModificarJugador(&listaJugador[posModificar], listaConfederacion, tamConfederacion);
	}

	return ok;
}
