// Question 1
/*
#include <stdio.h>
#include<stdlib.h>

// Do Arthimetic Operations for two numbers till user exits
int main()
{
while(1)
{
  // switch variable
    char var = 'a';
    printf("Addition - (+)\nSubtarction - (-)\nMultiplication - (*) \nDivision - (/)\n Exit - (x)");  // Explaining the Operations
    printf("Enter the Operation You Want to do(default Addition):"); 
    scanf("%c",&var); // getting the operator
    if (var=='x')
    {
        exit(0);
    }

    float x,y;
    printf("Enter the first number:");
    scanf("%f",&x); // getting the 1st number
    printf("\nEnter the second number(for division don't give zero):");
    scanf("%f",&y); // getting the secondd number

   



  // switch statement
    switch (var) {
        case '+': // doing the addition operation
            printf("\nAddition Operation.");
            printf("\nAddition of numbers is %f",x+y); // print the result
            break;

        case '-': // doing the subtraction operation
            printf("\nSubtract Operation.");
            printf("\nSubtraction  of numbers is %f",x-y); // print the result
            break;

        case '*': // doing the multiplication operator
            printf("\nMultiplication Operation.");
            printf("\nMultiplication of numbers is %f",x*y); // print the result
            break;
        case '/': // doing the division operator
            printf("\nDivision Operation.");
            if (y==0)
            {
                printf("Division is not possible for zero");
                break;
            }
            printf("\nDivision of numbers is %f",x/y); // print the result
            break;

        default:
            printf("\nDefault case is Matched."); // doing the default operation 
            printf("\nAddition Operation.");
            printf("\nAddition of numbers is %f",x+y); // print the result
            break;
    }

    return 0;
}
}


*/

/*
// Question 2
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("No of elements in array: ");
    scanf("%d",&num);
    int arr[num];
    int *a=arr;
    for(int i=0;i<num;i++)
    {
        scanf("%d",(a+i));
    }
    
    for(int i=0;i<num;i++)
    {
        if(*(a+i)&1)
        {
            printf("\nOdd number : %d",*(a+i));
        }
        else
        {
            printf("\nEven number : %d",*(a+i));
        }
    }
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if (*(a+i) > *(a+j)) 
                {
 
                    int b =  *(a+i);
                    *(a+i) = *(a+j);
                    
                    *(a+j) = b;
 
                }
        }
    }
    printf("\n Ascending Order");
    for(int i=0;i<num;i++)
    {
        printf("\n%d",*(a++));
    }
    return 0;
    
}
*/
// Question 3
#include <stdio.h>
#include <stdlib.h>
int check(int* a,int num)
{
    for(int i=0;i<num;i++)
    {
        if(*(a+i)&1)
        {
            printf("\nOdd number : %d",*(a+i));
        }
        else
        {
            printf("\nEven number : %d",*(a+i));
        }
    }
    return 0;
}


int* ascend(int* a,int num)
{
    
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if (*(a+i) > *(a+j)) 
                {
 
                    int b =  *(a+i);
                    *(a+i) = *(a+j);
                    
                    *(a+j) = b;
 
                }
        }
    }
    return a;
}

int main()
{
    int num;
    printf("No of elements in array: ");
    scanf("%d",&num);
    int arr[num];
    int *a=arr;
    for(int i=0;i<num;i++)
    {
        scanf("%d",(a+i));
    }
    
    check(arr,num);
    
    int *ascending_arr = ascend(arr,num);
    printf("\n Ascending Order");
    for(int i=0;i<num;i++)
    {
        printf("->%d",*(ascending_arr++));
    }
}
