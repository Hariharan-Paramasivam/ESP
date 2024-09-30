// Question 3
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is odd or even
int check_odd_even(int* a) {
    if (*(a) & 1) {
        return 1; // Return 1 if the number is odd
    } else {
        return 0; // Return 0 if the number is even
    }
}

// Function to sort an array in ascending order using bubble sort
int* ascend(int* a, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (*(a + i) > *(a + j)) {
                // Swap the elements if they are out of order
                *(a + i) = *(a+i) + *(a+j);
                *(a + j) = *(a+i) - *(a + j);
                *(a + i) =  *(a+i) - *(a + j);
            }
        }
    }
    return a; // Return the sorted array
}

int main() {
    int num;

    // Ask the user for the number of elements in the array
    printf("No of elements in array: ");
    scanf("%d", &num);

    // Declare an array of size 'num'
    int arr[num];

    // Declare a pointer 'a' and point it to the beginning of the array
    int *a = arr;

    // Ask the user to enter the elements of the array separated by spaces
    printf("Enter elements of array with space: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", (a + i));
    }

    // Loop through the array to determine if each element is odd or even
    for (int i = 0; i < num; i++) {
        if (check_odd_even((a + i))) {
            printf("\nOdd number : %d", *(a + i));
        } else {
            printf("\nEven number : %d", *(a + i));
        }
    }

    // Sort the array in ascending order
    int *ascending_arr = ascend(arr, num);

    // Print the sorted array in ascending order
    printf("\nAscending Order");
    for (int i = 0; i < num; i++) {
        printf(" -> %d", *(ascending_arr++));
    }

    return 0;
}
