#include <stdio.h>
main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    int num[r+1][c],i,j;
    for(j = 0;j < c;j ++)  num[r][j] = 0;
    for(i = 0;i < r;i ++)
        for(j = 0;j < c;j ++){
            scanf("%d",&num[i][j]);
            num[r][j] += num[i][j];
        }
    for(j = 0;j < c - 1;j ++)  printf("%d\n",num[r][j]/r);
    printf("%d",num[r][j]/r);
    return 0;
}
