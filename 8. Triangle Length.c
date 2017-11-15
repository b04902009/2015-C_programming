#include <stdio.h>
main()
{
	int a, b, c, k;
	scanf("%d%d%d", &a, &b, &c);

	k = (a > 0 && b > 0 && c > 0) && (a + b > c) && (b + c > a) && (a + c > b);
	printf("%d", k);
	
	return 0;
}
