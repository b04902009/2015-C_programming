#include <stdio.h>
int main()
{
    int n, m, sx, sy;
    while(scanf("%d%d%d%d", &n, &m, &sx, &sy) != EOF){
        int x = sx, y = sy, move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, temp = -1;
        printf("%d %d\n", x ,y);
        while(1){
            if(x == sx && y == sy && temp != -1)  break;
            if(x == 0 && y != 0)  temp = 3;
            else if(x == 0 && y == 0)  temp = 0;
            else if(x == n-1 && y % 2 == 0)  temp = 1;
            else if(x == 1 && y % 2 == 1 && y != m-1)  temp = 1;
            else if(y % 2 == 0 && x != 0)  temp = 0;
            else if(y % 2 == 1 && x != 0)  temp = 2;
            x += move[temp][0];
            y += move[temp][1];
            printf("%d %d\n", x ,y);
        }
    }
    return 0;
}