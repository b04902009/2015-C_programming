#include <stdio.h>
#include <stdlib.h>
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
int overlap(int xa1,int ya1,int xa2,int ya2,int xb1,int yb1,int xb2,int yb2)
{
    int xc1,xc2,yc1,yc2;
    xc1 = max(xa1,xb1);
    xc2 = min(xa2,xb2);
    yc1 = max(ya1,yb1);
    yc2 = min(ya2,yb2);
    if(xc2 > xc1 && yc2 > yc1)
        return    (xc2-xc1) * (yc2-yc1);
    else
        return 0;
}
int main(void)
{
    int  l[4],b[4],r[4],t[4],area = 0;
    for(int i = 0;i < 3;i ++)    scanf("%d%d%d%d",&l[i],&b[i],&r[i],&t[i]);
    l[3] = l[0];    b[3] = b[0];    r[3] = r[0];    t[3] = t[0];
    for(int i = 0;i < 3;i ++)    area += (r[i]-l[i]) * (t[i]-b[i]);
    for(int i = 0;i < 3;i ++)    area -= overlap(l[i],b[i],r[i],t[i],l[i+1],b[i+1],r[i+1],t[i+1]);
    area += overlap(max(l[0],l[1]),max(b[0],b[1]),min(r[0],r[1]),min(t[0],t[1]),l[2],b[2],r[2],t[2]);
    printf("%d",area);
    return 0;
}
