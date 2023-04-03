/*
File      :   Matrix.h
Time      :   02.04.2023 22:42:46
Compile   :   gcc -Wall -Wextra -std=c18 Matrix.h -o Matrix
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Header file for Matrix.c
*/

#ifndef MATRIX_H
#define MATRIX_H

// Include built-in Libraries
#include <stdio.h>

// Determine the size of the array
#define SIZE 20

// 5 elements for sum
#define ADJACENCY 5

// 15 times to select 5 consecutives for sum
#define LIMIT 16
#define LO 3

// Declare functions we wish to share for other files to use
void result();
int horizontalSum();
int verticalSum();
int diagonalSum();
void testMatrix();

#endif 

