#include "insertlist.h"

node* insertlist(node* head, node* sublist){
    
    if(head == NULL || sublist == NULL){
        return NULL;
    }

    node* cursor = NULL;

    //go to end of sublist
    cursor = sublist;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    //set head->next->prev to the end of sublist
    node* temp = head->next;
    temp->prev = cursor;
    //set sublist->next to head->next
    cursor->next = temp;    


    //go to the start of sublist
    cursor = sublist;
    while(cursor->prev != NULL){
        cursor = cursor->prev;
    }
    //set head->next to the sublist start
    head->next = cursor;
    //set sublist->prev to head
    cursor->prev = head;
    
    //returns place where new sublist starts
    return cursor;
}
