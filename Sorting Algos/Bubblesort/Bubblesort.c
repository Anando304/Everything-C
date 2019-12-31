#include <stdio.h>

/*Program: BubbleSort
  By Anando Zaman
  Worst complexity: О(n^2), Best complexity: O(n)*/

int main(){

    int A[] = {4,6,3,1,2};

    /*Sort the array*/
    for(int i = 0; i<(sizeof(A)/sizeof(int)); i++){
        for(int j = 0; j<(sizeof(A)/sizeof(int)); j++){
            if(A[j]<A[j-1]){
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
       }
    }

    /*Print the sorted array*/
    printf("Sorted Array: ");
    for(int s = 0; s<(sizeof(A)/sizeof(int)); s++){
        printf("%d ", A[s]);
    }
}
