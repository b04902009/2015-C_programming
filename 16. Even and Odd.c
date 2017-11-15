#include <stdio.h>
main()
{
    int n,i;
    scanf("%d",&n);
    int a[n],odd[n],even[n],num_odd = 0,num_even = 0;
    for(i = 0;i < n;i ++){
        scanf("%d",&a[i]);
        if(a[i] % 2 == 1){
            odd[num_odd] = a[i];
            num_odd ++;
        }
        if(a[i] % 2 == 0){
            even[num_even] = a[i];
            num_even ++;
        }
    }
    for(i = 0;i < num_odd - 1;i ++)  printf("%d ",odd[i]);
    printf("%d\n",odd[num_odd - 1]);
    for(i = 0;i < num_even - 1;i ++)  printf("%d ",even[i]);
    printf("%d",even[num_even - 1]);

    return 0;
}
