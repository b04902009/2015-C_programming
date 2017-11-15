#include <stdio.h>
#include <string.h>
int len_a,len_b;
int min(int a,int b)
{
    if(a < b)    return a;
    else    return b;
}
int distance(char a[],char b[],int la,int lb)
{
    if(la == 0)    return lb;
    if(lb == 0)    return la;
    if(a[len_a-la] == b[len_b-lb])    return distance(a,b,la-1,lb-1);
    else    return 1+min(distance(a,b,la,lb-1),distance(a,b,la-1,lb));

}
int main(void)
{
    char word[100][11];
    int n = 0,ans[3] = {999999999,11,11};
    while(scanf("%s",word[n]) != EOF){
        for(int i = 0;i < n;i ++){
            len_a = strlen(word[i]);
            len_b = strlen(word[n]);
            int D = distance(word[i],word[n],len_a,len_b);
            if(D < ans[0]){
                ans[0] = D;
                ans[1] = i+1;
                ans[2] = n+1;
            }
            if(D == ans[0] && i+1 < ans[1]){
                ans[0] = D;
                ans[1] = i+1;
                ans[2] = n+1;
            }
        }
        n ++;
    }
    printf("%d %d %d",ans[0],ans[1],ans[2]);
    return 0;
}
