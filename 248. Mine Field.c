#include<stdio.h>
int field[11][11],ans[11][11] = {{0}},flag = 0;
int check(int y,int x)
{
    if(x > 1 && y > 1 && field[y-1][x-1] != 0)    return 0;
    for(int i = -1;i <= 1;i ++)
        for(int j = -1;j <= 1;j ++)
            if(field[y+i][x+j] < 0)    return 0;
    return 1;
}
void mine(int y,int x)
{
    if(flag)    return;
    if(y == 10){
        flag = 1;
        for(int i = 1;i < 10;i ++)
            for(int j = 1;j < 10;j ++)
                printf("%d%c",ans[i][j],j == 9 ? '\n' : ' ');
        return;
    }

    if(check(y,x))    mine(y+x/9,x%9+1);

    ans[y][x] = 1;
    for(int i = -1;i <= 1;i ++)
        for(int j = -1;j <= 1;j ++)
            field[y+i][x+j] --;
    if(check(y,x))    mine(y+x/9,x%9+1);
    ans[y][x] = 0;
    for(int i = -1;i <= 1;i ++)
        for(int j = -1;j <= 1;j ++)
            field[y+i][x+j] ++;

}
int main(void)
{
    for(int i = 0;i < 11;i ++)
        field[0][i] = field[10][i] = field[i][0] = field[i][10] = 9;
    for(int i = 1;i < 10;i ++)
        for(int j = 1;j < 10;j ++)
            scanf("%d",&field[i][j]);
    mine(1,1);
    if(!flag)    printf("no solution\n");
    return 0;
}
