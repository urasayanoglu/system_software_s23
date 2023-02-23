/*
File:           Exercise 5
Author:         Uras Ayanoglu
Description:    Tasks 3 and 4 for Exercise 5 of System Software course by Sanna Määttä.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_NUMBER 10000000

// Function declarations

int armstrongChecker(int x);                // Returns true if the argument is an Armstrong number
void printArmstrong(int x);                 // Prints all the Armstrong numbers up to the argument
void printArray(int array[], int length);   // Prints out the elements of an array.
void randomArray(int array[], int length);  // Replaces array elements with random numbers.
void sortArray(int array[], int length);    // Sorts an integer array in ascending order.

int main(int argc, char *argv[]){
    
    // Task 3a - Give an integer between 0 - 10000000 as a command line argument and print proper warning if it is not so!
    printf("Task 3a - Given an integer between 0 - 10000000 as a command line argument and print proper warning if it is not so!\n");

    int i = 0;
    int number = 0;
     
    // First Checks if the user gives an argument then checks if the user gives only one arguement.
    if (argc == 1){
        printf("There should have been one argument. None received!\n");
        return 0;
    } else if (argc > 2){
        printf("There should have been only one argument. More than one received.\n");
        return 0;
    } else{
        do{
          if (!isdigit(argv[1][i])){
                printf("Invalid argument type. The argument must be an integer between 0 and 10,000,000.\n");
                return 0;
            } else{
                i++;
            }
        } while (argv[1][i] != '\0');       // Iterate till end of line (EOL) comes.
        
        // The number given as an arguement should be less than 9 digits and max number
        if (i < 9 && atol(argv[1]) <= MAX_NUMBER){
            number = atoi(argv[1]);
        }
        else{
            printf("Number given is out of range limit. The argument must be an integer between 0 and 10,000,000.\n");
            return 0;
        }
    }

    printf("You have given a valid argument and it is: %d\n", number);


    // Task 3b - Find and print out all Armstrong numbers user gives as an input.
    printf("\nTask 3b - Find and print out all Armstrong numbers user gave as a command line arguement in Task 3a.\n");

    printf("Here are all the Armstrong numbers up to %d:\n", number);
    printArmstrong(number);

    // Task 4a - Write a function that takes a (ready filled) array and its length as arguments and prints out the elements of the array

    printf("\nTask 4a - Write a function that takes a (ready filled) array and its length as arguments and prints out the elements of the array\n");
    int sampleArray[10] = {25, 12, 43, 34, 5, 11, 70, 38, 9, 42};
    // int sampleArray[10] = {}; // Test case 1 for 4a
    // int sampleArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Test case for 2 4a
    printArray(sampleArray, 10);

    // Task 4b - Write a function that takes an empty array and its length as arguments and fill the array with random generated numbers smaller than 1000000.
    printf("\n\nTask 4b - Write a function that takes an empty array and its length as arguments and fill the array with random generated numbers smaller than 1000000.\n");
    int emptyArray[10]; // = {-23, -45, -100, -12, -1, -2, -3, -4, -5, -6}; // Test case for 4c
    randomArray(emptyArray, 10);
    printf("Here is the array filled with random numbers: ");
    printArray(emptyArray, 10);

    // Task 4c - Write a function that takes the array from Task 4b and its length as arguments and then sort the array and print it.
    printf("\n\nTask 4c - Write a function that takes the array from Task 4b and its length as arguments and then sort the array and print it.\n");
    sortArray(emptyArray, 10);
    printArray(emptyArray, 10);


    return 0;
}

int armstrongChecker(int x){
    int sum = 0;
    int temp = x;
    int digit = 0;
    int length = 0;
    int power = 0;
    int i = 0;
    
    // Find the length of the number
    while (temp != 0){
        temp = temp / 10;
        length++;
    }
    
    temp = x;
    
    // Find the sum of the digits raised to the power of the length of the number
    while (temp != 0){
        digit = temp % 10;
        power = 1;
        for (i = 0; i < length; i++){
            power = power * digit;
        }
        sum = sum + power;
        temp = temp / 10;
    }
    
    if (sum == x){
        return 1;
    } else{
        return 0;
    }
}

void printArmstrong(int x){
    int counter = 0;
    while (counter <= x){

        if (counter && armstrongChecker(counter)){
            printf(", %d", counter);
        } else if (!counter && armstrongChecker(counter)){
            printf("%d", counter);
        }
    counter++;
    }
    printf("\n");
}

void printArray(int array[], int length){
    int i = 0;
    for (i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
}

void randomArray(int array[], int length){
    int i = 0;
    srand(time(NULL));
    for (i = 0; i < length; i++){
        array[i] = rand() % 1000000;
    }
}

void sortArray(int array[], int length){
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < length; i++){
        for (j = i + 1; j < length; j++){
            if (array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}