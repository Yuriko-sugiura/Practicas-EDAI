#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

Nodo *inicio = NULL;

void insertarCircular(Nodo **i, int val){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = val;

    if (*i == NULL){
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *i = nuevo;
        return;
    }

    Nodo *ultimo = (*i)->anterior;

    nuevo->siguiente = *i;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*i)->anterior = nuevo;
}

void recorrerCircular(Nodo *i){
    if (i == NULL){
        printf("Lista circular vacia\n");
        return;
    }

    printf("Lista circular: ");
    Nodo *aux = i;
    do {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    } while (aux != i);
    printf("\n");
}

int eliminarCircular(Nodo **i, int val){
    if (*i == NULL) return 0;

    Nodo *aux = *i;

    do {
        if (aux->dato == val){
            if (aux->siguiente == aux){
                free(aux);
                *i = NULL;
                return 1;
            }

            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;

            if (aux == *i)
                *i = aux->siguiente;

            free(aux);
            return 1;
        }
        aux = aux->siguiente;
    } while (aux != *i);

    return 0;
}

void liberarCircular(Nodo *i){
    if (i == NULL){
        printf("Memoria liberada correctamente.\n");
        return;
    }

    Nodo *aux = i;
    Nodo *tmp;

    do {
        tmp = aux->siguiente;
        free(aux);
        aux = tmp;
    } while (aux != i);

    printf("Memoria liberada correctamente.\n");
}

int main(){
    int y, u, r;
    inicio = NULL;

    do {
        printf("\n¿Que desea realizar?\n");
        printf("1. Insertar valores\n 2. Recorrer\n 3. Eliminar valor\n 4. Salir\n");
        scanf("%d", &y);

        switch(y){
            case 1:
                printf("¿Cuantos valores desea insertar?\n");
                scanf("%d", &u);
                for (int k = 0; k < u; k++){
                    int x;
                    printf("Ingrese valor %d:\n", k+1);
                    scanf("%d", &x);
                    insertarCircular(&inicio, x);
                    recorrerCircular(inicio);
                }
                break;

            case 2:
                recorrerCircular(inicio);
                break;

            case 3:
                printf("Ingrese el valor a eliminar:\n");
                scanf("%d", &u);
                r = eliminarCircular(&inicio, u);
                printf(r ? "Eliminado\n" : "Valor no encontrado\n");
                recorrerCircular(inicio);
                break;

            case 4:
                liberarCircular(inicio);
                printf("Adio uwu\n");
                break;

            default:
                printf("Opcion no valida\n");
        }

    } while (y != 4);

    return 0;
}
