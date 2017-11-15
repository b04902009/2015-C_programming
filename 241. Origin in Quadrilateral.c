#include <stdio.h>
#include <stdlib.h>
main()
{
	int a,b,c,d,e,f,g,h,k;
	scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
	k = (a*d+c*f+e*h+g*b-a*h-g*f-e*d-c*b == abs(a*d-c*b)+abs(c*f-e*d)+abs(e*h-g*f)+abs(g*b-a*h));
	printf("%d", k);
	return 0;
}
