#include <stdio.h>
main()
{
    int n,temp = 1,x,y,tic[9]={0},flag = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++){
        scanf("%d%d",&y,&x);
        if(x >= 0 && x < 3 && y >= 0 && y < 3 && tic[y*3+x] == 0){
            tic[y*3+x] = temp;
            temp *= -1;
            if(judge(tic) == -1){
                flag = 1;
                printf("White wins.");
                break;
            }
            else if(judge(tic) == 1){
                flag = 1;
                printf("Black wins.");
                break;
            }
        }
    }
    if(flag == 0)  printf("There is a draw.");

    return 0;
}

int judge(int *a)
{
    for(int i = 0;i < 3;i ++)
        if(a[3*i] == a[3*i+1] && a[3*i+1] == a[3*i+2])  return a[3*i];
    for(int i = 0;i < 3;i ++)
        if(a[i] == a[i+3] && a[i+3] == a[i+6])  return a[i];
    if(a[0] == a[4] && a[4] == a[8])  return a[0];
    else if(a[2] == a[4] && a[4] == a[6])  return a[2];
    else  return 0;
}
