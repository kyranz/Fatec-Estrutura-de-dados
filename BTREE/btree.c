#include <stdlib.h>
#include <stdio.h>

typedef struct STNODE BTREE; 
typedef struct STNODE TNODE;


struct STNODE {
    int info;
    BTREE *left;
    BTREE *right;
};

void btree_initialize(BTREE **btree) {
    *btree = NULL;
}

void btree_create_node(BTREE **btree, int info) {
    if (*btree != NULL) {
        return;
    }

    *btree = malloc(sizeof(BTREE));
    (*btree)->info = info;
    (*btree)->left = NULL;
    (*btree)->right = NULL;
}

void btree_insert_ord(BTREE **btree, int info) {
    if (*btree == NULL) {
        btree_create_node(btree, info);
    }
    else
    {
        if ((*btree)->info >= info) {
            printf("\nEsquerda");
            btree_insert_ord(&((*btree)->left), info);
        }
        else {
            printf("\nDireita");
            btree_insert_ord(&((*btree)->right), info);
        }
    }
}

TNODE * btree_search(BTREE *btree, int info) {
    if (btree == NULL) {
        return NULL;
    }
    if (info == btree->info) {
        return btree;
    }
    if (info <= btree->info) {
        return btree_search(btree->left, info);
    }
    else {
        return btree_search(btree->right, info);
    }
}

void btree_sort(BTREE *btree) {
    if (btree == NULL) return;

    btree_sort(btree->left);
    printf("\n[%x] -> %i", btree, btree->info);
    btree_sort(btree->right);
}

void show_tabs(int tabs) {
    while (tabs-- > 0) printf("     ");
}

void show(BTREE *tree, int tabs) {
    if (tree == NULL) {
        return;
    }
    show_tabs(tabs);
    printf("[ %i ]\n", tree->info);
    show(tree->right, tabs + 2);
    show(tree->left, tabs - 2);
}