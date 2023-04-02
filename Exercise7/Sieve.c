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

int* sieve(int n) {
    int *is_prime = (int*) malloc(sizeof(int) * (n+1)); // create the array dynamically
    if (is_prime == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    } else {
		printf("Memory allocation is successful.\n");

	}

    // Initialize the array to 1 (true) for all elements
    for (int i = 0; i <= n; i++) {
        *(is_prime + i) = 1;
    }

    // Set 0 and 1 to not prime
    *(is_prime + 0) = 0;
    *(is_prime + 1) = 0;

    // Mark all multiples of numbers up to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (*(is_prime + i)) {
            for (int j = i * i; j <= n; j += i) {
                *(is_prime + j) = 0;
            }
        }
    }

    return is_prime;
}
