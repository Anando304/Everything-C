#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel{
    unsigned char r,g,b;
}Pixel;

typedef struct image{
unsigned int width,height ,max;
Pixel** data;
}Image;

void printPPM(Image *image){
    for (int i = 0; i<image->height; i++){
         for (int j = 0; j<image->width; j++){
            //printf("#%o2x%02x%02x ", image->data[i][j].r,image->data[i][j].g,image->data[i][j].b);

         }
         printf("\n"); //fscanf returns number of words seperated by spaces or newline. This is why it can seperate by spaces without any other issues
                        //%hhu is for storing number of unsigned character of large value
                        //strcmp compares strings and characters directly
    }

}

Image *readPPM(char *file_name){
    FILE *file = fopen(file_name,"r");
    if (!file){
        fprintf(stderr,"Unable to open file %s \n", file_name);
        return NULL;
    }
    char format[3];
    fscanf(file,"%s\n",format);
    if(strcmp(format,"P3")){
        return NULL;
    }

    Image *image = malloc(sizeof(Image));

    if (fscanf(file, "%u %u %u", &image->width,&image->height,&image->max) != 3){ //Since this part is for getting these 3 paramaters only.
        return NULL;
    }

    image->data = malloc(sizeof(Pixel *) * image->height);
    for (int i = 0; i<image->height; i++){
        image->data[i] = malloc(sizeof(Pixel)* image->width);
    }

    for(int i = 0; i < image->height; i++){
        for(int j = 0; j<image->width; j++){
            int pixels_read = fscanf(file,"%hhu %hhu %hhu", &(image->data[i][j].r),&(image->data[i][j].g),&(image->data[i][j].b));

            if (pixels_read != 3){
                return NULL;
            }
        }
    }
    fclose(file);
    return image;
}

int writePPM(char *file_name, Image *image){

    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        fprintf(stderr,"Unable to open file %s \n", file_name);
        return -1;
    }

    fprintf(file,"P3\n");
    fprintf(file,"%u %u\n",image->width,image->height);
    fprintf(file,"%u\n",image->max);


    for(int i = 0; i < image->height; i++){
        for(int j = 0; j<image->width; j++){
            fprintf(file, "%u %u %u ", image->data[i][j].r,image->data[i][j].g,image->data[i][j].b); /*Writing to the file */
            }
        fprintf(file, "\n");
        }
    fclose(file);
    return 0;
    }

int main(){
    Image *image = readPPM("car.ppm");
    if(image == NULL){
        return -1;
    }
    printf("%d",image->data[0][0].b);
    //printPPM(image);


}
