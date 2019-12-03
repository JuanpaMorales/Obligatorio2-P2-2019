
#include "AbbClientes.h"


int main(){

    AbbClientes clientes;
    Crear(clientes);

    Cliente c;
    for(int i=0; i<1; i++){
        CargarCliente(c);
        if(!ClienteRegistrado(clientes, ObtenerCI(c))){
            AltaCliente(clientes, c);
        }else{
            printf("\nError: cliente ya ingresado");
        }
    }

    if(!EsVacio(clientes)){
        ListarClientes(clientes);
    }


}
