#include "btree.c"
#include <stdlib.h>
#include <stdio.H>

void CreateVectorSorted(BTREE *tree, int **vet, int *pos)  {
    int info;
    
    if (tree == NULL) {
        return;
    }
    
    info = tree->info;
    
    CreateVectorSorted(tree->left, vet, pos);
    
    (*vet)[(*pos)++] = info;

    CreateVectorSorted(tree->right, vet, pos);    
    
}


int main(void) {
    BTREE *btree;
    int info = 0;
    int size = 0;

    btree_initialize(&btree);

    while (info >= 0) {
        printf("\n-> ");
        scanf("%i", &info);

        if (info < 0) break;

        btree_insert_ord(&btree, info);
        size++;
    }

    int pos = 0;
    int *vet = malloc(sizeof(int) * size);

    CreateVectorSorted(btree, &vet, &pos);
    printf("\nArvore Binaria transformada num vetor ordenado:\n");
    for (int i = 0; i < size; i++) printf("%i, ", vet[i]);

    return 0;
}