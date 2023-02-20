/*
File:           Task1.c
Author:         Uras Ayanoglu
Description:    Task1: Tribonacci Numbers
                Till the count reaches the number prompted:
                x <-- y; y <-- z, z <-- newVariable
                newVariable will be the sum of x, y, and z.
*/

#include <stdio.h>

int main(){

    int num = 0;
    int x = 0;
    int y = 1;
    int z = 2;
    int newVariable = 0;
    int count = 3;

    printf("Enter a number:\t");
    scanf("%d", &num);
    printf("\nTribonacci Numbers - Initial values for variables: x = %d , y = %d , z = %d", x, y, z);
    printf("\nTill count %d reaches the number prompted,", count);
    printf(" x will get y's; y will get z's; z will get new variable's value.");
    printf("\nNew variable will be the sum of variables x, y, and z!\n");
    
    // Iteration starts at number count and continues till count is smaller than number prompted.
    while (count < num){
        newVariable = x + y + z;
        printf("\nx:%d, y:%d, z:%d and New variable is: %d",x, y, z, newVariable);
        x = y;
        y = z;
        z = newVariable;
        count += 1; 
    }

    return 0;
}