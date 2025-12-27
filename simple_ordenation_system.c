#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void obtener_cantidad(int *cantidad){
    printf("Introduce la cantidad de numeros random a ordenar: ");
    scanf("%d", cantidad);
}

void rellenar_array(int *array, int cantidad){
    srand(time(NULL));
    for(int i = 0; i<cantidad; i++){
        *(array+i) = rand();
    }
}
void mostrar_array(int *array, int cantidad){
    printf("Los numeros son: ");
    for(int i = 0; i<cantidad; i++){
        printf("%d\t",*(array+i));
    }
    printf("\n");
}

void ordenar_array(int *array_origen, int *array_destino, int cantidad){
    for (int j=0; j<cantidad; j++){
        int menor = -1;
        int posmenor = 0;
        for (int i=0; i<cantidad; i++){
            if (((*(array_origen+i) < menor) && *(array_origen+i) != -1) || menor == -1){
                menor = *(array_origen+i);
                posmenor = i;
            }
        }
        if (menor != -1){
            *(array_destino+j) = menor;
            *(array_origen+posmenor) = -1;
        }
    }
}

int main(){
    int cantidad = 0;
    int *ptcantidad = &cantidad;
    obtener_cantidad(ptcantidad);
    int array[cantidad];
    int array_ordenado[cantidad];
    rellenar_array(&array[0], cantidad);
    mostrar_array(&array[0], cantidad);
    ordenar_array(&array[0], &array_ordenado[0], cantidad);
    mostrar_array(&array_ordenado[0], cantidad);
    return 0;
}
