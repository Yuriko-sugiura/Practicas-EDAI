#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

Nodo *inicio = NULL;

void insertarInicio(Nodo **i, int val){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = val;
    nuevo->anterior = NULL;
    nuevo->siguiente = *i;

    if (*i != NULL)
        (*i)->anterior = nuevo;

    *i = nuevo;
}

void insertarFinal(Nodo **i, int val){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = val;
    nuevo->siguiente = NULL;

    if (*i == NULL){
        nuevo->anterior = NULL;
        *i = nuevo;
        return;
    }

    Nodo *aux = *i;
    while (aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    nuevo->anterior = aux;
}

void recorrerAdelante(Nodo *i){
    if (i == NULL){
        printf("Lista vacia\n");
        return;
    }

    printf("Lista adelante: ");
    Nodo *aux = i;
    while (aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
    printf("\n");
}

void recorrerAtras(Nodo *i){
    if (i == NULL){
        printf("Lista vacia\n");
        return;
    }

    Nodo *aux = i;
    while (aux->siguiente != NULL)
        aux = aux->siguiente;

    printf("Lista atras: ");
    while (aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->anterior;
    }
    printf("\n");
}

int eliminar(Nodo **i, int val){
    if (*i == NULL) return 0;

    Nodo *aux = *i;

    while (aux != NULL){
        if (aux->dato == val){
            if (aux == *i){
                *i = aux->siguiente;
                if (*i != NULL)
                    (*i)->anterior = NULL;
            } else if (aux->siguiente == NULL){
                aux->anterior->siguiente = NULL;
            } else {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
            }

            free(aux);
            return 1;
        }
        aux = aux->siguiente;
    }

    return 0;
}

void liberar(Nodo *i){
    Nodo *aux = i;
    Nodo *tmp;

    while (aux != NULL){
        tmp = aux->siguiente;
        free(aux);
        aux = tmp;
    }

    printf("Memoria liberada correctamente.\n");
}

int main(){
    int y, u, r;
    inicio = NULL;

    do {
        printf("\n¿Que desea realizar?\n");
        printf("1. Insertar al inicio\n 2. Insertar al final\n 3. Recorrer adelante\n 4. Recorrer atras\n 5. Eliminar valor\n 6. Salir\n");
        scanf("%d", &y);

        switch(y){
            case 1:
                printf("¿Cuantos valores desea insertar?\n");
                scanf("%d", &u);
                for (int k = 0; k < u; k++){
                    int x;
                    printf("Ingrese valor %d:\n", k+1);
                    scanf("%d", &x);
                    insertarInicio(&inicio, x);
                    recorrerAdelante(inicio);
                }
                break;

            case 2:
                printf("¿Cuantos valores desea insertar?\n");
                scanf("%d", &u);
                for (int k = 0; k < u; k++){
                    int x;
                    printf("Ingrese valor %d:\n", k+1);
                    scanf("%d", &x);
                    insertarFinal(&inicio, x);
                    recorrerAdelante(inicio);
                }
                break;

            case 3:
                recorrerAdelante(inicio);
                break;

            case 4:
                recorrerAtras(inicio);
                break;

            case 5:
                printf("Ingrese el valor a eliminar:\n");
                scanf("%d", &u);
                r = eliminar(&inicio, u);
                printf(r ? "Eliminado\n" : "Valor no encontrado\n");
                break;

            case 6:
                liberar(inicio);
                printf("Adio uwu\n");
                break;

            default:
                printf("Opcion no valida\n");
        }

    } while (y != 6);

    return 0;
}
