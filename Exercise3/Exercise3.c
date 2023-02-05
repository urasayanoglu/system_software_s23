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

// Function declarations:
int isFibonacci(int number);

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
    // int generatedNumber = -3;                   // Test case
    printf("\nGenerated number between 2 and 20 is: %d\n", generatedNumber);

    int maxLimit = (int) sqrt((float)INT_MAX);        // Max integer value that the variable can hold

    if (generatedNumber == 1 || generatedNumber == 0) {
        printf("Integer is %d, and the sequence its squares and their squares is %d, %d, %d, ...\n", generatedNumber, generatedNumber, generatedNumber, generatedNumber);           
    }
    else if (generatedNumber == -1) {
        printf("Integer is -1, and the sequence of its squares and their squares is 1, 1, 1, ...\n"); 
    }
    else {
        do {
            printf("Integer is: %d and its product by itself: %d\n", generatedNumber, generatedNumber*generatedNumber);
            generatedNumber *= generatedNumber;
        }
        while 
            (generatedNumber <= maxLimit); // Checks if the product is under the maxLimit that the variable can hold.
    }



    //4 - Generate a random number under 100 and generate Collatz sequence 
    printf("\nTask 4: Collatz Sequence");

    srand(time(NULL));
    int collatz_upper = 100;
    int collatz_lower = 1;
    int collatzNumber = rand() % (collatz_upper - collatz_lower + 1) + lower;
    // int collatzNumber = 0;              // test case
    printf("\nThe number generated for Collatz sequence is: %d\n", collatzNumber);
    
    int counter = 1;

    if (collatzNumber < 1) {
        printf("There is no Collatz sequence for numbers smaller than 1.\n");
    }
    else {
        printf("Collatz sequence for number %d is: %d", collatzNumber, collatzNumber);
    }
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
    if (collatzNumber > 0) {
    printf("\nLength of the Collatz sequence is %d\n", counter);
    }

    //5 - Generate a Fibonacci series and check if the random number is in the series.
    printf("\nTask 5 - Fibonacci Series:\n");
    
    srand(time(NULL));
    int fibonacciNumber = rand() % 100000;
    // int fibonacciNumber = -1;            // test case
    printf("The number generated for Fibonacci series is: %d\n", fibonacciNumber);
    
    if (isFibonacci(fibonacciNumber)) {
        printf("Number %d is in the Fibonacci series.\n", fibonacciNumber);
    }
    else {
        printf("Number %d is not in the Fibonacci series.\n", fibonacciNumber);
    }


    return 0;
}

int isFibonacci(int number){

    int a = 0;
    int b = 1;

            
    while (a < number && b < number){

        if (a < b){

            a = a + b;

        }
        else {

            b = a + b;

        }
    }
            
    return (a == number || b == number || number == 0);
}
