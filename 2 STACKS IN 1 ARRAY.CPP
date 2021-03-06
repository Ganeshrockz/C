/*This program helps us to maintain two stacks in a single array
ALGO:
1:Create an array of size MAX
2.Store one stack from 0 to MAX/2-1
3.Store second stack from MAX/2 to MAX-1
4.Stack 1 gets full when first half of array gets full
5.Stack 2 gets full when the second half of array gets full
The disadvantage of this method is that when STACK1 is full and STACK2 is empty
you cannot use STACK2 to store the elements of STACK1 which is space inefficient*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 6
struct stack
{
int data[MAX];
int top1;
int top2;
}a;
void push1()
{
int d;
printf("\nEnter data : ");
scanf("%d",&d);
if(a.top1==MAX/2-1)
{
printf("\nStack1 Overflow");
return;
}
a.top1+=1;
a.data[a.top1]=d;
}
void push2()
{
int d;
printf("\nEnter data : ");
scanf("%d",&d);
if(a.top2==MAX-1)
{
printf("\nStack2 Overflow");
return;
}
a.top2+=1;
a.data[a.top2]=d;
}
void pop1()
{
int z;
if(a.top1==-1)
{
printf("\nStack1 Underflow");
return;
}
z=a.data[a.top1];
a.top1--;
printf("\nElement deleted from stack1 is %d",z);
}
void pop2()
{
int z;
if(a.top2==MAX/2-1)
{
printf("\nStack1 Underflow");
return;
}
z=a.data[a.top2];
a.top2--;
printf("\nElement deleted from stack1 is %d",z);
}
void display()
{
printf("\nStack1\n");
if(a.top1==-1)
{
printf("\nStack1 is empty");
}
else
{
for(int i=0;i<=a.top1;i++)
printf("%d ",a.data[i]);
}
printf("\nStack2\n");
if(a.top2==MAX/2-1)
{
printf("\nStack2 is empty");
return;
}
for(int i=MAX/2;i<=a.top2;i++)
printf("%d ",a.data[i]);
}
void main()
{
a.top1=-1;
a.top2=MAX/2-1;
int d;
clrscr();
do
{
printf("\nMENU");
printf("\n1.Push1");
printf("\n2.Push2");
printf("\n3.Pop1");
printf("\n4.Pop2");
printf("\n5.Display");
printf("\n\nEnter choice : ");
scanf("%d",&d);
switch(d)
{
case 1: push1();
break;
case 2:
push2();
break;
case 3:
pop1();
break;
case 4:
pop2();
break;
case 5:
display();
break;
case 6:
exit(0);
}
}while(d!=6);
getch();
}
