#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv) {

    srand(time(NULL));
    if (argc <= 1) {
        printf("\nError: Missing arguments");
        printf("\nExample: rgn 500\n\n");
        return 1;
    }

    int *arr, n, i;
    n = atoi(argv[1]);

    arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
        printf("%i ", arr[i]);
    }

    return 0;
}