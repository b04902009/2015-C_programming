#include <stdio.h>
#include <string.h>
typedef struct{
    unsigned int id;
    char name[32];
} Person;
typedef struct{
    unsigned id1;
    unsigned id2;
} Friend;
int main()
{
	FILE *fin = fopen("friends","rb");
	int P,F;
	Person person[10000];
	Friend friend[10000];

	fread(&P, 4, 1, fin);
	for(int i = 0; i < P; i++)
		fread(&person[i],sizeof(Person),1,fin);
	fread(&F, 4, 1, fin);
	for(int i = 0; i < F; i++)
		fread(&friend[i],sizeof(Friend),1,fin);

	char p1[50], p2[50];
	while(1){
		int flag = 0, id1, id2;
		scanf("%s", p1);
		if(strcmp(p1, "end") == 0)  break;
		scanf("%s", p2);
		for(int i = 0; i < P; i++){
			if(strcmp(p1, person[i].name) == 0)  id1 = person[i].id;
			if(strcmp(p2, person[i].name) == 0)  id2 = person[i].id;
		}
		for(int i = 0; i < F; i++)
			if((id1 == friend[i].id1 && id2 == friend[i].id2) || (id2 == friend[i].id1 && id1 == friend[i].id2)){
				flag = 1;
				break;
			}
		flag ? printf("yes\n") : printf("no\n");
	}
	fclose(fin);
	return 0;
}