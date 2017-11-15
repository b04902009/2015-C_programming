#include <stdio.h>
#include <string.h>
int main()
{
    char a[128],ans[128];
    scanf("%s",ans);
    int n = strlen(ans);
    while(scanf("%s",a) != EOF){
        int flag = 1;
        for(int i = strlen(a);i >= 0;i --)
            if(ans[n-1] == a[i]){
                int temp = 0;
                for(int j = 1;j <= i;j ++)    if(a[i-j] == ans[n-1-j])    temp ++;
                if(temp == i){
                    for(int j = i+1;j < strlen(a);j ++,n ++)    ans[n] = a[j];
                    flag = 0;
                    break;
                }
            }
        if(flag)    for(int j = 0;j < strlen(a);j ++,n ++)    ans[n] = a[j];
    }
    for(int i = 0;i < n;i ++)    printf("%c",ans[i]);

    return 0;
}
