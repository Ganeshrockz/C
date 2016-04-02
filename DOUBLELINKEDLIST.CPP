#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node*blink;
struct node*flink;
}node;
node *head,*p,*q,*prev,*ll;
void create()
{
head=(node*)malloc(sizeof(node));
head->flink=NULL;
head->blink=NULL;
}
void inserttail()
{
int d;
printf("\nEnter the element : ");
scanf("%d",&d);
p=head;
ll=(node*)malloc(sizeof(node));
ll->blink=NULL;
ll->flink=NULL;
ll->data=d;
while(p->flink!=NULL)
{
p=p->flink;
}
p->flink=ll;
ll->blink=p;
}
void deletetail()
{
int s;
prev=head;
p=head->flink;
if(prev->flink==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
while(p->flink!=NULL)
{
p=p->flink;
prev=prev->flink;
}
s=p->data;
prev->flink=NULL;
p->blink=NULL;
printf("\nElement deleted is %d",s);
}
void inserthead()
{
int d;
printf("\nEnter element to be inserted : ");
scanf("%d",&d);
prev=head;
p=head->flink;
ll=(node*)malloc(sizeof(node));
ll->data=d;
ll->blink=p->blink;
ll->flink=prev->flink;
prev->flink=ll;
p->blink=ll;
}
void deletehead()
{
prev=head;
p=head->flink;
q=p->flink;
if(prev->flink==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
prev->flink=p->flink;
q->blink=p->blink;
p->flink=NULL;
p->blink=NULL;
}
void insertpos()
{
int e,pos,count=1;
printf("\nEnter the element : ");
scanf("%d",&e);
printf("\nEnter the position : ");
scanf("%d",&pos);
prev=head;
p=head->flink;
ll=(node*)malloc(sizeof(node));
ll->flink=NULL;
ll->blink=NULL;
ll->data=e;
while(count<pos)
{
prev=prev->flink;
p=p->flink;
count++;
}
ll->blink=p->blink;
ll->flink=prev->flink;
prev->flink=ll;
p->blink=ll;
}
void deletepos()
{
int pos,count=1;
prev=head;
if(prev->flink==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
printf("\nEnter position to be deleted : ");
scanf("%d",&pos);
p=prev->flink;
q=p->flink;
while(count<pos)
{
prev=prev->flink;
p=p->flink;
q=q->flink;
count++;
}
prev->flink=p->flink;
q->blink=p->blink;
p->flink=NULL;
p->blink=NULL;
}
void display()
{
p=head->flink;
if(p==NULL)
printf("\nLIST IS EMPTY");
while(p!=NULL)
{
printf("%d ",p->data);
p=p->flink;
}
}
void main()
{
int c;
clrscr();
create();
do
{
printf("\n---MENU---");
printf("\n1.insert");
printf("\n2.Display");
printf("\n3.Delete");
printf("\n4.InsertHead");
printf("\n5.DeleteHead");
printf("\n6.InsertPosition");
printf("\n7.DeletePositon");
printf("\n8.Exit");
printf("\nEnter choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
inserttail();
break;
case 2:
display();
break;
case 3:
deletetail();
break;
case 4:
inserthead();
break;
case 5:
deletehead();
break;
case 6:
insertpos();
break;
case 7:
deletepos();
break;
case 8:
exit(0);
break;
default:
printf("\nInvalid Choice");
}
}while(c!=8);
getch();
}
