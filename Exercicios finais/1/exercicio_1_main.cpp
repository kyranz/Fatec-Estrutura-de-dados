#include <stdio.h>
#include <stdlib.h>
#include "exercicio_1.h"

int main(void)
{
    DESCRIPTOR *descriptor;
    INFO info;

    initialization(&descriptor);

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
        insertInOrder(&descriptor, info);
    }
    /*
     exibir resultados
     */
    show(descriptor);

    /*
     destruir a lista
     */
    destroy(&descriptor);

    exit(0);
}