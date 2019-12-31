#include <stdio.h>
#define stack_size 10

/*  Program: QuickSort Sorting Algorithm
    By: Anando Zaman
    Date: December 2nd, 2019
 */

 /*Design technique known as "divide-and-conquer" which is a large problem divided into smaller pieces that are tackled by the same algorithm*/

 int Partition(int *A,int start,int end){

    int Pivot = A[end];
    int pindex = start; /* set partition index to the start value initially each time */
    for (int i = start; i<end-1; i++){
        if(A[i]<Pivot){
            /*Swap values of array at pindex and at i*/
            int temp = A[pindex];
            A[pindex] = A[i];
            A[i] = temp;
            pindex++;
        }
    }

    /*Swap values of array at pindex and at end once reaches end of the loop above*/
    /* This gives us a new updated array that has been partitioned with smaller values to left of pindex and larger values to right.*/
    int temp2 = A[pindex];
    A[pindex] = A[end];
    A[end] = temp2;
    return pindex; /* returns new pindex which will be used to internally seperate the array into left and right to further sort each subarray. */
                   /* Note: This does not physically seperate the array into 2 but rather treats it like that. More memory efficient */
 }

 void QuickSort(int *A, int start, int end){

    if(start<end){
        int partitionIndex = Partition(A,start,end); /* partitions the array and returns the new pindex which will become the new pivot. It will change for each recursive call of Quicksort */
        QuickSort(A,start,partitionIndex-1); /* sorts the left side of the array */
        QuickSort(A,partitionIndex+1,end); /* sorts the right side of the array */
    }
 }

 int main(){

    int A[] = {9,4,12,4,6,3,1,1,0,8,5,7};
    printf("Unsorted array: ");
    int A_length = sizeof(A)/sizeof(int);
    for(int i = 0;i<A_length;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    QuickSort(A,0,11);
    printf("New sorted array: ");
    for(int i = 0;i<11;i++){
        printf("%d ",A[i]);
    }
    printf("\n");


    return 0;
 }


