#include <stdio.h>
int main(void)
{
    int k,n,pos = 0,neg = 0,flag = 1,max_flag,num = 0,max = 0;
    scanf("%d",&k);
    while(scanf("%d",&n)){
        if(n == 0)    break;
        int con = 0;
        n > 0 ? pos ++ : neg ++;
        if(flag == 1 && pos < k && pos > 0 && neg > 0){
            flag = -1;
            pos = 0;
            num = 0;
        }
        else if(flag == -1 && pos > 0 && neg < k && neg > 0){
            flag = 1;
            neg = 0;
            num = 0;
        }
        else if(flag == -1 && pos != 0){
            pos = k;
            flag = 1;
            num = k;
            con = 1;
        }
        else if(flag == 1 && neg != 0){
            neg = k;
            flag = -1;
            num = 0;
            con = 1;
        }
        if(pos * flag  == k && neg == 0){
            if(!con)    num += pos;
            if(num > max){
                max = num;
                max_flag = flag;
            }
            flag *= -1;
            pos = 0;
        }
        else if(neg * flag  == -1 * k && pos == 0){
            if(!con)    num += neg;
            if(num > max){
                max = num;
                max_flag = flag;
            }
            flag *= -1;
            neg = 0;
        }
    }
    if(max_flag == -1)     max -= k;
    if((max/k) % 2 == 0 && max != 0)    max -= k;
    if(max == k)    max = 0;

    printf("%d",max);

    return 0;
}
