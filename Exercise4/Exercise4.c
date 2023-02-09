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
    
    printf("Task 4a - Generate a random number between the ranges of the function parameters.\n");
    
    int randomNumber = 0;    
    randomNumber = randNum(150, -300);
    // randomNumber = randNum(0,0); // Test case1
    // randomNumber = randNum(-1,30); // Test case2
    // randomNumber = randNum(299, 300); // Test case3
    // randomNumber = randNum(160, 20); // Test case4

    // Task 4b - Write a function that checks the corresponding grade of the random number generated in the previous task.
    printf("\nTask 4b - Checking the corresponding grade of the random number generated in the previous task.\n");
    
    int gradeNumber = 0;
    gradeNumber = randNum(0, 120);
    //gradeNumber = -20; // Test case1
    // gradeNumber = 130; // Test case2
    // gradeNumber = 0; // Test case3
    // gradeNumber = 60; // Test case4
    // gradeNumber = 72; // Test case5
    // gradeNumber = 84; // Test case6
    // gradeNumber = 96; // Test case7
    // gradeNumber = 108; // Test case8
    // gradeNumber = 120; // Test case9
    gradeCheck(gradeNumber);


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

int gradeCheck(int points){

    int grade = 0;

    int grades[6] = {0,1,2,3,4,5};

    if (points < 0 || points > 120){
        printf("Points: %d\n", points);
        printf("Invalid points. Grade points should be between 0 and 120.\n");
    } else if (points < 60){
        printf("%d points corresponds to grade %d.\n",points, grades[0]);
        grade = grades[0];
    } else if(points < 72){
        printf("%d points corresponds to grade %d.\n", points, grades[1]);
        grade = grades[1];
    } else if (points < 84){
        printf("%d points corresponds to grade %d.\n", points, grades[2]);
        grade = grades[2];
    } else if (points < 96){
        printf("%d points corresponds to grade %d.\n", points, grades[3]);
        grade = grades[3];
    } else if (points < 108){
        printf("%d points corresponds to grade %d.\n", points, grades[4]);
        grade = grades[4];
    } else if (points <= 120){
        printf("%d points corresponds to grade %d.\n", points, grades[5]);
        grade = grades[5];
    }

    return grade;
    
}