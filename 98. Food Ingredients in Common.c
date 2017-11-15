#include <stdio.h>
#include <string.h>
int main(void)
{
    int n_food,n_ingredient[100],n_query;
    char food[100][65],ingredient[100][10][65];
    scanf("%d",&n_food);
    for(int i = 0;i < n_food;i ++){
        scanf("%s%d",food[i],&n_ingredient[i]);
        for(int j = 0;j < n_ingredient[i];j ++)    scanf("%s",ingredient[i][j]);
    }

    scanf("%d",&n_query);
    char query_food[2][65],qiery_food_num[2],ans[10000][10][65];
    int n[10000] = {0};
    for(int i = 0;i < n_query;i ++){
        for(int j = 0;j < 2;j ++){
            scanf("%s",query_food[j]);
            for(int k = 0;k < n_food;k ++)
                if(strcmp(food[k],query_food[j]) == 0)    qiery_food_num[j] = k;
        }
        for(int j = 0;j < n_ingredient[qiery_food_num[0]];j ++)
            for(int k = 0;k < n_ingredient[qiery_food_num[1]];k ++)
                if(strcmp(ingredient[qiery_food_num[0]][j],ingredient[qiery_food_num[1]][k]) == 0){
                    strcpy(ans[i][n[i]],ingredient[qiery_food_num[0]][j]);
                    n[i] ++;
                    continue;
                }
        for(int j = n[i]-1;j >= 0 ;j --)
            for(int k = 0;k < j;k ++)
                if(strcmp(ans[i][k],ans[i][k+1]) > 0){
                    char temp[65];
                    strcpy(temp,ans[i][k]);
                    strcpy(ans[i][k],ans[i][k+1]);
                    strcpy(ans[i][k+1],temp);
                }
    }
    for(int i = 0;i < n_query;i ++){
        if(n[i] == 0)    printf("nothing");
        for(int j = 0;j < n[i];j ++)
            j != n[i]-1 ? printf("%s ",ans[i][j]) : printf("%s",ans[i][j]);
        if(i != n_query-1)    printf("\n");
    }
    return 0;
}
