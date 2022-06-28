#ifndef _QUEUE_
#define _QUEUE_
#include "descriptor.h"
typedef DESCRIPTOR QUEUE;

extern void queue_inititaization(QUEUE **);
extern void queue_insert(QUEUE **, INFO);
extern NODO * queue_remove(QUEUE **);

#endif