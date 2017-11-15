#include "polynomial.h"
#include <stdio.h>
void init(Polynomial *poly, int coefficient[], int n){
    poly->num = n-1;
    for(int i = 0;i < n;i ++)
        poly->co[i] = coefficient[i];
}
Polynomial add(Polynomial *poly1, Polynomial *poly2){
    Polynomial ans;
    ans.num = poly1->num > poly2->num ? poly1->num : poly2->num;
    for(int i = 0;i <= ans.num;i ++)
        ans.co[i] = (poly1->co[i]) + (poly2->co[i]);
    return ans;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2){
    Polynomial ans;
    ans.num = poly1->num + poly2->num;
    for(int i = 0;i <= 4096;i ++)
        ans.co[i] = 0;
    for(int i = 0;i <= poly1->num;i ++)
        for(int j = 0;j <= poly2->num;j ++)
                ans.co[i+j] += (poly1->co[i]) * (poly2->co[j]);
    return ans;
}
void print(Polynomial *poly){
    for(int i = poly->num;i > 1 ;i --)
        if(poly->co[i] != 0)    printf("%+dx^%d",poly->co[i],i);
    if(poly->co[1] != 0)    printf("%+dx",poly->co[1]);
    if(poly->co[0] != 0)    printf("%+d",poly->co[0]);
    printf("\n");
}