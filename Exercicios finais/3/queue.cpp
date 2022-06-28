#include "queue.h"

void queue_inititaization(QUEUE ** queue)
{
    initialization(queue);
}
void queue_insert(QUEUE ** queue, INFO info)
{
    insertAtTheEnd(queue, info);
}
NODO * queue_remove(QUEUE ** queue)
{
    return removeFromStart(queue);
}