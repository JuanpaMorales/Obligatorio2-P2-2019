#include "menu.h"

void menuGeneral(int &opcionGeneral){
    printf("\n\n============= Menu ===================\n");
    printf("\n1- Altas / Bajas");
    printf("\n2- Consultas");
    printf("\n3- Listados");
    printf("\n4 - Salir");
    printf("\n");

    scanf("%i", &opcionGeneral);
}
void menuAltasBajas(int &opcionSubMenu){
    printf("\n\n--------- Altas / Bajas ---------\n");
    printf("\n1- Alta de cliente");
    printf("\n2- Alta de reclamo");
    printf("\n3- Baja de cliente");
    printf("\n4- Volver atras");
    printf("\n");

    scanf("%i", &opcionSubMenu);
}
void menuConsultas(int &opcionSubMenu){
    printf("\n\n--------- Consultas ---------\n");
    printf("\n1- Total reclamos solucionados");
    printf("\n2- Total reclamos NO solucionados");
    printf("\n3- Reclamos en rango de fechas");
    printf("\n4- Cliente mas reclamador");
    printf("\n5- Volver atras");
    printf("\n");

    scanf("%i", &opcionSubMenu);
}
void menuListados(int &opcionSubMenu){
    printf("\n\n--------- Listados ---------\n");
    printf("\n1- Clientes registrados");
    printf("\n2- Reclamos de un cliente");
    printf("\n3- Reclamos por fecha");
    printf("\n4- Datos cliente del reclamo");
    printf("\n5- Volver atras");
    printf("\n");

    scanf("%i", &opcionSubMenu);
}
