/*
File:           Exercise3.c
Author:         Uras Ayanoglu 
Description:    Tasks 3,4, and 5 for Exercise 3 of System Software course by Sanna Määttä.
*/

#include <stdio.h>

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

    return 0;
}