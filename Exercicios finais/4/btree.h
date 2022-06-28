#ifndef _BTREE_
#define _BTREE_ 0

typedef int INFO;
typedef struct STNODE BTREE; 

struct STNODE
{
    INFO info;
    BTREE * left;
    BTREE * right;
};

extern void btree_initialize(BTREE **);
extern void btree_create_node(BTREE **, INFO);
extern void btree_insert_ord(BTREE **, INFO);
extern void show(BTREE *, int);

#endif