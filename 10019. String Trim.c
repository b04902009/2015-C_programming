#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char c[100],b[100];
    gets(c);
    int i,l = 0;
    for(i = 0;i < strlen(c);i ++)    if(!isspace(c[i]))    break;
    for(int j = i;j < strlen(c);j ++,l ++)    b[l] = c[j];
    for(i = l-1;i >= 0;i --)    if(!isspace(b[i]))    break;

    for(int j = 0;j < i+1;j ++)    printf("%c",b[j]);
    return 0;
}
