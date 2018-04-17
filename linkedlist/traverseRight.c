#include "traverseRight.h"

node* traverseRight(node* head, int steps){

    if(head == NULL || steps <= 0){
        return head;
    }

    node* cursor = head;
    for(int i = 0; cursor->next != NULL && i < steps; i++){
        cursor = cursor->next;
    }

    return cursor;
}
