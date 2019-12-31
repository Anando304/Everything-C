#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 30

//Counts number of occurences of a word in a file

int main() {

    FILE *text = fopen("hamlet.txt", "r");

    char search_word[] = "hamlet";
    char current_word[MAX_WORD_LENGTH];
    int count = 0;

    //fscanf(stdin, "%s", current_word); /* Reads words from a file*/
    //fprintf(stdout, "%s\n", current_word);

     while (!feof(text)) { /* Reads files until end of text*/
         fscanf(text, "%s", current_word);

         if (!strcasecmp(current_word, search_word)) /* If string compared is used and correct, then increment count*/
             count++;
     }

     printf("%d\n", count);
}
