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

void printArmstrong(int x)
{
    int counter = 0;
    while (counter <= x)
    {
        if (counter && armstrongChecker(counter))   
        {
            printf(", %d", counter);
        }
        else if (!counter && armstrongChecker(counter))
        {
            printf("%d", counter);
        }
    counter++;
    }
    printf("\n");
}



