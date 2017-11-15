#include <stdio.h>
main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("%d\n", 2*(a*b+b*c+c*a)+8*d*(a+b+c-6*e) );
	printf("%d", a*b*c-(b-2*e)*(c-2*e)*2*d-(a-2*e)*(b-2*e)*2*d-(a-2*e)*(c-2*e)*2*d );

	return 0;
}
