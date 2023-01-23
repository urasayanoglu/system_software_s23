/*
File:           question4.c
Author:         Uras Ayanoglu 
Description:    Tasks 3,4, and 5 for Exercise 2 of System Software course by Sanna Määttä.
*/

#include <stdio.h>

int main(void){

    // 4a - Read two integers from the user and print them.
    long int number1 = 0;
    long int number2 = 0;

    printf("Enter an integer for Number1: ");
    scanf("%ld", &number1);

    printf("Enter an integer for Number2: ");
    scanf("%ld", &number2);


    // 4b - Check the numbers for their values and print them.
    if (number1 == number2){
        printf("Both numbers are the same and they are: %ld\n", number1);

    } else if (number1 >= number2){
        printf("Number1: %ld is greater than Number2: %ld\n", number1, number2);

    } else {
        printf("Number2: %ld is greater than Number1: %ld\n", number2, number1);
    }

    return 0;
}