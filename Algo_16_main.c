#include <stdio.h>
#include "Day_16_-_LinkedLists.c"

int main(){
    //starting with an empty node
    node* head = NULL;
    printf("Linked List: "); toString(head);

    printf("\nAdding 7\n");
    head = add(7, head);
    printf("Linked List: "); toString(head);

    printf("\nAdding 1 in front\n");
    head = add(1, head);
    printf("Linked List: "); toString(head);

    printf("\nAdding 5 to the end\n");
    head = append(5, head);
    printf("Linked List: "); toString(head);

    printf("\nAdding 6\n");
    head = add(6, head);
    printf("Linked List: "); toString(head);

    printf("\nRemoving the front node\n");
    head = chop(head);
    printf("Linked List: "); toString(head);

    printf("\nRemoving the end node\n");
    head = pop(head);
    printf("Linked List: "); toString(head);

    printf("\nSearching 6...\n");
    if(search(6, head))
        printf("FOUND!\n");
    else
        printf("NOT FOUND\n");

    printf("\nSearching 1....\n");
    if(search(1, head))
        printf("FOUND!\n");
    else
        printf("NOT FOUND\n");

    printf("\nDestroying...\n");
    destroy(&head);
    printf("Linked List: "); toString(head);
    return 0;
}
