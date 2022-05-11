#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(/*int argc, char ** argv*/) {

    srand(time(NULL));
    // if (argc <= 1) {
    //     printf("\nError: Missing argument");
    //     printf("\nExample: rgn 500\n\n");
    //     return 1;
    // }

    FILE *arquivo;

    arquivo = fopen("..\\Random numbers\\1000.txt", "wb");
    int *arr, i;

    // int n = atoi(argv[1]);
    int n = 1000;
    arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) {
        arr[i] = (rand() % 1000) + 1;
        // printf("%i ", arr[i]);
    }

    fwrite(arr, sizeof(int), n, arquivo);
    fclose(arquivo);

    free(arr);

    return 0;
}