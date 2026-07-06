#include <stdio.h>
#include <string.h>
#include "estructuras.h"
#include "existeID.h"

void registrarOrden(OrdenTrabajo *ordenes, int *n) {
    if (*n >= 10) {
        printf("No se pueden registrar más ordenes de trabajo. Capacidad máxima alcanzada.\n");
        return;
    }

    OrdenTrabajo ordentrabajo;
    int respuesta;

        int existe; //Declaramos la variable local
        do {
            printf("\nIngrese el ID de la orden (solo numeros positivos): ");
            scanf("%d", &ordentrabajo.id);
            getchar(); // Limpia el enter residual del teclado

            if (ordentrabajo.id <= 0) {
                printf("Error El ID debe ser un numero mayor a cero. Intente de nuevo.\n");
            }

            existeID(ordentrabajo.id, &existe, ordenes, *n);

            for (int i = 0; i < *n; i++) {
            if (ordenes[i].id == ordentrabajo.id) {
                existe = 1;
                break;
            }
        }

            if (existe == 1) { 
                printf("Error El ID %d ya se encuentra registrado. Intente con otro.\n", ordentrabajo.id);
            }

        // El bucle se repite si el numero es negativo/cero O si ya existe en el archivo
        } while (ordentrabajo.id <= 0 || existe == 1);

    printf("Ingrese el nombre del cliente: ");
    fgets(ordentrabajo.clientes.nombre, 100, stdin);
    ordentrabajo.clientes.nombre[strcspn(ordentrabajo.clientes.nombre, "\n")] = '\0'; 

    printf("Ingrese el equipo del cliente: ");
    fgets(ordentrabajo.clientes.equipo, 100, stdin);
    ordentrabajo.clientes.equipo[strcspn(ordentrabajo.clientes.equipo, "\n")] = '\0'; 

    printf("Ingrese el tipo de trabajo: ");
    fgets(ordentrabajo.clientes.tipoTrabajo, 100, stdin);
    ordentrabajo.clientes.tipoTrabajo[strcspn(ordentrabajo.clientes.tipoTrabajo, "\n")] = '\0'; 

    printf("Ingrese el costo base: ");
    do{
        scanf("%f", &ordentrabajo.costoBase);
        if (ordentrabajo.costoBase < 0) {
            printf("Error El costo base no puede ser negativo. Intente de nuevo: ");
        }
    } while (ordentrabajo.costoBase < 0);

    printf("Ingrese las horas de trabajo: ");
    do{
        scanf("%d", &ordentrabajo.horasTrabajo);
        if (ordentrabajo.horasTrabajo < 0) {
            printf("Error Las horas de trabajo no pueden ser negativas. Intente de nuevo: ");
        }

        ordentrabajo.tarifa = ordentrabajo.horasTrabajo * ordentrabajo.costoBase; // Calcula la tarifa según las horas de trabajo
    } while (ordentrabajo.horasTrabajo < 0);
    

    ordenes[*n] = ordentrabajo;
    (*n)++;


    printf("Orden/es de trabajo registrada exitosamente.\n");
    printf("Recuerde Guardar antes para poder ver las ordenes de trabajo\n");

}