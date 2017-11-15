#include <stdio.h>
int gcd(int a, int b)
{
  int temp;
  while(a != 0){
     temp = a;
     a = b % a;
     b = temp;
  }
  return b;
}
int main(void)
{
    int a,ans = 1;
    while(scanf("%d",&a) != EOF){
        ans = ans * a / gcd(ans,a);
    }
    printf("%d",ans);

    return 0;
}
