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


