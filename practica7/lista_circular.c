#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *sig;
} Nodo;

Nodo *cabeza = NULL;
Nodo *ultimo = NULL;

void iniLista(){
    cabeza = NULL;
    ultimo = NULL;
}

void insertarInicio(int val){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = val;

    if (cabeza == NULL){
        cabeza = nuevo;
        ultimo = nuevo;
        nuevo->sig = cabeza;
    } else {
        nuevo->sig = cabeza;
        cabeza = nuevo;
        ultimo->sig = cabeza;
    }
}

void imprimirCircular(){
    if (cabeza == NULL){
        printf("Lista vacia\n");
        return;
    }

    Nodo *aux = cabeza;
    printf("Datos en lista: ");

    do {
        printf("%d ", aux->valor);
        aux = aux->sig;
    } while (aux != cabeza);

    printf("\n");
}

int eliminarCircular(Nodo **c, int val){
    if (*c == NULL)
    return 0;

    Nodo *act = *c;
    Nodo *ant = ultimo;

    do {
        if (act->valor == val){
            if (act == ant && act == *c){
                *c = NULL;
                ultimo = NULL;
            } else if (act == *c){
                *c = act->sig;
                ultimo->sig = *c;
            } else {
                ant->sig = act->sig;
                if (act == ultimo) ultimo = ant;
            }

            free(act);
            return 1;
        }
        ant = act;
        act = act->sig;

    } while (act != *c);

    return 0;
}

int main(){
    int y, u, r;
    iniLista();

    do {
        printf("\n¿Que desea realizar?\n");
        printf("1. Insertar valores al inicio\n 2. Mostrar lista\n 3. Eliminar un valor\n 4. Salir\n");
        scanf("%d", &y);

        switch(y){
            case 1:
                printf("¿Cuantos valores desea insertar?\n");
                scanf("%d", &u);

                for (int i = 0; i < u; i++){
                    int x;
                    printf("Ingrese valor %d:\n", i+1);
                    scanf("%d", &x);
                    insertarInicio(x);
                    imprimirCircular();
                }
                break;

            case 2:
                imprimirCircular();
                break;

            case 3:
                printf("Ingrese el valor a eliminar:\n");
                scanf("%d", &u);
                r = eliminarCircular(&cabeza, u);
                printf(r ? "Eliminado\n" : "Valor no encontrado\n");
                break;

            case 4:
                printf("Adio uwu\n");
                break;

            default:
                printf("Opcion no valida\n");
        }
    } while (y != 4);

    return 0;
}
