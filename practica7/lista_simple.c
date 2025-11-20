#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertarInicio(Nodo **cabeza, int valor){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error: no se pudo asignar memoria\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(Nodo *cabeza){
    Nodo *aux = cabeza;
    while(aux){
        printf("%d -> ", aux->dato);
        aux = aux->siguiente;
    }
    printf("NULL\n");
}

void eliminar(Nodo **cabeza, int valor){
    if (!*cabeza) return;

    Nodo *aux = *cabeza;
    Nodo *ant = NULL;

    while(aux && aux->dato != valor){
        ant = aux;
        aux = aux->siguiente;
    }

    if (!aux){
        printf("Valor no encontrado\n");
        return;
    }

    if (!ant) *cabeza = aux->siguiente;
    else ant->siguiente = aux->siguiente;

    free(aux);
    printf("Valor eliminado\n");
}

void liberar(Nodo *cabeza){
    Nodo *aux;
    while(cabeza){
        aux = cabeza;
        cabeza = cabeza->siguiente;
        free(aux);
    }
    printf("Memoria liberada correctamente\n");
}

int main(){
    Nodo *cabeza = NULL;
    int y, u, r, i, k;

    do {
        printf("\n1. Agregar valor\n 2. Eliminar valor\n 3. Imprimir lista\n 4. Salir\n");
        scanf("%d", &y);

        switch(y){
            case 1:
                printf("¿Cuántos valores desea agregar? ");
                scanf("%d", &i);
                for(k = 0; k < i; k++){
                    printf("Ingrese valor %d: ", k+1);
                    scanf("%d", &u);
                    insertarInicio(&cabeza, u);
                    recorrer(cabeza);
                }
                break;
            case 2:
                printf("Ingrese valor a eliminar: ");
                scanf("%d", &u);
                eliminar(&cabeza, u);
                recorrer(cabeza);
                break;
            case 3:
                recorrer(cabeza);
                break;
            case 4:
                liberar(cabeza);
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while(y != 4);

    return 0;
}
