#include <stdio.h>
#include <stdlib.h>

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

void InsertionSort(int vet[], int size){
    int i, j, key;
    show(vet,size);

    for (i = 1; i < size; i++) {
        key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            show(vet, size);
            j = j - 1;
        }

        vet[j + 1] = key;
    }
}

int main(void){

    int vet[] = { 12, 11, 13, 5, 6 };
    int size = sizeof(vet) / sizeof(vet[0]);
    InsertionSort(vet, size);
    show(vet, size);

    return 0;
}