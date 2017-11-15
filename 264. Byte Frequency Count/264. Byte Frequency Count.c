#include <stdio.h>
int main()
{
	char name[250];
	FILE *fin;
	int max = 0, num, n[70000], ans;
	short int temp;
	scanf("%s", name);
	fin = fopen(name, "rb");
	fread(&num, 4, 1, fin);
	for(int i = 0; i < 70000; i++)  n[i] = 0;
	for(int i = 0; i < num; i++){
		fread(&temp, 2, 1, fin);
		n[temp+32768] ++;
		if(n[temp+32768] > max || (n[temp+32768] == max && temp > ans)){
			max = n[temp+32768];
			ans = temp;
		}
	}
	printf("%d\n%d\n",ans,n[ans+32768]);
	fclose(fin);
	return 0;
}