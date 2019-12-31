#include <stdio.h>
/*
Program: FindMissingNumber Algorithm
By: Anando Zaman

If you are given a sorted list but have one number missing, you can find the missing number by using the arithmetic series formula...

[(lastnumber)*(lastnumber + 1)]/2

The above equation gives the theoretical sum of the full set of numbers if all were available.

If you now take the sum of the entire list and subtract it with the theoretical sum calculated using the eqn above, you will output the
missing number!
*/
int main(){
    int sum = 0;
    int numbers[] = {1,2,3,4,5,6,7,8,10};
    int length = (sizeof(numbers)/sizeof(int));
    int sumTonumbers = (numbers[length-1]*(numbers[length-1]+1))/2;
    for (int i = 0; i<=length; i++){
        sum = sum + i;
        }
    printf("The missing number is: %d",sumTonumbers-sum-1);
}
