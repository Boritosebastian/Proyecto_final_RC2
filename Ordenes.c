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

void guardarOrdenes(OrdenTrabajo *a,int n);
void leerArchivoCSV();
void leerCSV();

int main(){
    
    OrdenTrabajo ListaOrdenes[10];

    ListaOrdenes[0].id = 3412;
    strcpy(ListaOrdenes[0].clientes.nombre, "Juan Perez");
    strcpy(ListaOrdenes[0].clientes.equipo, "Laptop");
    strcpy(ListaOrdenes[0].clientes.tipoTrabajo, "Reparacion de pantalla");
    ListaOrdenes[0].costoBase = 150.0;
    ListaOrdenes[0].horasTrabajo = 2;

    ListaOrdenes[1].id = 3413;
    strcpy(ListaOrdenes[1].clientes.nombre, "Maria Lopez");
    strcpy(ListaOrdenes[1].clientes.equipo, "PC de escritorio");
    strcpy(ListaOrdenes[1].clientes.tipoTrabajo, "Instalacion de software");
    ListaOrdenes[1].costoBase = 100.0;
    ListaOrdenes[1].horasTrabajo = 1;

  
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
            printf("\n          Ordenes de trabajo\n");  
            printf("--------------------------------------\n");
            leerArchivoCSV();
            break;
        case 5:
            printf("Mostrar el costo total\n");
            break;
        case 6:
            printf("                 Guardando\n");
            printf("--------------------------------------\n");
            guardarOrdenes(ListaOrdenes, 2);
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

void guardarOrdenes(OrdenTrabajo *a, int n) {
    FILE *archivo = fopen("ordenes.csv", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar las ordenes.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d;%s;%s;%s;%.2f;%d\n",
            a[i].id, 
            a[i].clientes.nombre, 
            a[i].clientes.equipo, 
            a[i].clientes.tipoTrabajo, 
            a[i].costoBase, 
            a[i].horasTrabajo);
    }

    fclose(archivo);
    printf("Ordenes guardadas exitosamente en 'ordenes.csv'.\n");
}

void leerArchivoCSV() {
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para leer las ordenes.\n");
        return;
    }

    char linea[200];
    while (fgets(linea, 200, archivo)!= NULL) 
    {
        printf("%s", linea);
    }

    fclose(archivo);
}

void leerCSV(){
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para leer las ordenes.\n");
        return;
    }

    OrdenTrabajo ordentrabajo;
    
    while(fscanf(archivo, "%d;%100[^;];%100[^;];%100[^;];%f;%d\n", 
        &ordentrabajo.id, 
        ordentrabajo.clientes.nombre, 
        ordentrabajo.clientes.equipo, 
        ordentrabajo.clientes.tipoTrabajo, 
        &ordentrabajo.costoBase, 
        &ordentrabajo.horasTrabajo) == 6)
        {
        printf("%s\n", ordentrabajo.clientes.tipoTrabajo);
        }
    fclose(archivo);
}