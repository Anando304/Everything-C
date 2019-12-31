#include <stdio.h>
#include <string.h>

/*Author: Anando Zaman
Date: October 2, 2019
Problem #3: Path Finding Algorithm*/

/* Problem Overview*/
/* Implementation of a recursive algorithm to find the path */
/* Uses Depth-First Search(DFS) implementation to find a possible path */
/* Creates a duplicate array that can be modified by placing previous path values to '2' for backtracking */
/* Finds a path from coordinates (i,j) to (k,l) */

/* Returns :
-1: if A[i][j] == 1 || A[k][l] == 1
-2: if i < 0 || i >= n
-3: if j < 0 || j >= m
 2: if path exists
 0: if NO path exists */

 /* Example:
 int A[] = {0,0,1,0,0,0,
            1,0,0,0,1,1,
            1,0,1,0,1,0,
            1,0,1,0,0,0};

//Does a path of 0's exist from (0,0) to (2,5)?
//Returns: 2, since a path does exist
*/

/* Explicit declaration of functions to avoid implicit declaration warnings */
int movements(int n, int m, int A_temp[], int i, int j, int k, int l, int path [][2],int old_i,int old_j);
int backtrack(int n, int m, int A_temp[], int i, int j, int k, int l, int path [][2],int old_i,int old_j);

int find_path(int n, int m, int A[], int i, int j, int k, int l, int path [][2]){


    int old_i = i;
    int old_j = j;

    int size_A = n*m;
    int A_temp[size_A];

    /* Creates a copy of A[] as A_temp */
    int s = 0;
    for (s = 0; s<size_A;s++){
        A_temp[s] = A[s];
    }

    /* Function return cases from Assignment PDF */
    /* Case I */
    if((A_temp[(i * m) + j] == 1) || (A_temp[(k * m) + l] == 1)){

        return -1;
    }

    /* Case II */
    else if((i<0) || (i>=n)){

        return -2;
    }

    /* Case III */
    else if((j<0) || (j>=m)){

        return -3;
    }

    /* Case IV */
    else if((i==k) && (j==l) && (A_temp[(i * m) + j] == 0) && (A_temp[(k * m) + l] == 0) ){

        return 1;
    }

    /* Check for path */
    return movements(n, m, A_temp, i, j, k, l, path,old_i,old_j);



}

int movements(int n, int m, int A_temp[], int i, int j, int k, int l, int path [][2],int old_i,int old_j){

/* Note: Both right and left movements need a right_last and left_last respectively due to the right and left boundaries. */
    int r = 0;

    if((A_temp[((i-1) * m) + j] == 0) && (i-1 >=0)) { /* check UP */
        A_temp[(i * m) + j] = 2; /* set old position to 2 for backtracking */

        old_i = i;
        old_j = j;

        if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }

        return movements(n, m, A_temp, i-1, j, k, l, path, old_i,old_j);

    }


    else if((A_temp[(i * m) + j + 1] == 0) && (j<=m)){ /* Check Right */
        A_temp[(i * m) + j] = 2;

        old_i = i;
        old_j = j;

        if((old_i == k) && (old_j == l)){ /* Path exists */
            r = 2;
            return r;
        }

       return movements(n, m, A_temp, i, j+1, k, l, path, old_i,old_j);

    }



        else if((A_temp[(i * m) + j] == 0) && (j<=m)){ /* Check Right_LAST */
        A_temp[(i * m) + j] = 2;

        old_i = i;
        old_j = j;

            if((old_i == k) && (old_j == l)){ /* Path exists */

                r = 2;
                return r;
            }

       return movements(n, m, A_temp, i, j, k, l, path, old_i,old_j);

    }




    else if((A_temp[((i+1) * m) + j] == 0) && (i+1 <= n)){ /* Check DOWN */
        A_temp[(i * m) + j] = 2;

        old_i = i;
        old_j = j;


        if((old_i == k) && (old_j == l)){ /* Path exists */
            r = 2;
            return r;
        }

        return movements(n, m, A_temp, i+1, j, k, l, path, old_i,old_j);

    }

    else if((A_temp[(i * m) + j - 1] == 0) && (j>=0)){ /* Check Left */
        A_temp[(i * m) + j] = 2;

        old_i = i;
        old_j = j;


        if((old_i == k) && (old_j == l)){ /* Path exists */
            r = 2;
            return r;
        }


        return movements(n, m, A_temp, i, j-1, k, l, path, old_i,old_j);

    }


        else if((A_temp[(i * m) + j] == 0) && (j>=0)){ /* Check Left_Last */
        A_temp[(i * m) + j] = 2;

        old_i = i;
        old_j = j;

            if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }

        return movements(n, m, A_temp, i, j, k, l, path, old_i,old_j);

    }

    else{

        return backtrack(n, m, A_temp, i, j, k, l, path, old_i,old_j);

    }

}


int backtrack(int n, int m, int A_temp[], int i, int j, int k, int l, int path [][2],int old_i,int old_j){

/*Backtrack when hits dead end by referring back to the 2's and makes successor elements change from 2 to a 1 */
        int r = 0;
        if((A_temp[((i-1) * m) + j] == 2) && (i-1 >=0)) { /* checks UP element */
        A_temp[(i * m) + j] = 1; /* set old position to 2 for backtracking */

        old_i = i;
        old_j = j;

        if((old_i == k) && (old_j == l)){ /* Path exists and reached said path */
                r = 2;
                return r;
        }

        return movements(n, m, A_temp, i-1, j, k, l, path, old_i,old_j);

    }


    else if((A_temp[(i * m) + j + 1] == 2) && (j<=m)){ /* Check Right */
        A_temp[(i * m) + j] = 1;

        old_i = i;
        old_j = j;

                if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }

       return movements(n, m, A_temp, i, j+1, k, l, path, old_i,old_j);
    }



        else if((A_temp[(i * m) + j] == 2) && (j<=m)){ /* Check Right_LAST */
        A_temp[(i * m) + j] = 1;

        old_i = i;
        old_j = j;

                if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }
       return movements(n, m, A_temp, i, j, k, l, path, old_i,old_j);
    }




    else if((A_temp[((i+1) * m) + j] == 2) && (i+1 <= n)){ /* Check DOWN */
        A_temp[(i * m) + j] = 1;

        old_i = i;
        old_j = j;

        if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }


        return movements(n, m, A_temp, i+1, j, k, l, path, old_i,old_j);

    }

    else if((A_temp[(i * m) + j - 1] == 2) && (j>=0)){ /* Check Left */
        A_temp[(i * m) + j] = 1;

        old_i = i;
        old_j = j;


        if((old_i == k) && (old_j == l)){ /* Path exists */
                r = 2;
                return r;
        }


        return movements(n, m, A_temp, i, j-1, k, l, path, old_i,old_j);


    }


        else if((A_temp[(i * m) + j] == 2) && (j>=0)){ /* Check Left_Last */
        A_temp[(i * m) + j] = 1;

        old_i = i;
        old_j = j;

            if((old_i == k) && (old_j == l)){ /* Path exists */

                r = 2;
                return r;
        }

        return movements(n, m, A_temp, i, j, k, l, path, old_i,old_j);

    }

    else{ /* If no path exists after backtracking and attempt at finding alternative routes */

        r = 0;
        return r;
    }

    return r;

}


int main(){
    int path[][2] = {0};

    /*Example 1

    int A[] = {0,1,0,0,
               1,0,0,1,
               1,0,1,0};
    find_path(3, 4, A, 1, 1, 0, 3, path);*/


    /*Example 2
    int A[] = {1,0,1,0,
               1,0,0,1,
               1,0,1,0};

    return find_path(3, 4, A, 2, 1, 0, 0, path);*/



    int A[] = {0,0,1,0,0,0,
           1,0,0,0,1,1,
           1,0,1,0,1,0,
           1,0,1,0,0,0};

    return (find_path(4, 6, A, 0, 0, 2, 5, path));
}
