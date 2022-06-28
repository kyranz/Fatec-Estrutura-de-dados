#include <stdio.h>
#include <stdlib.h>
#include "exercicio_3.h"

int main(void)
{
    QUEUE * queue;
    INFO info;

    queue_inititaization(&queue);

    /*
     Entrada de dados
     */
    for (info = 0; info >= 0;)
    {
        printf("\n>> ");
        scanf("%i", &info);
        if (info < 0 || info > 100)
        {
            continue;
        }
        queue_insert(&queue, info);
    }
    /*
     exibir resultados
     */
    showFrequencyDistribuition(queue);

    exit(0);
}