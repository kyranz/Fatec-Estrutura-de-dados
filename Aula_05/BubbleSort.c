#include <stdio.h>
#include <stdlib.h>
// Declaração de Constantes
#define VECTOR_SIZE 5
#define TRUE    1
#define FALSE   0
// Apelido para o tipode dado int
typedef int boolean;

void show(int vetor[], int size) {
    int indx;

    printf("\n");

    for (indx=0; indx < size; indx++) {
        printf("\t[%3d]", vetor[indx]);
    }
}

void swap(int vetor[], int x, int y) {
    int aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

void BubbleSort(int vetor[], int size) {
    int indx;
    boolean trocou = TRUE;

    while (trocou) {
        trocou = FALSE;
        for (indx=0; indx < size -1; indx++) {
            if (vetor[indx] > vetor[indx+1]) {
                swap(vetor, indx, indx+1);
                show(vetor,size);
                trocou = TRUE;
            }
        }
    }
}


int main(void) {
    int vetor[VECTOR_SIZE];
    int indx;

    for (indx=0; indx < VECTOR_SIZE; indx++) {
        printf("\nVetor[%2d] -> ", indx);
        scanf("%i",&vetor[indx]);
    }

    BubbleSort(vetor, VECTOR_SIZE);

    for (indx=0; indx < VECTOR_SIZE; indx++) {
        printf("\nVetor[%2d] -> %4d ", indx, vetor[indx]);
    }
    printf("\n\n\n");

    return 0;
}