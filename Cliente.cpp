#include "Cliente.h"


void CargarCliente(Cliente &c){
    printf("\nIngrese Nombre: ");
    strcrear(c.nombre);
    scan(c.nombre);

    printf("\nIngrese Apellido: ");
    strcrear(c.apellido);
    scan(c.apellido);

    printf("\nIngrese CI: ");
    scanf("%i", &c.cedula);

    printf("\nIngrese Tel.: ");
    scanf("%i", &c.telefono);

    printf("\nIngrese Dirección: ");
    strcrear(c.direccion);
    fflush(stdin);
    scan(c.direccion);
}
void MostrarCliente(Cliente c){
    printf("\n");
    print(c.nombre);
    printf(" ");
    print(c.apellido);
    printf(": ");
    printf("\nCI: %i", c.cedula);
    printf("\nTel.: %i", c.telefono);
    printf("\nDir.: ");
    print(c.direccion);
    printf("\n");
}
int ObtenerCI(Cliente c){ return c.cedula; }
string ObtenerNombre(Cliente c){ return c.nombre; }
string ObtenerApellido(Cliente c){ return c.apellido; }
string ObtenerDireccion(Cliente c){ return c.direccion; }
int ObtenerTel(Cliente c){ return c.telefono; }
