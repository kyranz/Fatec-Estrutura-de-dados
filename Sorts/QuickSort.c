#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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