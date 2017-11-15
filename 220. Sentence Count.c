#include <stdio.h>
#include <string.h>
int main(void)
{
    char c;
    int ans = 0;
    while(scanf("%c",&c) != EOF)
        while(c == '.'){
            scanf("%c",&c);
            if(c == EOF){
                ans ++;
                break;
            }
            else if(c == '\n')    ans ++;
            else if(c == ' '){
                scanf("%c",&c);
                if(c == ' ')    ans ++;
            }
        }

    printf("%d",ans);
    return 0;
}
