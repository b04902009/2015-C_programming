#include <stdlib.h>
main()
{
    int n;
    scanf("%d", &n);
    int i;
    for(i = 1;i < n;i ++)   printf("%d\n", i);
    for(i = n;i > 1;i --)   printf("%d\n", i);
    printf("1");

    return 0;
}
