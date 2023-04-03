/*
File      :   Matrix.c
Time      :   27.03.2023 22:42:15
Compile   :   gcc -Wall -Wextra -std=c18 Matrix.c -o Matrix
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Find the greatest sum of five adjacent numbers in the same direction
*/

#include "Matrix.h"


// Function that compares and returns the greatest sum of adjacent 5 numbers horizontally, vertically, diagonally.
void result( int diagonal, int vertical, int horizontal ) {

	if ( diagonal > vertical && horizontal ) {
		printf("\nGreatest sum of 5 adjacent numbers in 20 x 20 matrix is in diagonal direction and it is: %d\n", diagonal);
	}else if ( vertical > diagonal && horizontal ) {
		printf("\nGreatest sum of 5 adjacent numbers in 20 x 20 matrix is in vertical direction and it is: %d\n", vertical);
	}else if ( horizontal > diagonal && vertical ) {
		printf("\nGreatest sum of 5 adjacent numbers in 20 x 20 matrix is in horizontal direction and it is: %d\n",horizontal);
	}
	
}

// Function that finds greatest sum of 5 adjacent numbers diagonally.
int diagonalSum( int(*twoDimensional)[SIZE] ) {
	
	int maxSum = 0;
	
	
	// From Top-left to buttom right 
	for ( int row = 0; row < LIMIT; row++) {
		// Loop throgh columns on a row
		for ( int column = 0; column < LIMIT; column++) {
			int sum = 0;
			// Loop through elements in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += twoDimensional[row+k][column+k];
			}
			
			if ( sum > maxSum ) {
				maxSum = sum;
			}
		}
	}
	
	
	
	// From Buttom-left to top right
	for ( int row1 = 0; row1 < LIMIT; row1++) {
		// Loop through columns on a row
		for ( int column1 = 19; column1 > LO; column1--) {
			int sum1 = 0;
			// Loop through elements in 5 consecutive sequence
			for ( int k1 = 0; k1 < 5; k1++) {
				sum1 += twoDimensional[row1+k1][column1-k1];
			}	
			if ( sum1 > maxSum ) {
				maxSum = sum1;
			}			
		}
				
	}
	 printf("Greatest sum of 5 adjacent numbers diagonally: %d\n",maxSum);
	
    return maxSum;
}


// Function that finds greatest sum of 5 adjacent numbers vertically (by column).
int verticalSum( int (*twoDimensional)[SIZE] ) {

	int maxSum = 0;

	for ( int row = 0; row < LIMIT; row++) {
		// Loop through columns on a row
		for ( int column = 0; column < SIZE; column++) {
			int sum = 0;
			// Loop through elements in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += twoDimensional[row+k][column];
			}
			if ( sum > maxSum ) {
				maxSum = sum;
			}	
		}
	}
	printf("Greatest sum of 5 adjacent numbers vertically: %d\n",maxSum);
	return maxSum;
}


// Function that finds greatest sum of 5 adjacent numbers horizontally (by row).
int horizontalSum( int (*twoDimensional)[SIZE] ) {
	
	
	int maxSum = 0;
	
	for ( int row = 0; row < SIZE; row++) {
		// Loop through columns on a row
		for ( int column = 0; column < LIMIT; column++) {
			int sum = 0;
			// Loop through columns in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += twoDimensional[row][column+k];
			}
			if ( sum > maxSum ) {
				maxSum = sum;
			}
		}
	}
	printf("Greatest sum of 5 adjacent numbers horizontally : %d\n",maxSum);
	return maxSum;
}


void testMatrix(){

    // Print the task
	printf("\nExercise 7 Task 3 - Find the greatest sum of five adjacent numbers in the same direction\n\n");
    
}

