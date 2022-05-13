#include <stdlib.h>
#include <stdio.h>

/*
    Funções retiradas do Teams, que foram enviadas pelo professor.
*/

typedef struct Snode node;
typedef int BOOL;

#define TRUE   1
#define FALSE  0

struct Snode {
    char info;
    node *proximo;
};

void inicializar(node **lls) {
    *lls = NULL;
}

BOOL isEmpty(node *lls) {
    return lls == NULL ? TRUE : FALSE;
}

node * getElemPosN(node **lls, int pos) {
    int indx;
    node *aux = *lls;

    for (indx = 1;  indx < pos; indx++) {
        aux = aux->proximo;
        if (aux == NULL) {
            break;
        }
    }

    return aux;
}

void inserirPosN (node **lls, char info, int pos) {
    node *auxN;
    node *aux = (node *)malloc(sizeof(node));
    aux->info = info;
    aux->proximo = NULL;

    if (isEmpty(*lls) && pos != 1) {
        return;
    }

    if (pos == 1) {
        aux->proximo = *lls;
        *lls = aux;
        return;
    }

    auxN = getElemPosN(lls, pos-1);

    if (auxN == NULL) {
        return;
    }

    aux->proximo = auxN->proximo;
    auxN->proximo = aux;

    return;
}

node * removerPosN (node **lls, int pos) {
    node *aux;
    node *auxN;

    if (isEmpty(*lls)) {
        return NULL;
    }

    if (pos == 1) {
        aux = *lls;
        *lls = aux->proximo;
        aux->proximo = NULL;
        return aux;
    }

    auxN = getElemPosN(lls, pos-1);

    if (auxN == NULL) {
        return NULL;
    }

    aux = auxN->proximo;
    auxN->proximo = aux->proximo;
    aux->proximo = NULL;

    return aux;

}

int getSize(node *lls) {
    int i;
    node *aux = lls;

    for (i = 0; aux != NULL; i++) {
        aux = aux->proximo;
    }

    return i;
}

node * removerInicio(node **lls) {
    return removerPosN(lls, 1);
}

void inserirInicio(node **lls, char info) {
    inserirPosN(lls, info, 1);
}

void inserirFinal(node **lls, char info) {
    int final = getSize(*lls);
    inserirPosN(lls, info, final);
}

node * removerFinal(node **lls) {
    int final = getSize(*lls);
    return removerPosN(lls, final);
}

void destruir(node **lls) {
    while (*lls != NULL) {
        removerInicio(lls);
    }
}

void show(node *inicio) {
    while (inicio != NULL) {
        printf("\n[%x] [%c] [%x]",
                inicio, inicio->info, inicio->proximo);
        inicio = inicio->proximo;
    }
}