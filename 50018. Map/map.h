typedef struct{
    int key;
    char value[200];
} KeyValue;
typedef struct{
    int num;
    KeyValue a[1500];
} Map;
void init(Map *map);
int map(Map *map, const int key, const char *value);
int numPairs(Map *map);
void print(Map *map);
const char *getValue(Map *map, const int key);
int unmap(Map *map, int key);
int reverseMap(Map *map, const char *value, int keys[]);