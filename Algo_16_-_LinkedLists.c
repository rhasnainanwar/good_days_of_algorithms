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


/*-----  FUNCTIONS  -----*/
//creates a node with int data and links it with the next node.
//INPUT: a value for node, next node to link to
//OUTPUT: pointer to the newly created node
//EXPECTED ERROR: error while allocating memory to the node, memory restrictions
node* create(int value, node* next){

    //allocating memory for new node
    node* new_node = (node*)malloc(sizeof(node));

    //exception
    if(new_node == NULL){
        fprintf(stderr, "ERROR: while creating node");
        exit(1); //force terminate
    }

    //filling up
    new_node->data = value;
    new_node->next = next;

    return new_node;
}

//adds a node to the beginning of an existing list (maybe empty or populated).
//INPUTS: the value to be added to the node and the pointer to head of existing list
//OUTPUTS: pointer to the head of new list, with a node prepended
//EXPECTED ERROR: it calls create() function, see its description
node* add(int value, node* head){
    //create a new node, which is to be added
    node* new_node = create(value, head);

    //make the new node head
    head = new_node;

    return head;
}

//same description as add(), with a difference of node being added to the end
node* append(int value, node* head){

    node* pointer = head; //a pointer to head, which will move forward to point to all nodes 1-by-1

    //keep moving until you reach the end
    /*NOTE: I'm making use of the situation that the last node points to nothing!*/
    while(pointer->next != NULL)
        pointer = pointer->next;

    //on reaching the end
    node* new_node = create(value, NULL); //last one points to nothing
    pointer->next = new_node; //attach to end

    return head; //node added at the end, head remains the same
}

//tells if a node is present in the list
//INPUT: a value to find, and the head of the list to find in
//OUTPUT: 1 if value if found, 0 if not
int search(int value, node* head){
    node* pointer = head; //a pointer to point different nodes 1-by-1

    while(pointer != NULL){ //until end is reached
        if(pointer->data == value)
            return 1;
        pointer = pointer->next; //next one up for checking
    }
    return 0;
}

//removes a node from the front of the list, like dequeue in Data Structure QUEUE
//INPUT: head of the list which is to be chopped
//OUTPUT: new head of the list
node* chop(node* head){

    if(head == NULL)
        return NULL;

    node* new_head = head->next; //make the next node, the head
    head->next = NULL; //old head points to nothing now
    free(head); //free existing head, chop it!

    return new_head;
}

//removes the end node of the list, like pop in Data Structure STACK
//INPUT: head of the list
//OUTPUT: head of the list
node* pop(node* head){

    if(head == NULL || head->next == NULL) //if list is empty or has only one node
        return NULL;
    node* pointer = head; //a pointer like other functions
    node* prev = NULL; //previous node

    while(pointer->next != NULL){
        //current one becomes previous, a new one comes up
        prev = pointer;
        pointer = pointer->next;
    }
    prev->next = NULL; //making the second last pointer to nothing; aka last node
    free(pointer); //emptying the last node

    return head;//head unchanged
}

//deletes each node, i.e., whole Linked List
//INPUT: head of the list to destroy
//OUTPUT: NULL
void destroy(node** head){
    node* current = *head;
    node* next;

    while (current != NULL){
       next = current->next;
       free(current);
       current = next;
    }

    *head = NULL;
}

//prints the data in linked list. Name taken from Object class in Java
//INPUT: head of the list
//OUTPUT: NULL but prints the nodes on console
void toString(node* head){
    node* pointer = head;
    printf("[ ");
    while(pointer != NULL){ //until reached the end
        printf("%d ", pointer->data); //display data in the node
        pointer = pointer->next; //move to next node
    }
    printf("]\n");
}
