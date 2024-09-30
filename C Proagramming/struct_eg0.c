#include <stdio.h>
struct Point1
{
    int x,y;
};
struct Point2
{
    /* data */
    float X,Y;
};

int main()
{
    struct Point1 p1 = { 1, 2};
    struct Point2 p2 = {1.0,2.0};
    struct Point1 *p3 = &p1;
    struct Point2 *p4 = &p2;
    printf("%d %d\n",p3->x,p3->y);
    printf("%f %f\n",p4->X,p4->Y);
    return 0;

}