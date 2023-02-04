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
    printf("Tasks 3a, 3b and 3c:\n");
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

    printf("\nSum of even numbers between 1 - 1000 is: %d\n", sumOfEvenNumbers);

    //3c - Generate random int. between 2 and 20, multiply it with itself before integer overflow.
    srand(time(NULL));
    int upper = 20;
    int lower = 2;
    int generatedNumber = rand() % (upper - lower +1) + lower;
    printf("\nGenerated number between 2 and 20 is: %d\n", generatedNumber);

    int maxLimit = (int) sqrt((float)INT_MAX);        // Max integer value that the variable can hold

    do {
        printf("Integer is: %d and its product by itself: %d\n", generatedNumber, generatedNumber*generatedNumber);
        generatedNumber *= generatedNumber;
    }
    while 
        (generatedNumber <= maxLimit); // Checks if the product is under the maxLimit that the variable can hold.



    //4 - Generate a random number under 100 and generate Collatz sequence 
    printf("\nTask 4: Collatz Sequence");

    srand(time(NULL));
    int collatz_upper = 100;
    int collatz_lower = 1;
    int collatzNumber = rand() % (collatz_upper - collatz_lower + 1) + lower;
    printf("\nThe number generated for collatz sequence is: %d\n", collatzNumber);
    
    int counter = 1;

    printf("Collatz sequence for number %d is: %d", collatzNumber, collatzNumber);
    while (collatzNumber > 1){

        if (collatzNumber % 2 == 0){
            collatzNumber /= 2;
            counter += 1;
            printf(", %d", collatzNumber);
        }else{
            collatzNumber = collatzNumber * 3 + 1;
            counter += 1;
            printf(", %d", collatzNumber);
        }
    }
    printf("\nLength of the collatz sequence is %d", counter);


    return 0;

}