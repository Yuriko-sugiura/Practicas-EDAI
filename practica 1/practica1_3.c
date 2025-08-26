//Practica 1 -  ejercicio 3
#include <stdio.h>

int main(void) {
 int n;
 int a[5];
 int y;
 
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
    
    printf("Los elementos invertidos son:\n");
    for(int i = n-1; i >= 0; i--){
    printf("Elemento: %d\n", a[i]);
    }

   printf("\n");
   return 0;
}