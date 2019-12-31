#include <stdio.h>
#include <string.h>
#define N 80
/*Author: Anando Zaman
Date: October 2, 2019
Problem #1: Simple Addition & Subtraction Calculator */
/*This problem can be easily solved by simply converting the numbers to integers and then adding/subtracting.*/
/*However, that implementation has a certain size limit as integers are guaranteed to be able to hold -32767 to 32767. This can be too small for large number arithmetic*/
/*Instead, this program adds/subtracts any size numbers just as if you were to do it by hand(by adding/subtracting numbers in a column and using carries)*/

/*Usage: run the program using the following commands...
*********************
        gcc calc.c
        ./a.out
*********************
        //Enter two numbers with a space followed by the arithmetic operator symbol
        ie: 99 10000 -
        OUTPUT:
               99
            10000
            -9901
*********************
*/

/* ********************************************SUMMATION*********************** */

void add(char a[], char b[], char res[]){

    int Length_a = strlen(a);
    int Length_b = strlen(b);

     /*CASE I*/
    if (Length_a > Length_b){

        int indexb = Length_b-1;
        int carry = 0;
        int digitsum = 0;
        int Char_a_to_int = 0;
        int Char_b_to_int = 0;

        Char_a_to_int = a[0] - 48;
        Char_b_to_int = b[0] - 48;

        int i = 0;
        for (i = Length_a - 1; i>=0; i--){ /*If first number is larger than first*/

            if(indexb >= 0){
                Char_a_to_int = a[i] - 48;
                Char_b_to_int = b[indexb] - 48;

                digitsum = Char_a_to_int + Char_b_to_int;

                if (digitsum>9){ /*Will need to carry a 1*/
                    res[i] = ((digitsum + carry) % 10) + '0';
                    carry = 1;
                }

                else{
                    res[i] = ((digitsum + carry) % 10)  + '0';
                    carry = 0; /*No need to carry anything*/
                }

                indexb--;
            }



            else{
                /*Exceed past length of index b */

                Char_a_to_int = a[i] - 48;

                digitsum = Char_a_to_int + carry;

                if (digitsum>9){ /*Will need to carry a 1 */
                res[i] = (digitsum % 10) + '0';
                carry = 1;
                }

                else{
                    res[i] = (digitsum%10) + '0';
                    carry = 0; /* No need to carry anything */
                }
            }

        }
        if (carry == 1){ /* if a carry is still left for final digit calculation, ie; 99 + 99 */
            int s = 0;
            for (s = Length_a; s > 0; s--){

                res[s] = res[s-1]; /* Shift over all numbers by 1 column */
            }
            res[0] = '1';
            res[Length_a + 1] = '\0';

        }


    }

     /* CASE II */
    else if (Length_a < Length_b){ /* If second number is larger than first */

        int indexa = Length_a-1;
        int carry = 0;
        int digitsum = 0;
        int Char_a_to_int = 0;
        int Char_b_to_int = 0;

        Char_a_to_int = a[0] - 48;
        Char_b_to_int = b[0] - 48;

        int i = 0;
        for (i = Length_b - 1; i>=0; i--){

            if(indexa >= 0){
                Char_a_to_int = a[indexa] - 48;
                Char_b_to_int = b[i] - 48;

                digitsum = Char_a_to_int + Char_b_to_int;

                if (digitsum>9){ /* Will need to carry a 1 */
                    res[i] = ((digitsum + carry) % 10) + '0';
                    carry = 1;
                }

                else{
                    res[i] = ((digitsum + carry)%10) + '0';
                    carry = 0; /* No need to carry anything */
                }

                indexa--;
            }



            else{
                Char_b_to_int = b[i] - 48;

                digitsum = Char_b_to_int + carry;

                if (digitsum>9){
                res[i] = (digitsum % 10) + '0';
                carry = 1;
                }

                else{
                    res[i] = (digitsum %10) + '0';
                    carry = 0;
                }
            }

        }

            if (carry == 1){
            int s = 0;
            for (s = Length_b; s > 0; s--){

                res[s] = res[s-1]; /* Shift over all numbers by 1 column */
            }
            res[0] = '1'; /* add the 1 as the first value */
            res[Length_b + 1] = '\0'; /* add the 1 as the first value */

            }



    }

         /* CASE III */
        else if (Length_a == Length_b){

            int carry = 0;
            int digitsum = 0;
            int Char_a_to_int = 0;
            int Char_b_to_int = 0;

            Char_a_to_int = a[0] - 48;
            Char_b_to_int = b[0] - 48;

            int i = 0;
            for (i = Length_b - 1; i>=0; i--){

                    Char_a_to_int = a[i] - 48;
                    Char_b_to_int = b[i] - 48;

                    digitsum = Char_a_to_int + Char_b_to_int;

                    if (digitsum>9){
                        res[i] = ((digitsum  + carry) % 10) + '0';
                        carry = 1;
                    }

                    else{
                        res[i] = (digitsum + carry) + '0';
                        carry = 0;
                    }


            }


            if (carry == 1){

                int s = 0;
                for (s = Length_b; s > 0; s--){

                    res[s] = res[s-1];
                }
                res[0] = '1';
                res[Length_b + 1] = '\0';

            }


    }


}















/* ********************************************SUBTRACTION*********************** */

void sub(const char a[], const char b[], char res[]){

    int Length_a = strlen(a);
    int Length_b = strlen(b);

    /* CASE I */
    if (Length_a > Length_b){

        int indexb = Length_b-1; /* Represents index of a digit in array b */
        int carry = 0;
        int digitsub = 0;
        int Char_a_to_int = 0;
        int Char_b_to_int = 0;

        Char_a_to_int = a[0] - 48;
        Char_b_to_int = b[0] - 48;

        int i = 0;
        for (i = Length_a - 1; i>=0; i--){

            if(indexb >= 0){
                Char_a_to_int = a[i] - 48;
                Char_b_to_int = (b[indexb] + carry) - 48;

                if(Char_b_to_int <= Char_a_to_int){
                    digitsub = Char_a_to_int - Char_b_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 0;
                }


                else if(Char_b_to_int > Char_a_to_int){

                    digitsub = (10 + Char_a_to_int) - Char_b_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 1;

                }


                indexb--;
            }



            else{

                Char_a_to_int = a[i] - 48;

                if(carry<=Char_a_to_int){
                    digitsub = Char_a_to_int - carry;

                    res[i] = (digitsub % 10) + '0';
                    carry = 0;
                }

                else if(carry>Char_a_to_int){
                    digitsub = (10 + Char_a_to_int) - carry;

                    res[i] = (digitsub % 10) + '0';
                    carry = 1;
                }


            }

        }

    /* FINDS FIRST_NON_ZERO ELEMENT TO REMOVE LEADING 0'S */
    int s = 0;
    int condition = 1;
    int first_non_zero = 0;
    while(condition){
        if(res[s] != '0'){
            first_non_zero = s;
            condition = 0;
        }
        s++;
    }

    /* Shifts over the numbers after first non-zero, to the start of the array to remove leading 0's */
    for(s = 0; s<=Length_a; s++){

        if(first_non_zero<Length_a){
            res[s] = res[first_non_zero];
            first_non_zero++;
        }

        else if(first_non_zero==Length_a){
            res[s] = '\0';
        }
    }

    }









    /* CASE II */
    if (Length_a < Length_b){

        int indexa = Length_a-1;
        int carry = 0;
        int digitsub = 0;
        int Char_a_to_int = 0;
        int Char_b_to_int = 0;

        Char_a_to_int = a[0] - 48;
        Char_b_to_int = b[0] - 48;


        int i = 0;
        for (i = Length_b - 1; i>=0; i--){

            if(indexa >= 0){
                Char_a_to_int = (a[indexa] + carry) - 48;
                Char_b_to_int = b[i] - 48;

                if(Char_a_to_int <= Char_b_to_int){
                    digitsub = Char_b_to_int - Char_a_to_int;
                    res[i] = (digitsub % 10) + '0';

                    carry = 0;
                }


                else if(Char_a_to_int > Char_b_to_int){

                    digitsub = (10 + Char_b_to_int) - Char_a_to_int;
                    res[i] = (digitsub % 10) + '0';

                    carry = 1;

                }


                indexa--;
            }



            else{
                Char_b_to_int = b[i] - 48;

                if(carry<=Char_b_to_int){
                    digitsub = Char_b_to_int - carry;

                    res[i] = (digitsub % 10) + '0';
                    carry = 0;
                }

                else if(carry>Char_b_to_int){
                    digitsub = (10 + Char_b_to_int) - carry;

                    res[i] = (digitsub % 10) + '0';
                    carry = 1;
                }


            }

        }

        /* FINDS FIRST_NON_ZERO ELEMENT TO REMOVE LEADING 0'S */
        int s = 0;
        int condition = 1;
        int first_non_zero = 0;

        while(condition){
            if(res[s] != '0'){
                first_non_zero = s;
                condition = 0;
            }
            s++;
        }

        /* Remove leading 0's */
        for(s = 0; s<=Length_b; s++){

            if(first_non_zero<Length_b){

                res[s] = res[first_non_zero];
                first_non_zero++;
            }

            else if(first_non_zero==Length_b){
                res[s] = '\0';
            }
        }


        for(s = Length_b; s>0;s--){
            res[s] = res[s-1];
        }
        res[0] = '-';
        res[Length_b + 1] = '\0';

        }




    /*CASE III */
    if (Length_a == Length_b){

        int num_a_larger = 0;
        int num_b_larger = 0;
        int condition = 1;
        int index = 0;

        while(condition){ /* Finds out which number is larger of the two inputted */

            if(a[index]>b[index]){ /* if array a is larger number */
                num_a_larger++;
                condition = 0;
            }

            else if(a[index]<b[index]){ /* if array b is larger number */
                num_b_larger++;
                condition = 0;
            }

            index++;

            if(index == Length_a){ /* If reaches end of array without finding a digit that is larger, meaning both numbers are the same */
                condition = 0;
            }
        }


            if((num_a_larger == 0) && (num_b_larger==0)) { /* if the two numbers are the same */
                res[0] = '0';
                res[1] = '\0';

            }

            else if(num_a_larger){
            int carry = 0;
            int digitsub = 0;

            int Char_a_to_int = a[0] - 48;
            int Char_b_to_int = b[0] - 48;


            int i = 0;
            for (i = Length_a - 1; i>=0; i--){

                Char_a_to_int = a[i] - 48;
                Char_b_to_int = (b[i] + carry) - 48;

                if(Char_b_to_int <= Char_a_to_int){
                    digitsub = Char_a_to_int - Char_b_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 0;
                }


                else if(Char_b_to_int > Char_a_to_int){

                    digitsub = (10 + Char_a_to_int) - Char_b_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 1;

                }

            }

            /* FINDS FIRST_NON_ZERO ELEMENT TO REMOVE LEADING 0'S */
            int s = 0;
            int condition = 1;
            int first_non_zero = 0;
            while(condition){
                if(res[s] != '0'){
                    first_non_zero = s;
                    condition = 0;
                }
                s++;
            }

            /* Shifts over the numbers after first non-zero, to the start of the array to remove leading 0's */
            for(s = 0; s<=Length_a; s++){

                if(first_non_zero<Length_a){
                    res[s] = res[first_non_zero];
                    first_non_zero++;
                }

                else if(first_non_zero==Length_a){
                    res[s] = '\0';
                }
            }

        }




            else if(num_b_larger){ /* NUM_B_larger */
            int carry = 0;
            int digitsub = 0;

            int Char_a_to_int = a[0] - 48;
            int Char_b_to_int = b[0] - 48;


            int i = 0;
            for (i = Length_a - 1; i>=0; i--){

                Char_a_to_int = (a[i] + carry) - 48;
                Char_b_to_int = b[i] - 48;

                if(Char_a_to_int <= Char_b_to_int){
                    digitsub = Char_b_to_int - Char_a_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 0;
                }


                else if(Char_a_to_int > Char_b_to_int){

                    digitsub = (10 + Char_b_to_int) - Char_a_to_int;
                    res[i] = (digitsub % 10) + '0';
                    carry = 1;

                }

            }
            /* FINDS FIRST_NON_ZERO ELEMENT TO REMOVE LEADING 0'S */
            int s = 0;
            int condition = 1;
            int first_non_zero = 0;
            while(condition){
                if(res[s] != '0'){
                    first_non_zero = s;

                    condition = 0;
                }
                s++;
            }

            /* Shifts over the numbers after first non-zero, to the start of the array to remove leading 0's */
            for(s = 0; s<=Length_a; s++){

                if(first_non_zero<Length_a){
                    res[s] = res[first_non_zero];
                    first_non_zero++;
                }

                else if(first_non_zero==Length_a){
                    res[s] = '\0';
                }
            }

            for(s = Length_b; s>0;s--){
            res[s] = res[s-1];
            }
            res[0] = '-';
            res[Length_b + 1] = '\0';

            }


    }



}


char a[N], b[N], res[N + 1];
int main(){
printf("Enter two numbers \n");

char op;
scanf ("%s %s %c", &a, &b, &op);

switch (op){
case '+':
    add(a, b, res);
    break;
case '-':
    sub(a, b, res);
}

char buf[20];
int l1 = strlen (a), l2 = strlen (b), l3 = strlen (res);
int m = l1 > l2 ? l1 : l2;
m = m > l3 ? m : l3;
sprintf (buf , "%% %ds\n%% %ds\n%% %ds\n", m, m, m);
printf(buf,a,b,res);


return 0;
}

