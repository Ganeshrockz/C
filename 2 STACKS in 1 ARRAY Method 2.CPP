/*This program again helps to maintain two stacks in an array
    1.Create an array of size MAX
    2.Start top of stack 1 from 0 and top of stack 2 from MAX-1
    3.By this way the two stacks will be growing and shrinking in opposite directions
    This is a space efficient method.
    The overflow condition is reached when the distance between top of two stacks is 1.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
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
if(abs(a.top1-a.top2)==1)
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
if(abs(a.top2-a.top1)==1)
{
printf("\nStack2 Overflow");
return;
}
a.top2-=1;
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
if(a.top2==MAX)
{
printf("\nStack1 Underflow");
return;
}
z=a.data[a.top2];
a.top2++;
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
if(a.top2==MAX)
{
printf("\nStack2 is empty");
return;
}
for(int i=MAX-1;i>=a.top2;i--)
printf("%d ",a.data[i]);
}
void main()
{
a.top1=-1;
a.top2=MAX;
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
