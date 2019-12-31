#include <stdio.h>
#include <stdlib.h>

/*  Program: LinkedList implementation of a stack
    By: Anando Zaman
    Date: December 2nd, 2019
 */


/* A structure to represent a node of the stack */
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; /* Pointer used to keep track of what is at the top of the stack */

void push(int x){

    struct Node* temp = malloc(sizeof(struct Node)); /* Create a temporary node */
    temp->data = x;
    temp->next = top;
    top = temp; /*Set new top pointer to the new inserted node*/
}

void pop(){
    struct Node* temp;
    if(top == NULL) /*Stack is empty as pointer points to NULL*/
        return;

    temp = top; /*Used to remove node that was previously at top position*/
    top = top->next; /* Set top pointer to point to the next node*/
    free(temp); /* free temporary node effectively removing('popping') the previous 'top' node */
}

void empty(){ /* We will empty/destroy the stack iteratively */

    if (top == NULL){
        printf("Empty stack");
        return;
    }

    while(top != NULL){
        struct Node* current = top;
        top = top->next;
        free(current);
    }

}

void printStack(){
   if (top == NULL){
        printf("Stack is empty");
   }

   struct Node* current = top;
   for(current; current!=NULL; current=current->next){
        printf("%d ",current->data);
   }

}


void printStack_Recursively(struct Node* node){

   if (node == NULL){ /* Base case */
        return;
   }

   printf("%d ",node->data);
   printStack_Recursively(node->next);

}

