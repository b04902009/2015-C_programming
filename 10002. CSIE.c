#include <stdio.h>
main()
{
    int h,w,a;
    int area,length;
    scanf("%d%d%d", &h, &w, &a);

    area = 4*a*(h+2*w-2*a);
    length = 8*h+16*w-8*a;

    printf("%d\n%d",area,length);
    return 0;
}
