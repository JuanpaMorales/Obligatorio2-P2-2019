#ifndef LISTARECLAMOS_H_INCLUDED
#define LISTARECLAMOS_H_INCLUDED

#include "Reclamo.h"

typedef struct nodoB{
    Reclamo info;
    nodoB * sig;
} NodoReclamo;

typedef NodoReclamo * ListaReclamos;


void Crear(ListaReclamos & lis);
bool esVacia(ListaReclamos lis);
/* Precondición: lista NO vacía */
Reclamo Primero(ListaReclamos lis);
/* Precondición: lista NO vacía */
void Resto(ListaReclamos & lis);
void InsFront(ListaReclamos & lis, Reclamo e);

/// Precondición: ClienteRegistrado && (esVacia(lis) || mayorOigual(fecha reclamo, fecha ultimo cargado) ) && validarFecha(reclamo)
void AltaReclamo(ListaReclamos & lis, Reclamo e);
bool ReclamoExiste(ListaReclamos lis, int num);
int ProximoNum(ListaReclamos lis);

/// Precondición: ReclamoExiste
Reclamo ObtenerReclamo(ListaReclamos lis, int num);

void resolverReclamo(ListaReclamos lis, int num);

int TotalRecSolucionados(ListaReclamos lis);
int TotalRecNOSolucionados(ListaReclamos lis);
/// Precondición: !esVacia()
int CantidadRecPorCI(ListaReclamos lis, int ci);
/// Precondición: !esVacia()
int ciMasReclamador(ListaReclamos lis);
/// Precondición: ambas fechas validas y desde <= hasta
int ReclamosEnRango(ListaReclamos lis, Fecha desde, Fecha hasta);
/// Precondición: ClienteRegistrado()
void ListarReclamos_ci(ListaReclamos lis, int ci);
/// Precondición: facha valida
void ListarReclamos_fecha(ListaReclamos lis, Fecha f);





#endif // LISTARECLAMOS_H_INCLUDED
