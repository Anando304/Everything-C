#include <stdio.h>
#include <string.h>
/*Program: Reverse a string using bitwise XOR
  By Anando Zaman

  Example:
  Reverse the string 'abcdef' without using a temporary variable
  first loop yields: fbcdea
  second loop yields: fecdba
  third loop yields: fedcba, At this point, start is at index 2, and end is at index 3
  However, at the end of the last iteration, the start changes to 3 while end changes to 2
  The while loop ends and the resultant string is 'fedcba'

  How does using XOR make this work?
  Recall XOR property of a^a = 0
  Also, XOR is both commutative and associative.
  For the first iteration of the loop, we have...

  str[0] = a^f
  str[5] = f ^ (a^f)
           = (f^f) ^ a
           = 0 ^ a
           = a
  str[0] = (a^f) ^ a
             = a^a^f
             = 0^f
             = f
  So now str[0] = 'f' while str[5] = 'a'
  This process continues while start<end
*/

void reverseString(char *str,int start, int end){
    while(start<end){
        str[start] = str[start]^str[end];
        str[end] = str[end]^str[start];
        str[start] = str[start]^str[end];

        start++;
        end--;
    }

}

int main(){
    char str[] = "abcdefgH";
    printf("Original string: %s\n",str);

    reverseString(str,0,strlen(str)-1);
    printf("Reversed string: %s\n",str);
}
