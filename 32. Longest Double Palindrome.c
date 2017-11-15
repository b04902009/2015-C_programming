#include <stdio.h>
int main(void)
{
    int n = 0,a[200];
    while(scanf("%d",&a[n]) == 1)  n ++;

    int max = 0,start,end;
    for(int i = 0;i < n;i ++){
        int max1 = 0;
        for(int j = 0;j <= i;j ++){
            int flag = 1;
            for(int k = 1;k <= (i-j+1)/2;k ++)
                if(a[(i+j+1)/2-k] != a[(i+j)/2+k]){
                    flag = 0;
                    break;
                }
            if(flag == 1){
                max1 = i-j+1;
                break;
            }
        }
        int max2 = 0;
        for(int j = n-1;j >= i+1;j --){
            int flag = 1;
            for(int k = 1;k <= (j-i)/2;k ++)
                if(a[(i+j+2)/2-k] != a[(i+j+1)/2+k]){
                    flag = 0;
                    break;
                }
            if(flag == 1){
                max2 = j-i;
                break;
            }
        }
        if(max1+max2 >= max && i+max2 > end){
            max = max1+max2;
            start = i-max1+1;
            end = i+max2;
        }
    }
    for(int i = start;i <= end;i ++)
        if(i != end)    printf("%d ",a[i]);
        else    printf("%d",a[i]);

    return 0;
}
