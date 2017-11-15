#include <stdio.h>
main()
{
	int s,f,t;
	scanf("%d%d%d", &s, &f, &t);
	printf("%d\n%d\n%d", (8*s-f-4*t)/2, (f-8*s+6*t)/2, s-t );

	return 0;
}
