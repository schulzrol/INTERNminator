#include "defs.h"
#include "pop.h"
#include <stdio.h>

int pop(node** head){

    /* If no node to pop */
    if(*head == NULL){
        return EMPTY;
    }
    /* Get to the end of list */
    node* headptr = *head;
    while(headptr->next != NULL){
        headptr = headptr->next;        
    }
    /*Pop last*/ 
    node* temp = headptr->prev;
    free(headptr);

    /*Check if deleted the only node left*/
    if(temp == NULL){
        *head = NULL;
        return EMPTY;
    }
    /* ...if not, make previous node the last node  */
    
    temp->next = NULL;
    headptr = NULL;

    return SUCCESS; 
}

