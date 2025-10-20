#include <stdio.h>
#include <stdlib.h>


// Definiciones
#define MAX 5

// Estructura

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int tamaño;
} ColaCircular;

void initCola(ColaCircular *q){
    q->frente =0;
    q->final =0;
}

int colaVacia(ColaCircular *q){
    return q-> tamaño == 0;
}

int colaLlena(ColaCircular *q){
    return q-> tamaño == MAX;
}

int enqueue(ColaCircular *q, int valor){
    if (colaLlena(q)) return 0;
    int idx = (q->frente + q->tamaño) % MAX;
    q->datos[idx] = valor;
    q->tamaño++;
    return 1;
}
int dequeue(ColaCircular *q, int *valor){
    if (colaVacia(q)) return 0;
    *valor = q->datos[q->frente];
    q->frente = (q->frente + 1) % MAX;
    q->tamaño--;
    return 1;
}

int peek(ColaCircular *q, int *valor){
    if (colaVacia(q)) return 0;
    *valor = q->datos[q->frente];
    return 1;
}

void impimirCola(ColaCircular *q){
    if (colaVacia(q)){
        printf("Cola vacia\n");
        return;
    }
    printf("Cola: ");
    for (int i =0; i < q->tamaño; i++){
        int idx = (q->frente + i) % MAX;
        printf("%d ", q->datos[idx]);
    }
    printf("\n");
}

int main() {
        ColaCircular q;
        initCola(&q);

        int y, u, r;
        do {
            printf("¿Que desea realizar?\n");
            printf("1. Añadir a la cola\n 2. Eliminar de la cola\n 3. Ver frente de la cola\n 4. Imprimir cola\n 5. Salir\n");
            scanf("%d", &y);
            switch (y) {
                case 1:
                    printf("Ingrese el valor a añadir:\n");
                    if (scanf("%d", &u) != 1) return 0;
                    r = enqueue(&q, u);
                    printf(r ? "Valor añadido\n" : "Cola llena, no se puede añadir\n");
                    break;
                case 2:
                    r = dequeue(&q, &u);
                    if (r) printf("Desencolado: %d\n", u);
                    else printf("Cola vacia, no se puede eliminar\n");
                    break;
                case 3:
                    r = peek(&q, &u);
                    if (r) printf("Frente de la cola: %d\n", u);
                    else printf("Cola vacia\n");
                    break;
                case 4:
                    impimirCola(&q);
                    break;
                case 5:
                    printf("Adio uwu\n");
                    break;
                default:
                    printf("Opcion no valida\n");
        } 
    } while (y != 5);  
    
    return 0;
}
