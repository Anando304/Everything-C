#include <stdio.h>

/*Program: Custom Calendar days
By Anando Zaman*/

/*A C program that prints a calendar for you given the number of days of the month
  and the starting day of the week

  Example:
    Enter # of days in the month: 30
    Enter starting day of the week (1=Sun, 7=Sat) 2

         1  2  3  4  5  6
      7  8  9 10 11 12 13
     14 15 16 17 18 19 20
     21 22 23 24 25 26 27
     28 29 30
  */
int main(){

    int days,start;
    printf("Enter # of days in the month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat)");
    scanf("%d", &start);

    /* Spaces before start */
    printf("\n");
    for (int i = 0; i<start; i++){
        printf("  ");
    }

    /* Calendar days */
    int first_week = 1; /*To keep track of first week */
    int day_of_week_counter = 0;

    for (int j = 1; j <= days; j++){
        printf("%3d",j);

        if((first_week == 1) && (day_of_week_counter == (7-start))){ /* Prints for first week */
            printf("\n");
            first_week = 0; /* sets to 0 to print for following weeks */
            day_of_week_counter = 0;
        }

        else if (day_of_week_counter == 7){ /* Printing for following weeks */
            printf("\n");
            day_of_week_counter = 0;
        }
        day_of_week_counter++;

    }
    return 0;

}
