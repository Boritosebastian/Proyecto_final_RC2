#include<stdio.h>
#include<string.h>
#include "estructuras.h"

void eliminarOrden(OrdenTrabajo *ordenes, int *n, int IDeliminar) {
    FILE *archivo = fopen("ordenes.csv", "r");
    FILE *temporal = fopen("temporal.csv", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error al abrir los archivos para el proceso de eliminacion.\n");
        if (archivo) fclose(archivo);
        if (temporal) fclose(temporal);
        return;
    }

    OrdenTrabajo ordentrabajo;
    int encontrado = 0;

    // Leemos todo el archivo y pasamos al temporal solo lo que NO queremos borrar
    while (fscanf(archivo, " %d,%99[^,],%99[^,],%99[^,],%f,%d,%f", 
           &ordentrabajo.id, 
           ordentrabajo.clientes.nombre, 
           ordentrabajo.clientes.equipo, 
           ordentrabajo.clientes.tipoTrabajo, 
           &ordentrabajo.costoBase, 
           &ordentrabajo.horasTrabajo,
           &ordentrabajo.tarifa) == 7) 
    {
    
        if (ordentrabajo.id == IDeliminar) {
            encontrado = 1; // Marcamos que encontramos el registro a borrar
            // No escribimos nada en el archivo temporal, así se "elimina"
        } else {
            // Si el ID es diferente, lo conservamos en el temporal
            fprintf(temporal, "%d,%s,%s,%s,%.2f,%d,%.2f\n",
                ordentrabajo.id, 
                ordentrabajo.clientes.nombre, 
                ordentrabajo.clientes.equipo, 
                ordentrabajo.clientes.tipoTrabajo, 
                ordentrabajo.costoBase, 
                ordentrabajo.horasTrabajo,
                ordentrabajo.tarifa);
        }
    }

    fclose(archivo);
    fclose(temporal);

    int respuesta;
    printf("Esta seguro de eliminar\n");
    printf("1. Si\n");
    printf("2. No\n");
    scanf("%d",&respuesta);

    if(respuesta == 1){
    if (encontrado == 0) {
        printf("No se encontro ninguna orden con el ID %d en el archivo.\n", IDeliminar);
        remove("temporal.csv"); // Elimina el archivo temporal vacío o idéntico
    } else {
        // Reemplazamos el archivo viejo por el nuevo que no tiene la fila borrada
        remove("ordenes.csv");
        rename("temporal.csv", "ordenes.csv");
        printf("Orden con ID %d eliminada exitosamente del archivo.\n", IDeliminar);
    }
}

    // Buscamos la posición en el arreglo 
    for (int i = 0; i < *n; i++) {
        if (ordenes[i].id == IDeliminar) {
            // Recorremos todos los elementos siguientes una posición a la izquierda
            for (int j = i; j < (*n) - 1; j++) {
                ordenes[j] = ordenes[j + 1];
            }
            (*n)--;
            printf("Archivo actualizado correctamente\n");
            break;
        }
    }
}