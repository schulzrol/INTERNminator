#include "push.h"

int push(node** head, int datainput){
    
    /* Initialization of new node */
    node* newptr = malloc(sizeof(node));    
    if(newptr == NULL){
        return ALLOCFAIL;
    }
    newptr->next = NULL;
    newptr->data = datainput;
    
    /* Check for empty list */
    if(*head == NULL){
        newptr->prev = NULL;
        *head = newptr;
        return SUCCESS;
    }

    /* Get to the end of list*/
    node* headptr = *head;
    while(headptr->next != NULL){
        headptr = headptr->next;        
    }

    headptr->next = newptr;
    newptr->prev = headptr;
    return SUCCESS;
 }
