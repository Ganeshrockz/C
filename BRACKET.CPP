#include<stdio.h>
#define MAX 100
struct stack
{
char list[MAX];
int top;
}s;
void push(char z)
{
s.top+=1;
s.list[s.top]=z;
}
char pop()
{
char z;
z=s.list[s.top];
s.top--;
return z;
}
int isempty()
{
if(s.top==-1)
return 1;
else
return 0;
}
void main()
{
char a[MAX];
int i,flag=0;
char x;
s.top=-1;
printf("\nEnter expression : ");
scanf("%s",a);
i=0;
while(a[i]!='\0')
{
if(a[i]=='('||a[i]=='['||a[i]=='{')
push(a[i]);
else if(a[i]==')'||a[i]==']'||a[i]=='}')
{
x=pop();
if((a[i]==')'&&x=='(')||(a[i]==']'&&x=='[')||(a[i]=='}'&&x=='{'))
flag=0;
else
{
flag=1;
break;
}
}
i++;
}
if(flag==0&&isempty())
 printf("\nParentheses balanced");
 else
 printf("\nNot balanced");
 }