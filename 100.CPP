#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
struct stack1
{
int data[MAX];
int top;
}a;
struct stack2
{
int data[MAX];
int top;
}b;
int pop1()
{
int x;
x=a.data[a.top];
a.top=a.top-1;
return x;
}
void push1(int x)
{
b.top=b.top+1;
b.data[b.top]=x;
}
int pop2()
{
int d;
d=b.data[b.top];
b.top=b.top-1;
return d;
}
void enqueue()
{
int x;
printf("\nEnter element : ");
scanf("%d",&x);
while(a.top!=-1)
{
push1(pop1());
}
a.top=a.top+1;
a.data[a.top]=x;
while(b.top!=-1)
{
a.top=a.top+1;
a.data[a.top]=pop2();
}
}
void dequeue()
{
int d;
if(a.top==-1)
printf("\nQueue underflow");
else
{
d=a.data[a.top];
a.top=a.top-1;
printf("\nElement deleted is %d",d);
}
}
void display()
{
if(a.top==-1)
printf("\nQueue is empty");
else
{
for(int i=a.top;i>=0;i--)
{
printf("%d ",a.data[i]);
}
}
}
void main()
{
int d;
a.top=-1;
b.top=-1;
clrscr();
do
{
printf("\nMENU");
printf("\n1.Enqueue");
printf("\n2.Dequeue");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter choice : ");
scanf("%d",&d);
switch(d)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}while(d!=4);
getch();
}
