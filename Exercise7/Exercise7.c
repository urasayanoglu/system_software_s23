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
	
	// Memory allocation for the array
	int *memoryPointer = NULL;
	memoryPointer = (int*) malloc(ARRAY_SIZE * sizeof(int));
	
	// Check memory allocation, if no pointer is returned , mem alloc is unsuccessful.
	if ( memoryPointer == NULL ) {
		printf("Memory allocation is unsuccessful\n");
		return 0;
	} else {
		printf("Memory allocation is successful.\n");

	}
	
	
	int integer = 0;
	integer = askNumber();
	
	// Check can we run Primecheck
	if ( fillArray(integer, memoryPointer) == true ) {
		checkPrime(integer, memoryPointer );
	}
	
	
	// Free the memory 
	free(memoryPointer);


	// Task 3: Find the greatest sum of five adjacent numbers in the same direction up, down, left, right, or diagonally in the 20×20 grid
	printf("\nExercise 7 Task 3 - Find the greatest sum of five adjacent numbers in the same direction\n");
    testMatrix();

	
    return 0;
}


