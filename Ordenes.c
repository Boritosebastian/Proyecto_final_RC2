#include<stdio.h>
#include<string.h>
#include "estructuras.h"
#include "existeID.h"
#include "leerArchivoCSV.h"
#include "guardarOrdenes.h"
#include "registrarOrden.h"
#include "buscarOrden.h"
#include "limpiarArchivo.h"
#include "eliminarOrden.h"
#include "actualizarOrden.h"

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
    printf("5. Eliminar orden de trabajo\n");
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
            printf("\n--- ACTUALIZAR ORDEN DE TRABAJO ---\n");
            int IDactualizar;
            printf("Ingrese el ID de la orden que desea actualizar: ");
            scanf("%d", &IDactualizar);
            actualizarOrden( ListaOrdenes,  n, IDactualizar);
            break;
        case 4:
            printf("\n          Ordenes de trabajo\n");  
            printf("--------------------------------------\n");
            leerArchivoCSV(n);
            break;
        case 5:
            printf("Eliminar orden de trabajo\n");
            int IDeliminar;
            printf("Ingrese el ID de la orden a eliminar: ");
            scanf("%d", &IDeliminar);
            eliminarOrden(ListaOrdenes, &n, IDeliminar);
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
