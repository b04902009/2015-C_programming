#include <stdio.h>
int map(int r,int c,int dst_r,int dst_c)
{
    if(r == dst_r && c == dst_c)    return 1;
    if(r == dst_r)    return map(r,c+1,dst_r,dst_c);
    else if(c == dst_c)    return map(r+1,c,dst_r,dst_c);
    else    return map(r+1,c,dst_r,dst_c)+map(r,c+1,dst_r,dst_c);

}
int main(void)
{
    int r,c;
    scanf("%d%d",&r,&c);
    printf("%d",map(0,0,r-1,c-1));

    return 0;
}
