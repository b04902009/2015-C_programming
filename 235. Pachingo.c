#include <stdio.h>
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

int main()
{
    int N;
    scanf("%d",&N);
    int left,right,nu[16][16]={{0}},de[16][16]={{0}},temp_nu[40],temp_de[40];
    nu[0][0] = de[0][0] = 1;
    for(int i = 1;i <= N;i ++){
        for(int j = 0;j <= 2*i-2;j += 2){
            scanf("%d%d",&left,&right);
            if(left == 0)  right = 1;
            if(right == 0)  left = 1;
            int gcd_left_right = gcd(left,right);
            left /= gcd_left_right;
            right /= gcd_left_right;
            temp_nu[j] = nu[i-1][j/2] * left;
            temp_de[j] = de[i-1][j/2] * (left + right);
            temp_nu[j+1] = nu[i-1][j/2] * right;
            temp_de[j+1] = de[i-1][j/2] * (left + right);

            int gcd_tnu_tde = gcd(temp_nu[j],temp_de[j]);
            temp_nu[j] /= gcd_tnu_tde;
            temp_de[j] /= gcd_tnu_tde;
            gcd_tnu_tde = gcd(temp_nu[j+1],temp_de[j+1]);
            temp_nu[j+1] /= gcd_tnu_tde;
            temp_de[j+1] /= gcd_tnu_tde;
        }
        nu[i][0] = temp_nu[0];
        de[i][0] = temp_de[0];
        nu[i][i] = temp_nu[2*i-1];
        de[i][i] = temp_de[2*i-1];
        for(int j = 1;j < i;j ++){
            nu[i][j] = temp_nu[j*2-1] * temp_de[j*2] + temp_nu[j*2] * temp_de[j*2-1];
            de[i][j] = temp_de[j*2] * temp_de[j*2-1];
        }

        for(int j = 0;j <= i;j ++){
            int gcd_nu_de = gcd(nu[i][j],de[i][j]);
            nu[i][j] /= gcd_nu_de;
            de[i][j] /= gcd_nu_de;
        }
    }
    for(int i = 0;i <= N;i ++){
        printf("%d/%d",nu[N][i],de[N][i]);
        if(i != N)  printf("\n");
    }

    return 0;
}
