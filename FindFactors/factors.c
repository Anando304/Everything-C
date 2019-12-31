#include <stdio.h>
#include <string.h>

//Program: Finding_factors
//By Anando Zaman
//Completed: 09/21/2019
unsigned long int LCM(unsigned long int Input1, unsigned long int Input2){

unsigned long int multiple1 = Input1; //Set Default multiples to original values
unsigned long int multiple2 = Input2;

//********************Finds the LCM
while(1){
    //To Find LCM, find out which variable is smaller and find its multiples.
    //Do this back and forth until you get the LCM
    if(multiple1 > multiple2){
        multiple2 += Input2;
    }

    else if(multiple2 > multiple1){
        multiple1 += Input1;
    }


    else{

        return multiple1;
    }
}
}




//**********************Finds GCF
unsigned long int GCF(unsigned long int Input1, unsigned long int Input2){
    unsigned long int Factors_input1;
    unsigned long int Factors_input2;

    if(Input1 < Input2){ /*If Input1 is smaller, then find the factors of it first from largest to smallest and check if its also a factor of the larger number
                        Its more difficult to do it the other way around because if going from smaller to larger factors, then you have to keep track of all the factor
                        whereas going from larger to smaller, you take the first factor that is a match since it's already the largest. */
        int i;
        for(i = Input1; i>=1; i--){
            if (Input1 % i== 0){ //if it is a factor, then modulus outputs 0
                if(Input2 % i == 0){ //check if the factor i is also a factor of Input2

                    return i; //This is the GCF
                }
            }

        }

    }

    else if(Input2 < Input1){
        int i;
        for(i = Input2; i>=1; i--){
            if (Input2 % i == 0){
                if(Input1 % i == 0){

                    return i; //This is the GCF
                }
            }

        }

    }

    else{ //When Input1 and Input2 are the same

        return Input1;
    }

}


//**********************Finds all factors
unsigned long long int Factors(unsigned long int Input1, unsigned long int Input2){
    unsigned long int Factors_input1;
    unsigned long int Factors_input2;
    unsigned long long int sumfactors = 0;
    printf("Common factors of (%lu, %lu): ",Input1, Input2);
    if(Input1 <= Input2){

        unsigned long long int i;
        for(i = 1 ; i<=Input1; i++){
            if (Input1 % i== 0){ //if it is a factor, then modulus outputs 0
                if(Input2 % i == 0){ //check if the factor i is also a factor of Input2
                    sumfactors += i;
                    printf("%llu ",i);
                }
            }

            if(i == Input1){
                return sumfactors;
            }

        }

    }

    else if(Input2 <= Input1){
        unsigned long long int i;
        for(i = 1; i<=Input2; i++){
            if (Input2 % i == 0){
                if(Input1 % i == 0){
                    sumfactors += i; //Keeps track of the sum of the factors
                    printf("%llu ",i);

                }
            }
            if(i == Input2){
                return sumfactors;
            }


        }

    }


}





unsigned long int main(){
unsigned long int Input1;
unsigned long int Input2;


printf("Enter two positive integers: ");
scanf("%lu %lu", &Input1,&Input2);


unsigned long long int sum = 0;


sum = LCM(Input1,Input2) + GCF(Input1,Input2) + Factors(Input1,Input2);
printf("\nLCM: %lu \n",LCM(Input1,Input2));
printf("GCF: %lu \n",GCF(Input1,Input2));


printf("sum: %llu",sum);

return 0;
}
//*******************************



