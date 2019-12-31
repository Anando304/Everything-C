#include <stdio.h>
#include <stdlib.h>

/*  Program: Search and Remove nodes from a LinkedList
    By: Anando Zaman
    Date: December 2nd, 2019
 */


/* A structure to represent ListNode of a LinkedList */
struct Node {
    int data;
    struct Node* next;
};

struct Node* findkey(struct Node* list, int k){ /* Recursively findkey */

    /*Base case*/
    if(list==NULL)
        return NULL;

    else if(list->data==k){
        return list;
    }

    return findkey(list->next,k);
}

struct Node* findkey_iteratively(struct Node* list, int k){ /* Iteratively findkey */

    struct Node *p; /* Temporary pointer node used for searching through nodes of the LinkedList */
    for(p = list; p!=NULL; p=p->next){
        if(p->data == k)
            return p;
    return NULL; /* return NULL pointer if cannot find the node with given key */
    }
}

struct Node* delete_node(struct Node *list, int n){
    struct Node *cur, *prev;

    for(cur=list,prev=NULL; cur!= NULL && cur->data; prev=cur, cur=cur->next);
    if(cur == NULL) /*if n was not found */
        return list;

    else if(prev == NULL){
        /* n is in first node */
    }

    else{
        prev->next = cur->next; /* n is in some other node */
    }

    free(cur);
    return list;
}

struct Node* delete_node_recursively(struct Node *list, int n){   /*Delete the node with specified n-value and then return the resulting LinkedList(recursively)*/

    /*Base case*/
    if((list==NULL) || (list->next == NULL)){
        return list;
    }

    struct Node* temp = list->next;
    struct Node* new_list;

    if(list->data==n){ /* If starting node contains the number we are trying to remove*/
        temp = list;
        new_list = list->next;
        free(temp);
        return new_list;
    }

    else if(list->next->data == n){ /* If a successor node contains the number we are trying to remove*/
        temp = list->next;
        list->next = list->next->next; /*Connect node to the next to next node, essentially skipping over the next node*/
        free(temp); /* free/remove the old next node(temp node) */
        return list;
    }

    return delete_node_recursively(list->next,n);

}

int main(){

    /*Run above functions here*/

    return 0;
}
