#include <stdio.h>
int main(void)
{
    long long int a;
    while(scanf("%lld",&a) != EOF){
        int num = 0;
        while(a){
            if(a & 1)    num ++;
            a = a >> 1;
        }
        printf("%d\n",num);
    }
    return 0;
}
