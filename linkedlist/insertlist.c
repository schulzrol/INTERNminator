#include "insertlist.h"

/* 
 * Function merges two sublists
 * 
 * @head - Should point to node after which to insert
 * @sublist - Merges this whole list, starting from the beggining, afkter @head node
 */


node* insertlist(node* head, node** sublist){
    
    if(head == NULL || *sublist == NULL || head == *sublist ){
        return NULL;
    }

    node* cursor = NULL;

    /* Connect end of sublist */
    cursor = *sublist;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    node* temp = head->next;
    temp->prev = cursor;
    cursor->next = temp;    


    /* Connect start of sublist */  
    cursor = *sublist;
    while(cursor->prev != NULL){
        cursor = cursor->prev;
    }
    head->next = cursor;
    cursor->prev = head;
    
    /* Returns place where new sublist starts */
    *sublist = NULL;
    return cursor;
}
