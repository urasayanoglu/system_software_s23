/*
File:           Exercise4.c
Author:         Uras Ayanoglu 
Description:    Tasks 3,4, and 5 for Exercise 3 of System Software course by Sanna Määttä.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Helps us to check if the input is a number or if it is a whitespace etc. 
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function declarations 
int randNum(int x, int y);
int gradeCheck(int points);

int main(){

    // Task 4a - Write a function that generates a random number between the ranges of the function parameters.
    
    printf("Task 4a - Generating a random number between the ranges of the function parameters.\n");
    
    int randomNumber = 0;    
    randomNumber = randNum(150, -300);
    // randomNumber = randNum(0,0); // Test case1
    // randomNumber = randNum(-1,30); // Test case2
    // randomNumber = randNum(299, 300); // Test case3
    // randomNumber = randNum(160, 20); // Test case4

    return 0;
}

// Function definitions.

int randNum(int x, int y)
{

    int upper = 0;
    int lower = 0; 

    if (x == y){
        upper = x;
        lower = x;
    } else if(x > y){
        upper = x;
        lower = y;
    } else {
        upper = y;
        lower = x;
    }

    srand(time(NULL));
    int randomNumber = rand() % (upper - lower + 1) + lower;
    printf("Random number is: %d\n", randomNumber);
    printf("It was created between lower bound %d and upper bound %d\n", lower, upper);
    
    return randomNumber;

}