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

#define BUFFER_SIZE 4096

// Function declarations 
int randNum(int x, int y);
int gradeCheck(int points);
bool parseInteger(char *string, int *integer);
bool isPrime(int integer);

int main(){

    // Task 3a - Write a function that prints only the negative numbers of user input till given 0.
    printf("Task 3a - Write a function that prints only the negative numbers of user input till given 0.\n");
    int number = 0;
    bool typeCorrect = true;
    int negativeList[BUFFER_SIZE];
    int index = 0;

    while (true) {
        do{
            printf("Enter an integer: ");
            char temp[BUFFER_SIZE];
            fgets(temp, BUFFER_SIZE, stdin);
            typeCorrect = parseInteger(temp, &number);
            if (!typeCorrect){
                printf("Must be an integer value!\n");
            }

        } while (!typeCorrect);{
            if (number < 0){
                negativeList[index] = number;
                index++;
            } else if (number == 0){
                printf("Zero entered. Exiting the loop.\n");
                break;
            }
        }
    }
    printf("\nNegative numbers entered:\n");
    for (int i = 0; i < index; i++){
        printf("%d ", negativeList[i]);
    } 

    // Task 4a - Write a function that generates a random number between the ranges of the function parameters.
    
    printf("\n\nTask 4a - Generate a random number between the ranges of the function parameters.\n");
    
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

    // Task 5b - Writing a function that checks if a user given integer is a prime number or not.
    printf("\nTask 5b - Checking if a user given integer is a prime number or not.\n");
    
    int integer = 0;
    bool parsedCorrect = true;

    // keep asking the user for an integer until it has been validated as correct
    do{
    
    printf("Enter integer: ");

    // accept a line of string input from the user, store it into buffer
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    // validate the integer input, store the int into integer if it was 
    // validated as correct
    parsedCorrect = parseInteger(buffer, &integer);

    // if the input was not a valid integer, tell the user this
    if (!parsedCorrect)
    printf("Must be an integer value!\n");

    } while (!parsedCorrect);

    // once an integer has been successfully entered, output it back to the user
    printf("You have entered %d as an integer and ", integer);
    isPrime(integer);
    // isPrime(0); // Test case1
    // isPrime(1); // Test case2
    // isPrime(2); // Test case3
    // isPrime(-5) // Test case4
    // isPrime(-13); // Test case5
    // isPrime(13); // Test case6
    // isPrime(933) // Test case7

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

bool parseInteger(char *string, int *integer){
    // i will keep our current index into the string as we loop through it 
    // one character at a time
    int i = 0;
  
    // move through any leading whitespace
    while (isspace(string[i])) i++;
  
    // get the length of the string
    int length = strlen(string);
  
    // if the entire string was just whitespace characters ("a blank string") 
    // we'll have reached the end of the string and we can return false as the 
    // string did not contain an integer
    if (length == i) return false;
  
    // the integer chars will be stored into integer_buffer, we'll use 
    // integer_chars to keep track of our index into this buffer as we store 
    // each character
    char integer_buffer[BUFFER_SIZE];
    int integer_chars = 0;
  
    // in the case of a negative integer, the first char may be - symbol
    if (string[i] == '-')
    {
      // store the symbol into the buffer, and advance both indexes into the 
      // string and buffer
      integer_buffer[integer_chars] = '-';
      integer_chars++;
      i++;
    
      // if the - character is not followed by a digit, the string does not 
      // contain a valid integer
      if (!isdigit(string[i])) return false;
    }
  
    // loop through characters until we reach the end of the string or a trailing
    // whitespace character
    while (i < length && !isspace(string[i]))
    {
      // if we encounter anything that is not a digit, we do not have a valid int 
      // in the string
      if (!isdigit(string[i])) return false;
    
      // store the next character into the buffer, advance both indexes
      integer_buffer[integer_chars] = string[i];
      integer_chars++;
      i++;
    }
  
    // put a null terminator onto the end of the buffer to make it a proper string
    integer_buffer[integer_chars] = '\0';
  
    // loop through any trailing whitespace characters
    while (isspace(string[i])) i++;
  
    // if after doing so, we are NOT at the end of the string, then the string 
    // does not contain a valid integer
    if (string[i] != '\0') return false;
  
    // atoi converts the string representation of our integer to an int type 
    // value in C, and we de-reference integer to "return" the value via a pointer
    *integer = atoi(integer_buffer);
  
    // we've successfully validated the presence of an int and so can return true
    return true;
}

bool isPrime(int integer){

    bool prime = true;

    if (integer == 0 || integer == 1){
        prime = false;
    } else if (integer == 2){
        prime = true;
    } else {
        for (int i = 2; i < integer; i++){
            if (integer % i == 0){
                prime = false;
                break;
            }
        }
    }

    if (prime){
        printf("%d is a prime number.\n", integer);
    } else {
        printf("%d is not a prime number.\n", integer);
    }

    return prime;
}

