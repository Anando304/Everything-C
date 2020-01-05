#include <stdio.h>

/*
Program: Even or Odd using bitwise AND
By: Anando Zaman

How this works:
By taking a number and ANDing it with 1, outputs 0 if it is even and outputs 1 if odd.
ie; 8 in binary is 1000, so...
    1000
   &0001
   --------
    0000

    9 in binary is 1001, so...
    1001
   &0001
   --------
    0001

    The number 8 outputs 0 while 9 output 1. Therefore, our algorithm works!
    Alternatively, this same program could be solved by doing modulus 2, but it's good to understand alternative methods such as bitwise implementation.
*/

int is_even_odd(int number){
    int is_even_odd_check = number&1;

    if(is_even_odd_check == 1){
        printf("The number %d is odd\n",number);
        return 1;
    }

    printf("The number %d is even\n",number);
    return 0;
}


int main(){

    int number = 19;
    return is_even_odd(number);

    /*OUTPUT:
      The number 19 is odd
      returns 0x1
    */
}
