#include <stdio.h>
#include <string.h>
char letter[100],rule[1000][3];
int count[26] = {0},num,n,flag = 0,r[26][26] = {{0}},ans[100];
void order(int t)
{
    if(flag){
        flag = 0;
        return;
    }
    else if(t == num){
        for(int i = 0;i < num;i ++)
            printf("%c",ans[i]+'a');
        printf("\n");
        flag = 0;
        return;
    }
    for(int i = 0;i < 26;i ++){
        if(count[i] > 0){
            ans[t] = i;
            count[i] --;
            if(t > 0 && r[ans[t-1]][i] == 1)    flag = 1;
            order(t+1);
            count[i] ++;
        }
    }
}
int main(void)
{
    scanf("%s",letter);
    num = strlen(letter);
    for(int i = 0;i < num;i ++)
        count[letter[i]-'a'] ++;

    scanf("%d",&n);
    for(int i = 0;i < n;i ++){
        scanf("%s",rule[i]);
        r[rule[i][0]-'a'][rule[i][1]-'a'] = 1;
    }
    order(0);
    return 0;
}
