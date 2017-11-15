#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,r,w,a[60][10],m,s[60][10];
    char ans[60][10],stu[60][10];

    for(int i = 0;i < 60;i++)
        for(int j = 0;j < 5;j++){
            a[i][j] = 0;
            s[i][j] = 0;
        }

    scanf("%d%d%d",&n,&r,&w);
    for(int i = 0;i < n;i++)
        scanf("%s",ans[i]);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < strlen(ans[i]);j++)
            a[i][ans[i][j]-'A'] = 1;

    scanf("%d",&m);
    for(int k = 0;k < m;k++){
        int score = 0,flag = 0;
        for(int i = 0;i < 60;i++)
            for(int j = 0;j < 5;j++)
                s[i][j] = 0;
        for(int i = 0;i < n;i++)
            scanf("%s",stu[i]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < strlen(stu[i]);j++)
                if(stu[i][0] == 'N'){
                    score += w;
                    break;
                }
                else if(stu[i][j] >= 'A' && stu[i][j] <= 'E')    s[i][stu[i][j]-'A'] = 1;
                else    s[i][stu[i][j]-'a'] = 1;

        for(int i = 0;i < n;i ++){
            flag = 0;
            for(int j = 0;j < 5;j ++)
                if(a[i][j] != s[i][j]){
                    flag = 1;
                    break;
                }
            if(flag)    score -= w;
            else    score += r;
        }
        if(score < 0)    printf("0\n");
        else    printf("%d\n",score);
    }
    return 0;
}
