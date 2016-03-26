#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 30
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();
void main()
{
int c;
char ch;
clrscr();
do
{
printf("\n-----Menu-----");
printf("\n1----Enqueue");
printf("\n2----Dequeue");
printf("\n3----Display");
printf("\n4----Exit");
printf("\nEnter u r choice : ");
scanf("%d",&c);
switch(c)
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
goto f;
default:
printf("\nEnter valid choice");
}
printf("\nDo you want to continue : ");
getchar();
scanf("%c",&ch);
}while(ch=='Y'||ch=='y');
f:
printf("\nThank you");
getch();
}
void enqueue()
{
int d;
printf("Enter element to be inserted : ");
scanf("%d",&d);
if(rear==MAX-1)
printf("\nQueue is full");
else
queue[++rear]=d;
}
void display()
{
if(front>=rear)
printf("Stack is empty");
else
{
for(int i=front+1;i<=rear;i++)
printf("%d\t",queue[i]);
}
}
void dequeue()
{
int ele;
if(front>=rear)
printf("Stack underflow");
else
{
front++;
ele=queue[front];
printf("Element deleted is %d",ele);
}
}