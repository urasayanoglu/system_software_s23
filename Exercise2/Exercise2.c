/*
File:           Exercise2.c
Author:         Uras Ayanoglu 
Description:    Tasks 3,4, and 5 for Exercise 2 of System Software course by Sanna Määttä.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
        printf("\nBoth numbers are the same and they are: %ld\n", number1);

    } else if (number1 >= number2){
        printf("\nNumber1: %ld is greater than Number2: %ld\n", number1, number2);

    } else {
        printf("\nNumber2: %ld is greater than Number1: %ld\n", number2, number1);
    }
    
    // 4c - Sum, Average, Difference, Product,Division, and Power of the numbers.
    long int sum = number1 + number2;
    printf("\nThe sum of Number1 + Number2 equals to --> %ld + %ld = %ld\n", number1, number2, sum);
    
    double average = (number1 + number2) / 2;
    printf("The average of Number1 and Number2 equals to --> (%ld + %ld) / 2 = %.2f\n", number1, number2, average);

    long int difference = number1 - number2;
    printf("The difference of Number1 - Number2 equals to --> %ld - %ld = %ld\n", number1, number2, difference);

    long int product = number1 * number2;
    printf("The product of Number1 * Number2 equals to --> %ld * %ld = %ld\n", number1, number2, product);

    if (number2 != 0){
        float division = (float)number1 / (float)number2;
        printf("The division of Number1 by Number2 equals --> %ld / %ld = %.2f\n", number1, number2, division);
    } else {
        printf("Zero Devision Error! You cannot divide a number by zero\n");
    }

    double power = pow(number1, number2);
    printf("The Number1 to the power Number2 equals --> %ld ** %ld = %.2f\n", number1, number2, power);  

    // 5a - Generate a random number between 0 - 100 and print the number

    srand(time(NULL));
    int generatedNumber = rand() % 101;
    printf("\nGenerated number between 0 and 100 by the computer is %d\n", generatedNumber);

    // 5b - Check the number generated and print if it is odd or even.

    if (generatedNumber % 2 != 0){
        printf("Generated number %d is odd.\n", generatedNumber);
    } else {
        printf("Generated number %d is even.\n", generatedNumber);
    }
    
    // 5c - Check the generated number if it is divisible by 4 and 7. Print if it is divisible or not.

    if (generatedNumber % 27 == 0){
        printf("The number generated %d is divisible by 4 and 7\n", generatedNumber);
    } else {
        printf("The number generated %d is not divisible by 4 and 7\n", generatedNumber);
    }
    
    // 6a - Make an array with 10 integers, print them from the beginning to end and vice versa.

    int arrayIntegers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Print the array from the beginning to the end.

    printf("\nArray first to last:\n");
    
    for (int i = 0; i < 10; i++) {    
        printf("%d ", arrayIntegers[i]);
    }    
    
    // Print the array from the end to the beginning.
   
    printf("\n\nArray last to first:\n");
    for (int i = 9; i > -1; i--) {                                     
        printf("%d ", arrayIntegers[i]);
    }


    // 6b - Check if the generated number is in the array and print if it is or not!.

    // Count how many times the random number is in the array.
    int randomIsInArray = 0;  
                                              
    for (int i = 0; i < 10; i++) {                                      
        if (generatedNumber == arrayIntegers[i]) {                               
            randomIsInArray++;
        }
    }
    if (randomIsInArray == 0) {                                                 
        printf("\n\nEarlier generated random number %d is not among the integer array.\n", generatedNumber);
    } else {
        printf("\n\nEarlier generated random number %d is among the integer array.\n", generatedNumber);
    }

    return 0;
}