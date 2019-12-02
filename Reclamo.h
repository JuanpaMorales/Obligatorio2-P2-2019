#ifndef RECLAMO_H_INCLUDED
#define RECLAMO_H_INCLUDED

#include "string.h"
#include "Fecha.h"

typedef struct{
    int numReclamo;
    Fecha fec;
    int cedula;
    string descri;
    bool resuelto;
} Reclamo;

void CargarReclamo(Reclamo &r);
void MostrarReclamo(Reclamo r);
int ObtenerNum(Reclamo r);
Fecha ObtenerFecha(Reclamo r);
int ObtenerCI(Reclamo r);
string ObtenerDescri(Reclamo r);
bool estaResuelto(Reclamo r);


#endif // RECLAMO_H_INCLUDED
