#include "funcFutbol.h"


int cargarCosto(int *hospedaje, int *comida, int *transporte, int *banderaTodosLosCostosCargados){
	int ok;
	int costoSeleccionado;

	if(hospedaje != NULL && comida != NULL && transporte != NULL && banderaTodosLosCostosCargados != NULL){
		ok = 1;
		system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
		printf("\t\tIngreso de los costos de Mantenimiento\n"
				"\t\t======================================\n"
				"\n1.Costo de Hospedaje -> $%d"
				"\n2.Costo de Comida -> $%d"
				"\n3.Costo de Transporte -> $%d"
				"\n4.Volver al menu\n",*hospedaje,*comida,*transporte);

		costoSeleccionado = imprYGuardarNumConMinYMax("\nSeleccione un costo ","Respuesta no valida",1, 4,0);

		if(costoSeleccionado != 4){//Si es diferente de 4 entra al switch
			pedirCosto(hospedaje, comida, transporte, costoSeleccionado);

			if(hospedaje != 0 && comida != 0 && transporte != 0){
				*banderaTodosLosCostosCargados = 1;
			}
		}
	}


	return ok;
}

int pedirCosto(int *hospedaje, int *comida, int *transporte, int costoElegido){
	int ok;
	int montoGastado;

	if(hospedaje != NULL && comida != NULL && transporte != NULL && costoElegido >= 1 && costoElegido <= 3){
		ok = 1;

		montoGastado = imprYGuardarNumConMinYMax("\nMonto gastado $", "El monto ingresado NO es valido.", 1, 100000000, 0);

		switch(costoElegido){//switch de Costos
		case 1:
			*hospedaje = montoGastado;
			break;

		case 2:
			*comida = montoGastado;
			break;

		case 3:
			*transporte = montoGastado;
			break;
		}
	}
	return ok;
}

int validarPosicionDisponible(int arqueros, int defensores,int mediocampistas,int delanteros, int posicion,int avisar){
	int validacion;
	int limiteDePosiciones[4] = {MAXARQUEROS,MAXDEFENSORESYMEDIOCAMPISTAS,MAXDEFENSORESYMEDIOCAMPISTAS,MAXDELANTEROS};
	int PosicionesConSusJugadores[4] = {arqueros, defensores, mediocampistas, delanteros};//Cada una de las posiciones con su respectiva cantidad de jugadores
	validacion = 1;

	if(PosicionesConSusJugadores[posicion] == limiteDePosiciones[posicion]){
		printf("\nJugadores: %d\nLimite %d\n",PosicionesConSusJugadores[posicion],limiteDePosiciones[posicion]);
		validacion = 0;

		if(avisar){
			imprAviso("Se llego a la cantidad maxima de la posicion seleccionada");
		}
	}

	return validacion;

}

int cargarJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int *banderaJugadorCargado){
	int ok;

	if(arqueros != NULL && defensores != NULL && mediocampistas != NULL && delanteros != NULL){
		ok = 1;
		system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
		printf("\t\tCarga de jugadores\n"
				"\t\t==================\n"
				"\n1.Arqueros -> %d"
				"\n2.Defensores -> %d"
				"\n3.Mediocampistas -> %d"
				"\n4.Delanteros -> %d"
				"\n5.Volver al menu\n",*arqueros,*defensores,*mediocampistas,*delanteros);

	}
	return ok;
}

int pedirPosicionJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int posicionSeleccionada){
	int ok;
	ok = -1;


	if(arqueros != NULL && defensores != NULL && mediocampistas != NULL && delanteros != NULL){
		ok = 0;

		switch(posicionSeleccionada){
		case 1:
			(*arqueros)++;
		break;

		case 2:
			(*defensores)++;
		break;

		case 3:
			(*mediocampistas)++;
		break;

		case 4:
			(*delanteros)++;
		break;
		}

		if(posicionSeleccionada != 5){//Si es diferente de 5 significa que cargo un jugador
			ok = 1;
		}
	}
	return ok;
}

int pedirCamiseta(int camisetasSeleccionadas[]){
	int criterio;
	int numCamisetaSeleccionada;
	int PosDeCamisetaLibre;

	if(camisetasSeleccionadas){
		do{
			criterio = 0;
			numCamisetaSeleccionada = imprYGuardarNumConMinYMax("\nIngrese el numero de Camiseta(1-99) ", "\nEl numero de Camiseta seleccionado no esta permitido.", 1, 99, 0);
			if(buscarValorEnVector(camisetasSeleccionadas,MAXJUGADORES,numCamisetaSeleccionada)){
				criterio = 1;
				imprAviso("\nEl numero de Camiseta ya fue seleccionado.");
			}
		}while(criterio);

		PosDeCamisetaLibre = obtenerPosicionEnVector(camisetasSeleccionadas, MAXJUGADORES, 0);
		camisetasSeleccionadas[PosDeCamisetaLibre] = numCamisetaSeleccionada;
	}
	return numCamisetaSeleccionada;
}

int pedirConfederacion(int *cantidadUefa, int *cantidadConmebol, int *cantidadConcacaf, int *cantidadAfc, int *cantidadOfc, int *cantidadCaf){
	int confederacionSeleccionada;

		puts("\n1. UEFA"
				"\n2. CONMEBOL"
				"\n3. CONCACAF"
				"\n4. AFC"
				"\n5. OFC"
				"\n6. CAF");

		confederacionSeleccionada = imprYGuardarNumConMinYMax("\nSeleccione una confederacion ","Confederacion Invalida", 1, 6, 0);

		switch(confederacionSeleccionada){//Crea una funcion switchIncremental(); fijate el retorno y parameters
			case 1:
				(*cantidadUefa)++;
			break;

			case 2:
				(*cantidadConmebol)++;
			break;

			case 3:
				(*cantidadConcacaf)++;
			break;

			case 4:
				(*cantidadAfc)++;
			break;

			case 5:
				(*cantidadOfc)++;
			break;

			case 6:
				(*cantidadCaf)++;
			break;
	}
	return confederacionSeleccionada;
}
