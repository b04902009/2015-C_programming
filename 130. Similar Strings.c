#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t --){
        int flag = 1;
        char a[80],b[80];
        scanf("%s%s",a,b);
        if(abs((int)strlen(a)-(int)strlen(b)) > 1){
            printf("no\n");
            flag = 0;
            continue;
        }
        if(strlen(a) == strlen(b))
            for(int i = 0;i < strlen(a);i ++)
                if(a[i] != b[i]){
                    if(!(a[i+1] == b[i] && a[i] == b[i+1])){
                        printf("no\n");
                        flag = 0;
                    }
                    else{
                        for(int j = i+2;j < strlen(a);j ++)
                            if(a[j] != b[j]){
                                printf("no\n");
                                flag = 0;
                                break;
                            }
                    }
                    break;
                }
        if(strlen(a)-strlen(b) == 1){
            int i;
            for(i = 0;i < strlen(b);i ++)
                if(a[i] != b[i])    break;
            for(int j = i;j < strlen(b);j ++)
                if(!(a[j+1] == b[j])){
                    printf("no\n");
                    flag = 0;
                    break;
                }
        }
        if(strlen(b)-strlen(a) == 1){
            int i;
            for(i = 0;i < strlen(a);i ++)
                if(b[i] != a[i])    break;
            for(int j = i;j < strlen(a);j ++)
                if(!(b[j+1] == a[j])){
                    printf("no\n");
                    flag = 0;
                    break;
                }
        }
        if(flag == 1)    printf("yes\n");
    }
    return 0;
}
