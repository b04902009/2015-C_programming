#include <stdio.h>
#include <math.h>
main()
{
    int x[4],y[4],r[4],t,i,j,k;
    int R[11] = {0,5,13,29,49,81,113,149,197,253,317};
    scanf("%d",&t);
    while(t --){
        for(i = 0;i < 3;i ++)  scanf("%d%d%d",&x[i],&y[i],&r[i]);
        int num = R[r[0]]+R[r[1]]+R[r[2]],tangency = 0;
        x[3] = x[0];  y[3] = y[0];  r[3] = r[0];
        for(i = 0;i < 3;i ++){
            int pow_d = pow(x[i]-x[i+1],2) + pow(y[i]-y[i+1],2);
            if(pow_d <= pow(r[i]+r[i+1],2)){
                tangency ++;
                for(j = x[i]-r[i];j <= x[i]+r[i];j ++)
                    for(k = y[i]-r[i];k <= y[i]+r[i];k ++)
                        if(pow(j-x[i],2)+pow(k-y[i],2) <= r[i]*r[i] && pow(j-x[i+1],2)+pow(k-y[i+1],2) <= r[i+1]*r[i+1])  num -= 2;
            }
        }
        if(tangency == 3)
            for(j = x[0]-r[0];j <= x[0]+r[0];j ++)
                for(k = y[0]-r[0];k <= y[0]+r[0];k ++)
                    if(pow(j-x[0],2)+pow(k-y[0],2) <= pow(r[0],2) && pow(j-x[1],2)+pow(k-y[1],2) <= pow(r[1],2) && pow(j-x[2],2)+pow(k-y[2],2) <= pow(r[2],2))  num += 4;
        printf("%d\n",num);
    }
    return 0;
}
