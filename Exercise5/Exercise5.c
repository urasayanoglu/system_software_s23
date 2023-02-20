/*
File:           Exercise 5
Author:         Uras Ayanoglu
Description:    Tasks 3,4, and 5 for Exercise 5 of System Software course by Sanna Määttä.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_NUMBER 10000000

int main(int argc, char *argv[]){
    
    // Task 3a - Give an integer between 0 - 10000000 as a command line argument and print proper warning if it is not so!

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


    return 0;
}