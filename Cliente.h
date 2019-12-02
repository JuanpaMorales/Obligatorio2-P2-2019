#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "string.h"

typedef struct{
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    int telefono;

} Cliente;

void CargarCliente(Cliente &c);
void MostrarCliente(Cliente c);
int ObtenerCI(Cliente c);
string ObtenerNombre(Cliente c);
string ObtenerApellido(Cliente c);
string ObtenerDireccion(Cliente c);
int ObtenerTel(Cliente c);

#endif // CLIENTE_H_INCLUDED
