#include "leanvalidaciones.h"

int esPar(int num){
    int okPar;
    okPar = 0;
    
    if(num % 2 == 0){
        okPar = 1;
    }
    return okPar;
}

int esIgual(char* msj, int num1, int num2){
    int ok;
    ok = 0;
    
    if(num1 == num2){
        puts(msj);
        ok = 1;
    }
    return ok;
}
