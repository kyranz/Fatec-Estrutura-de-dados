#include <stdio.h>
#include <stdlib.h>

void swap(int vetor[], int x, int y) {
    int aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

void SelectionSort(int vetor[], int size) {
    int indx, indy;
    
    for (indx = 0; indx < size - 1; indx++) {
        for (indy = indx + 1; indy < size; indy++) {
            if (vetor[indx] > vetor[indy]) {
                swap(vetor, indx, indy);
            }
        }
    }
}