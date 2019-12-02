#include "ListaReclamos.h"

void Crear (ListaReclamos & lis){ lis = NULL; }
bool esVacia (ListaReclamos lis){ return lis == NULL; }
Reclamo Primero (ListaReclamos lis){ return lis->info; }

void Resto (ListaReclamos & lis) {
    ListaReclamos aux = lis;
    lis = lis->sig;
    delete aux;
}

void InsFront (ListaReclamos & lis, Reclamo e) {
    ListaReclamos aux = new NodoReclamo;
    aux->info = e;
    aux->sig = lis;
    lis = aux;
}

void AltaReclamo(ListaReclamos & lis, Reclamo e){ InsFront(lis, e); }

bool ReclamoExiste(ListaReclamos lis, int num){
    bool existe = false;
    while(!existe && lis != NULL){
        if( ObtenerNum(lis->info) == num )
            existe = true;
        else
            lis = lis->sig;
    }
    return existe;
}

int ProximoNum(ListaReclamos lis){
    int ultimoNum = 0;
    if(lis!=NULL)
        ultimoNum = ObtenerNum(Primero(lis));
    ultimoNum++;
    return ultimoNum;
}

Reclamo ObtenerReclamo(ListaReclamos lis, int num){
    if(ObtenerNum(lis->info) == num) return lis->info;
    else return ObtenerReclamo(lis->sig, num);
}

void resolverReclamo(ListaReclamos lis, int num){
    while(ObtenerNum(lis->info) != num)
        lis = lis->sig;
    setEstado(lis->info, true);
}

int TotalRecSolucionados(ListaReclamos lis){
    if(lis==NULL)
        return 0;
    else if(estaResuelto(lis->info))
        return 1 + TotalRecSolucionados(lis->sig);
    else
        return TotalRecSolucionados(lis->sig);
}
int TotalRecNOSolucionados(ListaReclamos lis){
    if(lis==NULL)
        return 0;
    else if(!estaResuelto(lis->info))
        return 1 + TotalRecNOSolucionados(lis->sig);
    else
        return TotalRecNOSolucionados(lis->sig);
}

int CantidadRecPorCI(ListaReclamos lis, int ci){
    int cantidad = 0;
    while(lis != NULL){
        if(ObtenerCI(lis->info) == ci)
            cantidad++;
        lis = lis->sig;
    }
    return cantidad;
}

int ciMasReclamador(ListaReclamos lis){
    int ciMax, cantidadMax=0, thisCI, thisCantidad;
    ListaReclamos aux = lis;

    while(aux != NULL){
        thisCI = ObtenerCI(lis->info);
        thisCantidad = CantidadRecPorCI(lis, thisCI);
        if(cantidadMax < thisCantidad){
            ciMax = thisCI;
            cantidadMax = thisCantidad;
        }
        aux = aux->sig;
    }

    return ciMax;
}

int ReclamosEnRango(ListaReclamos lis, Fecha desde, Fecha hasta){
    Fecha recFecha;
    int cantidad = 0;

    while(lis!=NULL){
        recFecha = ObtenerFecha(lis->info);
        if(mayorOigual(recFecha, desde) && mayorOigual(hasta, recFecha))
            cantidad++;
        lis = lis->sig;
    }

    return cantidad;
}

void ListarReclamos_ci(ListaReclamos lis, int ci){
    while(lis!=NULL){
        if(ObtenerCI(lis->info) == ci)
            MostrarReclamo(lis->info);
        lis = lis->sig;
    }
}

void ListarReclamos_fecha(ListaReclamos lis, Fecha f){
    while(lis!=NULL){
        if( sonIguales(ObtenerFecha(lis->info), f) )
            MostrarReclamo(lis->info);
        lis = lis->sig;
    }
}

