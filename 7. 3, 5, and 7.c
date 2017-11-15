#include <stdio.h>
main()
{
	int x, k;
	scanf("%d", &x);
	k = !((x % 15 == 0) && (x % 7 != 0));
	printf("%d", k);

	return 0;
}
