#include <stdio.h>
main()
{
    int X,Y,x[2],y[2],dx[2],dy[2],t,i;
    scanf("%d%d",&X,&Y);
    for(i = 0;i < 2;i ++)  scanf("%d%d",&x[i],&y[i]);
    for(i = 0;i < 2;i ++)  scanf("%d%d",&dx[i],&dy[i]);
    scanf("%d",&t);

    while(t --){
        for(i = 0;i < 2;i ++){
            x[i] += dx[i];
            y[i] += dy[i];
            if(x[i] == 1 || x[i] == X)  dx[i] *= -1;
            if(y[i] == 1 || y[i] == Y)  dy[i] *= -1;
        }
        if(x[1] == x[0] && y[1] == y[0]){
            if(dx[1] == dx[0] && dy[1] != dy[0]){
                dy[1] *= -1;
                dy[0] *= -1;
            }
            if(dx[1] != dx[0] && dy[1] == dy[0]){
                dx[1] *= -1;
                dx[0] *= -1;
            }
            if(dx[1] != dx[0] && dy[1] != dy[0]){
                dx[1] *= -1;
                dy[1] *= -1;
                dx[0] *= -1;
                dy[0] *= -1;
            }
        }
    }
    for(i = 0;i < 2;i ++)  printf("%d\n%d\n",x[i],y[i]);

    return 0;
}
