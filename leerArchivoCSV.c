#include<stdio.h>
#include<string.h>
#include "estructuras.h"

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