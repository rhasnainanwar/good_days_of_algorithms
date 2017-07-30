#include <stdio.h>
#include <stdlib.h>

/*-----  GLOBAL  -----*/
//Struct for containing a single node; i.e., the list will be chain of nodes connected through pointers
/*
NOTE that the name list is typdef-ed to be self-referencing for the "next" pointer.
This is because of the fact that the actual name of the struct "node" has not yet been declared; sequence.
*/
typedef struct list {
    int data; //value at in a node
    struct node* next; //pointer to next node
} node;


/*----- PROTOTYPES  -----*/
//NOTE: all these function are declared after the main block

//creates a Linked List with an int data in head and a pointer to the next node.
node* create(int, node*);

//adds a node to the beginning of an existing list (maybe empty or populated).
//INPUTS: the value to be added to the node and the pointer to head of existing list
//OUTPUTS: pointer to the head of new list, with a node prepended
node* add(int, node*);

//same as above, with a difference that the new node is added to the end of the list
node* append(int, node*); //more like a push operation

//tells if a node is present in the list
int search(int, node*);

//removes a node from the front of the list
node* delete(node*); //taken from Queue Data Structure; dequeue

//removes the end node of the list
node* pop(node*); //name taken from Stack Data Structure

//deletes the whole Linked List
void* destroy(node*);

int main(){


}
