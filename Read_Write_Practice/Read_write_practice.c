#include <stdio.h>
//fgets(buffer,filename,strlen)
//safer than gets()
// Read the data from data.csv and output formatted as below

// Item                 Unit Price           Purchase date
// 583                  $  13.50             2005/10/24
// 3912                 $ 599.99             2008/7/27

int main()
{

    FILE *data = fopen("data.csv", "r");
    if(!data)
        printf("Unable to open data");
    FILE *output = fopen("data1.csv", "w"); //w is for write, a is for append, r is for read

    unsigned int item, year, month,day;
    double price;

    printf("%-20s %-20s\n", "Item", "Unit price", "Purchased data");

                //stdin
    while (fscanf(data,"%u,%lf,%4u/%2u/%2u",&item, &price,&year,&month,&day) != EOF){

        printf("%-20u, $ %6.2lf              %u/%u/%u\n",item,price,year,month,day);
    }
}
