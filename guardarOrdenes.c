#include<stdio.h>
#include<string.h>
#include "estructuras.h"

void guardarOrdenes(OrdenTrabajo *a, int n) {
    FILE *archivo = fopen("ordenes.csv", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar las ordenes.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d,%s,%s,%s,%.2f,%d,%.2f\n",
            a[i].id, 
            a[i].clientes.nombre, 
            a[i].clientes.equipo, 
            a[i].clientes.tipoTrabajo, 
            a[i].costoBase, 
            a[i].horasTrabajo,
            a[i].tarifa
        );
    }

    fclose(archivo);
    printf("Ordenes guardadas exitosamente en 'ordenes.csv'.\n");
}