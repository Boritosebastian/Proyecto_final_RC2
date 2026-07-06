#include<stdio.h>
#include<string.h>
#include "estructuras.h"
#include "registrarOrden.h"

void existeID(int idBuscar, int *encontrado) {
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        *encontrado = 0; // Si el archivo no existe, no está repetido
        return;
    }

    OrdenTrabajo ordentrabajo;
    *encontrado = 0; // Inicializamos asumiendo que no existe

    while (fscanf(archivo, "%d,%99[^,],%99[^,],%99[^,],%f,%d,%f", 
           &ordentrabajo.id, 
           ordentrabajo.clientes.nombre, 
           ordentrabajo.clientes.equipo, 
           ordentrabajo.clientes.tipoTrabajo, 
           &ordentrabajo.costoBase, 
           &ordentrabajo.horasTrabajo,
           &ordentrabajo.tarifa) == 7) 
    {
        if (ordentrabajo.id == idBuscar) {
            *encontrado = 1; // Encontrado
            break;
        }
    }

    fclose(archivo);
}