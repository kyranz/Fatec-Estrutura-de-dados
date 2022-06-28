#include <stdio.h>
#include <stdlib.h>
#include "exercicio_4.h"

int main(void)
{
    BTREE * btree;
    INFO info;
    long height = 0;

    btree_initialize(&btree);

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
        btree_insert_ord(&btree, info);
    }
    /*
     exibir resultados
     */
    show(btree, 2);

    printf("\nCaminho percorrido: ");

    showMaxPath(btree);

    height = btree_height(btree);

    printf("\nAltura da arvore = %4d", height);

    exit(0);
}