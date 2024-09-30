#include<stdio.h>
#include<stdlib.h>

void add(int* x, int* y)
{
    int z;
    z=*x+*y;
    printf("\nsum = %d",z);
    printf("\nN0:1 = %d",*x);
    printf("\nN0:2 = %d",*y);
    *x+=1;
    *y+=1;
}
void main()
{
    int a=5,b=10;
    printf("\na : %d",a);
    printf("\nb : %d",b);
    add(&a,&b);
    printf("\na : %d",a);
    printf("\nb : %d",b);
}