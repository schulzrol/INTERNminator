#include "printlist.h"

int printlist(node* head){
    /* Check if valid node or empty list */
    if(head == NULL){
        printf("EMPTY LIST\n");
        return EMPTY;
    }

    /* Move to first node if not already */
    node* firstptr = head;
    while(firstptr->prev != NULL){
        firstptr = firstptr->prev;
    }

    /* Print entire list*/
    while(firstptr != NULL){
        if(firstptr->next != NULL){
            printf("%d -> ", firstptr->data);
        }
        else{
            printf("%d\n", firstptr->data);
        }
        firstptr = firstptr->next;
    }

    return SUCCESS;
}
