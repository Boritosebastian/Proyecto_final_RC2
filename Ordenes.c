#include<stdio.h>
#include<string.h>

struct Clientes {
    char nombre[100];
    char equipo[100];
    char tipoTrabajo[100];
};

typedef struct {
    int id;
    struct Clientes clientes;
    float costoBase;
    int horasTrabajo;
} OrdenTrabajo;

void mostrarOrdenes(OrdenTrabajo *a);

int main(){
    
    OrdenTrabajo ListaOrdenes[10];

    ListaOrdenes[0].id = 3412;
    strcpy(ListaOrdenes[0].clientes.nombre, "Juan Perez");
    strcpy(ListaOrdenes[0].clientes.equipo, "Laptop");
    strcpy(ListaOrdenes[0].clientes.tipoTrabajo, "Reparación de pantalla");
    ListaOrdenes[0].costoBase = 150.0;
    ListaOrdenes[0].horasTrabajo = 2;

    ListaOrdenes[1].id = 3413;
    strcpy(ListaOrdenes[1].clientes.nombre, "Maria Lopez");
    strcpy(ListaOrdenes[1].clientes.equipo, "PC de escritorio");
    strcpy(ListaOrdenes[1].clientes.tipoTrabajo, "Instalación de software");
    ListaOrdenes[1].costoBase = 100.0;
    ListaOrdenes[1].horasTrabajo = 1;

  
    int opcion;

    printf("---------------- MENU ----------------\n");
    printf("1. Registrar orden de trabajo\n");
    printf("2. Buscar ordenes de trabajo\n"); 
    printf("3. Actualizar ordenes de trabajo\n"); 
    printf("4. Ver ordenes de trabajo\n"); 
    printf("5. Mostrar el costo total\n");
    printf("6. Guardar ordenes de trabajo\n");
    printf("7. Salir\n");

    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Registrar orden de trabajo\n");
            break;
        case 2:
            printf("Buscar ordenes de trabajo\n");
            break;
        case 3:
            printf("Actualizar ordenes de trabajo\n");
            break;
        case 4:
            printf("Ver ordenes de trabajo\n");
            mostrarOrdenes(ListaOrdenes);
            break;
        case 5:
            printf("Mostrar el costo total\n");
            break;
        case 6:
            printf("Guardar ordenes de trabajo\n");

            break;
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida\n");
    }

    return 0;
}

void mostrarOrdenes(OrdenTrabajo *a) {
    for (int i = 0; i < 2; i++) {
        printf("ID: %d\n", a[i].id);
        printf("Nombre del cliente: %s\n", a[i].clientes.nombre);
        printf("Equipo: %s\n", a[i].clientes.equipo);
        printf("Tipo de trabajo: %s\n", a[i].clientes.tipoTrabajo);
        printf("Costo base: %.2f\n", a[i].costoBase);
        printf("Horas de trabajo: %d\n", a[i].horasTrabajo);
        printf("-----------------------------\n");
    }
}