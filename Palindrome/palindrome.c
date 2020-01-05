#include <stdio.h>

/*
Program: Palindrome
By: Anando Zaman
*/
/*
A palindrome is a sequence of integers that when reversed, is the same as the original.
ie; 1,3,7,8,7,3,1
This program is a recursive solution.
The program returns...
1: if a valid palindrome
0: otherwise
*/

int is_palindrome(int length, int *a){

    if(length<=1){
        printf("The given array is a valid palindrome\n");
        return 1; /*Base case for empty array or array with 1 number*/
    }

    else if(a[0] == a[length-1]){
        return is_palindrome(length-2,a+1);
    }

    else{
        printf("The given array is NOT a valid palindrome\n");
        return 0;
    }
}

int main(){

    int a[] = {0,1,2,3,4,3,2,1,0};
    int a_length = sizeof(a)/sizeof(int);
    is_palindrome(a_length,a);

    int b[] = {0,1,2,3,4,3,2,1,9};
    int b_length = sizeof(b)/sizeof(int);
    is_palindrome(b_length,b);

    /*OUTPUT:
      The given array is a valid palindrome
      The given array is NOT a valid palindrome
    */
}
