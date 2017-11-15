#include <stdio.h>
main()
{
	int x, k = -50;
	scanf("%d", &x);
	if(x <= 0)  printf("-100");
	else{
		if(x % 3 == 0)  k += 3;
	    if(x % 5 == 0)  k += 5;
	    if(x >= 100 && x <= 200)  k += 100;
		printf("%d", k);
	}
	return 0;
}
