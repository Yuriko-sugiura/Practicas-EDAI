// Practica 1 - ejercicio 1
#include <stdio.h>

int main(void) {
 int n;
 int a[5];

 do {
  printf("Ingrese una cantidad siendo el maximo 5\n");
  scanf("%d", &n);
    if (n<1 , n>5){
        printf("El numero debe ser entre 1 y 5\n");
    }
  } while (n>1, n>5);

 printf("Ingrese %d numeros:\n", n);
 for(int i = 0; i < n; i++) {
  printf("Elemento%d:", i);
  scanf("%d", &a[i]);
  }
 
 printf("Los elementos de array son:\n\n");
  for(int i = 0; i < n; i++){
   printf("Elemento %d: %d\n", i, a[i]);
   }
   return 0;
}