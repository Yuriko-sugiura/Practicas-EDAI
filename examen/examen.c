#include <stdio.h>
#include <stdlib.h>

int main () {
    int est;
    float *cal;
    float prom;

    printf("¿Cuantos estudiantes desea registrar? \n");
    scanf("%d", &est);

    cal = (float *) malloc(est * sizeof(float)); // se reserva la memoria para las calificaciones
    if (cal== NULL){
        printf("Hubo un error al asignar memoria (°ー°〃)\n");
        return 1;
    } // se verifica la asignacion de memoria

    for (int i = 0; i < est; i++) {
        printf("Ingrese la calificacion del estudiante %d: \n", i + 1);
        scanf("%f", &cal[i]);
    } // se piden las calificaciones

    prom = 0.0; 
    for (int i = 0; i < est; i++) {
        prom += cal[i];
    }
    prom /= est; 

    printf("El promedio de las calificaciones es: %.2f\n", prom);

    // Se promedia las calificaciones y se muestra

    printf("¿Desea añadir más estudiantes?\n");
    printf("1. Si\n 2. No\n");
    int y;
    scanf("%d", &y);

    // para mas facilidad añadi un menu con switch, en caso de querer añadirse más estudiantes

    switch (y) {
        case 1: {
            int est_nuevos;
            printf("¿Cuantos estudiantes desea añadir? \n");
            scanf("%d", &est_nuevos);
            cal = (float *) realloc(cal, (est + est_nuevos) * sizeof(float));
            if (cal == NULL) {
                printf("Hubo un error al reasignar memoria (°ー°〃)\n");
                return 1; // se vuelve a verificar la asignacion de memoria
            }
            for (int i = est; i < est + est_nuevos; i++) {
                printf("Ingrese la calificacion del estudiante %d: \n", i + 1);
                scanf("%f", &cal[i]);
            }
            prom = 0.0; 
            for (int i = 0; i < est + est_nuevos; i++) {
                prom += cal[i];
            }
            prom /= (est + est_nuevos);
            printf("El nuevo promedio de las calificaciones es: %.2f\n", prom);   

            // se promedia nuevamente con todos los estudiantes registrados
            
            printf("Calificaciones registradas en el programa:\n");
            for (int i = 0; i < est + est_nuevos; i++) {
                printf("Estudiante %d: %.2f\n", i + 1, cal[i]);
            } // se muestran todas las calificaciones registradas

            break;
        }
        case 2:
            printf("No se añadiran nuevos estudiantes :3.\n");
            break;
        default:
            printf("Opción no válida.\n");
    }



    free(cal); // se libera la memoria :3
    return 0;
}