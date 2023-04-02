/*
File      :   Exercise7.c
Time      :   27.03.2023 22:30:10
Compile   :   gcc -Wall -Wextra -std=c18 Exercise7.c -o Exercise7
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Exercise 7 Task 2 & 3
*/

#include <stdio.h>

#include "Sieve.h"
#include "Matrix.h"

int main() {
	
    // Task 2: Sieve of Eratosthenes Algorithm - Find all the prime numbers up to a number asked from the user.
    printf("Exercise7 Task 2: Sieve of Eratosthenes in order to find all prime numbers until a number asked from the user.\n");
    int n = askNumber();
        
    int* is_prime = sieve(n); // get the array of prime flags

    printf("Prime numbers up to %d: ", n);
    for (int i = 2; i <= n; i++) {
        if (*(is_prime + i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime); // free the dynamically allocated memory

	// Task 3: Find the greatest sum of five adjacent numbers in the same direction up, down, left, right, or diagonally in the 20×20 grid
	printf("\nExercise 7 Task 3 - Find the greatest sum of five adjacent numbers in the same direction\n");
    testMatrix();

	
    return 0;
}


