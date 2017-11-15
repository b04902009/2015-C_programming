#include <stdio.h>
int add(int n)
{
	if(n == 1)   return 1;
	else    return add(n-1)+n*n;
}
int main(void)
{
	int num;
	scanf("%d",&num);
	printf("%d",add(num));
    return 0;
}
