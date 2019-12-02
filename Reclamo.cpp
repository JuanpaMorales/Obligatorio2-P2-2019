#include "Reclamo.h"

void CargarReclamo(Reclamo &r, int numero){
    printf("\n---- Nuevo Reclamo ---- ");

    printf("\nIngrese CI: ");
    scanf("%i", &r.cedula);

    printf("\nIngrese Fecha: ");
    cargar(r.fec);

    printf("\nIngrese Descripción: ");
    strcrear(r.descri);
    scan(r.descri);

    r.resuelto = false;
    r.numReclamo = numero;
}


void MostrarReclamo(Reclamo r){
    printf("\n");
    printf("Num: %i, CI: %i, ", r.numReclamo, r.cedula);
    mostrar(r.fec);
    printf(" , ");

    if(r.resuelto)
        printf("RESUELTO");
    else
        printf("NO RESUELTO");

    printf(" , Descripción: ");
    print(r.descri);
}

int ObtenerNum(Reclamo r){ return r.numReclamo; }
Fecha ObtenerFecha(Reclamo r){ return r.fec; }
int ObtenerCI(Reclamo r){ return r.cedula; }
string ObtenerDescri(Reclamo r){ return r.descri; }
bool estaResuelto(Reclamo r){ return r.resuelto; }
