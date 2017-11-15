#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medicine.h"
int cmp(const void* a,const void* b){
    Ingredient *c = (Ingredient *)a;
    Ingredient *d = (Ingredient *)b;
    if(c->weight == d->weight)    return strcmp(c->name,d->name);
    else    return d->weight-c->weight;
}
void init(Medicine *medicine)
{
    medicine->num_active = 0;
    medicine->num_inactive = 0;
    for(int i = 0;i < 6;i ++){
        medicine->active[i].weight = 0;
        medicine->inactive[i].weight = 0;
    }
}
int addActive(Medicine *medicine, char *name, int weight)
{
    int n = medicine->num_active;
    for(int i = 0;i < n;i ++)
        if(strcmp(name,medicine->active[i].name) == 0){
            medicine->active[i].weight += weight;
            return medicine->active[i].weight;
        }
    if(n == 2)    return -1;
    else{
        strcpy(medicine->active[n].name,name);
        medicine->active[n].weight = weight;
        medicine->num_active ++;
        return medicine->active[n].weight;
    }
}
int addInactive(Medicine *medicine, char *name, int weight)
{
    int ans,m = medicine->num_inactive;
    for(int i = 0;i < m;i ++)
        if(strcmp(name,medicine->inactive[i].name) == 0){
            medicine->inactive[i].weight += weight;
            return medicine->inactive[i].weight;
        }
    if(m == 5)    return -1;
    else{
        strcpy(medicine->inactive[m].name,name);
        medicine->inactive[m].weight = weight;
        medicine->num_inactive ++;
        return medicine->inactive[m].weight;
    }
}
void print(Medicine *medicine)
{
    int n = medicine->num_active,m = medicine->num_inactive;
    qsort(medicine->active,n,sizeof(Ingredient),cmp);
    qsort(medicine->inactive,m,sizeof(Ingredient),cmp);
 
    printf("----- Active Ingredient begin   -----\n");
    for(int i = 0;i < n;i ++)
        printf("%d %s\n",medicine->active[i].weight,medicine->active[i].name);
    printf("----- end                       -----\n");
 
    printf("----- Inactive Ingredient begin -----\n");
    for(int i = 0;i < m;i ++)
        printf("%d %s\n",medicine->inactive[i].weight,medicine->inactive[i].name);
    printf("----- end                       -----\n");
 
}
int totalWeight(Medicine *medicine)
{
    int ans = 0;
    int n = medicine->num_active,m = medicine->num_inactive;
    for(int i = 0;i < n;i ++)    ans += medicine->active[i].weight;
    for(int i = 0;i < m;i ++)    ans += medicine->inactive[i].weight;
    return ans;
}
char *maxIngredient(Medicine *medicine)
{
    int max = -500,ans[2];
    int n = medicine->num_active,m = medicine->num_inactive;
    if(n == 0 && m == 0)    return NULL;
    for(int i = 0;i < n;i ++){
        if(medicine->active[i].weight > max){
            max = medicine->active[i].weight;
            ans[0] = 0;
            ans[1] = i;
        }
        if(medicine->active[i].weight == max)
            if(strcmp(medicine->active[i].name,medicine->active[ans[1]].name) < 0){
                ans[0] = 0;
                ans[1] = i;
            }
    }
    for(int i = 0;i < m;i ++){
        if(medicine->inactive[i].weight > max){
            max = medicine->inactive[i].weight;
            ans[0] = 1;
            ans[1] = i;
        }
        if(medicine->inactive[i].weight == max && ans[0] == 0)
            if(strcmp(medicine->inactive[i].name,medicine->active[ans[1]].name) < 0){
                ans[0] = 1;
                ans[1] = i;
            }
        if(medicine->inactive[i].weight == max && ans[0] == 1)
            if(strcmp(medicine->inactive[i].name,medicine->inactive[ans[1]].name) < 0){
                ans[0] = 1;
                ans[1] = i;
            }
    }
    if(ans[0] == 0)    return medicine->active[ans[1]].name;
    else    return medicine->inactive[ans[1]].name;
}