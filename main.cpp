
#include "AbbClientes.h"
#include "ListaReclamos.h"


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



    if(!EsVacio(clientes)){
        ListarClientes(clientes);
    }else printf("\nNo hay clientes cargados");


    int ciAborrar;
    printf("\nIngrese CI a borrar: ");
    scanf("%i", &ciAborrar);

    if(ClienteRegistrado(clientes, ciAborrar)){
        BajaCliente(clientes, ciAborrar);
    }else printf("\nEl Cliente a borrar no existe");

    if(!EsVacio(clientes)){
        ListarClientes(clientes);
    }else printf("\nNo hay clientes cargados");


}
