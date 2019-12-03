#include "Cliente.h"


void CargarCliente(Cliente &c){
    printf("\nIngrese Nombre: ");
    strcrear(c.nombre);
    scan(c.nombre);

    printf("Ingrese Apellido: ");
    strcrear(c.apellido);
    scan(c.apellido);

    printf("Ingrese CI: ");
    scanf("%i", &c.cedula);

    printf("Ingrese Tel.: ");
    scanf("%i", &c.telefono);

    printf("Ingrese Dirección: ");
    strcrear(c.direccion);
    fflush(stdin);
    scan(c.direccion);
}
void MostrarCliente(Cliente c){
    printf("\n");
    print(c.nombre);
    printf(" ");
    print(c.apellido);
    printf(" | ");
    printf("CI: %i", c.cedula);
    printf(" | Tel.: %i", c.telefono);
    printf(" | Dir.: ");
    print(c.direccion);
}
int ObtenerCI(Cliente c){ return c.cedula; }
string ObtenerNombre(Cliente c){ return c.nombre; }
string ObtenerApellido(Cliente c){ return c.apellido; }
string ObtenerDireccion(Cliente c){ return c.direccion; }
int ObtenerTel(Cliente c){ return c.telefono; }
