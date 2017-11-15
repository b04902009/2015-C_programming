#include <stdio.h>
main()
{
    int W,D;
    scanf("%d%d",&W,&D);
    int cell[D+2][W+2],i,j,end[2*(D+W)];

    for(i = 1;i <= D;i ++){
        cell[i][0] = 2*W + D + i - 1;
        cell[i][W+1] = W + D  - i;
    }
    for(j = 1;j <= W;j ++){
        cell[0][j] = 2*W + D - j;
        cell[D+1][j] = j - 1;
    }

    for(i = 1;i <= D;i ++)
        for(j = 1;j <= W;j ++)
            scanf("%d",&cell[i][j]);

    for(j = 1;j <= W;j ++){
        int x = j,y = D,path = 1;  //path:  1:往上  -1:往右  2:往下  -2:往左
        while(x <= W && x > 0 && y > 0 && y <= D){
            if(cell[y][x] == 0){
                if(path == 1)  y --;
                if(path == -1)  x ++;
            }
            else{
                path *= -1;
                if(path == 1)  y --;
                if(path == -1)  x ++;
            }
            end[j-1] = cell[y][x];
        }

        x = j;  y = 1;  path = 2;
        while(x <= W && x > 0 && y > 0 && y <= D){
            if(cell[y][x] == 0){
                if(path == 2)  y ++;
                if(path == -2)  x --;
            }
            else{
                path *= -1;
                if(path == 2)  y ++;
                if(path == -2)  x --;
            }
            end[2*W+D-j] = cell[y][x];
        }
    }

    for(i = 1;i <= D;i ++){
        int x = 1,y = i,path = -1;  //path:  1:往上  -1:往右  2:往下  -2:往左
        while(x <= W && x > 0 && y > 0 && y <= D){
            if(cell[y][x] == 0){
                if(path == 1)  y --;
                if(path == -1)  x ++;
            }
            else{
                path *= -1;
                if(path == 1)  y --;
                if(path == -1)  x ++;
            }
            end[2*W+D+i-1] = cell[y][x];
        }

        x = W;  y = i;  path = -2;
        while(x <= W && x > 0 && y > 0 && y <= D){
            if(cell[y][x] == 0){
                if(path == 2)  y ++;
                if(path == -2)  x --;
            }
            else{
                path *= -1;
                if(path == 2)  y ++;
                if(path == -2)  x --;
            }
            end[W+D-i] = cell[y][x];
        }
    }

    for(i = 0;i < 2*(W+D)-1;i ++)  printf("%d\n",end[i]);
    printf("%d",end[2*(W+D)-1]);

    return 0;
}
