#include <stdio.h>
int map(int obs[12][12],int r,int c,int dst_r,int dst_c)
{
    if(r == dst_r && c == dst_c)    return 1;
    if(obs[r][c] == 0)    return 0;
    if(r == dst_r)    return map(obs,r,c+1,dst_r,dst_c);
    else if(c == dst_c)    return map(obs,r+1,c,dst_r,dst_c);
    else    return map(obs,r+1,c,dst_r,dst_c)+map(obs,r,c+1,dst_r,dst_c);

}
int main(void)
{
    int r,c,obs[12][12];
    scanf("%d%d",&r,&c);
    for(int i = r-1;i >= 0;i --)
        for(int j = 0;j < c;j ++)
            scanf("%d",&obs[i][j]);
    printf("%d",map(obs,0,0,r-1,c-1));

    return 0;
}
