#include <stdio.h>
int main(void)
{
    int length,height,flag = 0,num;
    char c_0,c_1;
    unsigned int a;
    scanf("%d%d€n%c %c",&length,&height,&c_1,&c_0);
    num = height * length;
    while(scanf("%u",&a) != EOF){
        for(int i = 31;i >= 0;i --){
            if((a >> i) & 1)    printf("%c",c_1);
            else    printf("%c",c_0);
            num --;
            if(num % length == 0)    printf("€n");
            if(num == 0){
                flag = 1;
                break;
            }
        }
        if(flag)    break;
    }

    return 0;
}
