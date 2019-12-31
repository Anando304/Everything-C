#include <stdio.h>
#include <stdlib.h>

/*  Program: Reverse a LinkedList Recursively
    By: Anando Zaman
    Date: December 2nd, 2019
 */


/* A structure to represent ListNode of a LinkedList */
struct Node {
    int data;
    struct Node* next;
};

struct Node* findLast(struct Node* list){ /* Recursively find last node */

    if((list == NULL) || (list->next == NULL)){ /* Base Case */
        return list;
    }

    return findLast(list->next);
}

struct Node* findkey(struct Node* list, int k){ /* Recursively findkey */

    /*Base case*/
    if(list==NULL)
        return NULL;

    else if(list->data==k){
        return list
    }

    return findkey(list->next,k);
}

struct Node* append(struct Node* list, struct Node* node_insert){

    if(list == NULL){ /*Empty List provided*/
        return node
    }
    struct Node* last = findLast(L);
    last->next=node_insert;
    return list
}

struct Node* reverse(struct Node* list){ /* Recursively reverse the LikedList */

    if((list==NULL) || (list->next==NULL)){  /* Base case */
        return list;
    }

    struct Node* R = reverse(list->next);
    list->next=NULL; /* Set the previous nodes' next pointer to NULL so that it can be inserted into the last of the list. Continue this recursively*/
    list=append(R,list);

}

int main(){

    /*Run above functions here to reverse a specific Linked List*/

    return 0;
}
