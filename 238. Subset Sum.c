#include <stdio.h>
int subset(int n[], int num, int sum)
{
    if(sum == 0)   return 1;
    if(sum < 0 || num == 0)    return 0;
    return subset(n,num-1,sum)+subset(n,num-1,sum-n[num-1]);
}
int main(void)
{
	int num,n[15],sum;
	scanf("%d",&num);
	for(int i = 0;i < num;i ++)    scanf("%d",&n[i]);
	while(scanf("%d",&sum) != EOF){
		printf("%d\n",subset(n,num,sum));
	}
	return 0;
}
