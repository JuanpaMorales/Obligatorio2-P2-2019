
#include "AbbClientes.h"
#include "ListaReclamos.h"


int main(){

    ListaReclamos lis;
    Crear(lis);


    for(int i=0; i<2; i++){
        Reclamo r;
        CargarReclamo(r, ProximoNum(lis));
        if( (esVacia(lis) || mayorOigual(ObtenerFecha(r), ObtenerFecha(Primero(lis))) ) && validarFecha(ObtenerFecha(r)) ){
            AltaReclamo(lis, r);
        }else{
            printf("\nerror");
        }

    }

    if(ReclamoExiste(lis, 2)){
        MostrarReclamo(ObtenerReclamo(lis, 2));
        resolverReclamo(lis, 2);
        MostrarReclamo(ObtenerReclamo(lis, 2));
    }
    else printf("\nNo existe el reclamo");


}
