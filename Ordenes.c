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

<<<<<<< HEAD
void registrarOrden(OrdenTrabajo *ordenes, int *n);
void guardarOrdenes(OrdenTrabajo *a,int n);
void leerArchivoCSV(int n);
void leerCSV();
void limpiarArchivo(int *n);


int main(){
    
    OrdenTrabajo ListaOrdenes[10];

=======
int main(){
>>>>>>> 64e80fee8e238b6b3bbbac54808ce52c3a12d416
    int opcion;
    int n = 0;
    int ordenes[10];

    do{

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
            registrarOrden(ListaOrdenes, &n);
            break;
        case 2:
            printf("Buscar ordenes de trabajo\n");
            break;
        case 3:
            printf("Actualizar ordenes de trabajo\n");
            break;
        case 4:
<<<<<<< HEAD
            printf("\n          Ordenes de trabajo\n");  
            printf("--------------------------------------\n");
            leerArchivoCSV(n);
=======
            printf("Ver ordenes de trabajo\n");
>>>>>>> 64e80fee8e238b6b3bbbac54808ce52c3a12d416
            break;
        case 5:
            printf("Mostrar el costo total\n");
            break;
        case 6:
<<<<<<< HEAD
            printf("                 Guardando\n");
            printf("--------------------------------------\n");
            guardarOrdenes(ListaOrdenes, n);
=======
            printf("Guardar ordenes de trabajo\n");
>>>>>>> 64e80fee8e238b6b3bbbac54808ce52c3a12d416
            break;
        case 7:
            printf("Saliendo...\n");
            limpiarArchivo(&n);
            break;
        default:
            printf("Opción no válida\n");
    }
    } while(opcion != 7);  

    return 0;
<<<<<<< HEAD
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

void leerArchivoCSV(int n) {

    if (n == 0) {
        printf("No hay ordenes de trabajo registradas.\n");
    }
    
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

void registrarOrden(OrdenTrabajo *ordenes, int *n) {
    if (*n >= 10) {
        printf("No se pueden registrar más ordenes de trabajo. Capacidad máxima alcanzada.\n");
        return;
    }

    OrdenTrabajo ordentrabajo;
    int respuesta;

    do{
    printf("Ingrese el ID de la orden: ");
    scanf("%d", &ordentrabajo.id);
    getchar(); 

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
    scanf("%f", &ordentrabajo.costoBase);

    printf("Ingrese las horas de trabajo: ");
    scanf("%d", &ordentrabajo.horasTrabajo);
    
    printf("Desea registrar otra orden de trabajo\n");
    printf("1. Si\n");
    printf("2. No\n");
    scanf("%d", &respuesta);

    ordenes[*n] = ordentrabajo;
    (*n)++;

    } while (respuesta == 1);

    printf("Orden/es de trabajo registrada exitosamente.\n");
    printf("Recuerde Guardar antes para poder ver las ordenes de trabajo\n");

}

void limpiarArchivo(int *n) {
    int ordenes[10];
    // Al abrirlo con "w", el archivo se vacia por completo de golpe
    FILE *archivo = fopen("ordenes.csv", "w"); 
    
    if (archivo == NULL) {
        printf("Error al intentar limpiar el archivo.\n");
        return;
    }
    *n = 0; // Reiniciamos el conteo de órdenes registradas
    ordenes[0] = 0; // Reiniciamos el conteo de órdenes registradas
    fclose(archivo); // Lo cerramos inmediatamente
    printf("El archivo 'ordenes.csv' ha sido vaciado por completo\n");
=======
>>>>>>> 64e80fee8e238b6b3bbbac54808ce52c3a12d416
}