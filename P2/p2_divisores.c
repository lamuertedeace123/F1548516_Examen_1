/* p2_divisores.c
   Programa para generar 15 números aleatorios, calcular suma de divisores propios
   y clasificar cada número como Deficiente / Perfecto / Abundante.
   Compilar: gcc -o p2_divisores p2_divisores.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

/* Calcula la suma de los divisores propios de 'num' (excluye el propio número) */
int suma_divisores_propios(int num) {
    if (num <= 1) return 0; // 1 y 0 no tienen divisores propios positivos distintos de sí mismos
    int suma = 1; // 1 siempre es divisor propio si num > 1
    for (int d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
            suma += d;
            int otro = num / d;
            if (otro != d && otro != num) suma += otro;
            /* si otro == num (imposible aquí) no lo sumamos; si otro == d ya está sumado una vez */
        }
    }
    return suma;
}

int main(void) {
    int arr[N];
    /* Inicializar RNG */
    srand((unsigned) time(NULL));

    /* Llenar arreglo con valores aleatorios. Rango: 1..100 (puedes cambiarlo) */
    for (int i = 0; i < N; ++i) {
        arr[i] = (rand() % 100) + 1; // números entre 1 y 100 inclusive
    }

    /* Imprimir el arreglo */
    printf("El arreglo es: ");
    for (int i = 0; i < N; ++i) {
        printf("%d", arr[i]);
        if (i < N-1) printf(", ");
    }
    printf("\n\n");

    /* Para cada numero, calcular suma de divisores propios y clasificar */
    for (int i = 0; i < N; ++i) {
        int num = arr[i];
        int suma = suma_divisores_propios(num);

        if (suma < num) {
            printf("%d - Deficiente (suma divisores = %d)\n", num, suma);
        } else if (suma == num) {
            printf("%d - Perfecto  (suma divisores = %d)\n", num, suma);
        } else {
            printf("%d - Abundante (suma divisores = %d)\n", num, suma);
        }
    }

    return 0;
}
