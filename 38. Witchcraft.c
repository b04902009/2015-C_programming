#include <stdio.h>
int magic(int D,int a,int b,int c,int A,int B,int C)
{
    //printf("magic(%d,%d,%d,%d)€n",D,a,b,c);
	if(D == 0)    return 1;
    if(a < 0 || b < 0 || c < 0 || D < 0)    return 0;

    if(a > 0 && magic(D-A,a-1,b,c,A,B,C))    return 1;
    else if(b > 0 && magic(D-B,a,b-1,c,A,B,C))	return 1;
    else if(c > 0 && magic(D-C,a,b,c-1,A,B,C))    return 1;
	else return 0;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t --){
		int D,a,b,c,A,B,C;
		scanf("%d%d%d%d%d%d%d",&D,&a,&b,&c,&A,&B,&C);
		if(magic(D,a,b,c,A,B,C))    printf("yes€n");
		else    printf("no€n");
	}

	return 0;
}
