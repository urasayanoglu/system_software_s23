/*
File:           Task2.c
Author:         Uras Ayanoglu
Description:    Task2 creates an array with the size of  n (a number that user prompted (1-100)),
                Asks the user enter numbers, n times
                Replaces the value in the array at the index 0 if the number entered is bigger than 0th index
                Prints out the highest number in the array without decimals.

*/

#include <stdio.h>

int main(){
    
    int n = 0;
    float arr[100];

    printf("Enter total number of elements (1 to 100): ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++){

        printf("Enter number %d: ", i + 1); 
        scanf("%f", &arr[i]); // Assigns the number user entered at the ith index of the array.
    }
    
    // Checks if the user entered number is bigger than the number at the index 0, if so , 0th index will be replaced with the number entered.
    for (int i = 0; i < n; i++){
        if (arr[0] < arr[i]){
            arr[0] = arr[i];
        }
    }
   
    printf("What am I printing out? %2.f", arr[0]); // Prints the highest number in the array!

    return 0;
}