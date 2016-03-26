#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
struct stacks
{
int stack[MAX];
int top;
}a;
void push()
{
int item;
printf("\nEnter item to be added : ");
scanf("%d",&item);
if(a.top==MAX-1)
printf("\nStack overflow.....");
else
a.stack[++a.top]=item;
}
void display()
{
if(a.top==-1)
printf("Stack is empty");
else
{
for(int i=a.top;i>=0;i--)
printf("%d\n",a.stack[i]);
}
}
void pop()
{
int d;
if(a.top==-1)
{
printf("\nStack underflow");

}
else
{
d=a.stack[a.top];
a.top--;
printf("\nElement deleted is %d",d);
}
}
int pop1()
{
int o;
o=a.stack[a.top];
a.top--;
return o;
}
void sort()
{
int temp,n=0,b[20],x,i=0;
while(a.top!=-1)
{
x=pop1();
b[i++]=x;
n++;
}
for(i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
for(i=0;i<n;i++)
printf("%d ",b[i]);
}
void main()
{
a.top=-1;
int ch;
clrscr();
do
{
printf("\n***************");
printf("\n1.PUSH");
printf("\n2.POP");
printf("\n3.DISPLAY");
printf("\n4.EXIT");
printf("\n***************");
printf("\nEnter the choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
exit(0);
case 5:
sort();
break;
default:
printf("\nINVALID CHOICE\n");
}
}while(ch!=4);
g:
getch();
}
