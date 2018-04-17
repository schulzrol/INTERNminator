#include "defs.h"
#include "clearlist.h"
#include "pop.h"
#include "printlist.h"
#include "push.h"
#include "insertlist.h"

int main(){
    node *head = NULL;
    node *sublist = NULL;

    push(&head, 15);    
    push(&head, 20);    
    push(&head, 30);    
    push(&head, 40);    
    
    push(&sublist, 25);
    push(&sublist, 26);
    push(&sublist, 27);
    push(&sublist, 28);
    
        printf("Main list after 4 pushes:\n");
    printlist(head);
        printf("\n");    

        printf("Sublist after 4 pushes:\n");
    printlist(sublist);
        printf("\n");    

    pop(&head);
    
        printf("Main list after pop:\n");
    printlist(head);
        printf("\n");    

    insertlist(head->next, &sublist);
    
    
        printf("Main list merged with sublist:\n");
    printlist(head);
        printf("\n");    
    
        printf("Sublist list after merg\n");
    printlist(sublist);
        printf("\n");    

    clearlist(&head);
    
        printf("Main after clearing:\n");
    printlist(head);
        printf("\n");

        printf("Sublist list after clear\n");
    printlist(sublist);
        printf("\n");    

    return SUCCESS;
}
