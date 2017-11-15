typedef struct ingredient{
    char name[200];
    int weight;
}Ingredient;
typedef struct medicine{
    Ingredient active[10];
    Ingredient inactive[10];
    int num_active,num_inactive;
} Medicine;
void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);