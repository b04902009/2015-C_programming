#include <stdio.h>
main()
{
	int h,w,d;
	scanf("%d%d%d", &h, &w, &d);
	printf("%d\n", 2*(h*w+w*d+d*h));
	printf("%d", h*w*d);
	
	return 0;
}
