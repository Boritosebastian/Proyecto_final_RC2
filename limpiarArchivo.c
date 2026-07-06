#include<stdio.h>
#include<string.h>
#include "estructuras.h"

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