#include "exercicio_4.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Professor, no exemplo dado no pdf, o resultado esperado da altura da arvore esta como 6,
    mas nao seria 7 a resposta correta? pois o resultado esperado para o caminho percorrido eh:
    30 -> 30 -> 29 -> 10 -> 9 -> 8 -> 7
    E se contarmos a quantidade, ha 7 nodos no maior caminho.

    Outra duvida, quando o codigo eh compilado, aparecem duas warnings, mas ao ha nada que eu possa fazer quanto a elas,
    pois o erro se encontra no arquivo "exercicio_4_main.cpp", onde no prinf sobre a altura da arvore,
    voce colocou %4d para representar o resultado da funcao btree_height(), mas a funcao retorna o tipo long,
    e o compilador aponta isto, ja que %d eh usado para int.
*/

long btree_height(BTREE * btree)
{
    if (btree == NULL) return 0;

    long leftH = btree_height(btree->left);
    long rightH = btree_height(btree->right);

    return leftH > rightH ? leftH + 1 : rightH + 1;
}

void showMaxPath(BTREE * btree)
{
    printf("%i", btree->info);

    while (1) {
        if (btree_height(btree->left) > btree_height(btree->right)) {
            btree = btree->left;
        }
        else {
            btree = btree->right;
        }
        if (btree == NULL) return;

        printf(" -> %i", btree->info);
    }
}