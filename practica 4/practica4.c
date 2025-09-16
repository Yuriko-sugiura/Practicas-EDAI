#include <stdio.h>
#include <stdlib.h>

int main() {
    int y, u;
    int *arr, *arr2;

    printf("¿Cuantos enteros quiere almacenar (malloc)?\n");
    scanf("%d", &y);

    arr = (int*) malloc(y * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria con malloc\n");
        return 1;
    }
    printf("Valores iniciales con malloc:\n");
    for (int i = 0; i < y; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr2 = (int*) calloc(y, sizeof(int));
    if (arr2 == NULL) {
        printf("Error al reservar memoria con calloc\n");
        free(arr);
        return 1;
    }
    printf("Valores iniciales con calloc:\n");
    for (int i = 0; i < y; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Ingrese %d valores:\n", y);
    for (int i = 0; i < y; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("Valores guardados en arreglo2:\n");
    for (int i = 0; i < y; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Ingrese el nuevo tamaño del arreglo:\n");
    scanf("%d", &u);

    arr2 = (int*) realloc(arr2, u * sizeof(int));
    if (arr2 == NULL) {
        printf("Error al redimensionar memoria con realloc\n");
        free(arr);
        return 1;
    }

    if (u > y) {
        printf("Ingrese %d valores adicionales:\n", u - y);
        for (int i = y; i < u; i++) {
            scanf("%d", &arr2[i]);
        }
    }

    printf("Valores actuales en arr2:\n");
    for (int i = 0; i < u; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
