#include <stdio.h>
#include <stdlib.h>

/*  Program: LinkedList implementation of a Queue
    By: Anando Zaman
    Date: December 2nd, 2019
 */

/*We will initiate Enqueue at the end of the stack while we Dequeue from the front*/

/* A structure to represent a node of a Queue */
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL; /* Pointer used to keep track of what is at the front of the Queue */
struct Node* rear = NULL; /* Pointer used to keep track of what is at the end of the Queue */

void Enqueue(int x){

    /*Creating a node for insertion at the end of the Queue*/
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;

    if(front==NULL && rear==NULL){ /* If queue is empty */
        front=temp;
        rear=temp;
        return;
    }

    rear->next=temp;
    rear = temp; /* Sets rear pointer to point to the new rear/last node. Effectively inserting the new node to the end */

}

void Dequeue(){

    struct Node* temp = front; /* Temporary variable required to pop/remove the node front pointer is pointing to*/

    if(front==NULL){ /* Empty Queue */
        printf("Empty Queue");
        return;
    }

    else if(front == rear){ /* One element exists in the Queue*/
        front = NULL;
        rear = NULL;
    }

    else{ /*Update front pointer to point to the next node*/
        front=front->next;
    }

    /*Remove previous front node(temporary node)*/
    free(temp);

}

void empty_queue(){

    if(front == NULL){
        printf("Empty Queue");
        return;
    }

    while(front != NULL){
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
}

