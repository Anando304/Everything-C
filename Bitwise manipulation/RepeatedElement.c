#include <stdio.h>

/*
Program: Non-repeated Element
By: Anando Zaman

The following program will return 0 if no non-repeated element exists. Otherwise, it will return the element that occurs only once.

How this works:
This program finds the element that only occurs from an array of elements that occur more than once
For example, 9,2,2,3,3,4,4,5,5 has the number 9 occurring once. So the output of the program would be 9.

We could solve this problem using hashtables in which the element is used as the key while the count of occurrences is used as a value in a hash table.
This requires additional memory but still works!
Instead, we will use properties of bitwise XOR to solve the problem in O(n) time complexity and constant extra space
Recall XOR is commutative and associative.
XOR of an element with 0 results in itself, while XOR of an element with itself results in 0.
If we XOR all the elements in the array, if it outputs 0, then all elements are repeated more than once.
Otherwise, any other element is the element that occurred more than once.

ie; Given an array = {9,2,2,3,3,4,4,5,5}, find the non-repeated element. XORing this gives us 9^2^2^3^3^4^4^5^5 = 9 ^ 0 = 9
*/

int non_repeat(int A[], int len){

    int result = A[0];
    for (int i = 1; i < len; i++){
        result = result ^ A[i];
    }
    return result;
}

int main(){

    int A[] = {32,2,2,3,3,4,4,5,5};
    int len = sizeof(A)/sizeof(int);
    return non_repeat(A,len);
    /*OUTPUT:
      returns 32
    */
}
