#include <stdio.h>
main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n%d\n%d", x/100, x/10 - x/100*10, x%10);
	
	return 0;
}
