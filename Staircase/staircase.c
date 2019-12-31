#include <stdio.h>
#include <string.h>

//Problem #2: Staircase2
//By Anando Zaman
//Completed: 09/21/2019

/*Example:
Enter number of: staircases, stairs, rows: 12 3 4

OUTPUT:
  3   3   3   3
 33  33  33  33
333 333 333 333
  3   3   3   3
 33  33  33  33
333 333 333 333
  3   3   3   3
 33  33  33  33
333 333 333 333

*/

int printer2(unsigned int stairsPerRow, unsigned int stairs){
    int stairsIndex;
    int i;
    int y;
    int z;
    char StairCharacter[1]; //Character that is to be printed to the screen

    sprintf(StairCharacter,"%u",stairs); //Convert number of stairs per staircase inputed to a character known as StairCharacter



    char StairCharacterArray[9][11]; // in the form {"       7 ", "      77 ",...etc}. Will keep track of all the possible forms printed of a character for the staircase. Can hold a max of 9 strings



    char stairsToInsert[11]; //Will be modified in a loop to get the desired characters, then inserted into the array

    //Creates an empty string of length stairs
    for (z = 0; z<stairs; z++){
        stairsToInsert[z] = ' ';
    }
    stairsToInsert[stairs] = ' '; // Adds a space to the end
    stairsToInsert[stairs + 1] = '\0'; //prevent unassigned indices from printing after


    //Modifies stairsToInsert String-array and then inserts it to the 2D StairCharacterArray character array(AKA, array of strings)
    for (y = stairs - 1; y >=0; y--){
        stairsToInsert[y] = StairCharacter[0];
        strcpy(StairCharacterArray[abs(y-(stairs-1))], stairsToInsert);

    }

    //Prints out the triangles for a single row
    for(stairsIndex = 0; stairsIndex < stairs; stairsIndex++){ // For each stair value, print it as many times until reach stairsPerRow. Then repeat it for next stair value(ie;       77)
        for (i = 0; i<stairsPerRow; i++){

            printf("%s", StairCharacterArray[stairsIndex]);
            if (i+1 == stairsPerRow){
                printf("\n");
            }
        }
    }

}

int main(){
unsigned int NumberOfStaircases = 0;
unsigned int Number_Of_Stairs_Per_Staircase = 0;
unsigned int StaircasesPerRow = 0;

printf("Enter number of: staircases, stairs, rows: ");
scanf("%u %u %u", &NumberOfStaircases,&Number_Of_Stairs_Per_Staircase,&StaircasesPerRow);


    if((Number_Of_Stairs_Per_Staircase > 9) || (Number_Of_Stairs_Per_Staircase < 1)){ //Check if Number_Of_Stairs_Per_Staircase is WITHIN RANGE
        printf("m=%u, must be in [1,9]",Number_Of_Stairs_Per_Staircase);
        return 1; //Ends the function from executing further
    }

    if((StaircasesPerRow > 100) || (StaircasesPerRow < 1)){ //Check if StaircasesPerRow is WITHIN RANGE
        printf("p=%u, must be in [1,100]",StaircasesPerRow);
        return 1; //Ends the function from executing further if NOT WITHIN RANGE
    }

    if((NumberOfStaircases<=100) && (NumberOfStaircases>=0)){
        while(NumberOfStaircases > 0){

        if(NumberOfStaircases >= StaircasesPerRow){
            printer2(StaircasesPerRow, Number_Of_Stairs_Per_Staircase);
            }

        if((NumberOfStaircases < StaircasesPerRow)){
            printer2(NumberOfStaircases, Number_Of_Stairs_Per_Staircase);
            return 0;
        }
        NumberOfStaircases = NumberOfStaircases - StaircasesPerRow;

        }
        return 0;
    }

    else{
        printf("n=%u, must be in [0,100]",NumberOfStaircases);
        return 1;
    }

}
