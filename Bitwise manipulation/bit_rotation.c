#include <stdio.h>
#include <math.h>

/*Program: Bit rotation
  By Anando Zaman
*/
int rotateright(int n, unsigned int d){
    int right = n >> d;
    int left = n << (bits_length(n)-d);
    return (right | left);
}

int rotateleft(int n, unsigned int d){
    int right = n >> (bits_length(n)-d);
    int left = n << d;
    return (right | left);
}

int bits_length(int n){

    return (int)log2(n)+1; //since binary is base 2,
                                //we can just take the log of the number and convert it to a whole number.
                                //Add 1 since theres always atleast one bit no matter the number inputted
}

int bits_length_iterative(int n){ /*Alternative method to finding bits_length*/
    /*ie; 13/2 = 6, 6/2=3, 3/2=1, end while loop. count value is now 4, so 4 bits. Essentially, as if going through each binary bit and keeping track of how many there are*/
    int count = 1;
    while(n != 1){
        count++;
        n = n/2;
    }
    return count;
}


int main(){

    //printf("%d",bits_length(4));
    printf("%d",rotateleft(4<<1));
    /*
    OUTPUT for rotateleft(4,1)
    bits_length is 3
    Binary representation of the number 4 is 100,
    left shift by 1 = 1 000
    right shift by (3-1) = 001. We did 3-1 since 3 is the bit_length of the number 4
    Now ORing them together yields 1000 | 001 = 1001 = 9. Since our bits_length is 3, we can ignore the left most bit which yields 001.
    Thereby, successfully rotating the bits left by 1 bit
    */

return 0;
}
