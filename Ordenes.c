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
    float tarifa;
} OrdenTrabajo;

void registrarOrden(OrdenTrabajo *ordenes, int *n);
void guardarOrdenes(OrdenTrabajo *a,int n);
void buscarorden(OrdenTrabajo *ordenes, int n, int IDbuscar);
void leerArchivoCSV(int n);
void leerCSV();
void limpiarArchivo(int *n);
void existeID(int idBuscar, int *encontrado);

int main(){
    
    OrdenTrabajo ListaOrdenes[10];

    int opcion;
    int n = 0;
    int ordenes[10];

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
            guardarOrdenes(ListaOrdenes, n);
            break;
        case 2:
            printf("Buscar ordenes de trabajo\n");
            int IDbuscado;
            printf("Ingrese el ID de la orden a buscar: ");
            scanf("%d", &IDbuscado);
            buscarorden(ListaOrdenes, n, IDbuscado);
            break;
        case 3:
            printf("Actualizar ordenes de trabajo\n");
            break;
        case 4:
            printf("\n          Ordenes de trabajo\n");  
            printf("--------------------------------------\n");
            leerArchivoCSV(n);
            break;
        case 5:
            printf("Eliminar orden de trabajo\n");
            
            break;
        case 6:
            printf("                 Guardando\n");
            printf("--------------------------------------\n");
            guardarOrdenes(ListaOrdenes, n);
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
}

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

            existeID(ordentrabajo.id, &existe); 

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
}

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


    void existeID(int idBuscar, int *encontrado) {
    FILE *archivo = fopen("ordenes.csv", "r");
    if (archivo == NULL) {
        *encontrado = 0; // Si el archivo no existe, no está repetido
        return;
    }

    OrdenTrabajo ordentrabajo;
    *encontrado = 0; // Inicializamos asumiendo que no existe

    while (fscanf(archivo, "%d,%99[^,],%99[^,],%99[^,],%f,%d,%.2f", 
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
    


        

