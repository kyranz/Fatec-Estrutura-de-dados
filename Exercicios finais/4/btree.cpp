#include "btree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void btree_initialize(BTREE **btree)
{
    *btree = NULL;
}

void btree_create_node(BTREE **btree, INFO info)
{
    if (*btree != NULL)
    {
        return;
    }

    *btree = new BTREE;
    (*btree)->info = info;
    (*btree)->left = NULL;
    (*btree)->right = NULL;
}
void btree_insert_ord(BTREE **btree, INFO info)
{
    if (*btree == NULL)
    {
        btree_create_node(btree, info);
    }
    else
    {
        if ((*btree)->info >= info)
        {
            cout << "\nEsquerda";
            btree_insert_ord(&((*btree)->left), info);
        }
        else
        {
            cout << "\nDireita";
            btree_insert_ord(&((*btree)->right), info);
        }
    }
}

void show_tabs(int tabs)
{
    while (tabs-- > 0)
    {
        cout << "     ";
    }
}

void show(BTREE * tree, int tabs)
{
    if (tree == NULL)
    {
        return;
    }
    show_tabs(tabs);
    cout << "[ " << tree->info << " ]\n";
    show(tree->right, tabs+2);
    show(tree->left, tabs+2);
}