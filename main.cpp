#include "menu.h"
#include "AbbClientes.h"


int main(){

    AbbClientes clientes;
    Crear(clientes);

    ListaReclamos reclamos;
    Crear(reclamos);

    Cliente clienteAux;

    int opcionMenuGeneral=0, opcionMenuInterior=0;

    while(opcionMenuGeneral!=4){
        menuGeneral(opcionMenuGeneral);

        switch(opcionMenuGeneral){
            case 1:
                menuAltasBajas(opcionMenuInterior);
                switch(opcionMenuInterior){
                    case 1:
                        CargarCliente(clienteAux);
                        if(!ClienteRegistrado(clientes, ObtenerCI(clienteAux)))
                            AltaCliente(clientes, clienteAux);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                }

                break;
            case 2:
                menuConsultas(opcionMenuInterior);
                switch(opcionMenuInterior){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }

                break;
            case 3:
                menuListados(opcionMenuInterior);
                switch(opcionMenuInterior){
                    case 1:
                        if(!EsVacio(clientes))
                            ListarClientes(clientes);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
        }


    }



}
