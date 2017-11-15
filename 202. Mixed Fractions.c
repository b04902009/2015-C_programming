#include <stdio.h>
#include <math.h>
main()
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int i = a*c+b, j = c, k = e*g+f, l = g;
    if(a < 0)  i -= 2*b;
    if(e < 0)  k -= 2*f;

    int A = 0,B,C;
    if(d == 0){
        B = i*l+j*k;
        C = j*l;
    }
    if(d == 1){
        B = i*l-j*k;
        C = j*l;
    }
    if(d == 2){
        B = i*k;
        C = j*l;
    }
    if(d == 3){
        B = i*l;
        C = j*k;
    }
    A = B/C;
    B -= A*C;
    if(A < 0)  B *= -1;
    if(B == 0)  C = 1;

    int gcd_A_B;
    gcd_A_B = gcd(B,C);
    B /= gcd_A_B;
    C /= gcd_A_B;

    printf("%d\n%d\n%d",A,B,C);

    return 0;
}

int gcd(int a, int b)
{
  int temp;
  while(a != 0){
     temp = a;
     a = b % a;
     b = temp;
  }
  return b;
}
