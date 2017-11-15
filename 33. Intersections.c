#include <stdio.h>
int main(void)
{
    int n,ans[4]={0},c[102][102]={{0}};
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            scanf("%d",&c[i][j]);

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            if(c[i][j]) {
                switch(c[i-1][j] + c[i][j-1] + c[i][j+1] + c[i+1][j]) {
                    case 4: ans[0] ++; break;
                    case 3: ans[1] ++; break;
                    case 2:  if(!(c[i-1][j] && c[i+1][j]) && !(c[i][j-1] && c[i][j+1])) ans[2] ++; break;
                    case 1: ans[3] ++; break;
                }
            }
    for(int i = 0;i < 4;i ++)    printf("%d€n",ans[i]);
    return 0;
}

