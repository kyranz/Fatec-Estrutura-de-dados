#include <stdio.h>
#include <stdlib.h>

void swap(int vetor[], int x, int y) {
    int aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

void InsertionSort(int vet[], int size){
    int i, j, key;
    show(vet,size);

    for (i = 1; i < size; i++) {
        key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }

        vet[j + 1] = key;
    }
}