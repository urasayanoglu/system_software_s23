/*
File      :   Sieve.h
Time      :   27.03.2023 22:28:27
Compile   :   gcc -Wall -Wextra -std=c18 Sieve.h -o Sieve
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Header file for Sieve.c
*/

#ifndef SIEVE_H
#define SIEVE_H

// Built-in libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Determine the string size limit 
#define BUFFER_SIZE 4096

// Declare functions
int* sieve(int n);
bool parseInteger(char *string, int *integer);
int askNumber();


#endif 

