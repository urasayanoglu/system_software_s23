/*
File:           Exercise3.c
Author:         Uras Ayanoglu 
Description:    Tasks 3,4, and 5 for Exercise 3 of System Software course by Sanna Määttä.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main(void){

    //3a - Count the sum of numbers 1-100
    
    int sumOfNumbers = 0;

    for (int i=1; i<101; i++) {
        sumOfNumbers += i;
    }

    printf("Sum of numbers between 1 - 100 is: %d", sumOfNumbers);

    //3b - Count the sum of even numbers between 1-1000

    int sumOfEvenNumbers = 0;

    for (int i = 2; i < 1002; i=i+2){
        sumOfEvenNumbers += i;
    }

    printf("\nSum of even numbers between 1 - 1000 is: %d", sumOfEvenNumbers);

    //3c - Generate random int. between 2 and 20, multiply it with itself before integer overflow.
    srand(time(NULL));
    int upper = 20;
    int lower = 2;
    int generatedNumber = rand() % (upper - lower +1) + lower;
    printf("\nGenerated number between 2 and 20 is: %d\n", generatedNumber);

    int maxLimit = (int) sqrt((float)INT_MAX);        // Max integer value that the variable can hold

    do {
        printf("\nInteger is: %d and its product by itself: %d", generatedNumber, generatedNumber*generatedNumber);
        generatedNumber *= generatedNumber;
    }
    while 
        (generatedNumber <= maxLimit); // Checks if the product is under the maxLimit that the variable can hold.






    return 0;
}