#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[200000],command[1000];
    scanf("%s",s);
    int flag = 1,n = strlen(s);
    while(scanf("%s",command) == 1){
        char invalid,x,y;
        if(strcmp(command,"end") == 0)    break;
        if(strcmp(command,"replace") == 0){
            scanf("%c%c%c%c",&invalid,&x,&invalid,&y);
             for(int i = 0;i < n;i ++)
                if(s[i] == x)    s[i] = y;
        }
        else if(strcmp(command,"remove") == 0){
            scanf("%c%c",&invalid,&x);
            for(int i = 0;i < n;i ++)
                if(s[i] == x){
                    for(int j = i;j < n;j ++)    s[j] = s[j+1];
                    i --;
                    n --;
                }
        }
        else if(strcmp(command,"addhead") == 0){
            scanf("%c%c",&invalid,&x);
            for(int i = n;i > 0;i --)    s[i] = s[i-1];
            s[0] = x;
            n ++;
        }
        else if(strcmp(command,"addtail") == 0){
            scanf("%c%c",&invalid,&x);
            s[n] = x;
            n ++;
        }
        else{
            printf("invalid command %s",command);
            flag = 0;
            break;
        }
    }
    if(flag)    printf("%s",s);
    return 0;
}
