
#include "AbbClientes.h"


int main(){

    AbbClientes clientes;
    Crear(clientes);

    Cliente c;
    for(int i=0; i<3; i++){
        CargarCliente(c);
        if(!ClienteRegistrado(clientes, ObtenerCI(c))){
            AltaCliente(clientes, c);
        }else{
            printf("\nError: cliente ya ingresado");
        }
    }

    ListaReclamos reclamos;
    Crear(reclamos);
    Reclamo recAux;

    for(int i=0; i<3; i++){
        CargarReclamo(recAux, ProximoNum(reclamos));
        if(ClienteRegistrado(clientes, ObtenerCI(recAux))){
            AltaReclamo(reclamos, recAux);
        }else printf("\nCliente del reclamo no existe");
    }


    printf("\nClientes sin reclamos: %i", ClientesNoReclamos(clientes, reclamos) );


}
