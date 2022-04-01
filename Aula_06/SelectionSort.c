#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 5
#define TRUE    1
#define FALSE   0

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

void SelectionSort(int vetor[], int size) {
    int indx, indy;

    show(vetor,size);
    
    for (indx = 0; indx < size - 1; indx++) {
        for (indy = indx + 1; indy < size; indy++) {
            if (vetor[indx] > vetor[indy]) {
                swap(vetor, indx, indy);
                show(vetor,size);
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

    SelectionSort(vetor, VECTOR_SIZE);

    for (indx=0; indx < VECTOR_SIZE; indx++) {
        printf("\nVetor[%2d] -> %4d ", indx, vetor[indx]);
    }
    printf("\n\n\n");

    return 0;
}
