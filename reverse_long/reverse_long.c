#include <stdio.h>
#include <string.h>

//Program: Reverse_long
//By Anando Zaman
//Completed: 09/21/2019

int main(){
unsigned long int Input1;
unsigned long int reversed = 0;
unsigned long int LastValue = 0;
unsigned long int leftoverInteger;

printf("Enter an integer: ");
scanf("%lu", &Input1);

int condition = 1;

while(1){
LastValue = Input1 % 10; //Gets the last digit of the number
Input1 = Input1 / 10; //Remainder of Integer after digit is removed
reversed = (reversed *10) + LastValue;

//Could also just save in a character array and combine together at the end to form the string but requires more work and memory!

if (Input1 == 0){ //End loop once input1 becomes 0
    printf("%lu",reversed);
    return 0;
}
}
}




