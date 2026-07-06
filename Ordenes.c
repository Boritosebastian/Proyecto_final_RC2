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

int main(){
    int opcion;

    do{

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
    } while(opcion != 7);  

    return 0;
}