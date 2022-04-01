#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void QuickSort(int vector[], int began, int end) {
    int i = began;
    int j = end - 1;
    int pivo = vector[(began + end) / 2];

    while (i <= j) {
        while (vector[i] < pivo && i < end) {
            i++;
        }
        while (vector[j] > pivo && j > began) {
            j--;
        }
        if (i <= j) {
            swap(vector,i,j);
            show(vector, end);
            i++;
            j++;
        }
    }

    if (j > began) {
        QuickSort(vector, began, j+1);
    }
    if (i < end) {
        QuickSort(vector, i, end);
    }
}

int main(void){

    int vet[] = { 12, 11, 13, 5, 6 };
    int size = sizeof(vet) / sizeof(vet[0]);

    show(vet, size);
    QuickSort(vet, 0, size);
    show(vet, size);

    return 0;
}