/*
File    :   Exercise6.c
Compile :   gcc -Wall -Wextra -std=c18 Exercise6.c -o Exercise6
Version :   1.0
Contact :   uras.ayanoglu@edu.turkuamk.fi
Authors :   (C)Copyright 2023, Jan-Krister Helenius, Uras Ayanoglu
Desc    :   System Software exercise 6
*/

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printArray(int *firstElement, int length);    
int randomNumber(int minimum, int maximum);
int *fillArray(int *first, int length);         // Fills an array with random numbers
int *sortAndFind(int *first, int length, int guessedNumber);        // Sorts an array in descending order and checks if a given number is in it
void swap(int *a, int *b);          // swaps the values stored in two pointers
void sortArray(int *first, int length);     // Sorts an array in descending order (quicksort)
int inputInteger(char *prompt);
double *readLookupTable(double *table, char *filename);         // Reads a csv file into the array
double temperature(double *table, int adc);         // Converts resistance reading to temperature using a lookup table and linear interpolation

#define ARRAY_LENGTH 10
#define MAX_VALUE 999999        // Max value for random number generator
#define MIN_VALUE 0
#define STRINGMAX 13        // Length of input string to read
#define NTC_FILE_NAME "1k_NTC_Thermistor_Look_Up_Table.txt"     // File name for the ADC lookup table
#define FILE_BUFFER_SIZE 1024       // Buffer size for reading the file

int main()
{
    srand(time(NULL));
    int *arrayPointer = NULL;
    int *resultPointer = NULL;
    int array[ARRAY_LENGTH];
    int guess = -1;
    arrayPointer = &array[0];
    arrayPointer = fillArray(arrayPointer, ARRAY_LENGTH);
    double lookup[32][2] = {{0}};
    double *lookupPointer = NULL;
    int userNumber = 0;

    printf("* Tasks 3a nd 3b - Fill an array with random numbers and print out its contents. *\n");
    printArray(arrayPointer, ARRAY_LENGTH);
    printf("\n");

    printf("\n* Task 3c - Sort the array and find user-provided number in it. *\n");
    while (guess < MIN_VALUE || MAX_VALUE <= guess) 
    { 
        guess = inputInteger("Please enter an integer (0-999999): ");
    }
    resultPointer = sortAndFind(arrayPointer, ARRAY_LENGTH, guess);
    printf("The sorted list:\n");
    printArray(arrayPointer, ARRAY_LENGTH);
    if (resultPointer == NULL)
    {
        printf("\nYour number was not in the list. Here's a null pointer: %p\n", resultPointer);
    }
    else 
    {
        printf("\nYour number was in the list. The result pointer points to %d\n", *resultPointer);
    }

    printf("\n* Task 4c - 1k NTC thermistor lookup table *\n");
    lookupPointer = &lookup[0][0];
    lookupPointer = readLookupTable(lookupPointer, NTC_FILE_NAME);
    if (lookupPointer == NULL)
    {
        printf("Error opening the lookup table file.\n");
        return 0;
    }

    printf("ADC\tC\n");
    for (int i = 0; i < 32; i++)        // Prints the contents of the lookup table
    {
        printf("%.0f\t%.1f\n", *(lookupPointer + 2 * i), *(lookupPointer + 2 * i +  1));
    }
    
    while (userNumber < 250 || userNumber > 1000)
    {
        userNumber = inputInteger("Enter an ADC value(250-1000): ");
    }
    printf("Temperature: %.1f\u00B0C\n", temperature(lookupPointer, userNumber));

    return 0;
}


void printArray(int *firstElement, int length)      // Prints out the contents of an int array
{
    for (int i = 0; i < length; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", *(firstElement + i));
    }
}


int randomNumber(int minimum, int maximum)      // Returns a random number between minimum and maximum (inclusive)
{
    int midline = 0;
    int randLimit = 0;
    int randResult = 0;
    if ( minimum == maximum )
    {
        return minimum;
    }
    else if (maximum < minimum)
    {
        return randomNumber(maximum, minimum);
    }
    else if (((long)maximum - (long)minimum) < RAND_MAX)        // Check if the interval is short enough to use rand&remainder.
    {
        randLimit = RAND_MAX / (maximum - minimum);
        randLimit *= (maximum - minimum);           // Sets the acceptable rand() values to a multiple of interval length to get an even distribution
        do 
        {
            randResult = rand();
        } while(randLimit < randResult);
        return randResult%(maximum - minimum + 1) + minimum;
    }
    else            // If the interval is too long, split it in half, and retry on a randomly chosen half.
    {
        midline = (int)((long)minimum + (long)maximum) / 2;
        if (rand()%2 == 1)
        {
            return randomNumber(minimum, midline);
        }
        else 
        {
            return randomNumber(midline + 1, maximum); 
        }
    }
}


int *fillArray(int *first, int length)      // Fills the array with random numbers
{
    for (int i = 0; i < length; i++)
    {
        *(first + i) = randomNumber(MIN_VALUE, MAX_VALUE);
    }
    return first;
}


int *sortAndFind(int *first, int length, int guessedNumber)
{
    sortArray(first, length);
    int i = 0;
    while (i < length) 
    {
        if (*(first + i) == guessedNumber)
        {
            return first + i;
        }
        i++;
    }
    // Return NULL if the number wasn't found in the array
    return NULL;
}

void swap(int *a, int *b)   // Swaps the integer values at two locations
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int *first, int length)     
{
    if (length > 1)     // Do nothing if length is 0 or 1, in which case the array is already sorted
    {
        // A candidate index for the pivot number. The aim is to have all the numbers bigger
        // than the pivot to the left of this index, and all the smaller numbers to the right
        int pivotIndex = 0;     

        // The pivot number for this array. In this implementation, we choose the integer at 
        // index 0. The choice does not matter, because we expect random numbers
        int pivot = *first;

        // This integer will track the index of the element that contains the pivot value
        int pivotLocation = 0;

        // Going through the array once, greedily moving numbers larger than pivot to
        // pivotIndex. The arrangement of the rest is disregarded, and pivot gets moved
        // to its right place after the loop
        for (int i = 1; i < length; i++)
        {
            if (*(first + i) > pivot)
            {
                swap(first + i, first + pivotIndex);

                // If we just moved the pivot number, update its location
                if (pivotIndex == pivotLocation)    
                {
                    pivotLocation = i;
                }

                // A number larger than the pivot just got moved left, so increase
                // the index of the candidate spot by one.
                pivotIndex++;
            }
        }

        // Move pivot to its correct index, unless all the numbers were large
        // and got shifted
        if (pivotIndex < length)
        {
            swap(first + pivotLocation, first + pivotIndex);
        }

        // Call sortArray recursively on the left and right sub-arrays
        // sans the pivot
        sortArray(first, pivotIndex);
        sortArray(first + pivotIndex + 1, length - pivotIndex - 1);
    }
}


int inputInteger(char *prompt)            // Gets user input and makes sure it's an integer
{
    int i = 0;
    int isNewline = 0;
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
            isNewline = (buf[i+1] == '\n');
            if (isNewline && i < 11)     // If a sequence of integers ends in a newline and is short enough, we have our integer
            {
                if ((long)atol(buf) <= INT_MAX && INT_MIN <= (long)atol(buf))       // Makes sure that the number is within int limits
                {
                    return atoi(buf);               // Now the number can be converted to int
                }
            }
            i++;
        }
        if (!isNewline)             // Clears the buffer if no newline has been found
        {
            do 
            {
                fgets(buf, 2, stdin);
            } while(buf[0] != '\n' && buf[1] != '\n');
        }
        memset(buf, '\0', STRINGMAX);          // clear string
        printf("Invalid input! Please enter an integer; ");
    }
    while (atoi(buf) == 0);         // Read error, continue loop
    return atoi(buf);
}

double * readLookupTable(double *table, char *filename)
{
    char buffer[FILE_BUFFER_SIZE];
    int row = 0;
    int column = 0;
    FILE *fileptr;
    fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        // Return NULL if can't open file
        return NULL;
    }
    while (fgets(buffer, FILE_BUFFER_SIZE, fileptr))
    {
        column = 0;
        row++;

        // Skips the header row
        if (row == 1)
        {
            continue;
        }

        char* value = strtok(buffer,", ");

        // Converts to float and stores to array cell
        while (value) 
        {
            *(table + 2 * (row - 2) + column) = atof(value);
            value = strtok(NULL, ", ");
            column++;
        }
    }
    fclose(fileptr);
    return table;
}


double temperature(double *table, int adc)
{
    int i = 0;

    // If the ADC value is in the table, return corresponding value, otherwise interpolate
    while ((int)(*(table + i)) != adc)
    {
        if ((int)(*(table + i)) < adc && (int) (*(table + i + 2)) > adc)
        {
            // Linear interpolation formula from Wikipedia
            return ((*(table + i + 1)*(*(table + i + 2) - (double)adc)) + (*(table + i + 3)*((double)adc - *(table + i)))) / (*(table + i + 2) - *(table + i));
        }
        i = i + 2;
    }
    return *(table + i + 1);
}