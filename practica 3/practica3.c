#include <stdio.h>
#include <string.h>

#define TAM 10
#define NUM_DIR 2

struct pelicula {
    char nombre[50];
    char genero[20];
    int anio;
    int numDirectores;
    char directores[NUM_DIR][50];
};

int main() {
    struct pelicula videoteca[TAM];
    int pelis;
    int y;
    char buscar[50];
    int busGen = 0;

    for (pelis = 0; pelis < TAM; pelis++) {
        printf("Ingrese el nombre de la pelicula %d: ", pelis + 1);
        scanf(" %49[^\n]", videoteca[pelis].nombre);   // lee con espacios
        printf("Ingrese el genero: ");
        scanf(" %19[^\n]", videoteca[pelis].genero);
        printf("Ingrese el anio: ");
        scanf("%d", &videoteca[pelis].anio);
        printf("Ingrese el numero de directores (1..%d): ", NUM_DIR);
        scanf("%d", &videoteca[pelis].numDirectores);
        if (videoteca[pelis].numDirectores < 1) videoteca[pelis].numDirectores = 1;
        if (videoteca[pelis].numDirectores > NUM_DIR) videoteca[pelis].numDirectores = NUM_DIR;
        for (int j = 0; j < videoteca[pelis].numDirectores; j++) {
            printf("Ingrese el nombre del director %d: ", j + 1);
            scanf(" %49[^\n]", videoteca[pelis].directores[j]);
        }
    }
    printf("\n Contenido de la videoteca \n");
    for (pelis = TAM - 1; pelis >= 0; pelis--) {
        printf("Pelicula: %s\n", videoteca[pelis].nombre);
        printf("Genero: %s\n", videoteca[pelis].genero);
        printf("Anio: %d\n", videoteca[pelis].anio);
        printf("Directores (%d):\n", videoteca[pelis].numDirectores);
        for (int j = 0; j < videoteca[pelis].numDirectores; j++) {
            printf("  - %s\n", videoteca[pelis].directores[j]);
        }
        printf("\n");
    }
    while (1) {
        printf("\nMenu\n");
        printf("1) Buscar por genero\n 2) Buscar por director\n 3) Contador por genero\n 4) Salir\n");
        scanf("%d", &y);
        switch (y) {
        case 1:
            printf("Ingrese el genero a buscar: ");
            scanf(" %49[^\n]", buscar);
            for (pelis = 0; pelis < TAM; pelis++) {
                if (strcmp(videoteca[pelis].genero, buscar) == 0) {
                    printf("Pelicula encontrada: %s (%d)\n", videoteca[pelis].nombre, videoteca[pelis].anio);
                }
            }
            break;
        case 2:
            printf("Ingrese el nombre del director: ");
            scanf(" %49[^\n]", buscar);
            for (pelis = 0; pelis < TAM; pelis++) {
                for (int j = 0; j < videoteca[pelis].numDirectores; j++) {
                    if (strcmp(videoteca[pelis].directores[j], buscar) == 0) {
                        printf("Pelicula dirigida: %s (%d)\n", videoteca[pelis].nombre, videoteca[pelis].anio);
                    }
                }
            }
            break;
        case 3:
            printf("Ingrese el genero para contar: ");
            scanf(" %49[^\n]", buscar);
            busGen = 0;
            for (pelis = 0; pelis < TAM; pelis++) {
                if (strcmp(videoteca[pelis].genero, buscar) == 0) {
                    busGen++;
                }
            }
            printf("Hay %d peliculas del genero %s\n", busGen, buscar);
            break;
        case 4:
            printf("Saliendo...\n");
            return 0;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
    return 0;
}
