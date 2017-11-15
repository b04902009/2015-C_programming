#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[100];
    int ans[4] = {0};
    scanf("%s",a);
    for(int i = 0;i < strlen(a);i ++)
        if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')){
            ans[1] ++;
            a[i] == 'a' || a[i] == 'e' || a[i] =='i' || a[i] =='o' || a[i] == 'u' || a[i] == 'A' || a[i]  == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' ? ans[2] ++ : ans[3] ++;
        }
        else if(a[i] >= '0' && a[i] <= '9')    ans[0] ++;

    printf("%d %d %d %d",ans[0],ans[1],ans[2],ans[3]);
    return 0;
}
