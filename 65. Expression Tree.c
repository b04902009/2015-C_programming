#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ptr = 0;
char input[1050];
int count(){
	if(input[ptr] <= '9' && input[ptr] >= '0'){
		int n = input[ptr++] - '0';
		while(input[ptr] <= '9' && input[ptr] >= '0')
			n = n*10 + input[ptr++] - '0';
		ptr++;
		return n;
	}
	if(input[ptr] == '('){
		ptr+=2;
		char op = input[ptr];
		ptr+=2;
		int l = count();
		int r = count();
		ptr+=2;
		switch(op){
			case '+': return l+r; break;
			case '-': return l-r; break;
			case '*': return l*r; break;
			case '/': return l/r; break;
		}
	}
	return 0;
}
char *strinstr(char *var){
	int end = strlen(input);
	int nv = strlen(var);
	for(int i = 0; i < end; i++)
		if(var[0] == input[i]){
			int flag = 1;
			for(int j = 0; j < nv; j++)
				if(input[i+j] != var[j]){
					flag = 0;
					break;
				}
			if(flag && input[i+nv] ==' ')  return &input[i];
		}
	
	return NULL;
}
int main()
{
	char var[50], d[32];
	gets(input);
	while(scanf("%s = %s", var, d) != EOF){
		char *start;
		int end = strlen(input);
		while((start = strinstr(var)) != NULL){
			int nd = strlen(d);
			int nv = strlen(var);
			if(nv > nd)
				for(int i = start-input+nv; i <= end; i++)
					input[i+nd-nv] = input[i];
			else
				for(int i = end; i >= start-input+nv; i--)
					input[i+nd-nv] = input[i];
				
			end += nd-nv;
			for(int i = 0; i < nd; i++)
				input[start-input+i] = d[i];
		}
	}
	//printf("%s\n", input);
	printf("%d", count());
	return 0;
}