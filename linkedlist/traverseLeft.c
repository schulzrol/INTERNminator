
#include "traverseLeft.h"

node* traverseLeft(node* head, int steps){

    if(head == NULL || steps <= 0){
        return head;
    }

    node* cursor = head;
    for(int i = 0; cursor->prev != NULL && i < steps; i++){
        cursor = cursor->prev;
    }

    return cursor;
}
