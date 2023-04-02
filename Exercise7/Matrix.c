/*
File      :   Matrix.c
Time      :   27.03.2023 22:42:15
Compile   :   gcc -Wall -Wextra -std=c18 Matrix.c -o Matrix
Version   :   1.0
Author(s) :   Uras Ayanoglu, Jan-Krister Helenius
Contact   :   uras.ayanoglu@edu.turkuamk.fi, jan-krister.helenius@edu.turkuamk.fi
Desc      :   Find the greatest sum of five adjacent numbers in the same direction
*/

#include <stdio.h>
#include "Matrix.h"

const int twoDimensional[SIZE][SIZE] = {
	{ 8,  2, 22, 97, 38, 15, 00, 40, 00, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
	{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62, 00},
	{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
	{52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
	{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 18},
	{24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
	{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
	{67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94,  1},
	{24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
	{21, 36, 23,  9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95},
	{78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
	{16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57},
	{86, 56, 00, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
	{19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 04},
	{ 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
	{88, 36, 68, 87, 87, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53,  9},
	{ 4, 42, 16, 73, 38, 95, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
	{20, 69, 36, 41, 72, 30, 79, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
	{20, 73, 35, 29, 78, 31, 90, 81, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
	{ 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48}
};

int rowSum = 0;
int columnSum = 0;
int diagonalSum = 0;

void testMatrix() {

    int greatest = greatestSum();

    printf("The greatest sum of 5 adjacent numbers is: %d", greatest);
	printf("\nGreatest row sum = %d",rowSum);
	printf("\nGreatest column sum = %d",columnSum);
	printf("\nGreatest diagonal sum = %d",diagonalSum);

}

int greatestSum() {
    int i = 0;
	int j = 0;
	int sum = 0;
	int maxSum = 0;

    // Check rows for greatest sum
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= SIZE - 5; j++) {
            sum = twoDimensional[i][j] + twoDimensional[i][j+1] + twoDimensional[i][j+2] + twoDimensional[i][j+3] + twoDimensional[i][j+4];
            if (sum > maxSum) {
				rowSum = sum;
                maxSum = sum;
            }
        }
    }

    // Check columns for greatest sum
    for (i = 0; i <= SIZE - 5; i++) {
        for (j = 0; j < SIZE; j++) {
            sum = twoDimensional[i][j] + twoDimensional[i+1][j] + twoDimensional[i+2][j] + twoDimensional[i+3][j] + twoDimensional[i+4][j];
            if (sum > maxSum) {
				columnSum = sum;
                maxSum = sum;
            }
        }
    }

    // Check diagonals for greatest sum
    for (i = 0; i <= SIZE - 5; i++) {
        for (j = 0; j <= SIZE - 5; j++) {
            sum = twoDimensional[i][j] + twoDimensional[i+1][j+1] + twoDimensional[i+2][j+2] + twoDimensional[i+3][j+3] + twoDimensional[i+4][j+4];
            if (sum > maxSum) {
				diagonalSum = sum;
                maxSum = sum;
            }

            sum = twoDimensional[i][j+4] + twoDimensional[i+1][j+3] + twoDimensional[i+2][j+2] + twoDimensional[i+3][j+1] + twoDimensional[i+4][j];
            if (sum > maxSum) {
				diagonalSum = sum;
                maxSum = sum;
            }
        }
    }

    return maxSum;
}


