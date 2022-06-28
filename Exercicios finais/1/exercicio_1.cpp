#include "exercicio_1.h"
#include <stdio.h>
#include <stdlib.h>

void insertInOrder(DESCRIPTOR ** descriptor, INFO info) {

    int pos = 1;

    if ((*descriptor)->size == 0) {
        insertAtTheBeginning(descriptor, info);
        return;
    }

    NODO *node = (*descriptor)->start;

    while (node->info < info) {
        if (node->next != NULL) {
            node = node->next;
            ++pos;
        }
        else {
            insertAtTheEnd(descriptor, info);
            return;
        }
    }

    insertInTheNPosition(descriptor, info, pos);

}