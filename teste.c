#include <stdio.h>
#include <stdlib.h>
#include "Sorts\BubbleSort.c"

int main() {
    
    FILE *arquivo;

    arquivo = fopen("Random numbers\\1000.txt", "rb");
    int *arr, i;

    int n = 1000;
    arr = (int *) malloc(n * sizeof(int));

    fread(arr, sizeof(int), n, arquivo);
    fclose(arquivo);

    for (i = 0; i < n; ++i) {
        printf("%i ", arr[i]);
    }

    free(arr);

    return 0;
}