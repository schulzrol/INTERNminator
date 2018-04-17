#ifndef DEFS_H
#define DEFS_H

#define SUCCESS 0
#define FAIL -1
#define TRUE 0
#define FALSE -1
#define ALLOCFAIL -2
#define EMPTY -3

typedef struct Node node;
struct Node {
    node *next;
    node *prev;
    int data;
};


#endif
