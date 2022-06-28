#include "exercicio_2.h"
#include <stdio.h>

void insertInOrder(DESCRIPTOR *descriptor, INFO info)
{
    int pos = 1;

    if (descriptor->size == 0) {
        insertAtTheBeginning(&descriptor, info);
        return;
    }

    NODO *node = descriptor->start;

    while (node->info <= info) {
        if (node->info == info) return;
        else if (node->next != NULL) {
            node = node->next;
            ++pos;
        }
        else {
            insertAtTheEnd(&descriptor, info);
            return;
        }
    }

    insertInTheNPosition(&descriptor, info, pos);
}

void createBucket(DESCRIPTOR bucket[])
{
    for (int indx = 0; indx < 1000; indx++)
    {
        bucket[indx].end = NULL;
        bucket[indx].start = NULL;
        bucket[indx].size = 0;
    }
}

void addBucket(DESCRIPTOR bucket[], INFO info)
{
    for (int indx = 0; indx < 1000; indx++) {
        if (info <= (indx * 100 + 99)) {
            insertInOrder(&(bucket[indx]), info);
            break;
        }
    }
}

void showBucket(DESCRIPTOR bucket[])
{
    for (int indx = 0; indx < 1000; indx++)
    {
        if (bucket[indx].size > 0)
        {
            printf("\nBucket %5d - %5d", indx * 100, indx * 100 + 99);
            show(&(bucket[indx]));
        }
    }
}
