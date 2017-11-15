#include <stdio.h>
#include <string.h>
main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int board[n][m*m],order,place[n][m*m+1];
    char name[n][20];
    for(int i = 0;i < n;i ++){
        scanf("%s",&name[i]);
        for(int j = 0;j < m;j ++)
            for(int k = 0;k < m;k ++){
                scanf("%d",&board[i][j*m+k]);
                place[i][board[i][j*m+k]] = j*m+k;
            }
    }
    int count = 0;
    for(int l = 0;l < m*m;l ++){
        scanf("%d",&order);
        for(int i = 0;i < n;i ++){
            int flag = -1;
            board[i][place[i][order]] = 0;
            if(judge(m,board[i])){
                if(count == 0)  printf("%d",order);
                flag = i;
                printf(" %s",name[flag]);
                count ++;
            }
        }
        if(count != 0)  break;
    }

    return 0;
}

int judge(int m,int *a)
{
    for(int i = 0;i < m;i ++){
        int count = 0;
        for(int j = 0;j < m;j ++)
            if(a[i*m] == a[i*m+j])  count ++;
            else  break;
        if(count == m)  return 1;
    }
    for(int i = 0;i < m;i ++){
        int count = 0;
        for(int j = 0;j < m;j ++)
            if(a[i] == a[j*m+i])  count ++;
            else  break;
        if(count == m)  return 1;
    }
    int count = 0;
    for(int i = 0;i < m;i ++){
        if(a[0] == a[i*m+i])  count ++;
        else  break;
        if(count == m)  return 1;
    }
    count = 0;
    for(int i = 0;i < m;i ++){
        if(a[m-1] == a[i*m+m-i-1])  count ++;
        else  break;
        if(count == m)  return 1;
    }
    return 0;
}
