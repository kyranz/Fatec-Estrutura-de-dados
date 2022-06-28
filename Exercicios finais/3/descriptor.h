#ifndef _DESCRIPTOR_
#define _DESCRIPTOR_ 

#define TRUE 1
#define FALSE 0

// type definition

typedef struct SDESCRIPTOR DESCRIPTOR;
typedef struct SNODO NODO;
typedef int INFO;
typedef int BOOL;

// data structures definition

struct SNODO
{
    INFO info;
    NODO * next;
};

struct SDESCRIPTOR
{
    NODO * start;
    NODO * end;
    int size;
};

// ooperations definition

extern void initialization(DESCRIPTOR **);
extern void destroy(DESCRIPTOR **);
extern BOOL isEmpty(DESCRIPTOR *);
extern int getSize(DESCRIPTOR *);
extern NODO * getStart(DESCRIPTOR **);
extern NODO * getLast(DESCRIPTOR **);

extern void show(DESCRIPTOR * inicio);
extern void insertInTheNPosition (DESCRIPTOR **, INFO, int);
extern void insertAtTheBeginning(DESCRIPTOR **, INFO);
extern NODO * removeFromStart(DESCRIPTOR **);
extern void insertAtTheEnd(DESCRIPTOR **, INFO);
extern NODO * removefromEnd(DESCRIPTOR **);
extern NODO * removeFromPositionN (DESCRIPTOR ** incio, int);





#endif