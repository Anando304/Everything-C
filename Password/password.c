#include <stdio.h>
#include <string.h>

//Historically, compilers had an issue that if you had a buffer and you add chars that are greater than the buffer length, the data will be
//overflowed resulting in data to be written to other variable blocks such as pass. So if you entered the wrong passcode here and
//length was greater than buffer, the additional data would be written to pass causing it to become 1, and granting root priviledges.

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    if(strcmp(buff, "thegeekstuff"))
    {
        printf ("\n Wrong Password \n");
    }
    else
    {
        printf ("\n Correct Password \n");
        pass = 1;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("\n Root privileges given to the user \n");
    }

    return 0;
}

// gcc overflow.c -fno-stack-protector
// hhhhhhhhhhhhhhhhhhhh
