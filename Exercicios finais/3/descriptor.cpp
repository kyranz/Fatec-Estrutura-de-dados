#include "descriptor.h"
#include <stdlib.h>
#include <stdio.h>

void initialization(DESCRIPTOR **descriptor)
{
    *descriptor = new DESCRIPTOR;
    (*descriptor)->start = NULL;
    (*descriptor)->end = NULL;
    (*descriptor)->size = 0;
}

void destroy(DESCRIPTOR **descriptor)
{
    NODO *aux = NULL;
    NODO *dest = NULL;
    if (!isEmpty(*descriptor))
    {
        aux = (*descriptor)->start;
    }
    while (aux != NULL)
    {
        dest = aux;
        aux = aux->next;
        free(dest);
    }
}

BOOL isEmpty(DESCRIPTOR *descriptor)
{
    BOOL retvalue = FALSE;
    if (descriptor == NULL || descriptor->start == NULL)
    {
        retvalue = TRUE;
    }
    return retvalue;
}

int getSize(DESCRIPTOR *descriptor)
{
    return descriptor->size;
}

NODO *getStart(DESCRIPTOR **descriptor)
{
    NODO *retaddr = NULL;
    if (!isEmpty(*descriptor))
    {
        retaddr = (*descriptor)->start;
    }
    return retaddr;
}

NODO *getLast(DESCRIPTOR **descriptor)
{
    NODO *retaddr = NULL;
    if (!isEmpty(*descriptor))
    {
        retaddr = (*descriptor)->end;
    }
    return retaddr;
}

NODO *getElementInTheNPosition(NODO **lls, int pos)
{
    int indx;
    NODO *aux = *lls;

    for (indx = 1; indx < pos; indx++)
    {
        aux = aux->next;
        if (aux == NULL)
        {
            break;
        }
    }

    return aux;
}

void insertInTheNPosition(DESCRIPTOR **descriptor, INFO info, int pos)
{
    NODO *auxN;
    NODO *aux = new NODO;
    aux->info = info;
    aux->next = NULL;

    if (isEmpty(*descriptor) && pos != 1)
    {
        return;
    }

    if (pos != 1 && pos > (*descriptor)->size + 1)
    {
        return;
    }

    if (pos == 1)
    {
        aux->next = (*descriptor)->start;
        (*descriptor)->start = aux;
        (*descriptor)->size += 1;
        if ((*descriptor)->size == 1)
        {
            (*descriptor)->end = aux;
        }
        return;
    }

    auxN = getElementInTheNPosition(&((*descriptor)->start), pos - 1);

    if (auxN == NULL)
    {
        return;
    }

    aux->next = auxN->next;
    auxN->next = aux;
    (*descriptor)->size += 1;

    return;
}
void insertAtTheBeginning(DESCRIPTOR **descriptor, INFO info)
{
    insertInTheNPosition(descriptor, info, 1);
}
NODO *removeFromStart(DESCRIPTOR ** descriptor)
{
    return removeFromPositionN(descriptor, 1);
}
void insertAtTheEnd(DESCRIPTOR **descriptor, INFO info)
{
    insertInTheNPosition(descriptor, info, (*descriptor)->size + 1);
}

NODO *removefromEnd(DESCRIPTOR **descriptor)
{
    return removeFromPositionN(descriptor, (*descriptor)->size);
}
NODO *removeFromPositionN(DESCRIPTOR **descriptor, int pos)
{
    NODO *aux;
    NODO *auxN;

    if (isEmpty(*descriptor))
    {
        return NULL;
    }

    if (pos == 1)
    {
        aux = (*descriptor)->start;
        (*descriptor)->start = aux->next;
        aux->next = NULL;
        (*descriptor)->size -= 1;
        if ((*descriptor)->size == 0)
        {
            (*descriptor)->end = (*descriptor)->start = NULL;
        }
        return aux;
    }

    if (pos > (*descriptor)->size)
    {
        return NULL;
    }

    auxN = getElementInTheNPosition(&((*descriptor)->start), pos - 1);

    if (auxN == NULL)
    {
        return NULL;
    }

    aux = auxN->next;
    auxN->next = aux->next;
    aux->next = NULL;
    (*descriptor)->size -= 1;
    if ((*descriptor)->size == 0)
    {
        (*descriptor)->end = (*descriptor)->start = NULL;
    }

    return aux;
}

void show(DESCRIPTOR *descriptor)
{
    NODO *aux = descriptor->start;
    while (aux != NULL)
    {
        printf("\n%d", aux->info);
        aux = aux->next;
    }
}

