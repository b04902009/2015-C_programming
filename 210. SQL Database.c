#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct Data{
    char lastname[80],firstname[80],ID[80];
    int salary,age;
};
struct Data data[50];
int order[15],field_n;
void print(int i){
    for(int j = 1;j < field_n;j ++){
        switch(order[j]){
            case 1: printf("%s%c",data[i].lastname,j == field_n-1 ? '\n' : ' '); break;
            case 2: printf("%s%c",data[i].firstname,j == field_n-1 ? '\n' : ' '); break;
            case 3: printf("%s%c",data[i].ID,j == field_n-1 ? '\n' : ' '); break;
            case 4: printf("%d%c",data[i].salary,j == field_n-1 ? '\n' : ' '); break;
            case 5: printf("%d%c",data[i].age,j == field_n-1 ? '\n' : ' '); break;
        }
    }
}
int main(void)
{
    int n,m;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
        scanf("%s %s %s %d%d",data[i].lastname,data[i].firstname,data[i].ID,&data[i].salary,&data[i].age);
    scanf("%d",&m);
    char field[15][80];
    for(int i = 0;i < m;i ++){
        int flag = 0;
        for(int j = 0;j < 15;j ++){
            scanf("%s",field[j]);
            if(field[j][0] == 'l')    order[j] = 1;
            if(field[j][0] == 'f')    order[j] = 2;
            if(field[j][0] == 'I')    order[j] = 3;
            if(field[j][0] == 's')    order[j] = 4;
            if(field[j][0] == 'a')    order[j] = 5;
            if(flag == 3)    break;
            if(flag)    flag ++;
            if(strcmp(field[j],"where") == 0){
                flag = 1;
                field_n = j;
            }
        }
        int temp;
        if(order[field_n+1] == 4 || order[field_n+1] == 5)    temp = atoi(field[field_n+3]);
        if(strcmp(field[field_n+2],"==") == 0)
            for(int i = 0;i < n;i ++)
                switch(order[field_n+1]){
                    case 1: if(strcmp(field[field_n+3],data[i].lastname) == 0)    print(i); break;
                    case 2: if(strcmp(field[field_n+3],data[i].firstname) == 0)    print(i); break;
                    case 3: if(strcmp(field[field_n+3],data[i].ID) == 0)    print(i); break;
                    case 4: if(data[i].salary == temp)    print(i); break;
                    case 5: if(data[i].age == temp)    print(i); break;
                    default: break;
                }
        else if(strcmp(field[field_n+2],"!=") == 0)
            for(int i = 0;i < n;i ++)
                switch(order[field_n+1]){
                    case 1: if(strcmp(field[field_n+3],data[i].lastname) != 0)    print(i); break;
                    case 2: if(strcmp(field[field_n+3],data[i].firstname) != 0)    print(i); break;
                    case 3: if(strcmp(field[field_n+3],data[i].ID) != 0)    print(i); break;
                    default: break;
                }
        else if(strcmp(field[field_n+2],">") == 0)
            for(int i = 0;i < n;i ++)
                switch(order[field_n+1]){
                    case 4: if(data[i].salary > temp)    print(i); break;
                    case 5: if(data[i].age > temp)    print(i); break;
                    default: break;
                }
        else if(strcmp(field[field_n+2],"<") == 0)
            for(int i = 0;i < n;i ++)
                switch(order[field_n+1]){
                    case 4: if(data[i].salary < temp)    print(i); break;
                    case 5: if(data[i].age < temp)    print(i); break;
                    default: break;
                }
    }

    return 0;
}
