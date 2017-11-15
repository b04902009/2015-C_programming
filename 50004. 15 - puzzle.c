#include <stdio.h>
#include <stdlib.h>
int main()
{
    int puzzle[5][5],num,x[16],y[16],flag = 0;
    for(int i = 0;i < 4;i ++)
        for(int j = 0;j < 4;j ++){
            scanf("%d",&puzzle[i][j]);
            x[puzzle[i][j]] = i;
            y[puzzle[i][j]] = j;
        }
    while(scanf("%d",&num)){
        if(num == 0)  break;
        if(abs(x[num]-x[0]) + abs(y[num]-y[0]) == 1){
            int temp = x[num];
            x[num] = x[0];
            x[0] = temp;

            temp = y[num];
            y[num] = y[0];
            y[0] = temp;

            puzzle[x[num]][y[num]] = num;
            puzzle[x[0]][y[0]] = 0;
        }
        if(x[0] == 3 && y[0] == 3)
            for(int j = 1;j <= 15;j ++)
                if(j - 1 == x[j]*4 + y[j]){
                    flag ++;
                }
        if(flag == 15)  break;
        flag = 0;
    }

    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++){
            printf("%d",puzzle[i][j]);
            if(j != 3)  printf(" ");
        }
        printf("\n");
    }
    if(flag != 15)  printf("0");
    else  printf("1 %d",num);


    return 0;
}
