#include <stdio.h>

/*
Program: MergeSort Algorithm
By: Anando Zaman
*/

/*Time complexity worst case is O(nLogn)*/

/* Common mistake note:
  The size of an array must be given to the function.
  Don't try to calculate using Sizeof internally in the function
  as the array parameter passed is treated as type pointer and the sizeof that will result in incorrect results.
  Visit the following link for more information https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/
  */

/*Merges 2 unsorted arrays into a single array of sorted order*/
void Merge(int left[],int right[], int A[],int left_length, int right_length){

    int i = 0; /*Keeps track of smallest index of left subarray */
    int j = 0; /* Keeps track of smallest index of right subarray */
    int k = 0; /* Keeps track of index of main output array A */

    /*Sorts the two left & right arrays. Overwrites the original array A by combining the sorted arrays */
    while(i<left_length && j<right_length){
        if(left[i]<=right[j]){
            A[k] = left[i];
            i++;
        }

        else{
            A[k] = right[j];
            j++;
        }
        k++;

    }

  /* If any elements remaining in left[], copy them over */
    while (i < left_length)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    /* If any elements remaining in right[], copy them over */
    while (j < right_length)
    {
        A[k] = right[j];
        j++;
        k++;
    }


}

/*Recursively partitions the given array to smaller subarrays. Sorts and merges subarrays by calling Merge() function from above*/
void mergeSort(int A[],int A_length){

    /*Base case -> once reaches bottom of the recursive tree*/
    /*Only one element will remain at this point*/
    if(A_length<=1){
        return;
    }

    /*Partition indices*/
    int mid = A_length/2;
    int left[mid]; /*Sub-array for the left half*/
    int right[A_length-mid];


    /*Creating of sub-arrays*/
    for (int i = 0; i<mid; i++){
        left[i] = A[i];
    }

    for (int j = 0; j<A_length-mid; j++){
        right[j] = A[j+mid]; /* (j+mid) is used as we want to get the right-side values of the array which is mid-number of units away to the right*/
    }

    /*Recursively call mergeSort to continue to create smaller sub-arrays for left and right sides*/
    mergeSort(left, mid);
    mergeSort(right, A_length-mid);

    /*Sort & Merge the final arrays traversing back up the tree*/
    Merge(left,right,A,mid,A_length-mid);
}

int main(){
    int A[] = {5,2,3,8,0,1,3,2,4,7,9};
    printf("Original unsorted array: ");
    int A_length = sizeof(A)/sizeof(int);
    for (int i = 0; i<A_length; i++){
        printf("%d ",A[i]);
    }
    printf("\n");


    mergeSort(A,A_length);
    printf("New sorted array: ");
    for (int i = 0; i<A_length; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}
