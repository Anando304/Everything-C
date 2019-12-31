#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
/*Question 1: Fractal trees
              NAME: Anando Zaman
              DATE: November 24,2019
              COURSE: SFTWRENG 2S03*/
int fib_length(int n){
   if (n <= 1)
      return n;
   return fib_length(n-1) + fib_length(n-2);
}

char* fibWord(int n, int fib_length_value)
{
    char* res_fibword = (char*) malloc(sizeof(char)*fib_length_value); /* Pointer to allocate memory for fibword */
    *res_fibword = (char){0};

    char* res_tempA = (char*) malloc(sizeof(char)*fib_length_value); /* Temporary variable used to store strings*/
    *res_tempA = (char){0};

    char* res_tempB = (char*) malloc(sizeof(char)*fib_length_value);
    *res_tempB = (char){0};

    char* res_temp_COMBINED = (char*) malloc(sizeof(char)*fib_length_value); /*Temporary variable used to combine string*/
    *res_temp_COMBINED = (char){0};

    /* return 0 if memory cannot be allocated */
    if ((res_fibword == NULL) || (res_tempA == NULL) || (res_tempB == NULL) || (res_temp_COMBINED == NULL) ) {
        return 0;
    }

    /*Assign variable values for first and second characters of fib word */
    strcpy(res_tempA,"1");
    strcpy(res_tempB,"0");

    int i;
    for (i=2; i<n; i++)
    {
        strcpy(res_temp_COMBINED,res_tempB);
        strcat(res_temp_COMBINED,res_tempA);

        *res_tempA = (char){0};
        strcpy(res_tempA,res_tempB);

        *res_tempB = (char){0};
        strcpy(res_tempB,res_temp_COMBINED);

        if (i == (n-1)){ /* Save the value to the fibword char pointer*/
            strcpy(res_fibword,res_temp_COMBINED);
        }

        *res_temp_COMBINED = (char){0};
    }
    return res_fibword;
}


void draw(int x, int y, int direction, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (direction == UP)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (direction == DOWN)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (direction == RIGHT)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (direction == LEFT)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}



int fib(int n, int x, int y, int step , RGB bc , RGB fc , int w, int h, RGB* image){

    int count = 1;
    int fib_length_value = fib_length(n);
    char* result = fibWord(n, fib_length_value);
    /*image = malloc(sizeof(RGB) * w * h);*/

    /* return 0 if memory cannot be allocated */
    if (image == NULL) {
        return 0;
    }

    /* set background */
    int i;
    for (i = 0; i < w * h; i++){
        image[i] = bc;
    }



    draw(x, y, UP, step, w, image, fc);
    x += step;

    int direction = RIGHT;
    int old_direction = UP;

    if ((x >= h) || (y >= w) || (x <= 0) || (y <= 0)){
        return 0;
    }

    /*Required loop to filter through fractals and print the pattern */
    int z;
    for (z = 0; z<fib_length_value-1;z++){

        if ((x >= h) || (y >= w) || (x <= 0) || (y <= 0)){
            return 0;
        }


        if((result[z] == '0') && (count % 2 == 1) && (direction == UP)){ /* ODD-UP */
            draw(x, y, direction, step, w, image, fc);
            x += step;

            /*Reset previous directions and update to new ones */
            old_direction = UP;
            direction = RIGHT;
        }


        else if((result[z] == '0') && (count % 2 == 0) && (direction == UP)){ /* EVEN-UP */
            draw(x, y, DOWN, step, w, image, fc);
            x -= step;

            /*Reset previous directions and update to new ones */
            old_direction = DOWN;
            direction = LEFT;
        }


        else if((result[z] == '1') && (old_direction == UP)){ /* CONTINUE ODD-UP */
            draw(x, y, old_direction, step, w, image, fc);
            x += step;

        }

        else if((result[z] == '1') && (old_direction == DOWN)){ /* CONTINUE EVEN-UP */
            draw(x, y, old_direction, step, w, image, fc);
            x -= step;

        }




        else if((result[z] == '0') && (count % 2 == 1) && (direction == RIGHT)){ /* ODD-RIGHT */
            draw(x, y, direction, step, w, image, fc);
            y += step;

            old_direction = RIGHT;
            direction = DOWN;
        }


        else if((result[z] == '0') && (count % 2 == 0) && (direction == RIGHT)){ /* EVEN-RIGHT */

            draw(x, y, LEFT, step, w, image, fc);
            y -= step;

            old_direction = LEFT;
            direction = UP;
        }

        else if((result[z] == '1') && (old_direction == RIGHT)){ /* CONTINUE ODD-RIGHT */
            draw(x, y, old_direction, step, w, image, fc);
            y += step;
        }

        else if((result[z] == '1') && (old_direction == LEFT)){ /*CONTINUE EVEN-RIGHT */
            draw(x, y, old_direction, step, w, image, fc);
            y -= step;

        }


        else if((result[z] == '0') && (count % 2 == 1) && (direction == LEFT)){ /*ODD-LEFT */
            draw(x, y, direction, step, w, image, fc);
            y -= step;

            old_direction = LEFT;
            direction = UP;
        }

        else if((result[z] == '0') && (count % 2 == 0) && (direction == LEFT)){ /* EVEN-LEFT */
            draw(x, y, RIGHT, step, w, image, fc); /*FOR EVENS, FLIP THE DIRECTION THAT THE DIRECTION SAYS TO GO BECAUSE THAT DIRECTION IS FOR GOING ODD ONLY */
            y += step;

            old_direction = RIGHT;
            direction = DOWN;
        }

        else if((result[z] == '1') && (old_direction == LEFT)){ /* CONTINUE ODD-LEFT */
            draw(x, y, old_direction, step, w, image, fc);
            y -= step;

        }

        else if((result[z] == '1') && (old_direction == RIGHT)){ /* CONTINUE EVEN-LEFT */
            draw(x, y, old_direction, step, w, image, fc);
            y += step;

        }

        else if((result[z] == '0') && (count % 2 == 1) && (direction == DOWN)){ /* ODD-DOWN */
            draw(x, y, direction, step, w, image, fc);
            x -= step;

            old_direction = DOWN;
            direction = LEFT;
        }

        else if((result[z] == '0') && (count % 2 == 0) && (direction == DOWN)){ /* EVEN-DOWN */
            draw(x, y, UP, step, w, image, fc);
            x += step;

            old_direction = UP;
            direction = RIGHT;
        }

        else if((result[z] == '1') && (old_direction == DOWN)){ /* CONTINUE ODD-DOWN */
            draw(x, y, old_direction, step, w, image, fc);
            x -= step;

        }

        else if((result[z] == '1') && (old_direction == UP)){ /* CONTINUE EVEN-DOWN */
            draw(x, y, old_direction, step, w, image, fc);
            x += step;

        }


        count++;

    }

    return count;
}



