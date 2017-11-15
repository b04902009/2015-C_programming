#include<stdio.h>
int main(void)
{
    double a,b,c,area = 0;
    scanf("%lf%lf%lf",&a,&b,&c);
    area += 0.75*c*c;
    if(c > a)    area += 0.25*(c-a)*(c-a);
    if(c > b)    area += 0.25*(c-b)*(c-b);

    printf("%f",area*3.1415926);

    return 0;
}

