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
void insert()
{
p=head;
int d;
printf("Enter element : ");
scanf("%d",&d);
ll=(node*)malloc(sizeof(node));
ll->data=d;
while(p->link!=NULL)
{
p=p->link;
}
ll->link=NULL;
p->link=ll;
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
void delete1()
{
prev=head;
p=prev->link;
if(prev->link==NULL)
printf("\nSTACK UNDERFLOW");
else
{
while(p->link!=NULL)
{
prev=prev->link;
p=p->link;
}
prev->link=NULL;
free(p);
}
}
void main()
{
int c;
do
{
printf("\n---MENU---");
printf("\n1.Enqueue");
printf("\n2.Dequeue");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter your choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
insert();
break;
case 2:
delete1();
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

