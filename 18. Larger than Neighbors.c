#include <stdio.h>
main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    int num[r+2][c+2],i,j,ans[r*c],count = 0;
    for(i = 0;i <= r+1;i ++)
        for(j = 0;j <= c+1;j ++)
            num[i][j] = 0;
    for(i = 1;i <= r;i ++)
        for(j = 1;j <= c;j ++)
            scanf("%d",&num[i][j]);

    for(i = 1;i <= r;i ++)
        for(j = 1;j <= c;j ++){
            if(num[i][j] > num[i][j+1] && num[i][j] > num[i][j-1] && num[i][j] > num[i+1][j] && num[i][j] > num[i-1][j]){
                ans[count] = num[i][j];
                count ++;
            }
        }

    for(i = 0;i < count-1;i ++)  printf("%d\n",ans[i]);
    printf("%d",ans[count-1]);

    return 0;
}
