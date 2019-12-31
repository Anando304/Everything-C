#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Date: Nov 6,2019
Program: Binary tree structure with more variables in nodes
 */
typedef struct node {
    int value;
    char* expr_string;
    struct node *left;
    struct node *right;
    //if we have int a* pointer then to free this too since its pointing to another node which also has to be freed.
}Node;

//typedef struct node Node; NO need for this since we already did tyepdef struct node at top with Node name after

Node *createNode(char* s,int value){
    Node *node = (Node*)malloc(sizeof(Node)); //allocate block o memory for Node of type node
    node->left = NULL;
    node->right =NULL;
    node->value = value;
    node->expr_string = s;

    return node;

}

void printTree(Node *root){

    //Base case
    if(root == NULL){
        return;
    }

    printf("%d \n", root->value);
    printTree(root->left);
    printTree(root->right);
}

void freeTree(Node *root){

    //if root or subtree passed is empty
    if(root == NULL){
        return;
    }

    /*//Reaches leaf nodes
    else if((root->left == NULL) && (root->right == NULL)){
        free(root);
    }*/

    //Recursively free each left and right node by running the freeTree function itself
    freeTree(root->left);
    freeTree(root->right);

    free(root); // Once reaches end of each function

    if(root != NULL){
        printf("VAL exists,%s %f \n",root->expr_string,root->value);
    }
}

Node *addNode(Node *root,char* s, int value){
    //Base case
    if (root == NULL){
        return createNode(s,value);
    }

    else if(value > root->value){
        root->right = addNode(root->right,s,value);
    }

    else if(value < root->value){
        root->left = addNode(root->left,s,value);
    }
}


char* makeString(char* s1, char* s2, char* s3){

    /* byte size length calculation to allocate memory for concatenation */
    size_t concatenated_length = strlen(s1) + strlen(s2) + strlen(s3) + 1;

    /* Dynamic array memory allocation using malloc */
    /* Syntax normally is malloc(n * sizeof(int or other data type used)).
       However, since we got the length already in terms of byte size above, we can just directly input it. */

    char *result = malloc(concatenated_length);

    /* Check if memory cannot be allocated */
    if (result == NULL) {
        printf("Memory cannot be allocated\n");
        return result;
        /*return null pointer*/
    }

    /* Concatenate strings by first copying s1 to result array */
    /* Each block index has a value saved into it */
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);


    return result;
}


int main(){
    //gdb a.out
    //run
    //explore to explore root with null pointer
    //check stack
    //explore root
    //Can print values from memory doing print root-value
    //pressing enter reruns last line command
    //can also add break points
    //ie; break 26, meaning breaks line at 26
    //gdb cheat sheet

    //Can also do this with VSCODE debugger
    //Remote wsl
    Node * a [4];
    a [0] = createNode ("a", .1);
    a [1] = createNode ("b", .2);
    a [2] = createNode ("c", .3);
    a [3] = createNode ("d", .4);
    //Node *node = createNode(makeString("ABC", "DEF", "GHI"),10);
    //addNode(root,5);
    //addNode(root,10);
    //printTree(node);
    freeTree(a[0]);

    /*
    if we had Node *a = createNode(10)
                   *b = createNode(10)
                   a = b;
                   This will result in memory being lost as 'a' now points to 'b' but previously created a node which resulted in a malloc to be executed
                   causing a memory block of type Node to be created. This block is now empty, so we must free it before setting a = b.
                   so should be like free(a)
                                     a = b;

    */
}
