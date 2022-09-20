int buscarValorEnVector(int vec[],int tam, int vBuscar){
	int retorno;
	retorno = 0;

	for(int i = 0; i < tam;i++){
		if(vec[i] == vBuscar){
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int obtenerPosicionEnVector(int vec[],int tam, int vBuscar){
	int posicion;
		posicion = -1;

		for(int i = 0; i < tam;i++){
			if(vec[i] == vBuscar){
				posicion = i;
				break;
			}
		}
		return posicion;
}

void rellenarVector(int vec[],int tam,int vInicial){
	for(int i = 0 ; i < tam; i++){
		vec[i] = vInicial;
	}
}

int obtenerMayorDeUnVector(int *vec,int tam){
	int mayor;
	int bandera;
	bandera = 0;

	for(int i = 0; i < tam; i++){
		if(bandera == 0 || *(vec+i) > mayor){
			mayor = *(vec+i);
			bandera = 1;
		}
	}

	return mayor;
}
