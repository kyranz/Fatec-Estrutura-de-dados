#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
  
    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;

            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void QuickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        QuickSort(array, low, pi - 1);

        QuickSort(array, pi + 1, high);
    }
}