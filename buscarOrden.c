#include<stdio.h>
#include<string.h>
#include "estructuras.h"

void buscarorden(OrdenTrabajo *ordenes, int n, int IDbuscar) {
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para buscar la orden.\n");
        return;
    }   

    OrdenTrabajo ordentrabajo;
    int encontrado = 0;

    while(fscanf(archivo, " %d,%99[^,],%99[^,],%99[^,],%f,%d,%f", 
        &ordentrabajo.id, 
        ordentrabajo.clientes.nombre, 
        ordentrabajo.clientes.equipo, 
        ordentrabajo.clientes.tipoTrabajo, 
        &ordentrabajo.costoBase, 
        &ordentrabajo.horasTrabajo,
        &ordentrabajo.tarifa) == 7)
    {
        if(IDbuscar == ordentrabajo.id) {
            printf("\n--- ORDEN ENCONTRADA ---\n");
            printf("ID: %d\n", ordentrabajo.id);
            printf("Nombre del cliente: %s\n", ordentrabajo.clientes.nombre);
            printf("Equipo del cliente: %s\n", ordentrabajo.clientes.equipo);
            printf("Tipo de trabajo: %s\n", ordentrabajo.clientes.tipoTrabajo);
            printf("Costo base: %.2f\n", ordentrabajo.costoBase);
            printf("Horas de trabajo: %d\n", ordentrabajo.horasTrabajo);
            printf("Tarifa: %.2f\n", ordentrabajo.tarifa);
            encontrado = 1;
            break; // Salimos del bucle al encontrarla
        }
    }

    if (encontrado == 0) {
        printf("Orden no encontrada.\n");
    }
        fclose(archivo);

    }