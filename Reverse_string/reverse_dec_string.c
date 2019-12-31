#include <stdio.h>
#include <string.h>

//Program: Reverse_dec_string
//By Anando Zaman
//Completed: 09/21/2019

int RightlastZero(char Input1[80], int length){
int i;
for(i = length - 1; i>=0; i--){

    if((Input1[i] == '0') && (Input1[i-1] != '0')){ //For removing leading 0's
        //printf("Input[%d] \n",i - 1);
        return i-1;
    }


    else if(Input1[i] != '0'){ //If starts with non-zero character
        //printf("Input[%d] \n",i);
        return i;
    }

}
}

int LeftlastZero(char Input1[80], int length){
int i;
for(i = 0; i<=length; i++){

    if((Input1[i] == '0') && (Input1[i+1] != '0')){ //If starts with leading 0's, then look for where first non-zero element is and save/return the index
        //printf("Input[%d] \n",i + 1);
        return i+1;
    }

    else if(Input1[i] != '0'){ //If starts with no leading 0's
    //printf("Input[%d] \n",i);
    return i;
    }

}
}



int main(){
char Input1[80];
char reversed[80] = "";
int reversedIndex = 0;

int start;
int end;


printf("Enter an integer: ");
scanf("%s", &Input1);
int length = strlen(Input1);

if (length>20){ //If length is greater than 20, then set length to 20 to be able to reverse first 20 characters. Note length of 20 means 0 to 19 indices
    length = 20;
}

end = RightlastZero(Input1,length);
start = LeftlastZero(Input1,length);

int x;
for (x = end; x>=start; x--){
    reversed[reversedIndex] = Input1[x];
    //printf("%c",Input1[x]);
    reversedIndex += 1;
}
printf("%s",reversed);


return 0;


}




