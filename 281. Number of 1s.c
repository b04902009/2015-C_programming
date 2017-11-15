#include <stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a) != EOF){
        int num = 0;
        while(a){
            if(a & 1)    num ++;
            a = a >> 1;
        }
        printf("%d\n",num);
    }

    return 0;
}
