#include "funcFutbol.h"


int cargarCosto(int hospedaje, int comida, int transporte){
	int costoSeleccionado;

	system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
	printf("\t\tIngreso de los costos de Mantenimiento\n"
			"\t\t======================================\n"
			"\n1.Costo de Hospedaje -> $%d"
			"\n2.Costo de Comida -> $%d"
			"\n3.Costo de Transporte -> $%d"
			"\n4.Volver al menu\n",hospedaje,comida,transporte);

	costoSeleccionado = imprYGuardarNumConMinYMax("\nSeleccione un costo ","Respuesta no valida",1, 4,0);
	return costoSeleccionado;
}

int modificarCosto(int *hospedaje, int *comida, int *transporte, int costoElegido){
	int ok;
	int montoGastado;

	if(hospedaje != NULL && comida != NULL && transporte != NULL && costoElegido >= 1 && costoElegido <= 3){
		ok = 1;

		montoGastado = imprYGuardarNumMayor("\nMonto gastado $", "El monto ingresado NO es valido.", 1);

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
		validacion = 0;

		if(avisar){
			imprAviso("Se llego a la cantidad maxima de la posicion seleccionada");
		}
	}

	return validacion;

}

int cargarJugador(int arqueros, int defensores,int mediocampistas,int delanteros){
	int posicionSeleccionada;
	posicionSeleccionada = -1;

	if((arqueros + defensores + mediocampistas + delanteros) < MAXJUGADORES){
		system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
		printf("\t\tCarga de jugadores\n"
				"\t\t==================\n"
				"\n1.Arqueros -> %d"
				"\n2.Defensores -> %d"
				"\n3.Mediocampistas -> %d"
				"\n4.Delanteros -> %d"
				"\n5.Volver al menu\n",arqueros,defensores,mediocampistas,delanteros);

		do{//Do While para validar si la posicion seleccionada llego al limite de jugadores
			posicionSeleccionada = imprYGuardarNumConMinYMax("\nSeleccione una posicion ","Posicion Invalida",1, 5,0);
		}while(posicionSeleccionada != 5 && !validarPosicionDisponible(arqueros, defensores, mediocampistas, delanteros, posicionSeleccionada-1,1));

	}
	return posicionSeleccionada;
}

int aumentarContadorPosicionJugador(int* arqueros, int* defensores,int* mediocampistas,int *delanteros, int posicionSeleccionada){
	int ok;
	ok = -1;

	if(arqueros != NULL && defensores != NULL && mediocampistas != NULL && delanteros != NULL){
		ok = 1;

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

		default:
			ok = 0;
		break;
		}
	}
	return ok;
}

int pedirCamisetaJugador(){
	int numCamisetaSeleccionada;
	numCamisetaSeleccionada = imprYGuardarNumConMinYMax("\nIngrese el numero de Camiseta(1-99) ", "\nEl numero de Camiseta seleccionado no esta permitido.", 1, 99, 0);

	return numCamisetaSeleccionada;
}

int pedirConfederacionJugador(int cantidadUefa, int cantidadConmebol, int cantidadConcacaf, int cantidadAfc, int cantidadOfc, int cantidadCaf){
	int confederacionSeleccionada;

	puts("\n1. UEFA"
			"\n2. CONMEBOL"
			"\n3. CONCACAF"
			"\n4. AFC"
			"\n5. OFC"
			"\n6. CAF");

	confederacionSeleccionada = imprYGuardarNumConMinYMax("\nSeleccione una confederacion ","Confederacion Invalida", 1, 6, 0);

	return confederacionSeleccionada;
}

int aumentarContadorConfederacion(int *cantidadUefa, int *cantidadConmebol, int *cantidadConcacaf, int *cantidadAfc, int *cantidadOfc, int *cantidadCaf, int confeSeleccionada){
	int ok;
	ok = -1;

	if(cantidadUefa != NULL && cantidadConmebol != NULL && cantidadConcacaf != NULL && cantidadAfc != NULL && cantidadOfc != NULL && cantidadCaf != NULL){
		ok = 1;
		switch(confeSeleccionada){//Crea una funcion switchIncremental(); fijate el retorno y parameters
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

				default:
					ok = 0;
				break;
		}
	}
	return ok;
}

int validarRealizarCalculos(int banderaCostosCargados, int banderaJugadoresCargados){
	int ok;
	ok = 0;

	if(banderaCostosCargados && banderaJugadoresCargados){
		ok = 1;
	}
	return ok;
}

int realizarAumentoEuropeo(int cantidadUefa, int cantidadDeJugadoresTotal, int mantenimiento){
	int aumentoEuropeo;
	aumentoEuropeo = 0;
	if(cantidadUefa > (cantidadDeJugadoresTotal - cantidadUefa)){//Si contadorUefa es mayor a la cantidad de jugadors de las demas confederaciones entra al if
		aumentoEuropeo = ((float)PORCENTAJEDEAUMENTOEUROPEO/100) * mantenimiento;
	}
	return aumentoEuropeo;
}

void informarPromedioConfederaciones(float promedioUefa,float promedioConmebol,float promedioConcacaf,float promedioAfc,float promedioOfc,float promedioCaf){
	system("cls"); //Limpia la pantalla (Solo funciona con el .exe)
	printf("\t\tInformar todos los Resultados\n"
		   "\t\t=============================\n"
		   "\nPromedio UEFA %.2f"
		   "\nPromedio CONMEBOL %.2f"
		   "\nPromedio CONCACAF %.2f"
		   "\nPromedio AFC %.2f"
		   "\nPromedio OFC %.2f"
		   "\nPromedio CAF %.2f",promedioUefa,promedioConmebol,promedioConcacaf,promedioAfc,promedioOfc,promedioCaf);
}

void informarCostosDeMantenimiento(int mantenimiento,int aumentoEuropeo, int mantenimientoEuropeo){
	if(aumentoEuropeo == 0){
		printf("\n\nEl costo de mantenimiento es de $%d\n\n",mantenimiento);
	}
	else{
		printf("\n\nEl costo de mantenimiento era de $%d y recibio un aumento de $%d, su nuevo valor es de $%d\n\n",mantenimiento,aumentoEuropeo,mantenimientoEuropeo);
	}
	system("pause");
}
