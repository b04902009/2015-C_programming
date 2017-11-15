#include <stdio.h>
int main(void)
{
    int k,n,m,d;
    scanf("%d%d%d%d",&n,&k,&m,&d);
    int matrix[n][n],pattern[k][k];
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            scanf("%d",&matrix[i][j]);
    for(int i = 0;i < k;i ++)
        for(int j = 0;j < k;j ++){
            scanf("%d",&pattern[i][j]);
            d += pattern[i][j];
        }

    int x = -1,y = -1,mismatch = 0,sum = 0;
    for(int i = 0;i <= n-k;i ++)
        for(int j = 0;j <= n-k;j ++){
            for(int a = 0;a < k;a ++)
                for(int b = 0;b < k;b ++){
                    if(matrix[i+a][j+b] != pattern[a][b])   mismatch ++;
                    sum += matrix[i+a][j+b];
                }
            if(mismatch <= m && sum <= d){
                x = i;
                y = j;
            }
            sum = 0;
            mismatch = 0;
        }
    printf("%d %d",x,y);

    return 0;
}
