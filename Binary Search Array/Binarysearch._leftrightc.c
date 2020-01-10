#include <stdio.h>
/*
Program: Binary Search Recursive Solution #2 Using left and right indices
By: Anando Zaman
Note: This search only works for sorted arrays. If the array is unsorted, sort it first before using this
*/
int binary_search(int array[], int left, int right, int x)
{
    if (right >= left) {
        int mid = left + (right - left) / 2; /*Important formula for calculating midpoint given left and right indices*/

        /*Base case*/
        if (array[mid] == x)
            return mid; /*return the index at which the value is found*/

        /*Check right sub-array if element is larger than mid element*/
        if (array[mid] < x)
            return binary_search(array, mid+1, right, x);

        /*Otherwise, check left sub-array*/
        return binary_search(array, left, mid-1, x);
    }

    /*If cannot find the value after navigating down the array(picture node trees for visualization when conducting recursion)*/
    return -1;
}

int main(void)
{
    int array[] = { 1, 2, 3, 10, 16, 42, 49, 68, 74, 89, 92 };
    int length = sizeof(array) / sizeof(int);
    int result = binary_search(array,0,length,10);
    printf("The index at which the number 10 is in the array is %d\n", result);
    return 0;
}
