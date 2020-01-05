#include <stdio.h>

/*
Program: InsertionSort Algorithm
By: Anando Zaman
*/

/*Time complexity best case: Ω(n), worst case O(n^2), Average O(n^2)
  Variable assignment and arithmetic operations take constant time*/

/*How the algo works:
  At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
  It repeats until no input elements remain

  *************************
  More in-depth explanation
  *************************
  A for-loop iterates through each index of an array starting at index 1.
  At the same time, previous values from the left are compared to the current index value of the loop(Also known as smallest value stored in a variable called "value").
  A variable called "hole" contains the current index of the loop as well.
  This "hole" index will behave like a hole, which will be shifted to the left depending on if the values to the left are larger than the value saved in the "value" variable.
  Continue this comparison until "hole" index reaches index 0 or if the value at hole-1 is smaller than "value" variable. */


void insertionSort(int A[], int A_length){

    /*Start sorting from index 1 as we need to be able to compare atleast one index to the left(index 0) in the while loop*/
    for(int i = 1; i<A_length; i++){
        int value = A[i]; /*Will be temporarily used as the smallest value for comparisons*/
        int hole = i; /*Temporary variable marking the hole that will be used to shift larger values to the right*/

        while((hole>0) && (A[hole-1]>value)){
            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = value; /*At the end of the loop, the value(smallest value) gets assigned to the new hole position marking it as the current smallest value in sorted order*/
    }

}


int main(){
    int A[] = {5,2,3,8,0,1,3,2,4,7,9};
    printf("Original unsorted array: ");
    int A_length = sizeof(A)/sizeof(int);
    for (int i = 0; i<A_length; i++){
        printf("%d ",A[i]);
    }
    printf("\n");


    insertionSort(A,A_length);
    printf("New sorted array: ");
    for (int i = 0; i<A_length; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}
