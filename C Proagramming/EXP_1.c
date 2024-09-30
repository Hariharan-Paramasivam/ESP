#include <stdio.h>
#include <stdlib.h>

// Do Arithmetic Operations for two numbers till the user exits
int main() {
    int running = 1;

    while (running) 
    {
        // switch variable
        char var = '+';
        printf("\nAddition - (+)\nSubtraction - (-)\nMultiplication - (*)\nDivision - (/)\nExit - (x)\n"); // Explaining the Operations
        printf("Enter the Operation You Want to do : ");
        scanf(" %c", &var); // getting the operator with a space to ignore preceding whitespace
        //printf("%c",var);
        if (var != 'x')
        {
            float x, y;
            printf("Enter the first number: ");
            scanf("%f", &x); // getting the 1st number
            printf("Enter the second number (for division don't give zero): ");
            scanf("%f", &y); // getting the second number

            // switch statement
            switch (var) 
            {
                case '+': // doing the addition operation
                    printf("\nAddition Operation.\n");
                    printf("Addition of numbers is: %f", x + y); // print the result
                    break;

                case '-': // doing the subtraction operation
                    printf("\nSubtraction Operation.\n");
                    printf("Subtraction of numbers is: %f", x - y); // print the result
                    break;

                case '*': // doing the multiplication operation
                    printf("\nMultiplication Operation.\n");
                    printf("Multiplication of numbers is: %f", x * y); // print the result
                    break;

                case '/': // doing the division operation
                    printf("\nDivision Operation.\n");
                    if (y == 0) {
                        printf("Division by zero is not possible.");
                    } else {
                        printf("Division of numbers is: %f", x / y); // print the result
                    }
                    break;
                default:
                    printf("Invalid operation. Please try again.");
                    break;
            }
            //continue;
        }
        else
        {
            running = 0;
            //continue; // exit the loop
        }
    }
    return 0;
}
