#include <stdio.h>
#include <stdlib.h> 

#define TRUE    1
#define FALSE   0

typedef int boolean;

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
                trocou = TRUE;
            }
        }
    }
}