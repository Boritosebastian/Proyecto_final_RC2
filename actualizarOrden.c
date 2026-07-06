#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "actualizarOrden.h"

void actualizarOrden(OrdenTrabajo *ordenes, int n, int IDactualizar) {
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para buscar la orden.\n");
        return;
    }

    OrdenTrabajo ordentrabajo;
    int encontrado = 0;

    // 1. Verificar si la orden existe en el archivo
    while (fscanf(archivo, " %d,%99[^,],%99[^,],%99[^,],%f,%d,%f", 
           &ordentrabajo.id, 
           ordentrabajo.clientes.nombre, 
           ordentrabajo.clientes.equipo, 
           ordentrabajo.clientes.tipoTrabajo, 
           &ordentrabajo.costoBase, 
           &ordentrabajo.horasTrabajo,
           &ordentrabajo.tarifa) == 7) 
    {
        if (ordentrabajo.id == IDactualizar) {
            encontrado = 1;
            break;
        }
    }
    fclose(archivo);

    if (encontrado == 0) {
        printf("No se encontro ninguna orden con el ID %d para actualizar.\n", IDactualizar);
        return;
    }

    OrdenTrabajo nuevaOrden;
    
    nuevaOrden.id = IDactualizar; 

    printf("\n--- ACTUALIZANDO LA ORDEN %d ---\n", IDactualizar);
    printf("(El ID de la orden no puede ser modificado por seguridad)\n\n");
    getchar(); // Limpiar enter residual del teclado

    printf("Ingrese el nuevo nombre del cliente: ");
    fgets(nuevaOrden.clientes.nombre, 100, stdin);
    nuevaOrden.clientes.nombre[strcspn(nuevaOrden.clientes.nombre, "\n")] = '\0';

    printf("Ingrese el nuevo equipo del cliente: ");
    fgets(nuevaOrden.clientes.equipo, 100, stdin);
    nuevaOrden.clientes.equipo[strcspn(nuevaOrden.clientes.equipo, "\n")] = '\0';

    printf("Ingrese el nuevo tipo de trabajo: ");
    fgets(nuevaOrden.clientes.tipoTrabajo, 100, stdin);
    nuevaOrden.clientes.tipoTrabajo[strcspn(nuevaOrden.clientes.tipoTrabajo, "\n")] = '\0';

    printf("Ingrese el nuevo costo base: ");
    do {
        scanf("%f", &nuevaOrden.costoBase);
        if (nuevaOrden.costoBase < 0) {
            printf("Error: El costo base no puede ser negativo. Intente de nuevo: ");
        }
    } while (nuevaOrden.costoBase < 0);

    printf("Ingrese las nuevas horas de trabajo: ");
    do {
        scanf("%d", &nuevaOrden.horasTrabajo);
        if (nuevaOrden.horasTrabajo < 0) {
            printf("Error: Las horas no pueden ser negativas. Intente de nuevo: ");
        }
    } while (nuevaOrden.horasTrabajo < 0);

    nuevaOrden.tarifa = nuevaOrden.horasTrabajo * nuevaOrden.costoBase;

    archivo = fopen("ordenes.csv", "r");
    FILE *temporal = fopen("temporal.csv", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error al procesar los archivos para la actualizacion.\n");
        if (archivo) fclose(archivo);
        if (temporal) fclose(temporal);
        return;
    }

    while (fscanf(archivo, " %d,%99[^,],%99[^,],%99[^,],%f,%d,%f", 
           &ordentrabajo.id, 
           ordentrabajo.clientes.nombre, 
           ordentrabajo.clientes.equipo, 
           ordentrabajo.clientes.tipoTrabajo, 
           &ordentrabajo.costoBase, 
           &ordentrabajo.horasTrabajo,
           &ordentrabajo.tarifa) == 7) 
    {
        if (ordentrabajo.id == IDactualizar) {
            // Se sobreescribe la fila vieja usando 'nuevaOrden' que conserva el ID intacto
            fprintf(temporal, "%d,%s,%s,%s,%.2f,%d,%.2f\n",
                nuevaOrden.id, 
                nuevaOrden.clientes.nombre, 
                nuevaOrden.clientes.equipo, 
                nuevaOrden.clientes.tipoTrabajo, 
                nuevaOrden.costoBase, 
                nuevaOrden.horasTrabajo,
                nuevaOrden.tarifa);
        } else {
            // Copiamos los registros de las otras órdenes tal cual estaban
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

    remove("ordenes.csv");
    rename("temporal.csv", "ordenes.csv");
    printf("\nArchivo CSV actualizado exitosamente.\n");

    for (int i = 0; i < n; i++) {
        if (ordenes[i].id == IDactualizar) {
            ordenes[i] = nuevaOrden;
            break;
        }
    }
}