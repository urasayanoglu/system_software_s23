/*
File      :   Sieve.c
Time      :   27.03.2023 22:26:10
Compile   :   gcc -Wall -Wextra -std=c18 Sieve.c -o Sieve
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Exercise7 Task 2, Write Sieve of Eratosthenes algorithm in order to find all prime numbers.
*/

#include "Sieve.h"


bool parseInteger(char *string, int *integer){
    
	// Keep current index into the string while looping through it one character at a time
    int i = 0;
  
    // Move through any leading whitespace
    while (isspace(string[i])) i++;
  
    // Get the length of the string
    int length = strlen(string);
  
    // If entire string is just whitespace, it doesn't contain an integer
    if (length == i) return false;
  
    // The integer chars will be stored into integer_buffer, we'll use 
    // integer_chars to keep track of our index into this buffer as we store 
    // each character
    char integer_buffer[BUFFER_SIZE];
    int integer_chars = 0;
  
    // In the case of a negative integer, the first char may be - symbol
    if (string[i] == '-')
    {
      // Store the symbol into the buffer, and advance both indexes into the string and buffer
    
      integer_buffer[integer_chars] = '-';
      integer_chars++;
      i++;
    
      // if the - character is not followed by a digit, the string does not contain a valid integer
      if (!isdigit(string[i])) return false;
    }
  
    // Loop through characters until we reach the end of the string or a trailing whitespace character
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
  
    // Put a null terminator onto the end of the buffer to make it a proper string
    integer_buffer[integer_chars] = '\0';
  
    // Loop through any trailing whitespace characters
    while (isspace(string[i])) i++;
  
    // If after doing so, we are NOT at the end of the string, then the string 
    // does not contain a valid integer
    if (string[i] != '\0') return false;
  
    // atoi converts the string representation of our integer to an int type 
    // value in C, and we de-reference integer to "return" the value via a pointer
    *integer = atoi(integer_buffer);
  
    // we've successfully validated the presence of an int and so can return true
    return true;
}

int askNumber() {

	// Validated integer will be stored in integer variable.
	int integer = 0;


	// Keep track if it is parsed correctly
	bool parsed_correct = true;
	
	do {
		printf("Please enter an integer: ");
		
		//Store the input string 
		char buffer[BUFFER_SIZE];
		
		// Store characters entered into buffer charachter array
		// up to BUFFER_SIZE amount of characters and not more
		fgets(buffer, BUFFER_SIZE, stdin);
		// Store true or false into parsed_correct variable
		parsed_correct = parseInteger(buffer, &integer);
				
		// Check if it is a valid integer or if it is below zero
		if ( !parsed_correct || integer < 0) {
			printf("\nInvalid input. Please enter a positive integer:\n");
		}
		
	} while ( !parsed_correct || integer < 0 );
	
	return integer;
	
}


// The function fills the array up to the number gotten by the prompt. 
bool fillArray( int upToNumber, int *array) {

	int filler = 2;
	// Check  if we can fill the array e.g. if the given number is too big
	if ( upToNumber > ARRAY_SIZE || upToNumber < SMALLEST_PRIME ) {
		printf("The number given is in the wrong interval.\n");
		return false;
		
	// Fill array after validation	
	} else {
		int counter = 0;

		printf("Numbers listed below are in allocated memory space [%d pcs]\n", upToNumber-SMALLEST_PRIME+1 );
		while ( filler <= upToNumber ) {
			*( array + counter ) = filler;
			printf("Number at [%d] is %d\n", counter, filler);
			counter++;
			filler++;
		}
	}

	return true;
}

// Function to check for primes
void checkPrime( int upToNumber, int *array ) {
	
	printf("\nPrime numbers between %d and %d: ",SMALLEST_PRIME, upToNumber );
	// Loop through whole array
	for ( int index = 0; index < upToNumber-1; index++) {
		
		bool prime = true;
		// Check for each value separetly if it is prime or not
		for ( int index2 = 2; index2 <= ( *(array+index)/2 ); index2++) {
			
			// Check if number is prime or not
			if ( *(array+index) % index2 == 0 ) {
				prime = false;
			}
		}
		if ( upToNumber == SMALLEST_PRIME ) {
			printf("%d", SMALLEST_PRIME );
		}
		// Print number if it is prime
		else if ( prime == true ) {
			printf("%d ", *(array+index));
		}		
	}
}
















