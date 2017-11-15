#include <stdio.h>
int main(void)
{
    int a,num,max;
    while(scanf("%d",&a) != EOF){
        num = 0;
        max = 0;
        while(a){
            if(a & 1)    num ++;
            else    num = 0;
            if(num > max)    max = num;
            a = a >> 1;
        }
        printf("%d\n",max);
    }

    return 0;
}
