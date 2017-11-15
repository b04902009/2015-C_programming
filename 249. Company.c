#include <stdio.h>
#include <string.h>
struct employee {
    long long int id;
    char first_name[32];
    char last_name[32];
    long long int boss_id;
};
struct employee p[33];
int n,m,flag = 1,end1 = 0,end2 = 0;
void relation(int p1,int p2,long long int p1_boss,long long int p2_boss)
{
    if(p1_boss == p[p2].id){
        flag = 0;
        printf("subordinate\n");
        return;
    }
    if(p2_boss == p[p1].id){
        flag = 0;
        printf("supervisor\n");
        return;
    }
    if(p1_boss == p2_boss){
        flag = 0;
        printf("colleague\n");
        return;
    }  
    for(int i = 0;i < n && !end1 && flag;i ++)
        if(p1_boss == p[i].id){
    //        printf("p1_bossid: %lld -> %lld\n",p1_boss,p[i].boss_id);
            if(p1_boss == p[i].boss_id)    end1 = 1;
            p1_boss = p[i].boss_id;
            relation(p1,p2,p1_boss,p2_boss);
        }
    for(int i = 0;i < n && !end2 && flag;i ++)
        if(p2_boss == p[i].id){
    //        printf("p2_bossid: %lld -> %lld\n",p2_boss,p[i].boss_id);
            if(p2_boss == p[i].boss_id)    end2 = 1;
            p2_boss = p[i].boss_id;
            relation(p1,p2,p1_boss,p2_boss);
        }
}
int main(void)
{
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
        scanf("%lld %s %s %lld",&p[i].id,p[i].first_name,p[i].last_name,&p[i].boss_id);
    scanf("%d",&m);
    char f1[32],l1[32],f2[32],l2[32];
    int p1,p2;
    for(int j = 0;j < m;j ++){
        scanf("%s %s %s %s",f1,l1,f2,l2);
        for(int i = 0;i < n;i ++){
            if(strcmp(f1,p[i].first_name) == 0 && strcmp(l1,p[i].last_name) == 0)    p1 = i;
            if(strcmp(f2,p[i].first_name) == 0 && strcmp(l2,p[i].last_name) == 0)    p2 = i;
        }
    //    printf("p1:%d  p2:%d\n",p1,p2);
        flag = 1;
        end1 = 0;
        end2 = 0;
        relation(p1,p2,p[p1].boss_id,p[p2].boss_id);
        if(flag)    printf("unrelated\n");
    }

    return 0;
}
