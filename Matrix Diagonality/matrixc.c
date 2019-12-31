#include<stdio.h>
/*Author: Anando Zaman
Date: October 2, 2019
Problem #1: Matrix*/

/*
Given an n x n matrix, you need to determine if each diagonal(from left to right) of
the matrix contains the same value. One such matrix is for example

1 2 3 4
7 1 2 3
8 7 1 2
9 8 7 1

Input :
n: number of rows and columns
a: array of size n x n storing an integer matrix row wise

Returns :
1: if each diagonal of the matrix
contains the same value
0: otherwise
*/

int is_same_diagonals ( int n, int a[]){
    int diagonal_term_index_check = 0;
    int diagonal_term_index = 0;
    int i = 0;
    for (i = 0; i<(n*n); i++){
        diagonal_term_index_check = i + (n + 1);

        if(diagonal_term_index_check<n*n){ /* first check diagonal term index is a valid matrix cell */

            if((i+1)%n == 0){
                i++; /*to prevent from checking last column, move to next index and continue checking */
            }

            diagonal_term_index = i + (n + 1);

            if(a[i] != a[diagonal_term_index]){ /*If any of the diagonals values are not equal to index value, then return 0 */
                return 0;
            }
        }
}

return 1;
}

int main(){


int n = 8;
int a[] = {1,2,3,4,5,6,7,8,
           4,1,2,3,4,5,6,7,
           5,4,1,2,3,4,5,6,
           6,5,4,1,2,3,4,5,
           7,6,5,4,1,2,3,4,
           7,7,6,5,4,1,2,3,
           3,7,7,6,5,4,1,2,
           2,3,7,7,6,5,4,1};

/*int n = 4;
int a[] = {4,2,8,9,12,4,2,8,13,12,4,2,14,13,12,4};*/
printf("%d",is_same_diagonals(n,a));
return(is_same_diagonals(n,a));

}
