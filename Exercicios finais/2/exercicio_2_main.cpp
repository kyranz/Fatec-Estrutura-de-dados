#include <stdio.h>
#include <stdlib.h>
#include "exercicio_2.h"

int main(void)
{
    DESCRIPTOR bucket[1000];
    INFO info;
    
    createBucket(bucket);
    /*
     Entrada de dados
     */
    for (info = 0; info >= 0;)
    {
        printf("\n>> ");
        scanf("%i", &info);
        if (info < 0)
        {
            continue;
        }
        addBucket(bucket, info);
    }
    /*
     exibir resultados
     */
    showBucket(bucket);

    exit(0);
}