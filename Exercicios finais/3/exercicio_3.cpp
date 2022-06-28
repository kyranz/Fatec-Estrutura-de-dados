#include "exercicio_3.h"
#include <stdio.h>
#include <stdlib.h>

void showFrequencyDistribuition(QUEUE * queue)
{
    int i, quant[10];
    NODO *node = queue->start;

    for (i = 0; i < 10; i++) {
        quant[i] = 0;
    }

    while (node != NULL) {
        for (i = 9; i >= 0; i--) {
            if (node->info >= (i * 10)) {
                quant[i]++;
                break;
            }
        }
        node = node->next;
    }

    for (i = 0; i < 9; i++) {
        printf("%2i A %3i = %i\n", i * 10, i * 10 + 9, quant[i]);
    }
    printf("99 A 100 = %i\n", quant[9]);
}