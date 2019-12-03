#include "menu.h"
#include "AbbClientes.h"


int main(){

    AbbClientes clientes;
    Crear(clientes);

    ListaReclamos reclamos;
    Crear(reclamos);

    Cliente clienteAux;
    Reclamo recAux;

    int opcionMenuGeneral=0, opcionMenuInterior=0, intAux;
    Fecha fechaAux, fechaAux2;

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
                        CargarReclamo(recAux, ProximoNum(reclamos));

                        if(
                           ClienteRegistrado(clientes, ObtenerCI(recAux)) &&
                           (
                                esVacia(reclamos) ||
                                mayorOigual(ObtenerFecha(recAux), ObtenerFecha(Primero(reclamos)))
                            ) &&
                           validarFecha(ObtenerFecha(recAux))
                        ){
                            AltaReclamo(reclamos, recAux);
                        }
                        break;
                    case 3:
                        printf("\nIngrese ci de cliente a borrar: ");
                        scanf("%i", &intAux);
                        if(ClienteRegistrado(clientes, intAux)){
                            BajaCliente(clientes, intAux);
                            BajaReclamos(reclamos, intAux);
                        }
                        else printf("\nCliente no registrado");
                        break;
                    case 4:
                        printf("\nIngrese numero de reclamo: ");
                        scanf("%i", &intAux);
                        if(ReclamoExiste(reclamos, intAux))
                            resolverReclamo(reclamos, intAux);
                        break;
                }

                break;
            case 2:
                menuConsultas(opcionMenuInterior);
                switch(opcionMenuInterior){
                    case 1:
                        printf("\nTotal reclamos solucionados: %i", TotalRecSolucionados(reclamos));
                        break;
                    case 2:
                        printf("\nTotal reclamos NO solucionados: %i", TotalRecNOSolucionados(reclamos));
                        break;
                    case 3:
                        printf("\nFecha desde: ");
                        cargar(fechaAux);
                        printf("\nFecha hasta: ");
                        cargar(fechaAux2);
                        if(validarFecha(fechaAux) && validarFecha(fechaAux2) && mayorOigual(fechaAux2, fechaAux) )
                            printf("\nCantidad de reclamos en el rango de fechas: %i", ReclamosEnRango(reclamos, fechaAux, fechaAux2));
                        else printf("\nFechas invalidas");
                        break;
                    case 4:
                        if(!esVacia(reclamos))
                            printf("\nci cliente mas reclamador: %i", ciMasReclamador(reclamos));
                        break;
                }

                break;
            case 3:
                menuListados(opcionMenuInterior);
                switch(opcionMenuInterior){
                    case 1:
                        if(!EsVacio(clientes))
                            ListarClientes(clientes);
                        else printf("\nNo hay clientes registrados");
                        break;
                    case 2:
                        printf("\nIngrese una ci: ");
                        scanf("%i", &intAux);
                        if(ClienteRegistrado(clientes, intAux))
                            ListarReclamos_ci(reclamos, intAux);
                        else printf("\nEl cliente no esta registrado");
                        break;
                    case 3:
                        printf("\nIngrese una fecha: ");
                        cargar(fechaAux);
                        if(validarFecha(fechaAux))
                            ListarReclamos_fecha(reclamos, fechaAux);
                        else printf("\nFecha invalida");
                        break;
                    case 4:
                        printf("\nIngrese numero de reclamo: ");
                        scanf("%i", &intAux);
                        if(ReclamoExiste(reclamos, intAux)){
                            recAux = ObtenerReclamo(reclamos, intAux);
                            if(ClienteRegistrado(clientes, ObtenerCI(recAux)))
                                MostrarCliente(ObtenerCliente(clientes, ObtenerCI(recAux)));
                        }
                        break;
                }
                break;
        }


    }



}
