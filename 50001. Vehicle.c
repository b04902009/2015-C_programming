#include <stdio.h>
#include <math.h>
main()
{
    int a,b,c,d,e,p,q,r,s,x,y,F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&p,&q,&r,&s,&x,&y,&F);
    int gold = abs(c*x+d*y)%e,i;
    int nx = x,ny = y;
    for(i = 0;i < F;i ++){
        x = nx;
        y = ny;
        if(abs(a*x+b*y) % 4 == 0)  ny ++;
        if(abs(a*x+b*y) % 4 == 1)  nx ++;
        if(abs(a*x+b*y) % 4 == 2)  ny --;
        if(abs(a*x+b*y) % 4 == 3)  nx --;
        gold += abs(c*nx+d*ny)%e;
        x = nx;
        y = ny;
        if(x == p && y == q){
            gold -= abs(c*x+d*y)%e;
            nx = r;
            ny = s;
        }
        if(x == r && y == s){
            gold -= abs(c*x+d*y)%e;
            nx = p;
            ny = q;
        }
    }
    printf("%d\n%d %d",gold,nx,ny);

    return 0;
}
