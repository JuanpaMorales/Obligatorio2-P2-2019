#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

void cargar(Fecha &f);
void mostrar(Fecha f);
int obtenerDia(Fecha f);
int obtenerMes(Fecha f);
int obtenerAnio(Fecha f);
bool validarFecha(Fecha f);
bool sonIguales(Fecha f1, Fecha f2);


#endif // FECHA_H_INCLUDED
