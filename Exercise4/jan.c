#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define STRINGMAX 50

int inputInteger(char *prompt);
int negativeNumbers();
int sumOfNumbers(int *overflowFlag);
int sumOfPositiveDivisibleByThree(int *overflowFlag);
int randomNumber(int x, int y);

int main()
{
    srand(time(NULL));
    int overflowFlag = 0;           // Overflow flag for when we are checking for it.
    int sum = 0;
    int x = 0;
    int y = 0;

    printf("* Task 3a - Counting negative integers *\n");
    printf("The number of negative integers was: %d\n", negativeNumbers());

    printf("\n* Task 3b - Calculates the sum of numbers *\n");
    sum = sumOfNumbers(&overflowFlag);      
    if (overflowFlag)
    {
        printf("There was an integer overflow.\n");
    }
    else
    {
        printf("The sum of the numbers is: %d\n", sum);
    }

    printf("\n* Task 3c - Sum of positive integers divisible by three *\n");
    sum = sumOfPositiveDivisibleByThree(&overflowFlag);
    if (overflowFlag)
    {
        printf("There was an integer overflow.\n");
    }
    else
    {
        printf("The sum of the positive integers divisible by three is: %d\n", sum);
    }

    printf("\n* Task 4a - Generates a random number. *\n");
    x = inputInteger("Please enter an integer: ");
    y = inputInteger("Please enter another integer: ");
    printf("The random number is %d\n", randomNumber(x, y));

    return 0;
}

int inputInteger(char *prompt)            // Gets user input and makes sure it's an integer
{
    int i = 0;
    char buf[STRINGMAX];           // Variable to store the string. 50 is hopefullt enough space to parse till newline
    printf(prompt);
    do
    {
        i = 0;

        fgets(buf, STRINGMAX, stdin);          // Reads up to 50 characters from stdin
        if (buf[0] == '-')          // If first character is '-', except a negative number, and offset reading location by one.
        {
            i++;
        }
        while (isdigit(buf[i]))         // Check if character is a digit
        {
            if (buf[i+1] == '\n' && i < 11)     // If a sequence of integers ends in a newline and is short enough, we have our integer
            {
                if ((long)atol(buf) <= INT_MAX && INT_MIN <= (long)atol(buf))       // Makes sure that the number is within int limits
                {
                    return atoi(buf);               // Now the number can be converted to int
                }
            }
            i++;
        }
        // clearerr(stdin);
        memset(buf, '\0', STRINGMAX);          // clear string
        printf("Invalid input! Please enter an integer; ");
    }
    while (atoi(buf) == 0);         // Read error, continue loop
    return atoi(buf);
}

int negativeNumbers()           //Asks the user for integer, counts the number of negatives. 
{
    int negativeAmount = 0;
    int readNumber = 1;
    while (readNumber != 0)         // Ask for numbers until user inputs 0, count negative integers
    {
        readNumber = inputInteger("Enter an integer (0 to end): ");
        if (readNumber < 0)
        {
            negativeAmount++;
        }
    }
    return negativeAmount;
}

int sumOfNumbers(int *overflowFlag)      // Calculates the sum of numbers entered until the input is 0.
{
    int sum = 0;
    int readNumber = 1;
    *overflowFlag = 0;
    while (readNumber != 0) 
    {
        readNumber = inputInteger("Enter an integer (0 to end): ");
        if ((long)readNumber + (long)sum > INT_MAX || (long)readNumber + (long)sum < INT_MIN)       // Checking if the sum is outside int limits.
        {
            *overflowFlag += 1;
        }
        sum += readNumber;
    }
    return sum;
}

int sumOfPositiveDivisibleByThree(int *overflowFlag)        // Adds up positive integers input by the user, discarding other numbers
{
    int sum = 0;
    int readNumber = 1;
    *overflowFlag = 0;
    while (readNumber != 0)
    {
        readNumber = inputInteger("Enter an integer (0 to end): ");
        if ((long)readNumber + (long)sum > INT_MAX) 
        {
            *overflowFlag += 1;
        }
        if (readNumber > 0 && readNumber % 3 == 0)
        {
            sum += readNumber;
        }
    }
    return sum;
}

int randomNumber(int x, int y)             // Generates a random integer between low and high (inclusive)
{
    // IntervalLimit is the longest interval rand()%interval will be used in. Longer intervals could result in significant skew in the distribution of the remainders, and could even
    // be longer than RAND_MAX. The division of RAND_MAX with 1000 represents a compromise where it works pretty well in GNU/Linux's (2^31)-1, and still works in systems that
    // have othere RAND_MAX values, such as (2^15)-1 (the C standard minimum) and (2^61)-1 (the largest Mersenne prime in a 64-bit system).
    
    const long int intervalLimit = (long)(sqrt((double)RAND_MAX))/1000;         // cast to long for comparison purposes
    if (y < x)
    {
        return randomNumber(y, x);
    }
    else if (x == y)
    {
        return x;
    }
    else if ((long)y - (long)x < intervalLimit && (long)x - (long)y < intervalLimit)        // Checks whether the interval is shorter than intervalLimit
    {
        int range = y - x;
        return rand()%(range + 1) + x;
    }
    else
    {
        double midline = ((double)x + (double)y) / 2;       // Splits the interval into two halves
        if (rand()%2 == 0)                          // Picks one half randomly, and calls randomNumber recursively on that half.
        {
            return randomNumber(x, (int)midline);
        }
        else
        {
            return randomNumber((int)midline + 1, y);
        }
    }
}