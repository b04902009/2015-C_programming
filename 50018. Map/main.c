#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
typedef struct{
    int key;
    char value[200];
} KeyValue;
typedef struct{
    int num;
    KeyValue a[1500];
} Map;
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
void test_all(Map *maps, int map_n) {
    for (int i = 0; i < map_n; i++)
        init(&maps[i]);
    int cmds, mid, cmd, key;
    char val[128];
    int keylist[1024];
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &mid);
            print(&maps[mid]);
        } else if (cmd == 2) {    
            scanf("%d %d %s", &mid, &key, val);
            int f = map(&maps[mid], key, val);
            printf("mf %d\n", f);
        } else if (cmd == 3) {
            scanf("%d %d", &mid, &key);
            int f = unmap(&maps[mid], key);
            printf("uf %d\n", f);
        } else if (cmd == 4) {
            scanf("%d %s", &mid, val);
            int keylist_n = reverseMap(&maps[mid], val, keylist);
            assert(keylist_n <= 1024);
            printf("list ");
            for (int i = 0; i < keylist_n; i++)
                printf("%d%c", keylist[i], " \n"[i == keylist_n-1]);
        } else if (cmd == 5) {
            scanf("%d", &mid);
            int ret = numPairs(&maps[mid]);
            assert(ret <= 1024);
            printf("size %d\n", ret);
        } else {
            assert(false);
        }
    }
}
int main() {
    int map_n = 1;
    Map *maps = (Map *) malloc(sizeof(Map) * map_n);
    test_all(maps, map_n);
    free(maps);
    return 0;
}