//Practica 1 - ejecicio 2
#include <stdio.h>

int main(void) {
 int n;
 int a[5];
 int y;
 int suma = 0; 
 int resta = 0;
 float promedio =0;
 float prom;
 int mayor, menor;
 
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

 printf("¿Que desea hacer con sus elementos?\n 1.Sumar los elementos\n 2.Restar los elementos\n 3.Calcular el promedio de los elementos\n 4.Cual es el menor y el mayor de los elementos\n");
 scanf("%d", &y);
 switch(y)
    {
    default: 
        printf("No se selecciono una opcion valida\n");
        break;
    case 1:
        for(int i = 0; i < n; i++){
        suma += a[i];
        }
        printf("El resultado de la suma es:%d\n", suma);
        break;
    case 2:
        resta = a[0];
        for(int i = 1; i < n; i++){
        resta -= a[i];
        }
        printf("El resultado de la resta es:%d\n", resta);
        break;
    case 3:
        for(int i = 0; i < n; i++){
        promedio += a[i];
        prom = (promedio/n);
        }
        printf("El resultado del promedio es:%f\n", prom);
        break;
    case 4:

        mayor = a[0];
        menor = a[0];

        for(int i = 0; i < n; i++){
         if (a[i] > mayor){
            mayor = a[i];
         }
         if(a[i] < menor){
            menor = a[i];
         }
        }
        printf("Elemento mayor:%d\n", mayor);
        printf("Elemento menor:%d\n", menor);
        break;
    }
   return 0;
}