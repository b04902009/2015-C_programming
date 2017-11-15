#include <stdio.h>
main()
{
	int s,f,t;
	scanf("%d%d%d", &s, &f, &t);
	if( (8*s-f-4*t) % 2 != 0 || (f-8*s+6*t) % 2 != 0 )  printf("0");
	else if( (8*s-f-4*t) < 0 || (f-8*s+6*t) < 0 || s-t < 0 )  printf("0");
	else  printf("%d\n%d\n%d", (8*s-f-4*t)/2, (f-8*s+6*t)/2, s-t );

	return 0;
}
