#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorts\QuickSort.c"

void show_100(int *arr) {
    int i;
    for (i = 0; i < 100; i++) {
        printf("%i, ", arr[i]);
    }
    printf("...\n\n");
}

int main() {
    
    FILE *arquivo;

    int *arr, i;

    clock_t start, end;
    double cpu_time_used;

    int n = 10000000;
    arr = (int *) malloc(n * sizeof(int));

    arquivo = fopen("Random numbers\\10000000.txt", "rb");
    fread(arr, sizeof(int), n, arquivo);
    fclose(arquivo);

    show_100(arr);

    start = clock();

    QuickSort(arr, 0, n - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    show_100(arr);

    printf("Total Time Sorting = %lf", cpu_time_used);

    free(arr);

    return 0;
}