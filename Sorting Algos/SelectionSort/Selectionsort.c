#include <stdio.h>

#define N 10

//Selection sort , recursive solution

void selection_sort(int a[], int n){

 int largest = n -1;
 if (n == 1) //base case, if only one element
    return; //end the function

 for (int i = 0; i < n - 1; i++){ //Finds the index with largest number

    if (a[i] > a[largest]){
        largest = i;
    }
 }

    if(largest < n -1){ //swapper values
        int temp = a[n - 1];
        a[n - 1] = a[largest];
        a[largest] = temp;
    }

    selection_sort(a, n - 1);

}

int main (void){

int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);

    for (i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    selection_sort(a, N);

    printf("In sorted order:");

    for(i = 0; i < N; i++){
        printf(" %d", a[i]);

    printf("\n");
}

return 0;

}
