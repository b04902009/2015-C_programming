#include <stdio.h>
int main(void)
{
    int n,step,c[12][102][102] ={{{0}}};
    scanf("%d%d",&n,&step);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++){
            scanf("%d",&c[0][i][j]);
            if(c[0][i][j] == 1)    c[step+1][i][j] ++;
        }
    for(int k = 0;k < step;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++){
                int neighbor = c[k][i-1][j-1]+c[k][i-1][j]+c[k][i-1][j+1]+c[k][i][j-1]+c[k][i][j+1]+c[k][i+1][j-1]+c[k][i+1][j]+c[k][i+1][j+1];
                if(c[k][i][j])
                    switch(neighbor){
                        case 2: case 3: c[k+1][i][j] = 1; c[step+1][i][j] ++; break;
                        default: c[k+1][i][j] = 0; break;
                    }
                else
                    if(neighbor == 3){
                        c[k+1][i][j] = 1;
                        c[step+1][i][j] ++;
                    }
            }
    int max = 0,x,y;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            if(c[step+1][i][j] >= max){
                x = i;
                y = j;
                max = c[step+1][i][j];
            }

    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++)
            if(j != n)    printf("%d ",c[step][i][j]);
            else    printf("%d",c[step][i][j]);
        printf("\n");
    }
    printf("%d %d",x,y);
    return 0;
}
