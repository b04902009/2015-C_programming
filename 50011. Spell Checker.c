#include <string.h>
char word[100000][100],len[100000],que[1000];
int main(void)
{
    int w,q;
    scanf("%d",&w);
    for(int i = 0;i < w;i ++){
        scanf("%s",word[i]);
        len[i] = strlen(word[i]);
    }

    scanf("%d",&q);
    for(int i = 0;i < q;i ++){
        int judge = 1,if_print = 0;
        scanf("%s",que);
        int n = strlen(que);
        for(int j = 0;j < w;j ++)
            if(n == len[j] && strcmp(que,word[j]) == 0){
                printf(">%s",que);
                if_print = 1;
                judge = 0;
                break;
            }
        if(judge != 0){
            for(int j = 0;j < w;j ++){
                if(n == len[j]){
                    int num = 0,flag = 1;
                    for(int k = 0;k < len[j];k ++){
                        if(que[k] != word[j][k])    num ++;
                        if(num > 2)    break;
                    }
                    if(num == 1){
                        if(if_print == 0)    printf("?");
                        printf("%s ",word[j]);
                        if_print = 1;
                    }
                }

                if(n-len[j] == 1){
                    int k,flag = 1;
                    for(k = 0;k < len[j];k ++){
                        if(que[k] != word[j][k])    break;
                    }
                    for(int l = k;l < len[j];l ++){
                        if(que[l+1] != word[j][l]){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        if(if_print == 0)    printf("?");
                        printf("%s ",word[j]);
                        if_print = 1;
                    }
                }
                if(len[j]-n == 1){
                    int k,flag = 1;
                    for(k = 0;k < len[j];k ++)
                        if(que[k] != word[j][k])    break;
                    for(int l = k;l < len[j]-1;l ++){
                        if(que[l] != word[j][l+1]){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        if(if_print == 0)    printf("?");
                        printf("%s ",word[j]);
                        if_print = 1;
                    }
                }
            }
        }

        if(if_print == 0)    printf("!%s",que);
        printf("\n");
    }
    return 0;
}
