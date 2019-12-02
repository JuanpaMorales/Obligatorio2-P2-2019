#include "Fecha.h"

void cargar(Fecha &f){
    do{
        printf("\nIngrese un dia: ");
        scanf("%i", &f.dia);
        printf("Ingrese un numero de mes: ");
        scanf("%i", &f.mes);
        printf("Ingrese un año: ");
        scanf("%i", &f.anio);
    }while( !validarFecha(f) );

}

void mostrar(Fecha f){
    printf("%i/%i/%i", f.dia, f.mes, f.anio);
}

int obtenerDia(Fecha f){ return f.dia; }
int obtenerMes(Fecha f){ return f.mes; }
int obtenerAnio(Fecha f){ return f.anio; }

bool validarFecha(Fecha f){
    bool esValida = false;
    switch(f.mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(f.dia >= 1 && f.dia <= 31)
                esValida = true;
            break;
        case 2:
            if(f.anio%4 == 0){
                if(f.dia >= 1 && f.dia <= 29)
                    esValida = true;
            }else{
                if(f.dia >= 1 && f.dia <= 28)
                    esValida = true;
            }
            break;
        default:
            if(f.dia >= 1 && f.dia <= 30)
                esValida = true;
            break;
    }
    return esValida;
}

bool sonIguales(Fecha f1, Fecha f2){
    bool iguales = false;
    if(f1.anio==f2.anio && f1.mes==f2.mes && f1.dia==f2.dia)
        iguales = true;
    return iguales;
}
