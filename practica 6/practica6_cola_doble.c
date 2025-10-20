#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int tamaño;
} Deque;

void initDeque(Deque *d){
    d->frente = 0;
    d->tamaño = 0;
}

int dequeVacio(Deque *d){
    return d->tamaño == 0;
}

int dequeLleno(Deque *d){
    return d->tamaño == MAX;
}

int insert_front(Deque *d, int valor){
    if (dequeLleno(d)) return 0;
    d->frente = (d->frente - 1 + MAX) % MAX;
    d->datos[d->frente] = valor;
    d->tamaño++;
    return 1;
}

int insert_rear(Deque *d, int valor){
    if (dequeLleno(d)) return 0;
    int final = (d->frente + d->tamaño) % MAX;
    d->datos[final] = valor;
    d->tamaño++;
    return 1;
}

int delete_front(Deque *d, int *valor){
    if (dequeVacio(d)) return 0;
    *valor = d->datos[d->frente];
    d->frente = (d->frente + 1) % MAX;
    d->tamaño--;
    return 1;
}

int delete_rear(Deque *d, int *valor){
    if (dequeVacio(d)) return 0;
    int final = (d->frente + d->tamaño - 1 + MAX) % MAX;
    *valor = d->datos[final];
    d->tamaño--;
    return 1;
}

int peek_front(Deque *d, int *valor){
    if (dequeVacio(d)) return 0;
    *valor = d->datos[d->frente];
    return 1;
}

int peek_rear(Deque *d, int *valor){
    if (dequeVacio(d)) return 0;
    int final = (d->frente + d->tamaño - 1 + MAX) % MAX;
    *valor = d->datos[final];
    return 1;
}

void imprimirDeque(Deque *d){
    if (dequeVacio(d)){
        printf("Cola Doble vacia\n");
        return;
    }
    printf("Cola Doble: ");
    for (int i = 0; i < d->tamaño; i++){
        int idx = (d->frente + i) % MAX;
        printf("%d ", d->datos[idx]);
    }
    printf("\n");
}

int main(){
    Deque d;
    initDeque(&d);
    int y, u, r;

    do {
        printf("\n¿Que desea realizar?\n");
        printf("1. Insertar al frente\n 2. Insertar al final\n 3. Eliminar del frente\n 4. Eliminar del final\n 5. Ver frente\n 6. Ver final\n 7. Imprimir Cola Doble\n 8. Salir\n");
        scanf("%d", &y);

        switch(y){
            case 1:
                printf("Ingrese el valor:\n");
                scanf("%d", &u);
                r = insert_front(&d, u);
                printf(r ? "Insertado al frente\n" : "Cola Doble llena\n");
                break;
            case 2:
                printf("Ingrese el valor:\n");
                scanf("%d", &u);
                r = insert_rear(&d, u);
                printf(r ? "Insertado al final\n" : "Cola Doble llena\n");
                break;
            case 3:
                r = delete_front(&d, &u);
                if (r) printf("Eliminado del frente: %d\n", u);
                else printf("Cola Doble vacia\n");
                break;
            case 4:
                r = delete_rear(&d, &u);
                if (r) printf("Eliminado del final: %d\n", u);
                else printf("Cola Doble vacia\n");
                break;
            case 5:
                r = peek_front(&d, &u);
                if (r) printf("Frente: %d\n", u);
                else printf("Cola Doble vacia\n");
                break;
            case 6:
                r = peek_rear(&d, &u);
                if (r) printf("Final: %d\n", u);
                else printf("Cola Doble vacia\n");
                break;
            case 7:
                imprimirDeque(&d);
                break;
            case 8:
                printf("Adio uwu\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (y != 8);

    return 0;
}
