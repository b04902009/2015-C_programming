#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
void init(Map *map){
    map->num = 0;
}
int map(Map *map, const int key, const char *value){
    for(int i = 0;i < map->num;i ++)
        if(map->a[i].key == key){
            strcpy(map->a[i].value,value);
            return 0;
        }
    map->a[map->num].key = key;
    strcpy(map->a[map->num].value,value);
    (map->num) ++;
    return 1;
}
int numPairs(Map *map){
    return map->num;
}
void print(Map *map){
    for(int i = 0;i < map->num-1;i ++)
        for(int j = 0;j < map->num-1-i;j ++)
            if(map->a[j].key > map->a[j+1].key){
                KeyValue temp = map->a[j];
                map->a[j] = map->a[j+1];
                map->a[j+1] = temp;
            }

    printf("----- map begin -----\n");
    for(int i = 0;i < map->num;i ++)
        printf("%d %s\n",map->a[i].key,map->a[i].value);
    printf("----- end       -----\n");
}
const char *getValue(Map *map, const int key){
    for(int i = 0;i < map->num;i ++)
        if(map->a[i].key == key)
            return map->a[i].value;
    return NULL;
}
int unmap(Map *map, int key){
    int i,flag = 0;
    for(i = 0;i < map->num;i ++)
        if(map->a[i].key == key){
            flag = 1;
            break;
        }
    if(flag)    map->num --;
    for(int j = i;j < map->num;j ++)
        map->a[j] = map->a[j+1];
    return flag;
}
int cmp(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
int reverseMap(Map *map, const char *value, int keys[]){
    int ans = 0;
    for(int i = 0;i < map->num;i ++)
        if(strcmp(map->a[i].value,value) == 0){
            keys[ans] = map->a[i].key;
            ans ++;
        }
    qsort(keys,ans,4,cmp);
    return ans;
}