#include <stdio.h>
#include <stdlib.h>

// declaraciones

struct NodoPila {
    int dato;
    struct NodoPila* siguiente;
};
struct NodoCola {
    int dato;
    struct NodoCola* siguiente;
};
struct NodoPila* tope = NULL;
struct NodoCola* frente = NULL;
struct NodoCola* final = NULL;
/// menus

void menuPrincipal();
void menuPila();
void menuCola();
void mostrarUltimos();

/// pila
void push(int dato);
void pop();
void mostrarPila();

/// cola
void enqueue(int dato);
void dequeue();
void mostrarCola();

/// 
/// codigo uwu

int main() {
    
    printf("\n");
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int y;
    do {
        printf("¿Que desea realizar?\n 1. Pila\n 2. Cola\n 3. Mostrar ultimos elementos\n 4. Salir\n");
        scanf("%d", &y);

        switch (y) {
            case 1:
                menuPila();
                break;
            case 2:
                menuCola();
                break;
            case 3:
                mostrarUltimos();
                break;
            case 4:
                printf("Adio uwu\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (y != 4);
    printf("\n");
}

//Pila
void menuPila() {
    int opcion, dato, cantidad, i;
    do {
        printf("¿Que operacion desea realizar en la pila?\n 1. Agregar Elemento\n 2. Eliminar Elemento\n 3. Mostrar Pila\n 4. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                 printf("¿Cuantos elementos desea agregar?, con un maximo de 5: ");
                scanf("%d", &cantidad);
                if (cantidad < 1 || cantidad > 5) {
                    printf("Cantidad no valida, debe ser entre 1 y 5.\n");
                    break;
                }
                for (i = 0; i < cantidad; i++) {
                    printf("Ingrese el dato %d: ", i + 1);
                    scanf("%d", &dato);
                    push(dato);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                mostrarPila();
                break;
            case 4:
                printf("Regresando al menu principal uwu\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 4);
}

void push(int dato) {
    struct NodoPila* nuevo = (struct NodoPila*)malloc(sizeof(struct NodoPila));
    nuevo->dato = dato;
    nuevo->siguiente = tope;
    tope = nuevo;
}

void pop() {

    if (tope == NULL) {
        printf("La pila esta vacia\n");
        return;
    }
    struct NodoPila* temp = tope;
    printf("Elemento eliminado: %d\n", temp->dato);
    tope = tope->siguiente;
    free(temp);
}

void mostrarPila() {
    struct NodoPila* actual = tope;
    printf("Elementos en la pila:\n");
    if (actual == NULL) {
        printf("La pila esta vacia\n");
        return;
    }
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

///Cola

void menuCola() {
    int opcion, dato, cantidad, i;
    do {
        printf("¿Que operacion desea realizar en la cola?\n 1. Agregar Elemento\n 2. Eliminar Elemento\n 3. Mostrar Cola\n 4. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("¿Cuantos elementos desea agregar?, con un maximo de 5: ");
                scanf("%d", &cantidad);
                if (cantidad < 1 || cantidad > 5) {
                    printf("Cantidad no valida, debe ser entre 1 y 5.\n");
                    break;
                }
                for (i = 0; i < cantidad; i++) {
                    printf("Ingrese el dato %d: ", i + 1);
                    scanf("%d", &dato);
                    enqueue(dato);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                mostrarCola();
                break;
            case 4:
                printf("Regresando al menu principal uwu\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 4);
}


void enqueue(int dato) {
    struct NodoCola* nuevo = (struct NodoCola*)malloc(sizeof(struct NodoCola));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    if (final == NULL) {
        frente = final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

void dequeue() {
    if (frente == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    struct NodoCola* temp = frente;
    printf("Elemento eliminado: %d\n", temp->dato);
    frente = frente->siguiente;
    if (frente == NULL) {
        final = NULL;
    }
    free(temp);
}

void mostrarCola() {
    struct NodoCola* actual = frente;
    printf("Elementos en la cola:\n");
    if (actual == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

void mostrarUltimos() {
    // Mostrar último de la pila (tope)
    if (tope == NULL) {
        printf("La pila está vacía\n");
    } else {
        printf("Ultimo elemento de la pila: %d\n", tope->dato);
    }

    // Mostrar último de la cola (final)
    if (final == NULL) {
        printf("La cola está vacía\n");
    } else {
        printf("Ultimo elemento de la cola: %d\n", final->dato);
    }
}