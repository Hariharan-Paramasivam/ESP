
#include<stdio.h>
//Static Program


/*void add(int b, int c)
 {
    static int a;
    printf("%d\n",a);


    a=b+c;
    printf("%d\n",a);
    printf("%d\n",&a);
 }
int main()
{
    add(5,6);
    add(5,8);
}*/ 
// Size of operator

//Size of operator is used to find the size of any data type or variable in bytes.

/*int main()
{
    int a;
    unsigned int b=4294967296;
    unsigned int e = 2147483647;
    float f;
    double d;
    char c;

    printf("Integer :%lu\n",sizeof(a));
    printf("Unsigned Int :%lu\n",sizeof(b));
    printf("Unsigned Int Value for e by d :%d\n",e);
    printf("Unsigned Int Value by d :%d\n",b);
    printf("Unsigned Int Value :%u\n",b);
    printf("Float :%lu\n",sizeof(f));
    printf("Double :%lu\n",sizeof(d));
    printf("Char :%lu\n",sizeof(c));
    

}*/

/*int main()
{
    int a[4]={1,2,3,4};
    

    printf("Integer :%lu\n",sizeof(a));
    printf("Integer :%d\n",a);
    printf("Integer :%d\n",&a[0]);
        
    

}*/
//pointer to Variable 

/*int main()
{
    int a,b,*c;
    int d[2];
    c=&a;
    printf("address of  %d\n",c);
    c=&b;
    printf("address of  %p\n",c);
    printf("address of  %p\n",&d[0]);
    printf("address of  %p\n",&d[1]);
    printf("sub d[1]-d[0] of  %p\n",((&d[1])-(&d[0]))/2^32);
    printf("sub a-b :  %p\n",((&a-&b)/2^32));
}

*/

// While
/*int main()
{
int i=5;
while(i<6){
    printf(" while inc This is Hari\n");
    i++;
}
i=9;
while(i>0){
    printf("while dec This is Hari\n");
    i--;
}
i=0;
// do while
do {
    printf("do while inc This is Hari\n");
    i++;

}
while(i>6);
i=8;
do {
    printf("do while inc This is Hari\n");
    i++;
}
while(i<8);

// Loop
for(i=1;i<6;i++)
{
printf("for inc This is Hari\n");
}
for(i=6;i>1;i--)
{
printf("for dec This is Hari\n");
}
}*/
// loop cntinue , break
/*int main(){
    int i = 10;
    //break
    for (i=0;i<10;i++)
    {
        if (i==3)
        {
            break;
        }
    printf("Number %d\n",i);
    }
    //continue
    for (i=0;i<10;i++)
    {
        if (i==3)
        {
            continue;
        }
    printf("\n continue - Number %d Hariharan \n",i);
    }
    
}
*/

// Array Operations
/*float avg()
{
    int n;
    
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    float sum=0.0;
    for(int i=n;i>0;i--)
    {
        sum+=arr[i];
        printf("\nNumber : %d",arr[i]);
        printf("\nSum : %f",sum);
    }
    printf("\nAverage of Sums - %f",sum/n);
    return 0;
}*/
/*int main()
{
    int a[5]={8,8,6,5,75};
    int *b,sum=0;
    b=&a[4];
    for (int i=0;i<5;i++)
    {
        sum+=*(b);
        printf("%d\n",*(b--));
        
        
    }
    printf("%d\n",sum);
    return 0;
    
}*/



// 
    
    
