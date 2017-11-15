#include <stdio.h>
int main(void)
{
    char letter;
    int num[27] = {0};
    while(scanf("%c",&letter) != EOF)
        if(letter >= 65 && letter <= 90)    num[letter-65] ++;
        else if(letter >= 97 && letter <= 122)    num[letter-97] ++;

    for(int i = 0;i < 26;i ++)    printf("%d\n",num[i]);
    return 0;
}
