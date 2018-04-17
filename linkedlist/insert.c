#include "insert.h"

int insert(node* head, int datainput){

    /* Initialization of new node */
    node* newptr = (node*) malloc(sizeof(node));    
    if(newptr == NULL){
        return ALLOCFAIL;
    }
    newptr->data = datainput;
    
    /* Check for empty list */
    if(head == NULL){
        newptr->prev = NULL;
        newptr->next = NULL;
        head = newptr;
        return SUCCESS;
    }

    /* Insert new node after current node */
    newptr->next = head->next;
    newptr->prev = head;
    head->next = newptr;
    return SUCCESS;
}
