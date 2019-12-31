#include <stdio.h>
#define stack_size 10

/*  Program: Array implementation of a stack
    By: Anando Zaman
    Date: December 2nd, 2019
 */

 /* Array implementation is easier but you lose flexibility of the size of the stack. LinkedLists are dynamic but use more memory vs array implementation */
int top = -1; /* set top position of stack initially to -1 since nothing in stack */
int stack_array[stack_size];

void push(int k){

    if(top==stack_size-1){
        printf("Stack Overflow!");
        return;
    }

    top = top + 1;
    stack_array[top] = k;
}

void pop(){

    if (top==-1){ //Empty stack
        printf("Empty stack");
        return;
    }
    top--; //Just decrement top_index counter. We don't have to worry about the garbage that is left, we only assume the stack exists from index 0 to the top_index

}

void printStack(){

    if(top == -1){
        printf("Empty stack!\n");
        return;
    }

    int i;
    printf("Stack printed: ");
    for(i = 0; i<top; i++){
        printf("%d ",stack_array[i]);
    }
    printf("\n");
}

void emptyStack(){
    top = -1;
}

void isEmpty(){

    if(top>=0){
        printf("Stack is NOT EMPTY\n");
    }

    else{
        printf("Stack is EMPTY\n");
    }

}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    printStack();
    pop();
    printStack();
    isEmpty();
    emptyStack();
    isEmpty();
    printStack();

    /*OUTPUT: Stack printed: 1 2 3 4 5
              Stack printed: 1 2 3 4
              Stack is NOT EMPTY
              Stack is EMPTY
              Empty stack!
    */

    return 0;
}
