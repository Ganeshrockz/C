#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list
{
int data;
struct list *link;
}node;
node *p,*ll,*prev,*head;
void create()
{
head=(node*)malloc(sizeof(node));
head->link=NULL;
}
void display()
{
p=head->link;
if(p==NULL)
printf("\nSTACK IS EMPTY");
else
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->link;
}
}
}
void insert1()
{
int e;
printf("\nEnter element : ");
scanf("%d",&e);
p=head;
ll=(node*)malloc(sizeof(node)); //NEW NODE CREATION
ll->data=e;
ll->link=p->link;
p->link=ll;
}
//DELETE AT HEAD
void delete2()
{
int count=0;
prev=head;
p=prev->link;
if(prev->link==NULL)
{
  printf("\nSTACK underflow");
  return;
}
prev->link=p->link;
}
void main()
{
int c;
do
{
printf("\n---MENU---");
printf("\n1.Push");
printf("\n2.Pop");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter your choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
insert1();
break;
case 2:
delete2();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("\nEnter a valid choice");
}
}while(c!=4);
getch();
}

