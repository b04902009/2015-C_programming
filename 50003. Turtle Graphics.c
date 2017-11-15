#include <stdio.h>
int min(int a,int b)
{
    if(a < b)  return a;
    else  return b;
}
int max(int a,int b)
{
    if(a > b)  return a;
    else  return b;
}
main()
{
    int L,X,Y,n,x,y,old_x,old_y,flag = 1;
    scanf("%d%d%d",&L,&X,&Y);
    int m[X][Y];
    for(int i = 0;i < X;i ++)
        for(int j = 0;j < Y;j ++)
            m[i][j] = 0;
    for(int i = 0;i < L;i ++){
        scanf("%d",&n);
        scanf("%d%d",&old_x,&old_y);
        for(int l = 0;l < n-1;l ++){
            scanf("%d%d",&x,&y);
            if(x != old_x && y == old_y)
                for(int j = min(x,old_x);j <= max(x,old_x);j ++)
                    m[X-1-y][j] = 1;
            else if(x == old_x && y != old_y)
                for(int j = min(y,old_y);j <= max(y,old_y);j ++)
                    m[X-1-j][x] = 1;

            else if(x - old_x == y - old_y){
                int k = 0;
                for(int j = min(x,old_x);j <= max(x,old_x);j ++){
                    m[X-1-min(y,old_y)-k][j] = 1;
                    k ++;
                }
            }
            else if(x - old_x == old_y - y){
                int k = 0;
                for(int j = min(x,old_x);j <= max(x,old_x);j ++){
                    m[X-1-max(y,old_y)+k][j] = 1;
                    k ++;
                }
            }
            else{
                printf("ERROR %d %d\n",i+1,l+2);
                flag = 0;
                break;
            }
            old_x = x;
            old_y = y;
        }
        if(flag == 0)  break;
    }

    if(flag)
        for(int i = 0;i < X;i ++){
            for(int j = 0;j < Y;j ++)
                printf("%d",m[i][j]);
            if(i != X-1)  printf("\n");
        }

    return 0;
}
