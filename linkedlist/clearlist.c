#include "clearlist.h"

int clearlist(node** head){
/*    if(*head == NULL){
*        return SUCCESS;
*    }
*
*     //Go to start
*    while((*head)->prev != NULL){
*        *head = (*head)->prev;
*    }
*    // Delete to the end
*    while(*head != NULL){
*        node *prevnode = *head;
*        *head = (*head)->next;
*        free(prevnode);
*    }
*/
    while(pop(head) != EMPTY){}

    return SUCCESS;
}
