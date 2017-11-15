#include <string.h>
char s[100000],flag = 0;
int eval(int head,int end)
{
    if(end-head == 0 && s[head]-'0' <= 9 && s[head]-'0' >= 0)   return s[head]-'0';
    int l = 0,r = 0;
    if(s[head] == '-')  return (-1)*eval(head+1,end);

    if(s[head] == '('){
        for(int i = head+1;i < end;i ++){
            if(s[i] == '(')    l ++;
            if(s[i] == ')')    r ++;
            if(l == r && s[i] != '-'){
                if(s[i+1] == '+')   return eval(head+1,i)+eval(i+2,end-1);
                if(s[i+1] == '-')   return eval(head+1,i)-eval(i+2,end-1);
                if(s[i+1] == '*')   return eval(head+1,i)*eval(i+2,end-1);
                if(s[i+1] == '/'){
                    if(eval(i+2,end-1) == 0)  return -2147483648;
                    return eval(head+1,i)/eval(i+2,end-1);
                }
            }
        }
    }
    flag = 1;
    return 0;
}
int expression(char *string)
{
    int ans;
    flag = 0;
    int n = strlen(string);
    for(int i = 0;i < n;i ++)    s[i] = string[i];
    ans = eval(0,n-1);
    if(flag)    return -2147483648;
    else    return ans;
}
