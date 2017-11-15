#include <stdio.h>
int judge(char in[],int i)
{
    if(in[i] == ' ' || in[i] == '\n')    return 1;
    else if(in[i] == 'o' && in[i+1] == 'f' && (in[i+2] == ' ' || in[i+2] == '\n' || in[i+2] == '.'))    return 1;
    else if(in[i] == 'a' && in[i+1] == 't' && (in[i+2] == ' ' || in[i+2] == '\n' || in[i+2] == '.'))    return 1;
    else if(in[i] == 'a' && in[i+1] == 'n' && in[i+2] == 'd' && (in[i+3] == ' ' || in[i+3] == '\n' || in[i+3] == '.'))    return 1;
    else if(in[i] == 't' && in[i+1] == 'h' && in[i+2] == 'e' && (in[i+3] == ' ' || in[i+3] == '\n' || in[i+3] == '.'))    return 1;
    else    return 0;

}
int main()
{
    char in[1000000];
    int i = 0;
    while(scanf("%c",&in[i]) != EOF){
        int n = 0;
        if(in[i] == '.'){
            if(!judge(in,0))    printf("%c",in[0]-32);
            for(int j = 0;j < i;j ++)
                if((in[j] == ' ' || in[j] == '\n') && !judge(in,j+1))    printf("%c",in[j+1]-32);
            i = 0;
            printf("\n");
        }
        else    i ++;
    }

    return 0;
}
