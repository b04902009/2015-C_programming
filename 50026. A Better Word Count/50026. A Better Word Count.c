#include <stdio.h>
int main()
{
	char name[1000], a;
	scanf("%s", name);
	int line = 0, word = 0, byte = 0, flag = 0, hasword = 0;
	FILE *fin = fopen(name, "rb");
	while((a = fgetc(fin))){
		byte ++;
		if(a == EOF){
			if(hasword)  line ++;
			byte --;
			break;
		}
		hasword = 1;
		if(a == '\n'){
			line ++;
			hasword = 0;
		}
		if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
			if(!flag){
				flag = 1;
				word ++;
			}
		}
		else  flag = 0;
	}
	printf("%d %d %d\n", line, word, byte);

	fclose(fin);
	return 0;
}