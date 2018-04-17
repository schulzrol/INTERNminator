#include "printnode.h"

int printnode(node* node){
    if(node == NULL){
        return EMPTY;
    }
    printf("%d", node->data);
    return SUCCESS;
}
