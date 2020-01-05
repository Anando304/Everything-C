#include <stdio.h>

/*
Program: OppositeSign Checker (Bitwise implementation)
By: Anando Zaman

Given 2 numbers, check whether both are of same sign OR if both are of different sign(negative and positive)
There are many ways to solve this problem such as using conditionals to check if one input is negative while
the other is positive and vice versa.

Bitwise Algorithm explanation:
We are going to use XOR bitwise operations to solve this problem.
Recall that for signed integers, the binary representation has the most significant bit on the far left.
This bit is also known as the sign bit as it tells us if the number is positive or negative.
By XOR the sign bit of 2 numbers, if the this value outputs 1(ie; 0 ^ 1 = 1) then the two numbers are of different signs.
Otherwise, the numbers are of same sign(0 ^ 0 = 0 OR 1 ^ 1 = 0)
Since we are dealing with sign bits, 1 means negative while 0 means positive.
So if after XORing, we get a negative number, that means sign bit is 1 and that the 2 numbers are of different sign.
If the number is positive, then the sign bit is 0 meaning that the 2 numbers provided are of SAME sign.

ie; -7 and 2 in binary are 1111 and 0010 respectively. 1111 ^ 0010 results in 1101 which is -5. Since the resulting
    sign bit is 1 and the binary in decimal form is a negative number, this means the two numbers provided are of opposite signs
*/

void is_oppsigns(int a, int b){

    if ((a^b)<0){
        printf("The two numbers are of opposite signs\n");
    }

    else{
        printf("The two numbers are of SAME signs\n");
    }

}

int main(){
    is_oppsigns(-9,4);

    /*OUTPUT:
      The two numbers are of opposite signs
    */
}
