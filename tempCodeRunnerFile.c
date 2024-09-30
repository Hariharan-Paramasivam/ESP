char var = '+';
        printf("Addition - (+)\nSubtraction - (-)\nMultiplication - (*)\nDivision - (/)\nExit - (x)\n"); // Explaining the Operations
        printf("Enter the Operation You Want to do (default Addition): ");
        scanf(" %c", &var); // getting the operator with a space to ignore preceding whitespace
        float x, y;