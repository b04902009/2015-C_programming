#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
    char num[1000];
    while(scanf("%s",num)){
        if(num[0] == '-' && num[1] == '1')    break;
        int l,odd = 0,even = 0;
        l = strlen(num);
        for(int j = 0;j < l;j += 2)    even += num[j] - '0';
        for(int k = 1;k < l;k += 2)    odd += num[k] - '0';

        (num[l-1]-'0') % 2 == 0 ? printf("yes ") : printf("no ");
        (even+odd) % 3 == 0 ? printf("yes ") : printf("no ");
        (num[l-1] == '0' || num[l-1] == '5') ? printf("yes ") : printf("no ");
        abs(odd-even) % 11 == 0 ? printf("yes€n") : printf("no€n");
    }

    return 0;
}
