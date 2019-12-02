#ifndef ABBCLIENTES_H_INCLUDED
#define ABBCLIENTES_H_INCLUDED

#include "Cliente.h"

typedef struct nodoA{
		Cliente info;
        nodoA *hizq;
		nodoA *hder;
} NodoCliente;

typedef NodoCliente *AbbClientes;


void Crear(AbbClientes &a);
bool EsVacio (AbbClientes a);
/// Precondición: Arbol NO vacío
Cliente DarRaiz (AbbClientes a);
/// Precondición: Arbol NO vacío
AbbClientes HijoIzq (AbbClientes a);
/// Precondición: Arbol NO vacío
AbbClientes HijoDer (AbbClientes a);
AbbClientes Cons(Cliente c, AbbClientes i, AbbClientes d);
/// Precondición: Arbol NO vacío
Cliente Minimo(AbbClientes a);
/// Precondición: Arbol NO vacío
void Borrar_Minimo (AbbClientes &a);

bool ClienteRegistrado(AbbClientes a, int ci);
/// Precondición: !ClienteRegistrado()
void AltaCliente(AbbClientes &a, Cliente c);

/// Precondición: !EsVacio()
void ListarClientes(AbbClientes a);
/// Precondición: ClienteRegistrado()
void BajaCliente(AbbClientes &a, int ci);

//====================================================================

/// Precondición: !EsVacio()
int ClientesNoReclamos(AbbClientes a);


#endif // ABBCLIENTES_H_INCLUDED
