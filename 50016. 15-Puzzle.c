#include <stdio.h>
int k,board[4][4],z_x,z_y,ans = 0;
void puzzle(int x,int y,int move)
{
    int flag = 0;
    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 4;j ++)
            if(board[i][j] == i*4+j+1)    flag ++;
    if(15-flag > k)    return;
    if(flag == 15){
        ans = 1;
        return;
    }
    for(int i = 0;i < 4;i ++){
        if(k > 0){
            if(i == 0 && y > 0){
                board[x][y] = board[x][y-1];
                board[x][y-1] = 0;
                k --;
                puzzle(x,y-1,i);
                k ++;
                board[x][y-1] = board[x][y];
                board[x][y] = 0;
            }
            if(i == 1 && y < 3){
                board[x][y] = board[x][y+1];
                board[x][y+1] = 0;
                k --;
                puzzle(x,y+1,i);
                k ++;
                board[x][y+1] = board[x][y];
                board[x][y] = 0;
            }
            if(i == 2 && x > 0){
                board[x][y] = board[x-1][y];
                board[x-1][y] = 0;
                k --;
                puzzle(x-1,y,i);
                k ++;
                board[x-1][y] = board[x][y];
                board[x][y] = 0;
            }
            if(i == 3 && x < 3){
                board[x][y] = board[x+1][y];
                board[x+1][y] = 0;
                k --;
                puzzle(x+1,y,i);
                k ++;
                board[x+1][y] = board[x][y];
                board[x][y] = 0;
            }
        }
    }
}
int main(void)
{
    while(scanf("%d",&k) != EOF){
        for(int i = 0;i < 4;i ++)
            for(int j = 0;j < 4;j ++){
                scanf("%d",&board[i][j]);
                if(board[i][j] == 0){
                    z_x = i;
                    z_y = j;
                }
            }
        ans = 0;
        puzzle(z_x,z_y,0);
        printf("%d€n",ans);
    }
    return 0;
}
