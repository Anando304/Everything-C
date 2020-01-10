#include <stdio.h>
/*
Program: Binary Search Recursive Solution
By: Anando Zaman
Note: This search only works for sorted arrays. If the array is unsorted, sort it first before using this
*/
int binary_search(int array[], int length, int x){

    if(length>=1){
    int mid = length/2;

    /*Base case*/
    if(array[mid] == x){
        return mid; /*return the index at which the value is found*/
    }

    else if(array[mid] < x){
        /*Check right subarray if element is larger than mid element*/
        return binary_search(array+mid,length,x);
    }

    /*Check left subarray if element is smaller than mid element*/
    return binary_search(array,mid-1,x);
    }
    return -1;


}

int main(){

    int array[] = { 1, 2, 3, 10, 16, 42, 49, 68, 74, 89, 92 };
    int length = sizeof(array) / sizeof(int);
    int result = binary_search(array,length,42);
    printf("The index at which the number 42 is in the array is %d\n", result);
    return 0;
}
