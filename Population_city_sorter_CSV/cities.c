#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NAME: ANANDO ZAMAN
   QUESTION 4: QSORT CITIES
   COMPLETED: NOVEMBER 25,2019
*/
typedef struct {
    char city[30];
    char country[30];
    int population;

}city;

int comparer(const void* a, const void* b){
    city *ca = (city*) a; /*Parses the void parameters to type city which can be used for comparison in qsort */
    city *cb = (city*) b;
    return ca->population - cb->population;

}

char* getColumn(char* row, int col)
{
    char* element;
    for (element = strtok(row, ","); element && *element; element = strtok(NULL, ",\n")) /*Each column is seperated by a comma, so use strtok to seperate at commas and do it until hits breaker or newline*/
    {
        if (!--col)
            return element;
    }
    return NULL;
}


int number_of_rows(){
    FILE *data_read = fopen("cities.csv", "r");
    char character;
    int length = 0;
    /* Extract characters from file and store in character c */
    while( (character=getc(data_read)) !=EOF ){
        if(character == '\n'){
            length++;
        }
    }
    fclose(data_read);
    return length;
}

int main()
{
    int LENGTH_OF_FILE = number_of_rows();
    FILE* data = fopen("cities.csv", "r");
    city result[LENGTH_OF_FILE]; /*An array of city nodes*/


    char row[LENGTH_OF_FILE];
    int index = 0;
    while (fgets(row, LENGTH_OF_FILE, data)) /*Scans the entire line from stream and saves it into an array of max size of 512. Keeps overwriting for each line read*/
    {
        /* REQUIRED TO HAVE THIS SINCE READING EACH COLUMN CAUSES THE MEMORY TO BE MODIFIED LIKELY REMOVED*/
        char* row_copy1 = (char*)malloc(sizeof(char*) * LENGTH_OF_FILE);
        if (row_copy1 == NULL) return 0;
        strcpy(row_copy1,row);
        char* row_copy2 = (char*)malloc(sizeof(char*) * LENGTH_OF_FILE);
        if (row_copy2 == NULL) return 0;
        strcpy(row_copy2,row);

        char* city_name = (char*)malloc(sizeof(char*) * LENGTH_OF_FILE);
        if (city_name == NULL) return 0;          /* if memory cannot be allocated */
        strcpy(city_name, getColumn(row, 2));     /* Copy each column value */

        char* pop = (char*)malloc(sizeof(char*) * LENGTH_OF_FILE);
        if (pop == NULL) return 0;
        strcpy(pop, getColumn(row_copy1, 5));

        char* country = (char*)malloc(sizeof(char*) * LENGTH_OF_FILE);
        if (country == NULL) return 0;

        strcpy(country, getColumn(row_copy2, 6));


        if(index!=0){
        strcpy(result[index].city, city_name);
        strcpy(result[index].country,country);
        result[index].population = atoi(pop); /* atoi saves as an integer in the struct */
        }


        free(city_name);
        free(pop);
        free(country);
        row_copy1 = (char*){0};
        row_copy2 = (char*){0};

        index++;
    }
    fclose(data);

    FILE *output = fopen("sorted.csv", "w");
    if (output == NULL) return 0;

    qsort (result, LENGTH_OF_FILE, sizeof(city), comparer );
    int i;
    for (i = LENGTH_OF_FILE-1; i>1; i--){
        fprintf(output, "%s,%d,%s\n", result[i].city, result[i].population, result[i].country);
    }
    fclose(output);
    return 0;
}
