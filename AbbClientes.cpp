#include "AbbClientes.h"


void Crear(AbbClientes &a){ a = NULL; }
bool EsVacio (AbbClientes a){ return a==NULL; }
Cliente DarRaiz (AbbClientes a){ return a->info; }
AbbClientes HijoIzq (AbbClientes a){ return a->hizq; }
AbbClientes HijoDer (AbbClientes a){ return a->hder; }
AbbClientes Cons(Cliente c, AbbClientes i, AbbClientes d){
    AbbClientes a = new NodoCliente;
    a -> info = c;
    a -> hizq = i;
    a -> hder = d;
    return a;
}

bool ClienteRegistrado(AbbClientes a, int ci) {
    if (a == NULL)
        return false;
    else if ( ObtenerCI(a->info) == ci)
        return true;
    else if ( ci < ObtenerCI(a->info) )
        return ClienteRegistrado(a->hizq, ci);
    else
        return ClienteRegistrado(a->hder, ci);
}

void AltaCliente(AbbClientes &a, Cliente c) {
    if (a == NULL) {
        a = new NodoCliente;
        a->info = c;
        a->hizq = NULL;
        a->hder = NULL;
    } else {
        if (ObtenerCI(c) < ObtenerCI(a->info))
            AltaCliente(a->hizq, c);
        else
            AltaCliente(a->hder, c);
    }
}

void ListarClientes(AbbClientes a){
    if(a != NULL){
        ListarClientes(a->hizq);
        MostrarCliente(a->info);
        ListarClientes(a->hder);
    }
}


Cliente Minimo(AbbClientes a){
    while(a->hizq != NULL)
        a = a->hizq;
    return a->info;
}

void Borrar_Minimo (AbbClientes &a){
    AbbClientes aux;
    if (a->hizq == NULL) {
        aux = a->hder;
        delete a;
        a = aux;
    } else
        Borrar_Minimo(a->hizq);
}

void BajaCliente(AbbClientes &a, int ci) {
    AbbClientes aux;
    if (ci == ObtenerCI(a->info)) {
        if (a->hder == NULL) {
            aux = a->hizq;
            delete a;
            a = aux;
        } else {
            if (a->hizq == NULL) {
                aux = a->hder;
                delete a;
                a = aux;
            } else {
                a->info = Minimo(a->hder);
                Borrar_Minimo(a->hder);
            }
        }
    } else {
        if(ci < ObtenerCI(a->info) )
            BajaCliente(a->hizq, ci);
        else
            BajaCliente(a->hder, ci);
    }
}


int ClientesNoReclamos(AbbClientes a, ListaReclamos r){
    if (a == NULL)
        return 0;
    else
        return CantidadRecPorCI(r, ObtenerCI(a->info) ) + ClientesNoReclamos(a->hizq, r) + ClientesNoReclamos(a->hder, r);
}



