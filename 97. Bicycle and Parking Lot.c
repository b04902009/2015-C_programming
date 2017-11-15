#include <stdio.h>
#include <stdlib.h>
main()
{
    int n,m,i,j;
    scanf("%d",&n);
    int px[n],py[n],c[n];
    for(i = 0;i < n;i ++)
        scanf("%d%d%d",&px[i],&py[i],&c[i]);

    scanf("%d",&m);
    int bx[m],by[m];
    int p[m],min_d,min_d_x,min_d_y;
    for(i = 0;i < m;i ++){
        scanf("%d%d",&bx[i],&by[i]);
        min_d = min_d_x = min_d_y = 99999999;
        for(j = 0;j < n;j ++){
            if(c[j] > 0){
                int dx = abs(bx[i]-px[j]),dy = abs(by[i]-py[j]);
                int d = dx + dy;
                if(d < min_d){
                    min_d = d;
                    min_d_x = px[j];
                    min_d_y = py[j];
                    p[i] = j;
                }
                if(d == min_d && px[j] < min_d_x){
                    p[i] = j;
                    min_d_x = px[j];
                }
                if(d == min_d && px[j] == min_d_x && py[j] < min_d_y){
                    p[i] = j;
                    min_d_y = py[j];
                }
            }
        }
        c[p[i]] --;
    }

    int num[n];
    for(i = 0;i < n;i ++)  num[i] = 0;
    for(i = 0;i < m;i ++)  num[p[i]] ++;
    for(i = 0;i < n;i ++)  printf("%d\n",num[i]);

    return 0;
}
